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

void Board::init() noexcept {
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
    FigureL f1;
    f1.drawFigure(6, 2, this->squares);

    FigureSquare f2;
    f2.drawFigure(3, 18, this->squares);

    FigureI f3;
    f3.drawFigure(9, 16, this->squares);

    FigureT f4;
    f4.drawFigure(6, 19, this->squares);

    FigureReversedL f5;
    f5.drawFigure (4, 7, this->squares);

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

#include <FigureI.h>

void Board::dropActiveShape() noexcept {
    static int x = 0;
    static int y = 0;

    if ( this->activeFigure == nullptr ) {
        this->activeFigure = new FigureI();
        x = 3;
        y = 5;
    }

    if ( y > 15 )
        return;
    /// FigureI ( x, y, squares )
    /// FigureI -> patratele sale
    /// Figure -> moveDown
    ///     sa-si mute patratele si sa le de-textureze pe cele vechi

    this->activeFigure->drawFigure(x, y, this->squares);
    std::cout << y << '\n';
    y++;


    this->repaint();
}