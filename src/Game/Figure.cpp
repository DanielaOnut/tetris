//
// Created by danie on 20.04.2021.
//

#include "Figure.h"
#include <Board.h>
#include <QPainter>

void Figure::createFigure(QPixmap * tex, const char * color, int size) noexcept {
    this->squareSize = size;
    if (color == "blue") {
        this->height = 3;
        this->width = 2;
        this->squares = new Square * [this->height];
        for (int i = 0;i < this->height;i++)
            this->squares[i] = new Square [this->width];
        this->squares[2][0].setTexture(tex);
        for (int i = 0;i < this->height;i++)
            this->squares[i][1].setTexture(tex);
    }
    this->repaint();
}

void Figure::paintEvent(QPaintEvent * event) noexcept {
    QPainter painter (this);

    painter.drawPixmap(2,0,this->squares[2][0].getTexture()->scaled(this->squareSize, this->squareSize));
    for (int i = 0;i < this->height;i++)
        painter.drawPixmap(i,1,this->squares[i][1].getTexture()->scaled(this->squareSize, this->squareSize));
    QWidget::paintEvent( event );
}

Figure::~Figure() noexcept {
    for ( int i = 0; i < this->height; i++ )
        delete [] this->squares[i];

    delete [] this->squares;
}