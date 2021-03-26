
#include "Settings.h"

#include "Util.h"

void Settings::init() {
    this->createComponents();
    this->alignComponents();
    this->adjustComponents();
    this->styleComponents();
    this->connectComponents();

    this->setSoundSettingsVisibility( false );
}

void Settings::createComponents () noexcept {
    this->mainLayout = new QVBoxLayout ( nullptr );
    this->resetButtonLayout = new QHBoxLayout ( nullptr );
    this->upSettingsButtons = new QVBoxLayout ( nullptr );
    this->lowerButtonsLayout = new QHBoxLayout ( nullptr );

    this->resetButton = new QPushButton ( this->resetButtonText, this );
    this->generalButton = new QPushButton ( this->generalButtonText, this);

    this->soundButton = new QPushButton ( this->soundButtonText, this );
    this->soundSettingsLayout = new QHBoxLayout ( nullptr );
    this->soundSettingsLabelsLayout = new QVBoxLayout( nullptr );
    this->soundSettingsSlidersLayout = new QVBoxLayout ( nullptr );

    this->soundMasterLabel = new QLabel ( this->soundMasterLabelText, this );
    this->soundMusicLabel = new QLabel ( this->soundMusicLabelText, this );
    this->soundFXLabel = new QLabel ( this->soundFXLabelText, this );

    this->soundMasterSlider = new QSlider(Qt::Horizontal, this);
    this->soundMusicSlider = new QSlider(Qt::Horizontal, this);
    this->soundFXSlider = new QSlider(Qt::Horizontal, this);

    this->videoButton = new QPushButton ( this->videoButtonText, this );
    this->controlsButton = new QPushButton ( this->controlsButtonText, this );

    this->backButton = new QPushButton ( this->backButtonText, this );
    this->okButton = new QPushButton ( this->okButtonText, this );
    this->applyButton = new QPushButton ( this->applyButtonText, this );
}

void Settings::alignComponents() noexcept {
    this->setLayout( this->mainLayout );
    this->mainLayout->addItem(this->resetButtonLayout);
    this->mainLayout->addItem(this->upSettingsButtons);
    this->mainLayout->addItem(this->lowerButtonsLayout);

    this->resetButtonLayout->addWidget( this->resetButton );
    this->upSettingsButtons->addWidget( this->generalButton );
    this->upSettingsButtons->addWidget( this->soundButton );

    this->upSettingsButtons->addItem( this->soundSettingsLayout );

    this->soundSettingsLayout->addItem( this->soundSettingsLabelsLayout );
    this->soundSettingsLayout->addItem( this->soundSettingsSlidersLayout );

    this->soundSettingsLabelsLayout->addWidget( this->soundMasterLabel );
    this->soundSettingsLabelsLayout->addWidget( this->soundMusicLabel );
    this->soundSettingsLabelsLayout->addWidget( this->soundFXLabel );

    this->soundSettingsSlidersLayout->addWidget( this->soundMasterSlider );
    this->soundSettingsSlidersLayout->addWidget( this->soundMusicSlider );
    this->soundSettingsSlidersLayout->addWidget( this->soundFXSlider );

    this->upSettingsButtons->addWidget( this->videoButton );
    this->upSettingsButtons->addWidget( this->controlsButton );

    this->lowerButtonsLayout->addWidget( this->backButton );
    this->lowerButtonsLayout->addWidget( this->okButton );
    this->lowerButtonsLayout->addWidget( this->applyButton );

    this->resetButtonLayout->setAlignment(this->resetButton, Qt::AlignTop | Qt::AlignRight);
    this->mainLayout->setAlignment(this->upSettingsButtons, Qt::AlignHCenter | Qt::AlignVCenter);

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
    this->resetButton->setMinimumWidth(150);

    this->generalButton->setMinimumWidth(200);
    this->soundButton->setMinimumWidth(200);
    this->videoButton->setMinimumWidth(200);
    this->controlsButton->setMinimumWidth(200);

    this->generalButton->setFixedHeight(80);
    this->soundButton->setFixedHeight(80);
    this->videoButton->setFixedHeight(80);
    this->controlsButton->setFixedHeight(80);
}

