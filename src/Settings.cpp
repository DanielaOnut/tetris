
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
    this->okButton = new QPushButton ( this->okButtonText, this );
    this->applyButton = new QPushButton ( this->applyButtonText, this );
}

void Settings::alignComponents() noexcept {
    this->setLayout( this->mainLayout );
    this->mainLayout->addWidget( this->backButton );
    this->mainLayout->addWidget( this->okButton );
    this->mainLayout->addWidget( this->applyButton );

    this->mainLayout->setAlignment(this->backButton, Qt::AlignBottom | Qt::AlignLeft);
    this->mainLayout->setAlignment(this->applyButton, Qt::AlignBottom | Qt::AlignRight);
    this->mainLayout->setAlignment(this->okButton, Qt::AlignBottom | Qt::AlignRight);
}

void Settings::styleComponents() noexcept {
    auto buttonStyle = Util::getStyle("GeneralButton.css");
    this->backButton->setStyleSheet(buttonStyle.c_str());
    this->okButton->setStyleSheet(buttonStyle.c_str());
    this->applyButton->setStyleSheet(buttonStyle.c_str());
}

void Settings::connectComponents() noexcept {
    connect( this->backButton, & QPushButton::clicked, [this] () { emit this->back(); } );
}

Settings::~Settings() noexcept {
    this->mainLayout->removeWidget(this->backButton);

    delete this->mainLayout;
    delete this->backButton;
}