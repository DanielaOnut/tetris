//
// Created by loghin on 30.01.2021.
//

#ifndef TETRIS_WINDOW_H
#define TETRIS_WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLayout>

class Window : public QWidget {
    Q_OBJECT

private:
    QWidget         * activePanel           = nullptr;
    QLayout         * mainLayout            = nullptr;
    /** se pozitioneaza pe mijloc, toata fereastra */

public:
    Window () noexcept : QWidget( nullptr ) { }
    void init () noexcept;

    void switchToTutorial () noexcept;
    void switchToMenu () noexcept;
    void switchToSettings () noexcept;

    ~Window () noexcept;
};


#endif //TETRIS_WINDOW_H
