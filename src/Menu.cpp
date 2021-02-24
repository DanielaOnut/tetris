//
// Created by loghin on 30.01.2021.
//

#include "Menu.h"

void Menu::init () noexcept {
    this->createComponents();
    this->alignComponents();
    this->adjustComponents();
}

void Menu::createComponents () noexcept {
    this->centralButtonsLayout = new QVBoxLayout ( nullptr );
    this->generalLayout = new QVBoxLayout ( nullptr );

    this->playButton = new QPushButton (this->playButtonText, this);
    this->statisticsButton = new QPushButton (this->statisticsButtonText, this);
    this->tutorialButton = new QPushButton (this->tutorialButtonText, this);

    this->rightButtonsLayout = new QHBoxLayout (nullptr);

    this->profileButton = new QPushButton (this->profileButtonText, this);
    this->settingsButton = new QPushButton (this->settingsButtonText, this);
}

void Menu::alignComponents() noexcept {
    this->setLayout ( this->generalLayout );

    //// add layout in layout
    //// primul e cel mai sus
    this->generalLayout->addItem( this->rightButtonsLayout );
    this->generalLayout->addItem( this->centralButtonsLayout );

    //// add widget in layout
    this->centralButtonsLayout->addWidget( this->playButton );
    this->centralButtonsLayout->addWidget( this->statisticsButton );
    this->centralButtonsLayout->addWidget( this->tutorialButton );

    this->rightButtonsLayout->addWidget( this->profileButton );
    this->rightButtonsLayout->addWidget( this->settingsButton );

    this->generalLayout->setAlignment(this->rightButtonsLayout, Qt::AlignTop | Qt::AlignRight);
    this->generalLayout->setAlignment(this->centralButtonsLayout, Qt::AlignCenter);
}

void Menu::adjustComponents () noexcept {

}

Menu::~Menu () noexcept {
    // undo what has been done in align
    this->centralButtonsLayout->removeWidget (this->playButton);
    this->centralButtonsLayout->removeWidget (this->statisticsButton);
    this->centralButtonsLayout->removeWidget (this->tutorialButton);

    this->rightButtonsLayout->removeWidget(this->profileButton);
    this->rightButtonsLayout->removeWidget(this->settingsButton);

    this->generalLayout->removeItem(this->centralButtonsLayout);
    this->generalLayout->removeItem(this->rightButtonsLayout);

    // undo what has been done in create
    delete this->centralButtonsLayout;
    delete this->generalLayout;

    delete this->playButton;
    delete this->statisticsButton;
    delete this->tutorialButton;

    delete this->rightButtonsLayout;

    delete this->profileButton;
    delete this->settingsButton;
}