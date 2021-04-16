//
// Created by loghin on 16.04.2021.
//

#ifndef TETRIS_SQUARETEXTURE_H
#define TETRIS_SQUARETEXTURE_H

#include <QPixmap>
#include <Util.h>

class SquareTexture {
private:
    static QPixmap * emptySquareTexture;

public:

    static QPixmap * empty () noexcept {
        if ( SquareTexture::emptySquareTexture == nullptr )
            SquareTexture::emptySquareTexture = new QPixmap(Util::getPixmap("emptySquare.png"));

        return SquareTexture::emptySquareTexture;
    }
};


#endif //TETRIS_SQUARETEXTURE_H
