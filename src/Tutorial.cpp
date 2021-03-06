//
// Created by loghin on 05.03.2021.
//

#include "Tutorial.h"
#include "Util.h"

void Tutorial::init() {
    this->createComponents();
    this->alignComponents();
    this->styleComponents();
    this->connectComponents();
}

void Tutorial::createComponents () noexcept {
    this->mainLayout = new QVBoxLayout ( this );
    this->backButton = new QPushButton ( this->backButtonText, this );
}

void Tutorial::alignComponents() noexcept {
    this->setLayout( this->mainLayout );
    this->mainLayout->addWidget( this->backButton );
}

void Tutorial::styleComponents() noexcept {
    auto buttonStyle = Util::getStyle("GeneralButton.css");
    this->backButton->setStyleSheet(buttonStyle.c_str());
}

void Tutorial::connectComponents() noexcept {
    connect( this->backButton, & QPushButton::clicked, [this] () { emit this->back(); } );
}

Tutorial::~Tutorial() noexcept {
    this->mainLayout->removeWidget(this->backButton);

    delete this->mainLayout;
    delete this->backButton;
}