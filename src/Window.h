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
    void switchToMenu (int) noexcept;
    void switchToSettings () noexcept;
    void switchToGame() noexcept;
    void switchToStatistics() noexcept;

    ~Window () noexcept override;

    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    void closeEvent (QCloseEvent *) override;

    void resizeEvent (QResizeEvent *) override;
};


#endif //TETRIS_WINDOW_H