void Settings::styleComponents() noexcept {
    auto buttonStyle = Util::getStyle("GeneralButton.css");
    auto settingButtonStyle = Util::getStyle("SettingButtons.css");

    this->backButton->setStyleSheet(buttonStyle.c_str());
    this->okButton->setStyleSheet(buttonStyle.c_str());
    this->applyButton->setStyleSheet(buttonStyle.c_str());

    this->resetButton->setStyleSheet(buttonStyle.c_str());
    this->generalButton->setStyleSheet(settingButtonStyle.c_str());
    this->soundButton->setStyleSheet(settingButtonStyle.c_str());
    this->videoButton->setStyleSheet(settingButtonStyle.c_str());
    this->controlsButton->setStyleSheet(settingButtonStyle.c_str());
}

void Settings::connectComponents() noexcept {
    connect( this->backButton, & QPushButton::clicked, [this] () { emit this->back(); } );

    connect( this->soundButton, & QPushButton::clicked, [this](){
        this->setSoundSettingsVisibility(true);
        this->setVideoSettingsVisibility(false);
    } );

    connect( this->videoButton, & QPushButton::clicked, [this](){
        this->setSoundSettingsVisibility(false);
        this->setVideoSettingsVisibility(true);
    } );

    connect( this->controlsButton, & QPushButton::clicked, [this](){
        this->setSoundSettingsVisibility(false);
        this->setVideoSettingsVisibility(false);
    } );

    connect( this->generalButton, & QPushButton::clicked, [this](){
        this->setSoundSettingsVisibility(false);
        this->setVideoSettingsVisibility(false);
    } );
}

Settings::~Settings() noexcept {
    this->lowerButtonsLayout->removeWidget(this->backButton);
    this->lowerButtonsLayout->removeWidget(this->okButton);
    this->lowerButtonsLayout->removeWidget(this->applyButton);
    this->resetButtonLayout->removeWidget(this->resetButton);

    this->upSettingsButtons->removeWidget(this->generalButton);
    this->upSettingsButtons->removeWidget(this->soundButton);

    this->upSettingsButtons->removeItem( this->soundSettingsLayout );

    this->soundSettingsLayout->removeItem( this->soundSettingsLabelsLayout );
    this->soundSettingsLayout->removeItem( this->soundSettingsSlidersLayout );

    this->soundSettingsLabelsLayout->removeWidget( this->soundMasterLabel );
    this->soundSettingsLabelsLayout->removeWidget( this->soundMusicLabel );
    this->soundSettingsLabelsLayout->removeWidget( this->soundFXLabel );

    this->soundSettingsSlidersLayout->removeWidget( this->soundMasterSlider );
    this->soundSettingsSlidersLayout->removeWidget( this->soundMusicSlider );
    this->soundSettingsSlidersLayout->removeWidget( this->soundFXSlider );

    this->upSettingsButtons->removeWidget(this->videoButton);
    this->upSettingsButtons->removeWidget(this->controlsButton);

    this->mainLayout->removeItem(this->lowerButtonsLayout);
    this->mainLayout->removeItem(this->upSettingsButtons);
    this->mainLayout->removeItem(this->resetButtonLayout);

    delete this->mainLayout;
    delete this->lowerButtonsLayout;
    delete this->upSettingsButtons;
    delete this->resetButtonLayout;

    delete this->generalButton;
    delete this->soundButton;
    delete this->videoButton;
    delete this->controlsButton;
    delete this->resetButton;

    delete this->backButton;
    delete this->okButton;
    delete this->applyButton;


    delete this->soundSettingsLayout;

    delete this->soundSettingsLabelsLayout;
    delete this->soundSettingsSlidersLayout;

    delete this->soundMasterLabel;
    delete this->soundMusicLabel;
    delete this->soundFXLabel;

    delete this->soundMasterSlider;
    delete this->soundMusicSlider;
    delete this->soundFXSlider;
}