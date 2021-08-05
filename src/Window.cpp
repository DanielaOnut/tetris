//
// Created by loghin on 30.01.2021.
//

#include "Window.h"
#include "Tutorial.h"
#include "Settings.h"
#include "Statistics.h"
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
    this->resize(CurrentSettings::instance().video().resolutionWidth, CurrentSettings::instance().video().resolutionHeight);
    // Vertical Box Layout
    this->mainLayout = new QVBoxLayout(this);

    this->setLayout( this->mainLayout );

    this->switchToMenu(0); // gameScore is 0 at the begging
}

void Window::switchToMenu(int gameScore) noexcept {
    if ( this->activePanel != nullptr ) { //aveam ceva inainte
         this->mainLayout->removeWidget(this->activePanel);
         delete this->activePanel;
    }

    auto menu = new Menu(this);
    this->mainLayout->addWidget( menu );

    connect ( menu, & Menu::howToPlay, [this]{this->switchToTutorial();} );
    connect ( menu, & Menu::settings, [this]{this->switchToSettings();} );
    connect ( menu, & Menu::game, [this]{ this->switchToGame(); } );
    connect ( menu, & Menu::statistics, [this]{ this->switchToStatistics(); } );

    if (gameScore)
        menu->setGameScore(gameScore);

    menu->init();

    this->activePanel = menu;
//    this->activePanel = new Menu(this); // derived to base is implicit
//    this->mainLayout->addWidget( this->activePanel );

//    auto howToPlaySwitchRequested = [this] () {
//        this->switchToTutorial();
//    };

//    auto menu = dynamic_cast < Menu * > ( this->activePanel );
//
//    connect ( menu, & Menu::howToPlay, howToPlaySwitchRequested );
//    connect ( menu, & Menu::settings, [this]() {this->switchToSettings();} );
//    connect ( menu, & Menu::game, [this] { this->switchToGame(); } );
//
//    menu->init();
}

void Window::switchToStatistics() noexcept {
    this->mainLayout->removeWidget(this->activePanel);
    delete this->activePanel;

    this->activePanel = new Statistics (nullptr);
    this->mainLayout->addWidget(this->activePanel);

    auto statistics = dynamic_cast <Statistics *> (this->activePanel);

    connect (statistics, & Statistics::back, [this] { this->switchToMenu(0); });

    statistics->init();
}

#include <Game.h>

void Window::switchToGame() noexcept {
    this->mainLayout->removeWidget(this->activePanel);
    delete this->activePanel;

    this->activePanel = new Game(this);
    this->mainLayout->addWidget(this->activePanel);

    auto game = dynamic_cast < Game * > ( this->activePanel );

    connect (game, & Game::quit, [this] (int score) {
        this->switchToMenu(score);
    } );

    game->init();
}

void Window::switchToTutorial() noexcept {
    this->mainLayout->removeWidget( this->activePanel );
    delete this->activePanel;

    this->activePanel = new Tutorial(this);
    this->mainLayout->addWidget(this->activePanel);

    auto backRequested = [this] () {
        this->switchToMenu (0);
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
        this->switchToMenu (0);
    };

    connect (dynamic_cast < Settings * > (this->activePanel), & Settings::back, backRequested );
    connect (dynamic_cast < Settings * > (this->activePanel), & Settings::resolutionChanged, [this] {
        this->resize(CurrentSettings::instance().video().resolutionWidth,
                         CurrentSettings::instance().video().resolutionHeight);
    } );

    dynamic_cast < Settings * > (this->activePanel)->init();
}

Window::~Window () noexcept {
    this->mainLayout->removeWidget(this->activePanel);

    delete this->mainLayout;
    delete this->activePanel;
}

void Window::keyPressEvent(QKeyEvent *event) {
    auto * p = dynamic_cast < Game * > ( this->activePanel );

    if ( p != nullptr )
        p->keyPressEvent(event);
}

void Window::keyReleaseEvent(QKeyEvent *event) {
    auto * p = dynamic_cast < Game * > ( this->activePanel );
    if ( p != nullptr )
        p->keyReleaseEvent(event);
//    std::cout << event->text().toStdString() << " released\n";

}

void Window::closeEvent(QCloseEvent *) {
    CurrentSettings::instance().save();
}

#include <QResizeEvent>
void Window::resizeEvent(QResizeEvent * e) {
    CurrentSettings::instance().video().resolutionWidth = e->size().width();
    if (e->size().width() == 1280)
        CurrentSettings::instance().video().resolutionHeight = 720;
    else
        CurrentSettings::instance().video().resolutionHeight = e->size().height();

    auto pGame = dynamic_cast<Game *>(this->activePanel);

    if ( pGame != nullptr ) {
//        pGame->getQueue()->resizeSquares (e->size().width(), e->size().height());
//        pGame->getBoard()->resizeSquares (e->size().width(), e->size().height());
    }
    std::cout << "Window resized : { w = " << e->size().width() << ", h = " << e->size().height() << " }\n";
}