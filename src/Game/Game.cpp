//
// Created by loghin on 16.04.2021.
//

#include "Game.h"
#include "Util.h"
#include "CurrentSettings.h"

void Game::init() noexcept {
    this->createComponents();
    this->alignComponents();
    this->adjustComponents();
    this->styleComponents();
    this->connectComponents();

    this->gameBoard->setVerticalMargin(5);
    this->gameBoard->setHorizontalMargin(5);

    this->queue->setVerticalMargin(20);
    this->queue->setHorizontalMargin(20);

    this->gameBoard->init();
    this->gameBoard->dropActiveShape();

    this->queue->init();
    this->queue->generateInitial();
}

void Game::createComponents() noexcept {
    this->generalLayout = new QHBoxLayout(nullptr);
    this->figuresQueueLayout = new QVBoxLayout (nullptr);
    this->boardLayout = new QVBoxLayout (nullptr);
    this->dataLayout = new QVBoxLayout (nullptr);

    this->quitButton = new QPushButton (this->quitButtonText, this);

    this->gameBoard = new Board(this);

    this->queueLabel = new QLabel (this->queueLabelText, this);
    this->queue = new Queue (this);

    this->shapeFallTimer = new QTimer(this);

    this->moveRightSignalGenerator = new QTimer(this);
    this->moveLeftSignalGenerator = new QTimer(this);
    this->dropSignalGenerator = new QTimer(this);
}

void Game::alignComponents() noexcept {
    this->setLayout(this->generalLayout);

    this->generalLayout->addItem(this->dataLayout);
    this->generalLayout->addItem(this->boardLayout);
    this->generalLayout->addItem(this->figuresQueueLayout);

    this->dataLayout->addWidget(this->quitButton);

    this->boardLayout->addWidget(this->gameBoard);

    this->figuresQueueLayout->addWidget(this->queue);
    this->figuresQueueLayout->addWidget(this->queueLabel);

    this->dataLayout->setAlignment(this->quitButton, Qt::AlignBottom | Qt::AlignLeft);

    this->boardLayout->setAlignment(this->gameBoard, Qt::AlignHCenter | Qt::AlignTop);

    this->figuresQueueLayout->setAlignment(this->queue, Qt::AlignLeft | Qt::AlignTop);
    this->figuresQueueLayout->setAlignment(this->queueLabel, Qt::AlignLeft | Qt::AlignTop);
}

void Game::adjustComponents() noexcept {
    this->moveRightSignalGenerator->setInterval(100);
    this->moveLeftSignalGenerator->setInterval(100);

    if (CurrentSettings::instance().general().difficulty == CurrentSettings::EASY) {
        this->shapeFallTimer->setInterval(1300);
        this->dropSignalGenerator->setInterval(60);
    }
    if (CurrentSettings::instance().general().difficulty == CurrentSettings::NORMAL) {
        this->shapeFallTimer->setInterval(650);
        this->dropSignalGenerator->setInterval(40);
    }
    if (CurrentSettings::instance().general().difficulty == CurrentSettings::HARD) {
        this->shapeFallTimer->setInterval(325);
        this->dropSignalGenerator->setInterval(20);
    }

    this->quitButton->setMinimumWidth(130);
    this->quitButton->setMaximumWidth(130);
}

void Game::styleComponents() noexcept {
    this->quitButton->setStyleSheet(Util::getStyle("ExitButton.css").c_str());
    this->quitButton->setIcon(Util::getIcon("quitButtonIcon.png", 20, 20));

    this->queueLabel->setStyleSheet(Util::getStyle("NextLabel.css").c_str());
}

#include <iostream>

void Game::connectComponents() noexcept {
    connect (this->quitButton, & QPushButton::clicked, [this] {emit this->quit();} );

    connect(this->shapeFallTimer, & QTimer::timeout, [this]{ this->gameBoard->dropActiveShape();});

    connect(this->moveRightSignalGenerator, & QTimer::timeout, [this]{
        emit this->moveRight();
    });

    connect(this->moveLeftSignalGenerator, & QTimer::timeout, [this]{
        emit this->moveLeft();
    });

    connect(this->dropSignalGenerator, & QTimer::timeout, [this] { this->gameBoard->dropActiveShape();});

    this->shapeFallTimer->start();
}

Game::~Game() noexcept {
    this->boardLayout->removeWidget(this->gameBoard);

    this->figuresQueueLayout->removeWidget(this->queueLabel);
    this->figuresQueueLayout->removeWidget(this->queue);

    this->dataLayout->removeWidget(this->quitButton);

    this->generalLayout->removeItem(this->figuresQueueLayout);
    this->generalLayout->removeItem(this->boardLayout);
    this->generalLayout->removeItem(this->dataLayout);

    delete this->generalLayout;

    delete this->dataLayout;
    delete this->boardLayout;
    delete this->figuresQueueLayout;

    delete this->quitButton;
    delete this->gameBoard;
    delete this->queueLabel;
    delete this->queue;

    delete this->shapeFallTimer;
    delete this->moveRightSignalGenerator;
    delete this->moveLeftSignalGenerator;
    delete this->dropSignalGenerator;
}
#include <CurrentSettings.h>

void Game::keyPressEvent(QKeyEvent *event) {
//    if ( ! event->isAutoRepeat() )
//        std::cout << event->text().toStdString() << " pressed\n";

    if ( ! event->isAutoRepeat() ) {
        if (
                CurrentSettings::getControlKeyForQKey( static_cast < Qt::Key > (event->key()) ) ==
                CurrentSettings::instance().control().moveRightKey
        ) {
            emit this->moveRight();
            this->moveRightSignalGenerator->start();
        }
        if (
            CurrentSettings::getControlKeyForQKey( static_cast < Qt::Key > (event->key()) ) ==
            CurrentSettings::instance().control().moveLeftKey
        ) {
            emit this->moveLeft();
            this->moveLeftSignalGenerator->start();
        }
        if (
                CurrentSettings::getControlKeyForQKey( static_cast < Qt::Key > (event->key()) ) ==
                CurrentSettings::instance().control().dropKey
        ) {
            this->gameBoard->dropActiveShape();
            this->shapeFallTimer->stop();
            this->dropSignalGenerator->start();
        }
        if (
                CurrentSettings::getControlKeyForQKey( static_cast < Qt::Key > (event->key()) ) ==
                CurrentSettings::instance().control().rotateKey
        )
            this->gameBoard->rotateShape();
    }
//    std::cout << event->text().toStdString() << " pressed " << event->isAutoRepeat() << '\n';
}

void Game::keyReleaseEvent(QKeyEvent *event) {
//    if ( ! event->isAutoRepeat() )
//        std::cout << event->text().toStdString() << " released\n";
    if ( ! event->isAutoRepeat() ) {
        if (
                CurrentSettings::getControlKeyForQKey( static_cast < Qt::Key > (event->key()) ) ==
                CurrentSettings::instance().control().moveRightKey
        )
            this->moveRightSignalGenerator->stop();
        if (
                CurrentSettings::getControlKeyForQKey( static_cast < Qt::Key > (event->key()) ) ==
                CurrentSettings::instance().control().moveLeftKey
                )
            this->moveLeftSignalGenerator->stop();
        if (
                CurrentSettings::getControlKeyForQKey( static_cast < Qt::Key > (event->key()) ) ==
                CurrentSettings::instance().control().dropKey
        ) {
            this->dropSignalGenerator->stop();
            this->shapeFallTimer->start();
        }
    }
//    std::cout << event->text().toStdString() << " released " << event->isAutoRepeat() << '\n';
}