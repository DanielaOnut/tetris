//
// Created by danie on 04.05.2021.
//

#ifndef PROIECT_FIGUREI_H
#define PROIECT_FIGUREI_H

#include <Figure.h>
#include <Board.h>

class FigureI : public Figure {
private:
    QPixmap * squareTexture;

    int height = 4;
    int width = 0;

    int xfigureOffsets[4] = { 0, 0, 0, 0};
    int yfigureOffsets[4] = {-1, 0, 1, 2};
public:

    void drawFigure (int x, int y, Square ** & boardMatrix) noexcept (false) override {
        int matrixWidth = Board::DEFAULT_WIDTH;
        int matrixHeight = Board::DEFAULT_HEIGHT;
        if (y > matrixHeight)
            throw std::runtime_error ("FigureI: y is out of the matrix dimensions");
        if (x > matrixWidth)
            throw std::runtime_error ("FigureI: x is out of the matrix dimensions");
        this->squareTexture = this->getSquareTexture();

        for (int i = y; this->height--; i++)
            boardMatrix[i][x].setTexture(this->squareTexture);
    }

    QPixmap * getSquareTexture () const noexcept override {
        return SquareTexture::lightblue();
    }

    int getWidth () noexcept override {
        return this->width;
    }

    int getHeight () noexcept override {
        return this->height;
    }

    const char * toString () noexcept override {
        return "FigureI";
    }

};


#endif //PROIECT_FIGUREL_H
