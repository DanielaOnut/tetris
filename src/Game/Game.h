//
// Created on 16.04.2021.
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
#include <QTimer>
#include <list>

class GameOver;

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
    QLabel * timeLabel {nullptr};
    QPushButton * quitButton {nullptr};

    const char * quitButtonText = "Quit To Menu";
    const char * scoreLabelText = "Score: 0";
    int gameScore = 0;

    QLayout * figuresQueueLayout {nullptr};

    Queue * queue {nullptr};
    QLabel * queueLabel {nullptr};
    QLabel * pauseLabel {nullptr};
    QPushButton * pauseButton {nullptr};

    QTimer * pIncTimer { nullptr };
    int timePassed {0};
    bool gamePlayedForMinutes = false;
    bool gamePlayedForHours = false;

    const char * queueLabelText = "Next Figures";
    const char * pauseLabelText = "Game is on Pause";

public:
    Queue * getQueue () noexcept {
        return this->queue;
    }

    void editScore (int x) noexcept;
    void saveData () noexcept;
    static std::list <std::string> isDataInFile () noexcept;

    void setGameOverWindow () noexcept;

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
    void gameOverSignal(int);
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

class GameOver : public QWidget {
    Q_OBJECT
private:
    QLayout * generalLayout {nullptr};

    QPushButton * gameOverButton {nullptr};

    QPushButton * backButton {nullptr};
public:
    explicit GameOver ( QWidget * pParent = nullptr ) noexcept : QWidget(pParent) { }

    void init () noexcept {
        this->createComponents();
        this->alignComponents();
        this->connectComponents();
        this->styleComponents();
    }

    void createComponents () {
        this->generalLayout = new QVBoxLayout (nullptr);

        this->gameOverButton = new QPushButton (this);
        this->backButton = new QPushButton ("Back to Menu", this);
    }

    void alignComponents () {
        this->setLayout(this->generalLayout);

        this->generalLayout->addWidget(this->gameOverButton);
        this->generalLayout->addWidget(this->backButton);

        this->generalLayout->setAlignment(this->gameOverButton, Qt::AlignCenter);
        this->generalLayout->setAlignment(this->backButton, Qt::AlignLeft);
    }

    void connectComponents () {
        connect (this->backButton, & QPushButton::clicked, [this] {
           emit this->back();
        });
    }

    void styleComponents () {
        this->gameOverButton->setIcon(Util::getIcon("game over.png", 1000, 500));
        this->gameOverButton->setIconSize(QSize(800, 450));

        this->gameOverButton->setStyleSheet("QPushButton {\n"
                                            "    border-color: #96a2c3;\n"
                                            "    background-color: #ba0909;\n"
                                            "    border-width: 2px;\n"
                                            "    border-radius: 3px;\n"
                                            "    border-style: outset;\n"
                                            "    margin: 3px;\n"
                                            "}");
        this->backButton->setStyleSheet(Util::getStyle("Generalbutton.css").c_str());
        this->backButton->setMaximumWidth(150);
        this->backButton->setMinimumWidth(150);
    }

    ~GameOver () noexcept override {
        this->generalLayout->removeWidget(this->gameOverButton);
        this->generalLayout->removeWidget(this->backButton);

        delete this->generalLayout;

        delete this->gameOverButton;
        delete this->backButton;
    }
signals:
    void back();
};


#endif //TETRIS_GAME_H
