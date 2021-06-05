//
// Created by loghin on 16.04.2021.
//

#include "Game.h"

void Game::init() noexcept {
    this->createComponents();
    this->alignComponents();
    this->adjustComponents();
    this->styleComponents();
    this->connectComponents();

    this->gameBoard->setVerticalMargin(5);
    this->gameBoard->setHorizontalMargin(5);

    this->gameBoard->init();
    this->gameBoard->dropActiveShape();
}

void Game::createComponents() noexcept {
    this->generalLayout = new QHBoxLayout(nullptr);

    this->gameBoard = new Board(this);

    this->shapeFallTimer = new QTimer(this);

    this->moveRightSignalGenerator = new QTimer(this);
    this->moveLeftSignalGenerator = new QTimer(this);
}

void Game::alignComponents() noexcept {
    this->setLayout(this->generalLayout);

    this->generalLayout->addWidget(this->gameBoard);

    this->generalLayout->setAlignment(this->gameBoard, Qt::AlignHCenter | Qt::AlignTop);

}

void Game::adjustComponents() noexcept {
    this->shapeFallTimer->setInterval(1300);

    this->moveRightSignalGenerator->setInterval(150);
    this->moveLeftSignalGenerator->setInterval(150);
}

void Game::styleComponents() noexcept {

}

#include <iostream>

void Game::connectComponents() noexcept {
    connect(this->shapeFallTimer, & QTimer::timeout, [this]{ this->gameBoard->dropActiveShape();});

    connect(this->moveRightSignalGenerator, & QTimer::timeout, [this]{
        emit this->moveRight();
    });

    connect(this->moveLeftSignalGenerator, & QTimer::timeout, [this]{
        emit this->moveLeft();
    });

    this->shapeFallTimer->start();
}

Game::~Game() noexcept {
    this->generalLayout->removeWidget(this->gameBoard);

    delete this->generalLayout;

    delete this->gameBoard;

    delete this->shapeFallTimer;
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
    }
//    std::cout << event->text().toStdString() << " released " << event->isAutoRepeat() << '\n';
}