//
// Created by loghin on 30.01.2021.
//

#ifndef TETRIS_MENU_H
#define TETRIS_MENU_H

#include <QWidget>
#include <QPushButton>
#include <QLayout>

class Menu : public QWidget {
    Q_OBJECT

private:
    QLayout         * generalLayout         = nullptr;
    QLayout         * centralButtonsLayout  = nullptr;

    QPushButton     * playButton            = nullptr;
    QPushButton     * statisticsButton      = nullptr;
    QPushButton     * tutorialButton        = nullptr;

    const char      * playButtonText        = "Play";
    const char      * statisticsButtonText  = "Statistics";
    const char      * tutorialButtonText    = "How to Play";

public:
    explicit Menu ( QWidget * parent ) noexcept : QWidget(parent) { }

    void init () noexcept;

    void createComponents () noexcept;
    void alignComponents () noexcept;
    void adjustComponents() noexcept;

    ~Menu () noexcept;
};


#endif //TETRIS_MENU_H
