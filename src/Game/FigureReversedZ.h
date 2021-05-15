//
// Created by danie on 04.05.2021.
//

#ifndef PROIECT_FIGUREREVERSEDZ_H
#define PROIECT_FIGUREREVERSEDZ_H

#include <Figure.h>
#include <Board.h>

class FigureReversedZ : public Figure {
private:
    QPixmap * squareTexture {nullptr};

    int height = 2;
    int width = 2;

    int xfigureOffsets[4] = {0, 1,  0,  1};
    int yfigureOffsets[4] = {0, 0, -1, -1};
public:

    void drawFigure (int x, int y, Square ** & boardMatrix) noexcept (false) override {
        int matrixWidth = Board::DEFAULT_WIDTH;
        int matrixHeight = Board::DEFAULT_HEIGHT;
        if (y > matrixHeight - 2)
            throw std::runtime_error ("FigureReversedZ: y is out of the matrix dimensions");
        if (x > matrixWidth - 2)
            throw std::runtime_error ("FigureReversedZ: x is out of the matrix dimensions");
        this->squareTexture = this->getSquareTexture();

        boardMatrix[y][x].setTexture(this->squareTexture);
        boardMatrix[y][x+1].setTexture(this->squareTexture);
        boardMatrix[y-1][x+1].setTexture(this->squareTexture);
        boardMatrix[y-1][x+2].setTexture(this->squareTexture);
    }

    QPixmap * getSquareTexture () const noexcept override {
        return SquareTexture::green();
    }

    int getWidth () noexcept override {
        return this->width;
    }

    int getHeight () noexcept override {
        return this->height;
    }

    const char * toString () noexcept override {
        return "FigureReversedZ";
    }

};



#endif //PROIECT_FIGUREREVERSEDZ_H
