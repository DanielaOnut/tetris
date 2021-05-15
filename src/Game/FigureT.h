//
// Created by danie on 04.05.2021.
//

#ifndef PROIECT_FIGURET_H
#define PROIECT_FIGURET_H

#include <Figure.h>
#include <Board.h>

class FigureT : public Figure {
private:
    QPixmap * squareTexture;

    int height = 2;
    int width = 3;

    int xfigureOffsets[4] = {0, 0, -1, 1};
    int yfigureOffsets[4] = {0, 1,  0, 0};
public:

    void drawFigure (int x, int y, Square ** & boardMatrix) noexcept (false) override {
        int matrixWidth = Board::DEFAULT_WIDTH;
        int matrixHeight = Board::DEFAULT_HEIGHT;
        if (y > matrixHeight - 1)
            throw std::runtime_error ("FigureT: y is out of the matrix dimensions");
        if (x > matrixWidth - 3)
            throw std::runtime_error ("FigureT: x is out of the matrix dimensions");
        this->squareTexture = this->getSquareTexture();

        boardMatrix[y-1][x+1].setTexture(this->squareTexture);
        for (int j = x; this->width--; j++)
            boardMatrix[y][j].setTexture(this->squareTexture);
    }

    QPixmap * getSquareTexture () const noexcept override {
        return SquareTexture::purple();
    }

    int getWidth () noexcept override {
        return this->width;
    }

    int getHeight () noexcept override {
        return this->height;
    }

    const char * toString () noexcept override {
        return "FigureT";
    }

};


#endif //PROIECT_FIGURET_H
