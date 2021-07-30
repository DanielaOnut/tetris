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

    QLabel * scoreLabel {nullptr};
    QPushButton * quitButton {nullptr};

    const char * quitButtonText = "Quit To Menu";
    const char * scoreLabelText = "Score: 0";
    int gameScore = 0;

    QLayout * figuresQueueLayout {nullptr};

    Queue * queue {nullptr};
    QLabel * queueLabel {nullptr};
    QLabel * pauseLabel {nullptr};
    QPushButton * pauseButton {nullptr};

    const char * queueLabelText = "Next Figures";
    const char * pauseLabelText = "Game is on Pause";

public:
    Queue * getQueue () noexcept {
        return this->queue;
    }

    void editScore (int x) noexcept;

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
    void quit(int);
};

class NoKeyButton : public QPushButton {
    Q_OBJECT

public:
    explicit NoKeyButton (QWidget * parent = nullptr) noexcept : QPushButton(parent) { }
    explicit NoKeyButton (const char * pText, QWidget * parent = nullptr) noexcept : QPushButton(pText, parent) { }
    ~NoKeyButton () noexcept override = default;

    void keyPressEvent(QKeyEvent * e) override {

    }
};


#endif //TETRIS_GAME_H
