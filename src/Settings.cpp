
#include "Settings.h"

#include "Util.h"

void Settings::init() {
    this->createComponents();
    this->alignComponents();
    this->adjustComponents();
    this->styleComponents();
    this->connectComponents();
}

void Settings::createComponents () noexcept {
    this->mainLayout = new QVBoxLayout ( this );
    this->upSettingsButtons = new QHBoxLayout ( this );
    this->lowerButtonsLayout = new QHBoxLayout ( this );

    this->generalButton = new QPushButton ( this->generalButtonText, this);
    this->soundButton = new QPushButton ( this->soundButtonText, this );
    this->videoButton = new QPushButton ( this->videoButtonText, this );
    this->controlsButton = new QPushButton ( this->controlsButtonText, this );

    this->backButton = new QPushButton ( this->backButtonText, this );
    this->okButton = new QPushButton ( this->okButtonText, this );
    this->applyButton = new QPushButton ( this->applyButtonText, this );
}

void Settings::alignComponents() noexcept {
    this->setLayout( this->mainLayout );
    this->mainLayout->addItem(this->upSettingsButtons);
    this->mainLayout->addItem(this->lowerButtonsLayout);

    this->upSettingsButtons->addWidget( this->generalButton );
    this->upSettingsButtons->addWidget( this->soundButton );
    this->upSettingsButtons->addWidget( this->videoButton );
    this->upSettingsButtons->addWidget( this->controlsButton );

    this->lowerButtonsLayout->addWidget( this->backButton );
    this->lowerButtonsLayout->addWidget( this->okButton );
    this->lowerButtonsLayout->addWidget( this->applyButton );

    this->upSettingsButtons->setAlignment( this->controlsButton, Qt::AlignTop);
    this->upSettingsButtons->setAlignment( this->videoButton, Qt::AlignTop);
    this->upSettingsButtons->setAlignment( this->soundButton, Qt::AlignTop);
    this->upSettingsButtons->setAlignment( this->generalButton, Qt::AlignTop);

    this->lowerButtonsLayout->setAlignment(this->okButton, Qt::AlignBottom);
    this->lowerButtonsLayout->setAlignment(this->applyButton, Qt::AlignBottom);
    this->lowerButtonsLayout->setAlignment(this->backButton, Qt::AlignBottom | Qt::AlignLeft);
}

void Settings::adjustComponents() noexcept {
    this->backButton->setMaximumWidth(100);
    this->applyButton->setMaximumWidth(100);
    this->okButton->setMaximumWidth(100);

    this->backButton->setMinimumWidth(100);
    this->applyButton->setMinimumWidth(100);
    this->okButton->setMinimumWidth(100);

    this->generalButton->setMaximumWidth(300);
    this->soundButton->setMaximumWidth(300);
    this->videoButton->setMaximumWidth(300);
    this->controlsButton->setMaximumWidth(300);

    this->generalButton->setMinimumWidth(300);
    this->soundButton->setMinimumWidth(300);
    this->videoButton->setMinimumWidth(300);
    this->controlsButton->setMinimumWidth(300);
}

void Settings::styleComponents() noexcept {
    auto buttonStyle = Util::getStyle("GeneralButton.css");
    auto settingButtonStyle = Util::getStyle("SettingButtons.css");

    this->backButton->setStyleSheet(buttonStyle.c_str());
    this->okButton->setStyleSheet(buttonStyle.c_str());
    this->applyButton->setStyleSheet(buttonStyle.c_str());

    this->generalButton->setStyleSheet(settingButtonStyle.c_str());
    this->soundButton->setStyleSheet(settingButtonStyle.c_str());
    this->videoButton->setStyleSheet(settingButtonStyle.c_str());
    this->controlsButton->setStyleSheet(settingButtonStyle.c_str());
}

void Settings::connectComponents() noexcept {
    connect( this->backButton, & QPushButton::clicked, [this] () { emit this->back(); } );
}

Settings::~Settings() noexcept {
    this->lowerButtonsLayout->removeWidget(this->backButton);
    this->lowerButtonsLayout->removeWidget(this->okButton);
    this->lowerButtonsLayout->removeWidget(this->applyButton);

    this->upSettingsButtons->removeWidget(this->generalButton);
    this->upSettingsButtons->removeWidget(this->soundButton);
    this->upSettingsButtons->removeWidget(this->videoButton);
    this->upSettingsButtons->removeWidget(this->controlsButton);

    this->mainLayout->removeItem(this->lowerButtonsLayout);
    this->mainLayout->removeItem(this->upSettingsButtons);

    delete this->mainLayout;
    delete this->lowerButtonsLayout;
    delete this->upSettingsButtons;

    delete this->generalButton;
    delete this->soundButton;
    delete this->videoButton;
    delete this->controlsButton;

    delete this->backButton;
    delete this->okButton;
    delete this->applyButton;
}