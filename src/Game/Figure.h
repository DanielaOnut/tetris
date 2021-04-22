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

private:
    Square ** squares {nullptr};
    int height;
    int width;
    int squareSize {-1};
public:
    explicit Figure (QWidget * parent) noexcept : QWidget(parent) { }

    void createFigure (QPixmap *, const char *, int) noexcept;

    void paintEvent ( QPaintEvent * ) noexcept override;

    Square ** getFigureSquares () noexcept {
        return this->squares;
    }

    ~Figure() noexcept override;
};


#endif //PROIECT_FIGURE_H
