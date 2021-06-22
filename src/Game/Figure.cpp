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
    int yOffsetMax = 0;
    for (int i = 0;i < SQUARE_COUNT;i++)
        if (this->yOffsetsForRotation(this->rotation)[i] > yOffsetMax)
            yOffsetMax = this->yOffsetsForRotation(this->rotation)[i];

    int xOffsets[4];
    int yOffsets[4];

    for ( int i = 0; i < SQUARE_COUNT; i++ ) {
        xOffsets[i] = this->x + this->xOffsetsForRotation(this->rotation)[i];
        yOffsets[i] = this->y + 1 + this->yOffsetsForRotation(this->rotation)[i];

        if ( yOffsets[i] < 0 || yOffsets[i] >= Board::DEFAULT_HEIGHT )
            throw std::runtime_error("Out of Bounds");
        if (
                boardMatrix[yOffsets[i]][xOffsets[i]].getTexture() != SquareTexture::empty() &&
                ! this->contains( xOffsets[i], yOffsets[i] )
        )
            throw std::runtime_error("Collision");
    }

    this->clearDrawnFigures(boardMatrix);

    this->y++;

    for ( int i = 0; i < SQUARE_COUNT; i++ )
        boardMatrix[yOffsets[i]][xOffsets[i]].setTexture(this->getSquareTexture());
}

