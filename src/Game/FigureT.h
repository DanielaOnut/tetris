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

    int height = 0;
    int width = 0;
public:

    void drawFigure (int x, int y, Square ** & boardMatrix) noexcept override {
        int matrixWidth = Board::DEFAULT_WIDTH;
        int matrixHeight = Board::DEFAULT_HEIGHT;
        if (x > matrixHeight - 2 && y > matrixWidth - 3)
            throw std::runtime_error ("coordinates out of the matrix dimensions");
        this->squareTexture = this->getSquareTexture();
        this->setHeight(2);
        this->setWidth(3);

        boardMatrix[x-1][y+1].setTexture(this->squareTexture);
        for (int j = y; this->width--; j++)
            boardMatrix[x][j].setTexture(this->squareTexture);
    }

    QPixmap * getSquareTexture () const noexcept override {
        return SquareTexture::purple();
    }

    void setWidth (const int width) noexcept override {
        this->width = width;
    }

    void setHeight (const int height) noexcept override {
        this->height = height;
    }

};


#endif //PROIECT_FIGURET_H
