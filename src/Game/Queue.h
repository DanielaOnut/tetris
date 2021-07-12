//
// Created by danie on 01.07.2021.
//

#ifndef PROIECT_QUEUE_H
#define PROIECT_QUEUE_H

#include <QWidget>
#include <QPainter>
#include <Square.h>
#include <Figure.h>
#include <list>
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

    std::list <Figure *> queue;
public:
    explicit Queue (QWidget * parent) noexcept : QWidget(parent) {
        if (CurrentSettings::instance().general().difficulty == CurrentSettings::EASY
            || CurrentSettings::instance().general().difficulty == CurrentSettings::NORMAL)
            this->height = 8;
        else if (CurrentSettings::instance().general().difficulty == CurrentSettings::HARD)
            this->height = 2;
        this->squares = new Square * [this->height];
        for ( int i = 0; i < this->height; i++ ) {
            this->squares [i] = new Square [this->width];
        }
        for ( int i = 0; i < this->height; i ++ )
            for (int j = 0; j < this->width; j++) {
                this->squares[i][j].setTexture(SquareTexture::empty());
            }
    }

    void init () noexcept;

    int queueHeight () const noexcept {
        return this->height;
    }

    void setVerticalMargin(int margin) noexcept {
        this->verticalMargin = margin;
    }

    void setHorizontalMargin(int margin) noexcept {
        this->horizontalMargin = margin;
    }

    void paintEvent ( QPaintEvent * ) noexcept override;

    /// iti generezi el. din coada
    /// configurezi squares
    void generateInitial () noexcept;

    /// scoti prima, o pastrezi deoparte
    /// shiftezi elementele
    /// push cu inca un element
    /// reconfigurezi squares
    Figure * pop () noexcept;

    /// goleste toate squares
    /// 'deseneaza' (seteaza texturi ) pt. figurile din coada
    void adjustSquares () noexcept;
    void cleanSquares () noexcept;

    ~Queue () noexcept override;
};


#endif //PROIECT_QUEUE_H
