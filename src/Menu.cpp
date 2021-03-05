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
}

#include <iostream>
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
    this->generalLayout->setAlignment(this->centralButtonsLayout, Qt::AlignHCenter | Qt::AlignTop);
//    this->generalLayout->setAlignment(this->centralButtonsLayout, Qt::AlignHCenter | Qt::AlignCenter); todo : place back when inbox section is added
}

void Menu::adjustComponents () noexcept {

}

void Menu::styleComponents() noexcept {
//    this->playButton->setStyleSheet(
//        "QPushButton {"
//        "   border-style: outset;"
//        "   border-width: 5px;"
//        "   border-color: red;"
//        "   border-radius: 5px;"
//        "   height: 200px;"
//        "   width: 200px;"
//        "}"
//        ""
//        "QPushButton:hover {"
//        "   border-style: solid;"
//        "}"
//        ""
//        "QPushButton:pressed {"
//        "   border-style: inset;"
//        "}"
//    );

    auto buttonStyle = Util::getStyle("GeneralButton.css"); // se construieste un string din Util::getStyle, se copiaza intr-ul alt string, se distruge string-ul initial
//    auto buttonStyle = Util::getStyle("GeneralButton.css").c_str(); // se construieste un string din Util::getStyle, se obtine c_str(), se distruge obiectul

/**
 *
 * 1. auto buttonStyle = Util::getStyle("GeneralButton.css);
 *          buttonStyle     |   Util::getStyle(...);
 *  DataType std::string    |  std::string
 *  Obj      s2             |  s1
 *  Ptr      p2             |  p1
 *
 *  Distrugem string-ul din functie, distrugem p1.
 *  p2 ramane in pace
 *
 * 2. auto buttonStyle = Util::getStyle("GeneralButton.css).c_str();
 *          buttonStyle     |   Util::getStyle(...);
 *  DataType const char *   | std::string
 *  Obj      ?              | s1
 *  Ptr      p1             | p1
 *  Distrugem string-ul din functie, distrugem p1
 *  buttonStyle avea valoarea p1, se distruge si el
 */

    this->playButton->setStyleSheet(buttonStyle.c_str());
    this->statisticsButton->setStyleSheet(buttonStyle.c_str());
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