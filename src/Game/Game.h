//
// Created by loghin on 16.04.2021.
//

#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include <QWidget>
#include <Board.h>
#include <QLayout>
#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include <Queue.h>

class Game : public QWidget {
    Q_OBJECT

    QLayout * generalLayout {nullptr};

    QLayout * boardLayout {nullptr};
    Board * gameBoard { nullptr };

    QTimer * shapeFallTimer {nullptr};

    QTimer * moveRightSignalGenerator {nullptr};
    QTimer * moveLeftSignalGenerator {nullptr};
    QTimer * dropSignalGenerator {nullptr};

    QLayout * dataLayout {nullptr};

    QPushButton * quitButton {nullptr};
    const char  * quitButtonText = "Quit To Menu";

    QLayout * figuresQueueLayout {nullptr};

    Queue * queue {nullptr};

    QLabel * queueLabel {nullptr};
    const char * queueLabelText = "Next Figures";

public:
    Queue * getQueue () noexcept {
        return this->queue;
    }

    Board * getBoard () noexcept {
        return this->gameBoard;
    }

    explicit Game ( QWidget * parent ) noexcept : QWidget(parent) { }

    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    void init () noexcept;

    void createComponents () noexcept;
    void alignComponents () noexcept;
    void adjustComponents() noexcept;
    void styleComponents () noexcept;
    void connectComponents () noexcept;
    ~Game () noexcept override;

    /**
     * Specifice Qt, nu le implementam noi
     */
signals:
    void moveLeft ();
    void moveRight ();
    void quit();
};


#endif //TETRIS_GAME_H
