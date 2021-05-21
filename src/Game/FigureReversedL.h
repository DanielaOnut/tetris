//
// Created by danie on 04.05.2021.
//

#ifndef PROIECT_FIGUREREVERSEDL_H
#define PROIECT_FIGUREREVERSEDL_H

#include <Figure.h>
#include <Board.h>

class FigureReversedL : public Figure {
private:
    constexpr static int ROTATION_COUNT = 4;

    int xFigureOffsets[ROTATION_COUNT][4] = { {0,-1, 0, 0}, {0, 0, 1, 2}, {0, 1, 0, 0}, {0, 0,-1,-2} };
    int yFigureOffsets[ROTATION_COUNT][4] = { {0, 0,-1,-2}, {0,-1, 0, 0}, {0, 0, 1, 2}, {0, 1, 0, 0} };
public:
    QPixmap * getSquareTexture () const noexcept override {
        return SquareTexture::blue();
    }

    const char * toString () noexcept override {
        return "FigureReversedL";
    }


    int rotationCount() const noexcept override {
        return ROTATION_COUNT;
    }

    const int * xOffsetsForRotation(int rotationIndex) const noexcept override {
        return reinterpret_cast < int const * > (this->xFigureOffsets[rotationIndex]);
    }

    const int * yOffsetsForRotation(int rotationIndex) const noexcept override {
        return reinterpret_cast < int const * > (this->yFigureOffsets[rotationIndex]);
    }
};


#endif //PROIECT_FIGUREREVERSEDL_H
