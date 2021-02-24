//
// Created by loghin on 30.01.2021.
//

#include "Window.h"
#include <Menu.h>

void Window::init () noexcept {
    // Vertical Box Layout
    this->mainLayout = new QVBoxLayout(this);

    this->setLayout( this->mainLayout );

    this->activePanel = new Menu(this);

    this->mainLayout->addWidget( this->activePanel );

    dynamic_cast < Menu * > (this->activePanel)->init();
}

Window::~Window () noexcept {
    this->mainLayout->removeWidget(this->activePanel);

    delete this->mainLayout;
    delete this->activePanel;
}

