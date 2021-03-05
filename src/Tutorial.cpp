//
// Created by loghin on 05.03.2021.
//

#include "Tutorial.h"

void Tutorial::init() {
    this->mainLayout = new QVBoxLayout ( this );
    this->backButton = new QPushButton ( this->backButtonText, this );

    this->setLayout( this->mainLayout );
    this->mainLayout->addWidget( this->backButton );

    connect( this->backButton, & QPushButton::clicked, [this] () { emit this->back(); } );
}

Tutorial::~Tutorial() noexcept {
    this->mainLayout->removeWidget(this->backButton);

    delete this->mainLayout;
    delete this->backButton;
}