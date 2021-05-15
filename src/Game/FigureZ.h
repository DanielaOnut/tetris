//
// Created by danie on 04.05.2021.
//

#ifndef PROIECT_FIGUREZ_H
#define PROIECT_FIGUREZ_H

#include <Figure.h>
#include <Board.h>

class FigureZ : public Figure {
private:
    QPixmap * squareTexture {nullptr};

    int height = 2;
    int width = 2;

    int xfigureOffsets[4] = {0, -1,  0,  1};
    int yfigureOffsets[4] = {0,  0, -1, -1};
public:

    void drawFigure (int x, int y, Square ** & boardMatrix) noexcept (false) override {
        int matrixWidth = Board::DEFAULT_WIDTH;
        int matrixHeight = Board::DEFAULT_HEIGHT;
        if (y > matrixHeight - 2)
            throw std::runtime_error ("FigureZ: y is out of the matrix dimensions");
        if (x > matrixWidth - 2)
            throw std::runtime_error ("FigureZ: x is out of the matrix dimensions");
        this->squareTexture = this->getSquareTexture();

        boardMatrix[y][x].setTexture(this->squareTexture);
        boardMatrix[y][x+1].setTexture(this->squareTexture);
        boardMatrix[y+1][x+1].setTexture(this->squareTexture);
        boardMatrix[y+1][x+2].setTexture(this->squareTexture);
    }


    QPixmap * getSquareTexture () const noexcept override {
        return SquareTexture::red();
    }

    int getWidth () noexcept override {
        return this->width;
    }

    int getHeight () noexcept override {
        return this->height;
    }

    const char * toString () noexcept override {
        return "FigureZ";
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



#endif //PROIECT_FIGUREZ_H
