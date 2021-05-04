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

    int height = 0;
    int width = 0;
public:

    void drawFigure (int x, int y, Square ** & boardMatrix) noexcept override {
        int matrixWidth = Board::DEFAULT_WIDTH;
        int matrixHeight = Board::DEFAULT_HEIGHT;
        if (x > matrixHeight && y > matrixWidth)
            throw std::runtime_error ("coordinates out of the matrix dimensions");
        this->squareTexture = this->getSquareTexture();
        this->setHeight(4);

        for (int i = x; this->height--; i++)
            boardMatrix[i][y].setTexture(this->squareTexture);
    }

    QPixmap * getSquareTexture () const noexcept override {
        return SquareTexture::lightblue();
    }

    void setWidth (const int width) noexcept override {
        this->width = width;
    }

    void setHeight (const int height) noexcept override {
        this->height = height;
    }

};


#endif //PROIECT_FIGUREL_H
