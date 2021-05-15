//
// Created by danie on 04.05.2021.
//

#ifndef PROIECT_FIGUREL_H
#define PROIECT_FIGUREL_H

#include <Figure.h>
#include <Board.h>

class FigureL : public Figure {
private:
    QPixmap * squareTexture {nullptr};

    int height = 3;
    int width = 1;

    int xfigureOffsets[4] = {0, 1, 0, 0};
    int yfigureOffsets[4] = {0, 0, 1, 2};
public:

    void drawFigure (int x, int y, Square ** & boardMatrix) noexcept (false) override {
        int matrixWidth = Board::DEFAULT_WIDTH;
        int matrixHeight = Board::DEFAULT_HEIGHT;
        if (y > matrixHeight - 3)
            throw std::runtime_error ("FigureL: y is out of the matrix dimensions");
        if (x > matrixWidth - 1)
            throw std::runtime_error ("FigureL: x is out of the matrix dimensions");
        this->squareTexture = this->getSquareTexture();

        int i = y;
        for (i = y; this->height--; i++)
            boardMatrix[i][x].setTexture(this->squareTexture);
        boardMatrix[i-1][x+1].setTexture(this->squareTexture);
    }


    QPixmap * getSquareTexture () const noexcept override {
        return SquareTexture::orange();
    }

    int getWidth () noexcept override {
        return this->width;
    }

    int getHeight () noexcept override {
        return this->height;
    }

    const char * toString () noexcept override {
        return "FigureL";
    }

};


#endif //PROIECT_FIGUREL_H
