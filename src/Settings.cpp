
#include "Settings.h"

#include "Util.h"

void Settings::init() {
    this->createComponents();
    this->alignComponents();
    this->adjustComponents();
    this->styleComponents();
    this->connectComponents();

    this->setGeneralSettingsVisibility(false);
    this->setSoundSettingsVisibility( false );
    this->setVideoSettingsVisibility(false);
    this->setControlsSettingsVisibility(false);
}

void Settings::createComponents () noexcept {
    this->mainLayout = new QVBoxLayout ( nullptr );
    this->resetButtonLayout = new QHBoxLayout ( nullptr );
    this->upSettingsButtons = new QVBoxLayout ( nullptr );
    this->lowerButtonsLayout = new QHBoxLayout ( nullptr );

    this->resetButton = new QPushButton ( this->resetButtonText, this );
    this->generalButton = new QPushButton ( this->generalButtonText, this);
    this->generalSettingsLayout = new QHBoxLayout ( nullptr );
    this->generalSettingsLabel = new QVBoxLayout ( nullptr );
    this->generalActionsLayout = new QVBoxLayout ( nullptr );

    this->difficultyLabel = new QLabel (this->difficultyLabelText, this);
    this->accountLabel = new QLabel (this->accountLabelText, this);
    this->notificationsLabel = new QLabel (this->notificationsLabelText, this);

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
    this->videoSettingsLayout = new QHBoxLayout ( nullptr );
    this->videoSettingsLabel = new QVBoxLayout ( nullptr );
    this->videoActionsLayout = new QVBoxLayout ( nullptr );

    this->resolutionLabel = new QLabel (this->resolutionLabelText, this);
    this->displayModeLabel = new QLabel (this->displayModeLabelText, this);
    this->brightnessLabel = new QLabel (this->brightnessLabelText, this);
    this->shadowsLabel = new QLabel (this->shadowsLabelText, this);

    this->brightnessSlider = new QSlider (Qt::Horizontal, this);

    this->controlsButton = new QPushButton ( this->controlsButtonText, this );
    this->controlsSettingsLayout = new QHBoxLayout (nullptr);
    this->controlsSettingsLabel = new QVBoxLayout (nullptr);
    this->controlsActionsLayout = new QVBoxLayout (nullptr);

    this->moveRightLabel = new QLabel (this->moveRightLabelText, this);
    this->moveLeftLabel = new QLabel (this->moveLeftLabelText, this);
    this->rotateLabel = new QLabel (this->rotateLabelText, this);
    this->dropLabel = new QLabel (this->dropLabelText, this);

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

    this->upSettingsButtons->addItem( this->generalSettingsLayout );

    this->generalSettingsLayout->addItem( this->generalSettingsLabel );
    this->generalSettingsLayout->addItem( this->generalActionsLayout );

    this->generalSettingsLabel->addWidget( this->difficultyLabel );
    this->generalSettingsLabel->addWidget( this->accountLabel );
    this->generalSettingsLabel->addWidget( this->notificationsLabel );

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
    this->upSettingsButtons->addItem( this->videoSettingsLayout );

    this->videoSettingsLayout->addItem( this->videoSettingsLabel );
    this->videoSettingsLayout->addItem( this->videoActionsLayout );

    this->videoSettingsLabel->addWidget( this->resolutionLabel );
    this->videoSettingsLabel->addWidget( this->displayModeLabel );
    this->videoSettingsLabel->addWidget( this->brightnessLabel );
    this->videoSettingsLabel->addWidget( this->shadowsLabel );

    this->videoActionsLayout->addWidget( this->brightnessSlider );

    this->upSettingsButtons->addWidget( this->controlsButton );
    this->upSettingsButtons->addItem( this->controlsSettingsLayout );

    this->controlsSettingsLayout->addItem( this->controlsSettingsLabel );
    this->controlsSettingsLayout->addItem( this->controlsActionsLayout );

    this->controlsSettingsLabel->addWidget( this->moveRightLabel );
    this->controlsSettingsLabel->addWidget( this->moveLeftLabel );
    this->controlsSettingsLabel->addWidget( this->rotateLabel );
    this->controlsSettingsLabel->addWidget( this->dropLabel );

    this->lowerButtonsLayout->addWidget( this->backButton );
    this->lowerButtonsLayout->addWidget( this->okButton );
    this->lowerButtonsLayout->addWidget( this->applyButton );

    this->resetButtonLayout->setAlignment(this->resetButton, Qt::AlignTop | Qt::AlignRight);
    this->upSettingsButtons->setAlignment(this->generalButton, Qt::AlignHCenter);
    this->upSettingsButtons->setAlignment(this->soundButton, Qt::AlignHCenter);
    this->upSettingsButtons->setAlignment(this->videoButton, Qt::AlignHCenter);
    this->upSettingsButtons->setAlignment(this->controlsButton, Qt::AlignHCenter);

    this->generalSettingsLabel->setAlignment(Qt::AlignHCenter);

    this->soundSettingsLabelsLayout->setAlignment(this->soundMasterLabel, Qt::AlignRight);
    this->soundSettingsLabelsLayout->setAlignment(this->soundMusicLabel, Qt::AlignRight);
    this->soundSettingsLabelsLayout->setAlignment(this->soundFXLabel, Qt::AlignRight);
    this->soundSettingsSlidersLayout->setAlignment(this->soundMasterSlider, Qt::AlignLeft);
    this->soundSettingsSlidersLayout->setAlignment(this->soundMusicSlider, Qt::AlignLeft);
    this->soundSettingsSlidersLayout->setAlignment(this->soundFXSlider, Qt::AlignLeft);
    this->soundSettingsLayout->setSpacing(35);

    this->resolutionLabel->setAlignment(Qt::AlignRight);
    this->displayModeLabel->setAlignment(Qt::AlignRight);
    this->brightnessLabel->setAlignment(Qt::AlignRight);
    this->shadowsLabel->setAlignment(Qt::AlignRight);
    this->videoActionsLayout->setAlignment(this->brightnessSlider, Qt::AlignLeft);

    this->moveRightLabel->setAlignment(Qt::AlignHCenter);
    this->moveLeftLabel->setAlignment(Qt::AlignHCenter);
    this->rotateLabel->setAlignment(Qt::AlignHCenter);
    this->dropLabel->setAlignment(Qt::AlignHCenter);

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

    this->soundMasterSlider->setMaximumWidth(200);
    this->soundMusicSlider->setMaximumWidth(200);
    this->soundFXSlider->setMaximumWidth(200);

    this->soundMasterSlider->setMinimumWidth(200);
    this->soundMusicSlider->setMinimumWidth(200);
    this->soundFXSlider->setMinimumWidth(200);

    this->brightnessSlider->setMaximumWidth(200);
    this->brightnessSlider->setMinimumWidth(200);
}

