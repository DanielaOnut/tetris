//
// Created by loghin on 16.04.2021.
//

#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include <QWidget>
#include <Board.h>
#include <QLayout>
#include <QTimer>

class Game : public QWidget {
    Q_OBJECT

    QLayout * generalLayout {nullptr};

    Board * gameBoard { nullptr };

    QTimer * shapeFallTimer {nullptr};

    QTimer * moveRightSignalGenerator {nullptr};

public:
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
    void rotateLeft ();
    void rotateRight ();
};


#endif //TETRIS_GAME_H
