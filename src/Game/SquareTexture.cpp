//
// Created by loghin on 16.04.2021.
//

#include "SquareTexture.h"

QPixmap * SquareTexture::emptySquareTexture = nullptr;
QPixmap * SquareTexture::blueSquareTexture = nullptr;
QPixmap * SquareTexture::lightblueSquareTexture = nullptr;
QPixmap * SquareTexture::redSquareTexture = nullptr;
QPixmap * SquareTexture::purpleSquareTexture = nullptr;
QPixmap * SquareTexture::yellowSquareTexture = nullptr;
QPixmap * SquareTexture::greenSquareTexture = nullptr;
QPixmap * SquareTexture::orangeSquareTexture = nullptr;
QPixmap * SquareTexture::whiteSquareTexture = nullptr;
QPixmap * SquareTexture::blackSquareTexture = nullptr;
QPixmap * SquareTexture::rainbowSquareTexture = nullptr;
QPixmap * SquareTexture::brownSquareTexture = nullptr;

SquareTexture::TextureType SquareTexture::activeTextureType = STANDARD;


void SquareTexture::switchToTexture(TextureType textureType) noexcept {
    SquareTexture::activeTextureType = textureType;
    SquareTexture::reloadFigureTextures();
}

void SquareTexture::reloadFigureTextures() noexcept {
    delete SquareTexture::emptySquareTexture;
    delete SquareTexture::blueSquareTexture;
    delete SquareTexture::lightblueSquareTexture;
    delete SquareTexture::redSquareTexture;
    delete SquareTexture::purpleSquareTexture;
    delete SquareTexture::yellowSquareTexture;
    delete SquareTexture::greenSquareTexture;
    delete SquareTexture::orangeSquareTexture;
    delete SquareTexture::whiteSquareTexture;
    delete SquareTexture::blackSquareTexture;
    delete SquareTexture::rainbowSquareTexture;
    delete SquareTexture::brownSquareTexture;

    switch (SquareTexture::activeTextureType) {
        case STANDARD:
            SquareTexture::emptySquareTexture = new QPixmap(Util::getPixmap("emptySquare.png"));
            SquareTexture::whiteSquareTexture = new QPixmap(Util::getPixmap("whiteSquare.png"));
            SquareTexture::rainbowSquareTexture = new QPixmap(Util::getPixmap("rainbowSquare.png"));
            SquareTexture::blackSquareTexture = new QPixmap(Util::getPixmap("blackSquare.png"));
            SquareTexture::brownSquareTexture = new QPixmap(Util::getPixmap("brownSquare.png"));
            SquareTexture::blueSquareTexture = new QPixmap (Util::getPixmap("blueSquare.png"));
            SquareTexture::lightblueSquareTexture = new QPixmap (Util::getPixmap("lightblueSquare.png"));
            SquareTexture::redSquareTexture = new QPixmap (Util::getPixmap("redSquare.png"));
            SquareTexture::purpleSquareTexture = new QPixmap (Util::getPixmap("purpleSquare.png"));
            SquareTexture::yellowSquareTexture = new QPixmap (Util::getPixmap("yellowSquare.png"));
            SquareTexture::greenSquareTexture = new QPixmap (Util::getPixmap("greenSquare.png"));
            SquareTexture::orangeSquareTexture = new QPixmap (Util::getPixmap("orangeSquare.png"));
            break;
        case BLACK:
            SquareTexture::emptySquareTexture = new QPixmap(Util::getPixmap("emptySquare.png"));
            SquareTexture::whiteSquareTexture = new QPixmap(Util::getPixmap("whiteSquare.png"));
            SquareTexture::rainbowSquareTexture = new QPixmap(Util::getPixmap("rainbowSquare.png"));
            SquareTexture::brownSquareTexture = new QPixmap(Util::getPixmap("brownSquare.png"));
            SquareTexture::blackSquareTexture = new QPixmap(Util::getPixmap("blackSquare.png"));
            SquareTexture::blueSquareTexture = new QPixmap (Util::getPixmap("blackSquare.png"));
            SquareTexture::lightblueSquareTexture = new QPixmap (Util::getPixmap("blackSquare.png"));
            SquareTexture::redSquareTexture = new QPixmap (Util::getPixmap("blackSquare.png"));
            SquareTexture::purpleSquareTexture = new QPixmap (Util::getPixmap("blackSquare.png"));
            SquareTexture::yellowSquareTexture = new QPixmap (Util::getPixmap("blackSquare.png"));
            SquareTexture::greenSquareTexture = new QPixmap (Util::getPixmap("blackSquare.png"));
            SquareTexture::orangeSquareTexture = new QPixmap (Util::getPixmap("blackSquare.png"));
            break;
        case WHITE:
            SquareTexture::emptySquareTexture = new QPixmap(Util::getPixmap("emptySquare.png"));
            SquareTexture::whiteSquareTexture = new QPixmap(Util::getPixmap("whiteSquare.png"));
            SquareTexture::brownSquareTexture = new QPixmap(Util::getPixmap("brownSquare.png"));
            SquareTexture::rainbowSquareTexture = new QPixmap(Util::getPixmap("rainbowSquare.png"));
            SquareTexture::blackSquareTexture = new QPixmap(Util::getPixmap("blackSquare.png"));
            SquareTexture::blueSquareTexture = new QPixmap (Util::getPixmap("whiteSquare.png"));
            SquareTexture::lightblueSquareTexture = new QPixmap (Util::getPixmap("whiteSquare.png"));
            SquareTexture::redSquareTexture = new QPixmap (Util::getPixmap("whiteSquare.png"));
            SquareTexture::purpleSquareTexture = new QPixmap (Util::getPixmap("whiteSquare.png"));
            SquareTexture::yellowSquareTexture = new QPixmap (Util::getPixmap("whiteSquare.png"));
            SquareTexture::greenSquareTexture = new QPixmap (Util::getPixmap("whiteSquare.png"));
            SquareTexture::orangeSquareTexture = new QPixmap (Util::getPixmap("whiteSquare.png"));
            break;
        case RAINBOW:
            SquareTexture::emptySquareTexture = new QPixmap(Util::getPixmap("emptySquare.png"));
            SquareTexture::whiteSquareTexture = new QPixmap(Util::getPixmap("whiteSquare.png"));
            SquareTexture::rainbowSquareTexture = new QPixmap(Util::getPixmap("rainbowSquare.png"));
            SquareTexture::brownSquareTexture = new QPixmap(Util::getPixmap("brownSquare.png"));
            SquareTexture::blackSquareTexture = new QPixmap(Util::getPixmap("blackSquare.png"));
            SquareTexture::blueSquareTexture = new QPixmap (Util::getPixmap("rainbowSquare.png"));
            SquareTexture::lightblueSquareTexture = new QPixmap (Util::getPixmap("rainbowSquare.png"));
            SquareTexture::redSquareTexture = new QPixmap (Util::getPixmap("rainbowSquare.png"));
            SquareTexture::purpleSquareTexture = new QPixmap (Util::getPixmap("rainbowSquare.png"));
            SquareTexture::yellowSquareTexture = new QPixmap (Util::getPixmap("rainbowSquare.png"));
            SquareTexture::greenSquareTexture = new QPixmap (Util::getPixmap("rainbowSquare.png"));
            SquareTexture::orangeSquareTexture = new QPixmap (Util::getPixmap("rainbowSquare.png"));
            break;
        case BROWN:
            SquareTexture::emptySquareTexture = new QPixmap(Util::getPixmap("emptySquare.png"));
            SquareTexture::whiteSquareTexture = new QPixmap(Util::getPixmap("whiteSquare.png"));
            SquareTexture::rainbowSquareTexture = new QPixmap(Util::getPixmap("rainbowSquare.png"));
            SquareTexture::brownSquareTexture = new QPixmap(Util::getPixmap("brownSquare.png"));
            SquareTexture::blackSquareTexture = new QPixmap(Util::getPixmap("blackSquare.png"));
            SquareTexture::blueSquareTexture = new QPixmap (Util::getPixmap("brownSquare.png"));
            SquareTexture::lightblueSquareTexture = new QPixmap (Util::getPixmap("brownSquare.png"));
            SquareTexture::redSquareTexture = new QPixmap (Util::getPixmap("brownSquare.png"));
            SquareTexture::purpleSquareTexture = new QPixmap (Util::getPixmap("brownSquare.png"));
            SquareTexture::yellowSquareTexture = new QPixmap (Util::getPixmap("brownSquare.png"));
            SquareTexture::greenSquareTexture = new QPixmap (Util::getPixmap("brownSquare.png"));
            SquareTexture::orangeSquareTexture = new QPixmap (Util::getPixmap("brownSquare.png"));
            break;
    }
}