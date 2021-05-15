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
}

void Game::createComponents() noexcept {
    this->generalLayout = new QHBoxLayout(nullptr);

    this->gameBoard = new Board(this);

    this->shapeFallTimer = new QTimer(this);
    this->shapeFallTimer->setInterval(2000);
}

void Game::alignComponents() noexcept {
    this->setLayout(this->generalLayout);

    this->generalLayout->addWidget(this->gameBoard);

    this->generalLayout->setAlignment(this->gameBoard, Qt::AlignHCenter | Qt::AlignTop);

}

void Game::adjustComponents() noexcept {

}

void Game::styleComponents() noexcept {

}
#include <iostream>

void Game::connectComponents() noexcept {
    connect(this->shapeFallTimer, & QTimer::timeout, [this]{ this->gameBoard->dropActiveShape();});

    this->shapeFallTimer->start();
}

Game::~Game() noexcept {
    this->generalLayout->removeWidget(this->gameBoard);

    delete this->generalLayout;

    delete this->gameBoard;

    delete this->shapeFallTimer;
}
