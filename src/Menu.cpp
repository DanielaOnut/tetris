//
// Created by loghin on 30.01.2021.
//

#include "Menu.h"
#include "Util.h"

void Menu::init () noexcept {
    this->createComponents();
    this->alignComponents();
    this->adjustComponents();
    this->styleComponents();
    this->connectComponents();
}

#include <iostream>
void Menu::createComponents () noexcept {
    this->generalLayout = new QVBoxLayout ( nullptr );
    this->centralButtonsLayout = new QVBoxLayout ( nullptr );

    this->playButton = new QPushButton (this->playButtonText, this);
    this->statisticsButton = new QPushButton (this->statisticsButtonText, this);
    this->tutorialButton = new QPushButton (this->tutorialButtonText, this);

    this->rightButtonsLayout = new QHBoxLayout (nullptr);

    this->profileButton = new QPushButton (this->profileButtonText, this);
    this->settingsButton = new QPushButton (this->settingsButtonText, this);

    this->leftButtonsLayout = new QHBoxLayout (nullptr);

    this->friendsButton = new QPushButton (this->friendsButtonText, this);
    this->inboxButton = new QPushButton (this->inboxButtonText, this);
    this->shopButton = new QPushButton (this->shopButtonText, this);
    this->exitButton = new QPushButton (this->exitButtonText, this);
}

void Menu::alignComponents() noexcept {
    this->setLayout ( this->generalLayout );

    //// add layout in layout
    //// primul e cel mai sus
    this->generalLayout->addItem( this->rightButtonsLayout );
    this->generalLayout->addItem( this->centralButtonsLayout );
    this->generalLayout->addItem( this->leftButtonsLayout );

    //// add widget in layout
    this->centralButtonsLayout->addWidget( this->playButton );
    this->centralButtonsLayout->addWidget( this->statisticsButton );
    this->centralButtonsLayout->addWidget( this->tutorialButton );

    this->rightButtonsLayout->addWidget( this->profileButton );
    this->rightButtonsLayout->addWidget( this->settingsButton );

    this->leftButtonsLayout->addWidget( this->friendsButton );
    this->leftButtonsLayout->addWidget( this->inboxButton );
    this->leftButtonsLayout->addWidget( this->shopButton );
    this->leftButtonsLayout->addWidget( this->exitButton );

    this->generalLayout->setAlignment(this->rightButtonsLayout, Qt::AlignTop | Qt::AlignRight);
    this->generalLayout->setAlignment(this->centralButtonsLayout, Qt::AlignHCenter | Qt::AlignVCenter);

    this->leftButtonsLayout->setAlignment(this->friendsButton, Qt::AlignBottom);
    this->leftButtonsLayout->setAlignment(this->inboxButton, Qt::AlignBottom);
    this->leftButtonsLayout->setAlignment(this->shopButton, Qt::AlignLeft | Qt::AlignBottom);

    this->leftButtonsLayout->setAlignment(this->exitButton, Qt::AlignRight | Qt::AlignBottom);
}

void Menu::adjustComponents () noexcept {
    this->friendsButton->setMaximumWidth(100);
    this->inboxButton->setMaximumWidth(100);
    this->shopButton->setMaximumWidth(100);
    this->friendsButton->setMinimumWidth(100);
    this->inboxButton->setMinimumWidth(100);
    this->shopButton->setMinimumWidth(100);
}
#include <QIcon>
void Menu::styleComponents() noexcept {
    auto buttonStyle = Util::getStyle("GeneralButton.css"); // se construieste un string din Util::getStyle, se copiaza intr-ul alt string, se distruge string-ul initial

    auto exitButtonStyle = Util::getStyle("ExitButton.css");
    auto optionsButtonStyle = Util::getStyle("OptionsButtons.css");

    this->playButton->setStyleSheet(buttonStyle.c_str());
    this->statisticsButton->setStyleSheet(buttonStyle.c_str());
    this->tutorialButton->setStyleSheet(buttonStyle.c_str());

    this->friendsButton->setStyleSheet(optionsButtonStyle.c_str());
    this->shopButton->setStyleSheet(optionsButtonStyle.c_str());
    this->inboxButton->setStyleSheet(optionsButtonStyle.c_str());
    this->profileButton->setStyleSheet(optionsButtonStyle.c_str());
    this->settingsButton->setStyleSheet(optionsButtonStyle.c_str());

    this->exitButton->setStyleSheet(exitButtonStyle.c_str());

    this->settingsButton->setIcon(Util::getIcon("rotita.png", 150, 150));
    this->settingsButton->setIconSize(QSize(150, 150)); /// scoatem background-ul ( alpha pe alb )
    this->settingsButton->setText("");
}

#include <QApplication>
void Menu::connectComponents() noexcept {
    auto howToPlayCallback = [this] () noexcept -> void {
        emit this->howToPlay();
    };

    connect ( this->tutorialButton, & QPushButton::clicked, howToPlayCallback );
    connect ( this->exitButton, & QPushButton::clicked, [](){QApplication::exit(0);} );
    connect ( this->settingsButton, & QPushButton::clicked, [this]() {emit this->settings();} );
}

Menu::~Menu () noexcept {
    // undo what has been done in align
    this->centralButtonsLayout->removeWidget (this->playButton);
    this->centralButtonsLayout->removeWidget (this->statisticsButton);
    this->centralButtonsLayout->removeWidget (this->tutorialButton);

    this->rightButtonsLayout->removeWidget(this->profileButton);
    this->rightButtonsLayout->removeWidget(this->settingsButton);

    this->leftButtonsLayout->removeWidget(this->friendsButton);
    this->leftButtonsLayout->removeWidget(this->inboxButton);
    this->leftButtonsLayout->removeWidget(this->settingsButton);
    this->leftButtonsLayout->removeWidget(this->exitButton);

    this->generalLayout->removeItem(this->centralButtonsLayout);
    this->generalLayout->removeItem(this->rightButtonsLayout);
    this->generalLayout->removeItem(this->leftButtonsLayout);

    // undo what has been done in create
    delete this->centralButtonsLayout;
    delete this->leftButtonsLayout;
    delete this->generalLayout;

    delete this->friendsButton;
    delete this->inboxButton;
    delete this->settingsButton;
    delete this->exitButton;

    delete this->playButton;
    delete this->statisticsButton;
    delete this->tutorialButton;

    delete this->rightButtonsLayout;

    delete this->profileButton;
}