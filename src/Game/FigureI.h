//
// Created by danie on 04.05.2021.
//

#ifndef PROIECT_FIGUREI_H
#define PROIECT_FIGUREI_H

#include <Figure.h>
#include <Board.h>

class FigureI : public Figure {
private:
    constexpr static int ROTATION_COUNT = 2;

    int xFigureOffsets [ROTATION_COUNT][4] = { {0, 0, 0, 0}, {-1, 0, 1, 2} };
    int yFigureOffsets [ROTATION_COUNT][4] = { {-1, 0, 1, 2}, {0, 0, 0, 0} };
public:

    QPixmap * getSquareTexture () const noexcept override {
        return SquareTexture::lightblue();
    }

    const char * toString () noexcept override {
        return "FigureI";
    }

    int rotationCount () const noexcept override {
        return ROTATION_COUNT;
    }

    const int * xOffsetsForRotation(int rotationIndex) const noexcept override {
        return reinterpret_cast < int const * > (this->xFigureOffsets[rotationIndex]);
    }

    const int * yOffsetsForRotation(int rotationIndex) const noexcept override {
//        return & this->yFigureOffsets[rotationIndex][0];

        /**
         * static - converteste tu - verif compilator
         * dynamic - e mostenita, verifica - verif compilator, om
         * reinterpret - stiu eu mai bine - verif om - castare C
         */
        return reinterpret_cast < int const * > (this->yFigureOffsets[rotationIndex]);
    }

    ~FigureI() noexcept override = default;
};


#endif //PROIECT_FIGUREL_H
