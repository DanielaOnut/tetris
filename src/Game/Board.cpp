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
                    this->activeFigure->clearDrawnFigures(this->squares);
                    this->activeFigure->moveFigureToRight(this->squares);
                    this->repaint();
                }
            } catch (std::exception const & e) {
                std::cout << e.what() << '\n';
            }
        } );
    }
}

void Board::moveActiveShapeToLeft () noexcept {
    auto * p = dynamic_cast < Game * > (this->parent());
    if ( p != nullptr ) {
        connect ( p, & Game::moveLeft, [this] {
            try {
                if ( this->activeFigure != nullptr ) {
                    this->activeFigure->clearDrawnFigures(this->squares);
                    this->activeFigure->moveFigureToLeft(this->squares);
                    this->repaint();
                }
            } catch (std::exception const & e) {
                std::cout << e.what() << '\n';
            }
        } );
    }
}

void Board::dropActiveShape() noexcept {
    if (this->activeFigure == nullptr)
        this->activeFigure = new FigureReversedL();
    if (this->activeFigure->getY() >= 0)
        this->activeFigure->clearDrawnFigures(this->squares);
    try {
        if (this->activeFigure != nullptr) {
            this->activeFigure->dropFigure(this->squares);
            this->repaint();
        }
    } catch (std::exception const & e) {
        std::cout << e.what() << '\n';
        this->activeFigure = nullptr;
    }
}

void Board::rotateShape () noexcept {
    if (this->activeFigure != nullptr && strcmp (this->activeFigure->toString(),"FigureSquare")) {
        this->activeFigure->clearDrawnFigures(this->squares);
        this->activeFigure->rotateFigure(this->squares);
        this->repaint();
    }
}