void Figure::moveFigureToRight (Square **&boardMatrix) noexcept(false) {
    int matrixWidth = Board::DEFAULT_WIDTH;
    int xOffsetRightMost = 0;
    for ( int i = 0; i < SQUARE_COUNT; i++ )
        if ( xOffsetRightMost < this->xOffsetsForRotation(this->rotation)[i] )
            xOffsetRightMost = this->xOffsetsForRotation(this->rotation)[i];
    if (this->x + xOffsetRightMost + 1 < matrixWidth) {
        int xCoordinates[4], yCoordinates[4];
        for (int i = 0;i < SQUARE_COUNT;i++) {
            xCoordinates[i] = this->x + this->xOffsetsForRotation(this->rotation)[i];
            yCoordinates[i] = this->y + this->yOffsetsForRotation(this->rotation)[i];
        }
        for (int i = 0;i < SQUARE_COUNT;i++) {
            int newY = this->y + this->yOffsetsForRotation(this->rotation)[i];
            int newX = this->x + 1 + this->xOffsetsForRotation(this->rotation)[i];
            bool validPair = true;
            for (int j = 0; j < 4 && validPair; j++)
                if (newX == xCoordinates[j] && newY == yCoordinates[j])
                    validPair = false;
            if (validPair) {
                if (boardMatrix[newY][newX].getTexture() != SquareTexture::empty())
                    throw std::runtime_error("figure can't be moved to right anymore");
            }
        }
        this->clearDrawnFigures(boardMatrix);
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
    int xOffsetLeftMost = 0;
    for ( int i = 0; i < SQUARE_COUNT; i++ )
        if ( xOffsetLeftMost > this->xOffsetsForRotation(this->rotation)[i] )
            xOffsetLeftMost = this->xOffsetsForRotation(this->rotation)[i];
    if (this->x + xOffsetLeftMost > 0) {
        int xCoordinates[4], yCoordinates[4];
        for (int i = 0;i < SQUARE_COUNT;i++) {
            xCoordinates[i] = this->x + this->xOffsetsForRotation(this->rotation)[i];
            yCoordinates[i] = this->y + this->yOffsetsForRotation(this->rotation)[i];
        }
        for (int i = 0;i < SQUARE_COUNT;i++) {
            int newY = this->y + this->yOffsetsForRotation(this->rotation)[i];
            int newX = this->x - 1 + this->xOffsetsForRotation(this->rotation)[i];
            bool validPair = true;
            for (int j = 0; j < 4 && validPair; j++)
                if (newX == xCoordinates[j] && newY == yCoordinates[j])
                    validPair = false;
            if (validPair) {
                if (boardMatrix[newY][newX].getTexture() != SquareTexture::empty())
                    throw std::runtime_error("figure can't be moved to left anymore");
            }
        }
        this->clearDrawnFigures(boardMatrix);
        this->x--;
        for (int i = 0; i < SQUARE_COUNT; i++) {
            boardMatrix[this->y + this->yOffsetsForRotation(this->rotation)[i]][this->x + this->xOffsetsForRotation(this->rotation)[i]]
                    .setTexture(this->getSquareTexture());
        }
    }
    else
        throw std::runtime_error ("figure can't be moved to left anymore");
}

static int oldRotation = 0;
bool Figure::findCoordinatesToRotateAt(Square **& boardMatrix) noexcept {
    int xOffsetLeftMost = 0;
    for ( int i = 0; i < SQUARE_COUNT; i++ )
        if ( xOffsetLeftMost > this->xOffsetsForRotation(this->rotation)[i] )
            xOffsetLeftMost = this->xOffsetsForRotation(this->rotation)[i];
    int xOffsetRightMost = 0;
    for ( int i = 0; i < SQUARE_COUNT; i++ )
        if ( xOffsetRightMost < this->xOffsetsForRotation(this->rotation)[i] )
            xOffsetRightMost = this->xOffsetsForRotation(this->rotation)[i];
    int yOffsetMax = 0;
    for (int i = 0;i < SQUARE_COUNT;i++)
        if (this->yOffsetsForRotation(this->rotation)[i] > yOffsetMax)
            yOffsetMax = this->yOffsetsForRotation(this->rotation)[i];
    int yOffsetMin = 9;
    for (int i = 0;i < SQUARE_COUNT;i++)
        if (this->yOffsetsForRotation(this->rotation)[i] < yOffsetMin)
            yOffsetMin = this->yOffsetsForRotation(this->rotation)[i];
    bool moveLeft = this->movingFigureToLeftPossible(oldRotation, boardMatrix);
    bool moveRight = this->movingFigureToRightPossible(oldRotation, boardMatrix);
    if (! moveLeft && ! moveRight)
        return false;
    if (! moveLeft && this->x + xOffsetRightMost >= Board::DEFAULT_WIDTH)
        return false;
    if (! moveRight && this->x + xOffsetLeftMost < 0)
        return false;
    while (this->y + yOffsetMax >= Board::DEFAULT_HEIGHT)
        this->y--;
    while (this->x + xOffsetLeftMost < 0)
        this->x++;
    while (this->x + xOffsetRightMost >= Board::DEFAULT_WIDTH)
        this->x--;
    int line,col,ok = 1,finalLin = this->y, finalCol = this->x;
    for (int i = 0;i < SQUARE_COUNT && ok;i++) {
        line = this->y + this->yOffsetsForRotation(this->rotation)[i];
        col = this->x + this->xOffsetsForRotation(this->rotation)[i];
        if (boardMatrix[line][col].getTexture() != SquareTexture::empty())
            ok = 0;
    }
    if (! ok) {
        bool placed = false;
        int newCol = this->x;
        while (!placed && newCol + xOffsetLeftMost > 0 && moveLeft) {
            newCol--;
            int i;
            for (i = 0; i < SQUARE_COUNT; ++i) {
                line = this->y + this->yOffsetsForRotation(this->rotation)[i];
                col = newCol + this->xOffsetsForRotation(this->rotation)[i];
                if (!this->contains(col, line) && boardMatrix[line][col].getTexture() != SquareTexture::empty()) {
                    break;
                }
            }
            if (i < SQUARE_COUNT) {
                break;
            } else if (!this->squaresHaveCollision(newCol, this->y, boardMatrix)) {
                std::cout << "Moving left....\n";
                placed = true;
                finalCol = newCol;
            }
        }
        while (! placed && newCol + xOffsetRightMost + 1 < Board::DEFAULT_WIDTH && moveRight) {
            newCol++;
            int i;
            for (i = 0; i < SQUARE_COUNT; ++i) {
                line = this->y + this->yOffsetsForRotation(this->rotation)[i];
                col = newCol + this->xOffsetsForRotation(this->rotation)[i];
                if (! this->contains(col, line) && boardMatrix[line][col].getTexture() != SquareTexture::empty()) {
                    break;
                }
            }
            if (i < SQUARE_COUNT) {
                break;
            }
            else if (! this->squaresHaveCollision(newCol,this->y,boardMatrix)) {
                std::cout << "Moving right....\n";
                placed = true;
                finalCol = newCol;
            }
        }
        int newLine = this->y;
        while (! placed && newLine + yOffsetMin > 0) {
            newLine--;
            int i;
            for (i = 0; i < SQUARE_COUNT; ++i) {
                line = newLine + this->yOffsetsForRotation(this->rotation)[i];
                col = this->x + this->xOffsetsForRotation(this->rotation)[i];
                if (! this->contains(col, line) && boardMatrix[line][col].getTexture() != SquareTexture::empty()) {
                    break;
                }
            }
            if (i < SQUARE_COUNT) {
                break;
            }
            else if (! this->squaresHaveCollision(this->x,newLine,boardMatrix)) {
                std::cout << "Moving up....\n";
                placed = true;
                finalLin = newLine;
            }
        }
    }
    else
        return true;
    if (! this->squaresHaveCollision(finalCol,finalLin,boardMatrix)) {
        this->x = finalCol;
        this->y = finalLin;
        return true;
    }
    else
        return false;
}

void Figure::rotateFigure(Square **& boardMatrix) noexcept (false) {
    oldRotation = this->rotation;
    this->rotation++;
    if (this->rotation >= this->rotationCount()) {
        this->rotation = 0;
    }
    if (! this->findCoordinatesToRotateAt(boardMatrix)) {
        this->rotation = oldRotation;
        throw std::runtime_error("Couldn't rotate");
    }
    auto sqTexture = this->getSquareTexture();
    for (int i = 0; i < SQUARE_COUNT; i++) {
        boardMatrix[this->y + this->yOffsetsForRotation(this->rotation)[i]][this->x + this->xOffsetsForRotation(
                this->rotation)[i]]
                .setTexture(sqTexture);
    }
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

//                cout << std::fixed << std::setprecision(9) << std::setw(9) << diff.count() << '\n';
                return true;
            }
        }
    return false;
}

#include <FigureI.h>
#include <FigureL.h>
#include <FigureT.h>
#include <FigureZ.h>
#include <FigureSquare.h>
#include <FigureReversedL.h>
#include <FigureReversedZ.h>

#include <ctime>

static bool isRunning = false;
static void startRandom () noexcept { // nu poate fi gasita cu extern
    if ( isRunning ) return;

    srand( time ( nullptr ) );
    isRunning = true;
}

Figure * Figure::Factory::spawn() const noexcept {
    Figure * newFigure;
    startRandom();

    int type = this->figureType;
    if ( this->figureType == 0 ) {
        type = rand() % 7 + 1;
    }

    switch ( type ) {
        case 1: newFigure = new FigureI(); break;
        case 2: newFigure = new FigureT(); break;
        case 3: newFigure = new FigureZ(); break;
        case 4: newFigure = new FigureReversedZ(); break;
        case 5: newFigure = new FigureL(); break;
        case 6: newFigure = new FigureReversedL(); break;
        case 7:
        default:
            newFigure = new FigureSquare(); break;
    }

    newFigure->x = this->x;
    newFigure->y = this->y;

    return newFigure;
}
