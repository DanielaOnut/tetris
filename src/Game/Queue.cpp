//
// Created by danie on 01.07.2021.
//

#include "Queue.h"

void Queue::init() noexcept {
    auto resWidth = CurrentSettings::instance().video().resolutionWidth;
    auto resHeight = CurrentSettings::instance().video().resolutionHeight;

    this->squareSize = 40;

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

    this->activeFigure = Figure::Factory().random().spawn();
    this->activeFigure->drawFigure(this->squares);

    this->repaint();
}

#include <QPainter>
void Queue::paintEvent(QPaintEvent * event ) noexcept {
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

Queue::~Queue() noexcept {
    for ( int i = 0; i < this->height; i++ )
        delete [] this->squares[i];

    delete [] this->squares;
}