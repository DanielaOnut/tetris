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
    static QPixmap * blueSquareTexture;
    static QPixmap * lightblueSquareTexture;
    static QPixmap * redSquareTexture;
    static QPixmap * purpleSquareTexture;
    static QPixmap * yellowSquareTexture;
    static QPixmap * greenSquareTexture;
    static QPixmap * orangeSquareTexture;

public:

    static QPixmap * empty () noexcept {
        if ( SquareTexture::emptySquareTexture == nullptr )
            SquareTexture::emptySquareTexture = new QPixmap(Util::getPixmap("emptySquare.png"));

        return SquareTexture::emptySquareTexture;
    }

    static QPixmap * blue () noexcept {
        if (SquareTexture::blueSquareTexture == nullptr)
            SquareTexture::blueSquareTexture = new QPixmap (Util::getPixmap("blueSquare.png"));
        return SquareTexture::blueSquareTexture;
    }

    static QPixmap * lightblue () noexcept {
        if (SquareTexture::lightblueSquareTexture == nullptr)
            SquareTexture::lightblueSquareTexture = new QPixmap (Util::getPixmap("lightblueSquare.png"));
        return SquareTexture::lightblueSquareTexture;
    }

    static QPixmap * red () noexcept {
        if (SquareTexture::redSquareTexture == nullptr)
            SquareTexture::redSquareTexture = new QPixmap (Util::getPixmap("redSquare.png"));
        return SquareTexture::redSquareTexture;
    }

    static QPixmap * purple () noexcept {
        if (SquareTexture::purpleSquareTexture == nullptr)
            SquareTexture::purpleSquareTexture = new QPixmap (Util::getPixmap("purpleSquare.png"));
        return SquareTexture::purpleSquareTexture;
    }

    static QPixmap * yellow () noexcept {
        if (SquareTexture::yellowSquareTexture == nullptr)
            SquareTexture::yellowSquareTexture = new QPixmap (Util::getPixmap("yellowSquare.png"));
        return SquareTexture::yellowSquareTexture;
    }

    static QPixmap * green () noexcept {
        if (SquareTexture::greenSquareTexture == nullptr)
            SquareTexture::greenSquareTexture = new QPixmap (Util::getPixmap("greenSquare.png"));
        return SquareTexture::greenSquareTexture;
    }

    static QPixmap * orange () noexcept {
        if (SquareTexture::orangeSquareTexture == nullptr)
            SquareTexture::orangeSquareTexture = new QPixmap (Util::getPixmap("orangeSquare.png"));
        return SquareTexture::orangeSquareTexture;
    }

};


#endif //TETRIS_SQUARETEXTURE_H
