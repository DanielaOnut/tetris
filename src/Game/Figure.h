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

class Figure : public QWidget {
    Q_OBJECT
public:
//    explicit Figure (QWidget * parent) noexcept : QWidget(parent) { }

    virtual void drawFigure (int x, int y, Square ** & boardMatrix) noexcept = 0;
    virtual QPixmap * getSquareTexture () const noexcept = 0;
    virtual void setWidth (int) noexcept = 0;
    virtual void setHeight (int) noexcept = 0;
};


#endif //PROIECT_FIGURE_H
