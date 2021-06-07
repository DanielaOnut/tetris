//
// Created by danie on 20.04.2021.
//

#include "Figure.h"
#include <Board.h>
#include <QPainter>
#include <iostream>

void Figure::drawFigure (Square **&boardMatrix) noexcept {
    if (this->findCoordinatesToSpawnAt(boardMatrix)) {
        auto sqTexture = this->getSquareTexture();
        for (int i = 0; i < SQUARE_COUNT; i++)
            boardMatrix[this->y + this->yOffsetsForRotation(this->rotation)[i]][this->x + this->xOffsetsForRotation(this->rotation)[i]]
                    .setTexture(sqTexture);
    }
    else {
        std::cout << "GAME OVER";
        exit(0);
    }
}

void Figure::clearDrawnFigures (Square ** & boardMatrix) const noexcept {
    for (int i = 0;i < SQUARE_COUNT;i++)
        boardMatrix[this->y + this->yOffsetsForRotation(this->rotation)[i]][this->x + this->xOffsetsForRotation(this->rotation)[i]]
                .setTexture(SquareTexture::empty());
}

void Figure::dropFigure (Square ** & boardMatrix) noexcept (false) {
    int matrixHeight = Board::DEFAULT_HEIGHT;
    if (this->x == -1 && this->y == -1) {
        this->drawFigure(boardMatrix);
        return;
    }
    if (boardMatrix[this->y + 1][this->x].getTexture() == SquareTexture::empty() && (matrixHeight - this->y > 1)) {
//        std::cout << this->y << '\n';
        this->y++;
        for (int i = 0; i < SQUARE_COUNT; i++) {
            boardMatrix[this->y + this->yOffsetsForRotation(this->rotation)[i]][this->x + this->xOffsetsForRotation(this->rotation)[i]]
                    .setTexture(this->getSquareTexture());
        }
    }
    else
        throw std::runtime_error ("figure can't be dropped anymore");
}

void Figure::moveFigureToRight (Square **&boardMatrix) noexcept(false) {
    int matrixWidth = Board::DEFAULT_WIDTH;
    if (boardMatrix[this->y][this->x + 1].getTexture() == SquareTexture::empty() && (matrixWidth - this->x > 1)) {
        this->x++;
        for (int i = 0; i < SQUARE_COUNT; i++) {
            boardMatrix[this->y + this->yOffsetsForRotation(this->rotation)[i]][this->x + this->xOffsetsForRotation(this->rotation)[i]]
                    .setTexture(this->getSquareTexture());
        }
    }
    else
        throw std::runtime_error ("figure can't be moved to right anymore");
}

void Figure::moveFigureToLeft (Square **&boardMatrix) noexcept(false) {
    /// cel mai stanga patrat
    /// mergi print toate offset-urile

    // same for other movements
    int xOffsetLeftMost = 0;
    for ( int i = 0; i < this->rotationCount(); i++ )
        if ( xOffsetLeftMost > this->xOffsetsForRotation(this->rotation)[i] )
            xOffsetLeftMost = this->xOffsetsForRotation(this->rotation)[i];

    if (boardMatrix[this->y][this->x - 1].getTexture() == SquareTexture::empty() && this->x + xOffsetLeftMost > 0) {
        this->x--;
        for (int i = 0; i < SQUARE_COUNT; i++) {
            boardMatrix[this->y + this->yOffsetsForRotation(this->rotation)[i]][this->x + this->xOffsetsForRotation(this->rotation)[i]]
                    .setTexture(this->getSquareTexture());
        }
    }
    else
        throw std::runtime_error ("figure can't be moved to left anymore");
}
#include <chrono>
#include <cmath>
#include <iomanip>
using namespace std;
bool Figure::findCoordinatesToSpawnAt(Square ** & boardMatrix) noexcept {
    auto start = chrono::high_resolution_clock::now();

    int matrixWidth = Board::DEFAULT_WIDTH;
    int matrixHeight = Board::DEFAULT_HEIGHT;
    int i, j, k;
    for ( i = 0; i < matrixHeight; i++ )
        for ( j = 0; j < matrixWidth; j++ ) {
            for ( k = 0; k < SQUARE_COUNT; k++ ) {
                int newLin = i + this->yOffsetsForRotation(this->rotation)[k];
                int newCol = j + this->xOffsetsForRotation(this->rotation)[k];
                if (newLin >= 0 && newLin < matrixHeight && newCol >= 0 && newCol < matrixWidth) {
                    if (boardMatrix[newLin][newCol].getTexture() != SquareTexture::empty())
                        break;
                }
                else break;
            }
            if (k >= SQUARE_COUNT) {
                this->x = j;
                this->y = i;

                auto end = chrono::high_resolution_clock::now();

                std::chrono::duration < double >  diff = end - start;

                cout << std::fixed << std::setprecision(9) << std::setw(9) << diff.count() << '\n';
//                auto diff = (end-start).count();
//                cout << (diff / pow(10, 9)) << '\n';

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
