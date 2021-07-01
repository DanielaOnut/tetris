//
// Created by danie on 01.07.2021.
//

#ifndef PROIECT_QUEUE_H
#define PROIECT_QUEUE_H

#include <QWidget>
#include <QPainter>
#include <Square.h>
#include <Figure.h>
#include <CurrentSettings.h>

class Queue : public QWidget {
    Q_OBJECT
public:
    constexpr static int DEFAULT_WIDTH = 4;
private:
    int width  {DEFAULT_WIDTH};
    int height {0};
    int verticalMargin {0};
    int horizontalMargin {0};

    int squareSize {-1};

    Square ** squares {nullptr};

    Figure * activeFigure {nullptr};
public:
    explicit Queue (QWidget * parent) noexcept : QWidget(parent) {
        if (CurrentSettings::instance().general().difficulty == CurrentSettings::EASY
            || CurrentSettings::instance().general().difficulty == CurrentSettings::NORMAL)
            this->height = 8;
        else if (CurrentSettings::instance().general().difficulty == CurrentSettings::HARD)
            this->height = 2;
    }

    void init () noexcept;

    void setVerticalMargin(int margin) noexcept {
        this->verticalMargin = margin;
    }

    void setHorizontalMargin(int margin) noexcept {
        this->horizontalMargin = margin;
    }

    void paintEvent ( QPaintEvent * ) noexcept override;

    ~Queue () noexcept override;
};


#endif //PROIECT_QUEUE_H
