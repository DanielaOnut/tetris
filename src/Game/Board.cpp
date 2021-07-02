//
// Created by loghin on 16.04.2021.
//

#include "Board.h"
#include <CurrentSettings.h>
#include <Figure.h>
#include <FigureL.h>
#include <FigureReversedL.h>
#include <FigureSquare.h>
#include <FigureI.h>
#include <FigureT.h>
#include <FigureZ.h>
#include <FigureReversedZ.h>

#include <iostream>

#include <Game.h>
void Board::init() noexcept {
    this->moveActiveShapeToRight();
    this->moveActiveShapeToLeft();
    auto resWidth = CurrentSettings::instance().video().resolutionWidth;
    auto resHeight = CurrentSettings::instance().video().resolutionHeight;

    this->squareSize = std::min (
            ( resWidth - this->horizontalMargin * 2 ) / this->width,
            ( resHeight - this->verticalMargin * 2 ) / this->height
    );

//    std::cout << this->squareSize << '\n';

    this->squares = new Square * [this->height];
    for ( int i = 0; i < this->height; i++ ) {
        this->squares [i] = new Square [this->width];
    }

    for ( int i = 0; i < this->height; i ++ )
        for (int j = 0; j < this->width; j++) {
            this->squares[i][j].setTexture(SquareTexture::empty());
        }

    this->setMinimumWidth( this->squareSize * this->width + this->horizontalMargin * 2 );
    this->setMinimumHeight( this->squareSize * this->height + this->verticalMargin * 2 );

    this->repaint();
}

Board::~Board() noexcept {
    for ( int i = 0; i < this->height; i++ )
        delete [] this->squares[i];

    delete [] this->squares;
}

#include <QPainter>
void Board::paintEvent(QPaintEvent * event ) noexcept {
    QPainter painter ( this );

    for ( int i = 0; i < this->height; i++ ) {
        for ( int j = 0; j < this->width; j++ ) {
            painter.drawPixmap(
                this->horizontalMargin + j * this->squareSize,
                this->verticalMargin + i * this->squareSize,
                this->squares[i][j].getTexture()->scaled(this->squareSize, this->squareSize)
            );
        }
    }

    QWidget::paintEvent( event );
}

void Board::moveActiveShapeToRight () noexcept {
    auto * p = dynamic_cast < Game * > (this->parent());
    if ( p != nullptr ) {
        // Game is parent
        connect ( p, & Game::moveRight, [this] {
            /// first clear then move
            try {
                if ( this->activeFigure != nullptr ) {
                    this->activeFigure->moveFigureToRight(this->squares);
                }
            } catch (std::exception const & e) {
                std::cout << e.what() << '\n';
            }
            this->repaint();
        } );
    }
}

void Board::moveActiveShapeToLeft () noexcept {
    auto * p = dynamic_cast < Game * > (this->parent());
    if ( p != nullptr ) {
        connect ( p, & Game::moveLeft, [this] {
            try {
                if ( this->activeFigure != nullptr ) {
                    this->activeFigure->moveFigureToLeft(this->squares);
                }
            } catch (std::exception const & e) {
                std::cout << e.what() << '\n';
            }
            this->repaint();
        } );
    }
}

void Board::deletingLine(int line) noexcept {
    for (int i = line; i > 0;i--)
        for (int j = 0;j < this->width;j++)
            this->squares[i][j].setTexture(this->squares[i-1][j].getTexture());
    for (int i = 0;i < this->width;i++)
        this->squares[0][i].setTexture(SquareTexture::empty());
}

void Board::lineIsFull() noexcept {
    for (int i = 0;i < this->height;i++) {
        bool isFull = true;
        for (int j = 0;j < this->width;j++)
            if (this->squares[i][j].getTexture() == SquareTexture::empty())
                isFull = false;
        if (isFull)
            this->deletingLine(i);
    }
}

static bool noRotation = false;
void Board::dropActiveShape() noexcept {
    if (this->activeFigure == nullptr) {
        noRotation = false;
        this->activeFigure = Figure::Factory().at(5, 2).spawn();
    }
    try {
        if (this->activeFigure != nullptr) {
            this->activeFigure->dropFigure(this->squares);
        }
    } catch (std::exception const & e) {
        std::cout << e.what() << '\n';
        this->lineIsFull();
        delete this->activeFigure;
        this->activeFigure = nullptr;
        auto pParent = dynamic_cast < Game * > (this->parent());
        if ( pParent != nullptr ) {
            this->activeFigure = pParent->getQueue()->pop();
        } else {
            this->activeFigure = Figure::Factory().random().spawn();
        }

        /// figure spawns at -1 -1, to remove pointless click, do another drop
        this->activeFigure->dropFigure(this->squares);
    }
    this->repaint();
}

void Board::rotateShape () noexcept {
    try {
        if (this->activeFigure != nullptr && strcmp(this->activeFigure->toString(), "FigureSquare")) {
            if (! noRotation)
                this->activeFigure->clearDrawnFigures(this->squares);
            this->activeFigure->rotateFigure(this->squares);
        }
    } catch (std::exception const & e) {
        std::cout << e.what() << '\n';
        try {
            this->activeFigure->dropFigure(this->squares);
        } catch (std::exception const & e) {
            std::cout << e.what() << " from rotation" << '\n';
            this->lineIsFull();
//            if (res != -1)
//                this->deletingLine(res);
            noRotation = true;
            delete this->activeFigure;
            this->activeFigure = nullptr;
        }
    }
    this->repaint();
}