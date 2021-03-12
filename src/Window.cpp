//
// Created by loghin on 30.01.2021.
//

#include "Window.h"
#include "Tutorial.h"
#include "Settings.h"
#include <Menu.h>
#include <iostream>

void Window::init () noexcept {
    /// Menu <- derivat din QWidget

    /// Fereastra - Panou Activ
    /// Menu
    /// Settings
    /// HowToPlay

    /// Avem 1 singur activ
    /// Incepem din Menu
    this->resize(1280, 720);
    // Vertical Box Layout
    this->mainLayout = new QVBoxLayout(this);

    this->setLayout( this->mainLayout );

    this->switchToMenu();
}

void Window::switchToMenu() noexcept {
    if ( this->activePanel != nullptr ) { //aveam ceva inainte
         this->mainLayout->removeWidget(this->activePanel);
         delete this->activePanel;
    }

    this->activePanel = new Menu(this);
    this->mainLayout->addWidget( this->activePanel );

    auto howToPlaySwitchRequested = [this] () {
        this->switchToTutorial();
    };

    connect ( dynamic_cast < Menu * > (this->activePanel), & Menu::howToPlay, howToPlaySwitchRequested );
    connect ( dynamic_cast < Menu *  > (this->activePanel), & Menu::settings, [this]() {this->switchToSettings();} );

    dynamic_cast < Menu * > (this->activePanel)->init();
}

void Window::switchToTutorial() noexcept {
    this->mainLayout->removeWidget( this->activePanel );
    delete this->activePanel;

    this->activePanel = new Tutorial(this);
    this->mainLayout->addWidget(this->activePanel);

    auto backRequested = [this] () {
        this->switchToMenu ();
    };

    connect ( dynamic_cast < Tutorial * > ( this->activePanel ), & Tutorial::back, backRequested );

    dynamic_cast < Tutorial * > (this->activePanel)->init();
}

void Window::switchToSettings() noexcept {
    this->mainLayout->removeWidget( this->activePanel );
    delete this->activePanel;

    this->activePanel = new Settings (this);
    this->mainLayout->addWidget( this->activePanel );

    auto backRequested = [this] () {
        this->switchToMenu ();
    };

    connect (dynamic_cast < Settings * > (this->activePanel), & Settings::back, backRequested );

    dynamic_cast < Settings * > (this->activePanel)->init();
}

Window::~Window () noexcept {
    this->mainLayout->removeWidget(this->activePanel);

    delete this->mainLayout;
    delete this->activePanel;
}