void Settings::styleComponents() noexcept {
    auto buttonStyle = Util::getStyle("GeneralButton.css");
    auto settingButtonStyle = Util::getStyle("SettingButtons.css");
    auto slidersStyle = Util::getStyle("Sliders.css");

    this->backButton->setStyleSheet(buttonStyle.c_str());
    this->okButton->setStyleSheet(buttonStyle.c_str());
    this->applyButton->setStyleSheet(buttonStyle.c_str());

    this->resetButton->setStyleSheet(buttonStyle.c_str());
    this->generalButton->setStyleSheet(settingButtonStyle.c_str());
    this->soundButton->setStyleSheet(settingButtonStyle.c_str());
    this->videoButton->setStyleSheet(settingButtonStyle.c_str());
    this->controlsButton->setStyleSheet(settingButtonStyle.c_str());

    this->soundMasterSlider->setStyleSheet(slidersStyle.c_str());
    this->soundMusicSlider->setStyleSheet(slidersStyle.c_str());
    this->soundFXSlider->setStyleSheet(slidersStyle.c_str());

    this->brightnessSlider->setStyleSheet(slidersStyle.c_str());
}

void Settings::connectComponents() noexcept {
    connect( this->backButton, & QPushButton::clicked, [this] () { emit this->back(); } );

    connect( this->generalButton, & QPushButton::clicked, [this](){
        this->setGeneralSettingsVisibility(true);
        this->setSoundSettingsVisibility(false);
        this->setVideoSettingsVisibility(false);
        this->setControlsSettingsVisibility(false);
    } );

    connect( this->soundButton, & QPushButton::clicked, [this](){
        this->setGeneralSettingsVisibility(false);
        this->setSoundSettingsVisibility(true);
        this->setVideoSettingsVisibility(false);
        this->setControlsSettingsVisibility(false);
    } );

    connect( this->videoButton, & QPushButton::clicked, [this](){
        this->setGeneralSettingsVisibility(false);
        this->setSoundSettingsVisibility(false);
        this->setVideoSettingsVisibility(true);
        this->setControlsSettingsVisibility(false);
    } );

    connect( this->controlsButton, & QPushButton::clicked, [this](){
        this->setGeneralSettingsVisibility(false);
        this->setSoundSettingsVisibility(false);
        this->setVideoSettingsVisibility(false);
        this->setControlsSettingsVisibility(true);
    } );

}

