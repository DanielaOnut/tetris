//
// Created by loghin on 30.01.2021.
//

#include "Menu.h"
#include "Util.h"
#include "Inbox.h"
#include "Shop.h"
#include "Friends.h"
#include "CurrentSettings.h"

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

    this->coinButton = new QPushButton (this->coinButtonText, this);
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

    this->rightButtonsLayout->addWidget( this->coinButton );
    this->rightButtonsLayout->addWidget( this->profileButton );
    this->rightButtonsLayout->addWidget( this->settingsButton );

    this->leftButtonsLayout->addWidget( this->friendsButton );
    this->leftButtonsLayout->addWidget( this->inboxButton );
    this->leftButtonsLayout->addWidget( this->shopButton );
    this->leftButtonsLayout->addWidget( this->exitButton );

    this->rightButtonsLayout->setAlignment(this->coinButton, Qt::AlignLeft | Qt::AlignTop);
    this->rightButtonsLayout->setAlignment(this->profileButton, Qt::AlignRight | Qt::AlignTop);
    this->rightButtonsLayout->setAlignment(this->settingsButton, Qt::AlignTop);

    this->generalLayout->setAlignment(this->centralButtonsLayout, Qt::AlignHCenter | Qt::AlignVCenter);

    this->leftButtonsLayout->setAlignment(this->friendsButton, Qt::AlignBottom);
    this->leftButtonsLayout->setAlignment(this->inboxButton, Qt::AlignBottom);
    this->leftButtonsLayout->setAlignment(this->shopButton, Qt::AlignLeft | Qt::AlignBottom);

    this->leftButtonsLayout->setAlignment(this->exitButton, Qt::AlignRight | Qt::AlignBottom);
}

void Menu::adjustComponents () noexcept {
    this->playButton->setFixedHeight(35);
    this->statisticsButton->setFixedHeight(35);
    this->tutorialButton->setFixedHeight(35);
    this->playButton->setMinimumWidth(100);
    this->statisticsButton->setMinimumWidth(100);
    this->tutorialButton->setMinimumWidth(100);

    this->friendsButton->setMaximumWidth(100);
    this->inboxButton->setMaximumWidth(100);
    this->shopButton->setMaximumWidth(100);
    this->friendsButton->setMinimumWidth(100);
    this->inboxButton->setMinimumWidth(100);
    this->shopButton->setMinimumWidth(100);

    this->settingsButton->setMaximumWidth(65);
    this->settingsButton->setMinimumWidth(65);
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

    this->coinButton->setStyleSheet ("QPushButton {\n"
                                     "    border-color: #96a2c3;\n"
                                     "    background-color: #f1f1f1;\n"
                                     "    border-width: 2px;\n"
                                     "    border-radius: 3px;\n"
                                     "    border-style: outset;\n"
                                     "    margin: 3px;\n"
                                     "}");
    this->coinButton->setIcon(Util::getIcon("coin.png", 30, 30));
    this->settingsButton->setIcon(Util::getIcon("rotita.png", 50, 50));
    this->settingsButton->setIconSize(QSize(50, 50)); /// scoatem background-ul ( alpha pe alb )
    this->settingsButton->setText("");
    this->profileButton->setIcon(Util::getIcon("profile.png", 50, 50));
    this->profileButton->setIconSize(QSize (50, 50));
    this->profileButton->setText("");

    this->friendsButton->setIcon(Util::getIcon("friends.png", 50, 50));
    this->friendsButton->setIconSize(QSize (50, 50));
    this->friendsButton->setText("");
    this->shopButton->setIcon(Util::getIcon("cart.png", 80, 80));
    this->shopButton->setIconSize(QSize (50, 50));
    this->shopButton->setText("");
    this->inboxButton->setIcon(Util::getIcon("envelope.png", 50, 50));
    this->inboxButton->setIconSize(QSize (50, 50));
    this->inboxButton->setText("");

    this->exitButton->setIcon(Util::getIcon("exit.png", 100, 100));
    this->exitButton->setIconSize(QSize (50, 50));
    this->exitButton->setText("");
}

#include <QApplication>
#include <Settings.h>
#include <Shop.h>
void Menu::connectComponents() noexcept {
    auto howToPlayCallback = [this] () noexcept -> void {
        emit this->howToPlay();
    };

    connect( this->playButton, & QPushButton::clicked, [this] {emit this->game();} );

    connect ( this->tutorialButton, & QPushButton::clicked, howToPlayCallback );
    connect ( this->exitButton, & QPushButton::clicked, [](){
            CurrentSettings::instance().save();
            QApplication::exit(0);
        }
    );
    connect ( this->settingsButton, & QPushButton::clicked, [this]() {emit this->settings();} );

    connect ( this->friendsButton, & QPushButton::clicked, [this](){
        delete this->currentPopup;

        this->currentPopup = new Popup(
                this,
                { 10, this->height() - 400 - (this->height() - this->friendsButton->y()) },
                { 300, 400 }
        );

        auto friends = new Friends(nullptr);
        friends->init();
        this->currentPopup->setContent(friends);

        connect ( this->currentPopup, & Popup::close, [this]() {
            delete this->currentPopup;

            this->currentPopup = nullptr;
        } );
    } );

    connect ( this->inboxButton, & QPushButton::clicked, [this]() {
        delete this->currentPopup;

        this->currentPopup = new Popup(
                this,
                { 10, this->height() - 400 - (this->height() - this->friendsButton->y()) },
                { 300, 400 }
        );

        auto inbox = new Inbox (nullptr);
        inbox->init();
        this->currentPopup->setContent(inbox);

        connect ( this->currentPopup, & Popup::close, [this]() {
            delete this->currentPopup;

            this->currentPopup = nullptr;
        } );
    } );
    connect ( this->shopButton, & QPushButton::clicked, [this]() {
        delete this->currentPopup;

        this->currentPopup = new Popup(
                this,
                { 10, this->height() - 400 - (this->height() - this->friendsButton->y()) },
                { 300, 400 }
        );

        auto shop = new Shop (nullptr);
        shop->init();
        this->currentPopup->setContent(shop);

        connect ( this->currentPopup, & Popup::close, [this]() {
            delete this->currentPopup;

            this->currentPopup = nullptr;
        } );
    } );

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
    delete this->rightButtonsLayout;

    delete this->friendsButton;
    delete this->inboxButton;
    delete this->exitButton;
    delete this->shopButton;

    delete this->playButton;
    delete this->statisticsButton;
    delete this->tutorialButton;

    delete this->settingsButton;
    delete this->profileButton;

    delete this->currentPopup;
}
