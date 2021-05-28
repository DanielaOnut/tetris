//
// Created by loghin on 16.04.2021.
//

#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H

#include <QWidget>
#include <QPainter>
#include <Square.h>
#include <Figure.h>

class Board : public QWidget {
    Q_OBJECT

public:

    /// constante default -> nu se modifica si sunt in => constexpr
    constexpr static int DEFAULT_WIDTH  = 10;
    constexpr static int DEFAULT_HEIGHT = 20;

private:
    int width  {DEFAULT_WIDTH};
    int height {DEFAULT_HEIGHT};
    int verticalMargin {0};
    int horizontalMargin {0};

    int squareSize {-1};

    Square ** squares {nullptr};

    Figure * activeFigure {nullptr};

public:
    explicit Board(QWidget * parent) noexcept : QWidget(parent) { }

    void init () noexcept;

    void setVerticalMargin(int margin) noexcept {
        this->verticalMargin = margin;
    }

    void setHorizontalMargin(int margin) noexcept {
        this->horizontalMargin = margin;
    }

    void paintEvent ( QPaintEvent * ) noexcept override;

    void dropActiveShape() noexcept;

    ~Board() noexcept override;
};


#endif //TETRIS_BOARD_H
