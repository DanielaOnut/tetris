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
#include <Board.h>
#include <Figure.h>
#include <string>

class Figure : public QWidget {
    Q_OBJECT
public:
    constexpr static int SQUARE_COUNT = 4;
//    explicit Figure (QWidget * parent) noexcept : QWidget(parent) { }

    virtual void drawFigure (int x, int y, Square ** & boardMatrix) noexcept (false);
    virtual QPixmap * getSquareTexture () const noexcept = 0;
    virtual int getWidth () noexcept = 0;
    virtual int getHeight () noexcept = 0;
    virtual const char * toString () noexcept = 0;

    virtual int rotationCount () const noexcept = 0;
    virtual int const * xOffsetsForRotation (int) const noexcept = 0;
    virtual int const * yOffsetsForRotation (int) const noexcept = 0;

    ~Figure () noexcept override = default;
};


//void Figure::drawFigure(int x, int y, Square ** & boardMatrix, const char * figure) noexcept(false) {
//    int matrixWidth = Board::DEFAULT_WIDTH;
//    int matrixHeight = Board::DEFAULT_HEIGHT;
//    if (figure == "FigureL" || figure == "FigureReversedL") {
//        if (x > matrixHeight - 1)
//            throw std::runtime_error ("x is out of the matrix dimensions");
//        if (y > matrixWidth - 3)
//            throw std::runtime_error ("y is out of the matrix dimensions");
//        QPixmap * squareTexture;
//        if (figure == "FigureL")
//            squareTexture = SquareTexture::orange();
//        else
//            squareTexture = SquareTexture::blue();
//        int i = y;
//        for (i = y; 3--; i++)
//            boardMatrix[i][x].setTexture(squareTexture);
//        boardMatrix[i-1][x+1].setTexture(squareTexture);
//    }
//}

#endif //PROIECT_FIGURE_H
