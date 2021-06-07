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
//    explicit Figure (QWidget * parent) noexcept : QWidget(parent) { }

    /// for later
    /// virtual std::list < std::pair < int, int > > findCoordinatesToSpawnAt (Square ** & boardMatrix ) noexcept = 0;

    virtual bool findCoordinatesToSpawnAt (Square ** & boardMatrix) noexcept;
    virtual void dropFigure (Square ** & boardMatrix) noexcept (false);
    virtual void drawFigure (Square ** & boardMatrix) noexcept;
    void clearDrawnFigures(Square ** & boardMatrix) const noexcept;
    void moveFigureToRight (Square ** & boardMatrix) noexcept (false);
    void moveFigureToLeft (Square ** & boardMatrix) noexcept (false);
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

    ~Figure () noexcept override = default;
};

#endif //PROIECT_FIGURE_H
