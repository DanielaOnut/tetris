//
// Created by danie on 01.07.2021.
//

#include "Queue.h"
#include "Figure.h"

void Queue::init() noexcept {
    this->squareSize = 40;

    this->setMinimumWidth( this->squareSize * this->width + this->horizontalMargin * 2 );
    this->setMinimumHeight( this->squareSize * this->height + this->verticalMargin * 2 );

    this->repaint();
}

void Queue::generateInitial () noexcept {
    this->queue.push_back(Figure::Factory().random().spawn());
    if (CurrentSettings::instance().general().difficulty == CurrentSettings::EASY
        || CurrentSettings::instance().general().difficulty == CurrentSettings::NORMAL) {
        this->queue.push_back(Figure::Factory().random().spawn());
        this->queue.push_back(Figure::Factory().random().spawn());
    }
    this->adjustSquares();
}

void Queue::adjustSquares() noexcept {
    this->cleanSquares();
    for (auto & figure : this->queue)
        figure->drawFigureForQueue (this->squares);
    this->repaint();
}

void Queue::cleanSquares () noexcept {
    for (int i = 0; i < this->height; ++i)
        for (int j = 0; j < this->width; ++j)
            this->squares[i][j].setTexture(SquareTexture::empty());
}

Figure * Queue::pop () noexcept {
    Figure * firstFigure = this->queue.front();
    this->queue.pop_front();
    this->queue.push_back(Figure::Factory().random().spawn());
    this->adjustSquares();
    return firstFigure;
}

#include <QPainter>
void Queue::paintEvent(QPaintEvent * event ) noexcept {
    QPainter painter ( this ); // iei in considerare activeFigures ->

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