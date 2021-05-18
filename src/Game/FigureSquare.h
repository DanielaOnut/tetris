//
// Created by danie on 04.05.2021.
//

#ifndef PROIECT_FIGURESQUARE_H
#define PROIECT_FIGURESQUARE_H

#include <Figure.h>
#include <Board.h>

class FigureSquare : public Figure {
private:
    constexpr static int ROTATION_COUNT = 1;

    int xFigureOffsets[ROTATION_COUNT][4] = { {0, 1, 0, 1} };
    int yFigureOffsets[ROTATION_COUNT][4] = { {0, 0, 1, 1} };
public:

    QPixmap * getSquareTexture () const noexcept override {
        return SquareTexture::yellow();
    }

    const char * toString () noexcept override {
        return "FigureSquare";
    }

    int rotationCount() const noexcept override {
        return 0;
    }

    const int * xOffsetsForRotation(int rotationIndex) const noexcept override {
        return reinterpret_cast < int const * > (this->xFigureOffsets[rotationIndex]);
    }

    const int * yOffsetsForRotation(int rotationIndex) const noexcept override {
        return reinterpret_cast < int const * > (this->yFigureOffsets[rotationIndex]);
    }

};


#endif //PROIECT_FIGUREL_H
