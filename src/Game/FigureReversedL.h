//
// Created by danie on 04.05.2021.
//

#ifndef PROIECT_FIGUREREVERSEDL_H
#define PROIECT_FIGUREREVERSEDL_H

#include <Figure.h>
#include <Board.h>

class FigureReversedL : public Figure {
private:
    QPixmap * squareTexture {nullptr};

    int height = 3;
    int width = 1;

    int xFigureOffsets[4] = {0, -1, 0, 0};
    int yFigureOffsets[4] = {0,  0, 1, 2};
public:

    void drawFigure (int x, int y, Square ** & boardMatrix) noexcept (false) override {
        int matrixWidth = Board::DEFAULT_WIDTH;
        int matrixHeight = Board::DEFAULT_HEIGHT;
        if (y > matrixHeight - 3)
            throw std::runtime_error ("FigureReversedL: y is out of the matrix dimensions");
        if (x > matrixWidth)
            throw std::runtime_error ("FigureReversedL: x is out of the matrix dimensions");
        this->squareTexture = this->getSquareTexture();

        int i = y;
        for (i = y; this->height--; i++)
            boardMatrix[i][x].setTexture(this->squareTexture);
        boardMatrix[i-1][x-1].setTexture(this->squareTexture);
    }


    QPixmap * getSquareTexture () const noexcept override {
        return SquareTexture::blue();
    }

    int getWidth () noexcept override {
        return this->width;
    }

    int getHeight () noexcept override {
        return this->height;
    }

    const char * toString () noexcept override {
        return "FigureReversedL";
    }


    int rotationCount() const noexcept override {
        return 0;
    }

    const int * xOffsetsForRotation(int) const noexcept override {
        return nullptr;
    }

    const int * yOffsetsForRotation(int) const noexcept override {
        return nullptr;
    }
};


#endif //PROIECT_FIGUREREVERSEDL_H
