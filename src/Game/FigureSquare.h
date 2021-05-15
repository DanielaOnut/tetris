//
// Created by danie on 04.05.2021.
//

#ifndef PROIECT_FIGURESQUARE_H
#define PROIECT_FIGURESQUARE_H

#include <Figure.h>
#include <Board.h>

class FigureSquare : public Figure {
private:
    QPixmap * squareTexture;

    int height = 2;
    int width = 2;

    int xfigureOffsets[4] = {0, 1,  0,  1};
    int yfigureOffsets[4] = {0, 0, -1, -1};
public:

    void drawFigure (int x, int y, Square ** & boardMatrix) noexcept (false) override {
        int matrixWidth = Board::DEFAULT_WIDTH;
        int matrixHeight = Board::DEFAULT_HEIGHT;
        if (y > matrixHeight - 2)
            throw std::runtime_error ("FigureSquare: y is out of the matrix dimensions");
        if (x > matrixWidth - 2)
            throw std::runtime_error ("FigureSquare: x is out of the matrix dimensions");
        this->squareTexture = this->getSquareTexture();

        for (int i = y; this->height--; i++) {
            boardMatrix[i][x].setTexture(this->squareTexture);
            boardMatrix[i][x + 1].setTexture(this->squareTexture);
        }
    }

    QPixmap * getSquareTexture () const noexcept override {
        return SquareTexture::yellow();
    }

    int getWidth () noexcept override {
        return this->width;
    }

    int getHeight () noexcept override {
        return this->height;
    }

    const char * toString () noexcept override {
        return "FigureSquare";
    }

};


#endif //PROIECT_FIGUREL_H
