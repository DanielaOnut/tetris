//
// Created by loghin on 16.04.2021.
//

#include "Board.h"
#include <CurrentSettings.h>
#include <Figure.h>

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

    for ( int i = 0; i < this->height; i ++ ) {
        for (int j = 0; j < this->width; j++) {
//            if (i == 2 && j == 2)
//                this->squares[i][j].setTexture( SquareTexture::blue() );

//            else
            this->squares[i][j].setTexture(SquareTexture::empty());
        }
    }
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