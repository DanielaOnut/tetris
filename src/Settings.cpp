
#include "Settings.h"

#include "Util.h"

void Settings::init() {
    this->createComponents();
    this->alignComponents();
    this->styleComponents();
    this->connectComponents();
}

void Settings::createComponents () noexcept {
    this->mainLayout = new QVBoxLayout ( this );
    this->backButton = new QPushButton ( this->backButtonText, this );
}

void Settings::alignComponents() noexcept {
    this->setLayout( this->mainLayout );
    this->mainLayout->addWidget( this->backButton );
}

void Settings::styleComponents() noexcept {
    auto buttonStyle = Util::getStyle("GeneralButton.css");
    this->backButton->setStyleSheet(buttonStyle.c_str());
}

void Settings::connectComponents() noexcept {
    connect( this->backButton, & QPushButton::clicked, [this] () { emit this->back(); } );
}

Settings::~Settings() noexcept {
    this->mainLayout->removeWidget(this->backButton);

    delete this->mainLayout;
    delete this->backButton;
}