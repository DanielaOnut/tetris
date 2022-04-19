//
// Created on 16.04.2021.
//

#ifndef TETRIS_SQUARE_H
#define TETRIS_SQUARE_H

#include <SquareTexture.h>

class Square {
private:
    QPixmap * texture {nullptr};

public:
    Square () noexcept = default;

    void setTexture ( QPixmap * tex ) noexcept {
        this->texture = tex;
    }

    QPixmap * getTexture () noexcept {
        return this->texture;
    }
};


#endif //TETRIS_SQUARE_H
