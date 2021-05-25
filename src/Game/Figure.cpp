//
// Created by danie on 20.04.2021.
//

#include "Figure.h"
#include <Board.h>
#include <QPainter>

void Figure::drawFigure (Square **&boardMatrix, int rotation) noexcept {
    this->findCoordinatesToSpawnAt(boardMatrix, rotation);
    auto sqTexture = this->getSquareTexture();
    for ( int i = 0; i < SQUARE_COUNT; i++ )
        boardMatrix[this->y + this->yOffsetsForRotation(rotation)[i]][this->x + this->xOffsetsForRotation(rotation)[i]]
            .setTexture(sqTexture);
}

bool Figure::findCoordinatesToSpawnAt(Square ** & boardMatrix, int rotation) noexcept {
    int matrixWidth = Board::DEFAULT_WIDTH;
    int matrixHeight = Board::DEFAULT_HEIGHT;
    int i, j, k;
    for ( i = 0; i < matrixHeight; i++ )
        for ( j = 0; j < matrixWidth; j++ ) {
            for ( k = 0; k < SQUARE_COUNT; k++ ) {
                int newLin = i + this->yOffsetsForRotation(rotation)[k];
                int newCol = j + this->xOffsetsForRotation(rotation)[k];
                if (newLin >= 0 && newLin < matrixHeight && newCol >= 0 && newCol < matrixWidth) {
                    if (boardMatrix[newLin][newCol].getTexture() != SquareTexture::empty())
                        break;
                }
                else break;
            }
            if (k >= SQUARE_COUNT) {
                this->x = j;
                this->y = i;
                return true;
            }
        }
    return false;
}

//void Figure::paintEvent(QPaintEvent * event) noexcept {
//    QPainter painter (this);
//
//    painter.drawPixmap(2,0,this->squares[2][0].getTexture()->scaled(this->squareSize, this->squareSize));
//    for (int i = 0;i < this->height;i++)
//        painter.drawPixmap(i,1,this->squares[i][1].getTexture()->scaled(this->squareSize, this->squareSize));
//    QWidget::paintEvent( event );
//}
