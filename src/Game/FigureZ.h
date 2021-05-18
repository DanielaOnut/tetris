//
// Created by danie on 04.05.2021.
//

#ifndef PROIECT_FIGUREZ_H
#define PROIECT_FIGUREZ_H

#include <Figure.h>
#include <Board.h>

class FigureZ : public Figure {
private:
    constexpr static int ROTATION_COUNT = 2;

    int xFigureOffsets[ROTATION_COUNT][4] = { {0, 1, 1, 2}, {0, 0,-1,-1} };
    int yFigureOffsets[ROTATION_COUNT][4] = { {0, 0, 1, 1}, {0, 1, 1, 2} };
public:

    QPixmap * getSquareTexture () const noexcept override {
        return SquareTexture::red();
    }

    const char * toString () noexcept override {
        return "FigureZ";
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



#endif //PROIECT_FIGUREZ_H