Settings::~Settings() noexcept {
    this->lowerButtonsLayout->removeWidget(this->backButton);
    this->lowerButtonsLayout->removeWidget(this->okButton);
    this->lowerButtonsLayout->removeWidget(this->applyButton);
    this->resetButtonLayout->removeWidget(this->resetButton);

    this->upSettingsButtons->removeWidget(this->generalButton);

    this->upSettingsButtons->removeItem(this->generalSettingsLayout);

    this->generalSettingsLayout->removeItem(this->generalSettingsLabel);
    this->generalSettingsLayout->removeItem(this->generalActionsLayout);

    this->generalSettingsLabel->removeWidget(this->difficultyLabel);
    this->generalSettingsLabel->removeWidget(this->accountLabel);
    this->generalSettingsLabel->removeWidget(this->notificationsLabel);

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

    this->upSettingsButtons->removeItem(this->videoSettingsLayout);

    this->videoSettingsLayout->removeItem(this->videoSettingsLabel);
    this->videoSettingsLayout->removeItem(this->videoActionsLayout);

    this->videoSettingsLabel->removeWidget(this->resolutionLabel);
    this->videoSettingsLabel->removeWidget(this->displayModeLabel);
    this->videoSettingsLabel->removeWidget(this->brightnessLabel);
    this->videoSettingsLabel->removeWidget(this->shadowsLabel);

    this->videoActionsLayout->removeWidget(this->brightnessSlider);

    this->upSettingsButtons->removeWidget(this->controlsButton);

    this->upSettingsButtons->removeItem(this->controlsSettingsLayout);

    this->controlsSettingsLayout->removeItem(this->controlsSettingsLabel);
    this->controlsSettingsLayout->removeItem(this->controlsActionsLayout);

    this->controlsSettingsLabel->removeWidget(this->moveRightLabel);
    this->controlsSettingsLabel->removeWidget(this->moveLeftLabel);
    this->controlsSettingsLabel->removeWidget(this->rotateLabel);
    this->controlsSettingsLabel->removeWidget(this->dropLabel);

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

    delete this->generalSettingsLayout;

    delete this->generalSettingsLabel;
    delete this->generalActionsLayout;

    delete this->difficultyLabel;
    delete this->accountLabel;
    delete this->notificationsLabel;

    delete this->soundSettingsLayout;

    delete this->soundSettingsLabelsLayout;
    delete this->soundSettingsSlidersLayout;

    delete this->soundMasterLabel;
    delete this->soundMusicLabel;
    delete this->soundFXLabel;

    delete this->soundMasterSlider;
    delete this->soundMusicSlider;
    delete this->soundFXSlider;

    delete this->videoSettingsLayout;

    delete this->videoSettingsLabel;
    delete this->videoActionsLayout;

    delete this->resolutionLabel;
    delete this->displayModeLabel;
    delete this->brightnessLabel;
    delete this->shadowsLabel;

    delete this->brightnessSlider;

    delete this->controlsSettingsLayout;

    delete this->controlsSettingsLabel;
    delete this->controlsActionsLayout;

    delete this->moveRightLabel;
    delete this->moveLeftLabel;
    delete this->rotateLabel;
    delete this->dropLabel;
}