//
// Created by danie on 20.04.2021.
//

#include "Figure.h"
#include <Board.h>
#include <QPainter>

void Figure::drawFigure(int x, int y, Square **&boardMatrix) noexcept(false) {
    int matrixWidth = Board::DEFAULT_WIDTH;
    int matrixHeight = Board::DEFAULT_HEIGHT;

    if ( y > matrixHeight )
        throw std::runtime_error ( std::string(this->toString()) + ": y is out of the matrix dimensions");
    if (x > matrixWidth)
        throw std::runtime_error ( std::string(this->toString()) + ": x is out of the matrix dimensions");
    auto sqTexture = this->getSquareTexture();

    for ( int i = 0; i < SQUARE_COUNT; i++ )
        boardMatrix[y + this->yOffsetsForRotation(0)[i]][x + this->xOffsetsForRotation(0)[i]]
            .setTexture(sqTexture);
}

//void Figure::paintEvent(QPaintEvent * event) noexcept {
//    QPainter painter (this);
//
//    painter.drawPixmap(2,0,this->squares[2][0].getTexture()->scaled(this->squareSize, this->squareSize));
//    for (int i = 0;i < this->height;i++)
//        painter.drawPixmap(i,1,this->squares[i][1].getTexture()->scaled(this->squareSize, this->squareSize));
//    QWidget::paintEvent( event );
//}
