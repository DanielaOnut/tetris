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
    int x, y;
public:
    constexpr static int SQUARE_COUNT = 4;
//    explicit Figure (QWidget * parent) noexcept : QWidget(parent) { }

    /**
     *
     * @param boardMatrix
     * @return true if shape spawned | false if shape could not find space to spawn at
     *
     */
    virtual bool findCoordinatesToSpawnAt (Square ** & boardMatrix, int rotation) noexcept;

    /// for later
    /// virtual std::list < std::pair < int, int > > findCoordinatesToSpawnAt (Square ** & boardMatrix ) noexcept = 0;

    virtual void drawFigure (Square ** & boardMatrix, int rotation) noexcept;
    virtual QPixmap * getSquareTexture () const noexcept = 0;
    virtual const char * toString () noexcept = 0;
    virtual int rotationCount () const noexcept = 0;
    virtual int const * xOffsetsForRotation (int) const noexcept = 0;
    virtual int const * yOffsetsForRotation (int) const noexcept = 0;

    int getX () noexcept {
        return this->x;
    }
    int getY () noexcept {
        return this->y;
    }

    ~Figure () noexcept override = default;
};

#endif //PROIECT_FIGURE_H
