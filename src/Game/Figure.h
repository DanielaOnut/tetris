//
// Created by danie on 20.04.2021.
//

#ifndef PROIECT_FIGURE_H
#define PROIECT_FIGURE_H

#include <QPixmap>
#include <QWidget>
#include <QPaintEvent>
#include <Square.h>
#include <SquareTexture.h>
#include <Util.h>
//#include <Board.h>
#include <Figure.h>
#include <string>

class Figure : public QWidget {
    Q_OBJECT
protected:
    int x = -1;
    int y = -1;
    int rotation = 0;
public:
    constexpr static int SQUARE_COUNT = 4;

    class Factory;

//    explicit Figure (QWidget * parent) noexcept : QWidget(parent) { }

    /// for later
    /// virtual std::list < std::pair < int, int > > findCoordinatesToSpawnAt (Square ** & boardMatrix ) noexcept = 0;

    virtual bool findCoordinatesToSpawnAt (Square ** & boardMatrix) noexcept;
    virtual void findCoordinatesToRotateAt (Square ** & boardMatrix) noexcept;
    virtual void dropFigure (Square ** & boardMatrix) noexcept (false);
    virtual void drawFigure (Square ** & boardMatrix) noexcept;
    void clearDrawnFigures(Square ** & boardMatrix) const noexcept;
    void moveFigureToRight (Square ** & boardMatrix) noexcept (false);
    void moveFigureToLeft (Square ** & boardMatrix) noexcept (false);
    void rotateFigure (Square ** & boardMatrix) noexcept (false);
    virtual QPixmap * getSquareTexture () const noexcept = 0;
    virtual const char * toString () noexcept = 0;
    virtual int rotationCount () const noexcept = 0;
    virtual int const * xOffsetsForRotation (int) const noexcept = 0;
    virtual int const * yOffsetsForRotation (int) const noexcept = 0;

    const int getX () noexcept {
        return this->x;
    }
    const int getY () noexcept {
        return this->y;
    }

    bool contains ( int x, int y ) const noexcept {
        for ( int i = 0; i < SQUARE_COUNT; i++ )
            if (
                    this->x + this->xOffsetsForRotation(this->rotation)[i] == x &&
                    this->y + this->yOffsetsForRotation(this->rotation)[i] == y
            )
                return true;

        return false;
    }

    ~Figure () noexcept override = default;
};

class Figure::Factory {
    /// Factory().at(1, 2).random().spawn();
    /// Factory().L().spawn();
    /// Factory().random().at(1, 3).spawn();
    /// Factory().spawn(); <- spawn random

    /// invocarea    parametrii    comanda
    /// fabricii

    int x = -1, y = -1;
    int figureType = 0; /// 0 = random, 1 - 7 figure

public:
    Factory() noexcept = default;

    Figure * spawn () const noexcept;

    Factory & at (int x, int y) noexcept {this->x = x; this->y = y; return * this;}
    Factory & random () noexcept { this->figureType = 0; return * this; }
    Factory & I () noexcept { this->figureType = 1; return * this; }
    Factory & T () noexcept  { this->figureType = 2; return * this; }
    Factory & Z () noexcept { this->figureType = 3; return * this; }
    Factory & reverseZ () noexcept { this->figureType = 4; return * this; }
    Factory & L () noexcept { this->figureType = 5; return * this; }
    Factory & reverseL () noexcept { this->figureType = 6; return * this; }
    Factory & square () noexcept { this->figureType = 7; return * this; }
};

#endif //PROIECT_FIGURE_H
