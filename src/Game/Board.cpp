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
    auto * p = dynamic_cast < Game * > (this->parent());
    if ( p != nullptr ) {
        // Game is parent

        connect ( p, & Game::moveRight, [] {
            std::cout << "Should move right\n";
            // preferabil intr-o alta functie
            // incerci sa muti figura
        } );
    }

    auto resWidth = CurrentSettings::instance().video().resolutionWidth;
    auto resHeight = CurrentSettings::instance().video().resolutionHeight;

    this->squareSize = std::min (
            ( resWidth - this->horizontalMargin * 2 ) / this->width,
            ( resHeight - this->verticalMargin * 2 ) / this->height
    );

    std::cout << this->squareSize << '\n';

    this->squares = new Square * [this->height];
    for ( int i = 0; i < this->height; i++ ) {
        this->squares [i] = new Square [this->width];
    }

    for ( int i = 0; i < this->height; i ++ )
        for (int j = 0; j < this->width; j++) {
            this->squares[i][j].setTexture(SquareTexture::empty());
        }
//    FigureL f1;
//    f1.drawFigure(6, 4, this->squares);

    FigureSquare f2;
    f2.drawFigure(3, 18, this->squares);

    FigureI f3;
    f3.drawFigure(9, 17, this->squares);

    FigureT f4;
    f4.drawFigure(7, 19, this->squares);

//    FigureReversedL f5;
//    f5.drawFigure (4, 7, this->squares);

    FigureZ f6;
    f6.drawFigure(0,18,this->squares);

    FigureReversedZ f7;
    f7.drawFigure(5,18,this->squares);

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

void Board::clearDrawnShapes (int x, int y, int rotation) noexcept {
    for (int i = 0;i < 4;i++)
        this->squares[y + this->activeFigure->yOffsetsForRotation(rotation)[i]][x + this->activeFigure->xOffsetsForRotation(rotation)[i]]
                .setTexture(SquareTexture::empty());
}

void Board::dropActiveShape() noexcept {
    static int x = 0;
    static int y = 0;

    if ( this->activeFigure == nullptr ) {

        /// this->activeFigure = new Figure::generateRandom() ? momentan una din ele
        /// auto r = this->activeFigure->findCoordinatesToSpawnAt ();
        /// if ( ! r ) ... game over or smth
        this->activeFigure = new FigureReversedZ();
        x = 3;
        y = 3;
    }

    if ( y > 17 )
        return;

    this->activeFigure->drawFigure(x, y, this->squares);
    /// this->activeFigure->drop (); <- ori are rezultat, ori arunca exceptie
    /// this->activeFigure->drawFigure ();
//    std::cout << y << '\n';
    y++;

    this->repaint();

    this->clearDrawnShapes(x,y - 1,0);
}