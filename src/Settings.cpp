
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
    this->difficultyLabelButtons = new QHBoxLayout ( nullptr );

    this->difficultyLabel = new QLabel (this->difficultyLabelText, this);
    this->accountLabel = new QLabel (this->accountLabelText, this);
    this->notificationsLabel = new QLabel (this->notificationsLabelText, this);

    this->easyButton = new QPushButton (this->easyButtonText, this);
    this->normalButton = new QPushButton (this->normalButtonText, this);
    this->hardButton = new QPushButton (this->hardButtonText, this);
    this->accountButton = new QPushButton (this);
    this->notificationsBox = new QCheckBox (this);

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
    this->displayModeButtons = new QHBoxLayout ( nullptr );

    this->resolutionLabel = new QLabel (this->resolutionLabelText, this);
    this->displayModeLabel = new QLabel (this->displayModeLabelText, this);
    this->brightnessLabel = new QLabel (this->brightnessLabelText, this);
    this->shadowsLabel = new QLabel (this->shadowsLabelText, this);

    this->windowModeButton = new QPushButton (this->windowModeButtonText, this);
    this->fullscreenButton = new QPushButton (this->fullscreenButtonText, this);
    this->brightnessSlider = new QSlider (Qt::Horizontal, this);
    this->shadowsBox = new QCheckBox (this);

    this->controlsButton = new QPushButton ( this->controlsButtonText, this );
    this->controlsSettingsLayout = new QHBoxLayout (nullptr);
    this->controlsSettingsLabel = new QVBoxLayout (nullptr);
    this->controlsActionsLayout = new QVBoxLayout (nullptr);

    this->moveRightLabel = new QLabel (this->moveRightLabelText, this);
    this->moveLeftLabel = new QLabel (this->moveLeftLabelText, this);
    this->rotateLabel = new QLabel (this->rotateLabelText, this);
    this->dropLabel = new QLabel (this->dropLabelText, this);

    this->moveRightButton = new QPushButton (this->moveRightButtonText, this);
    this->moveLeftButton = new QPushButton (this->moveLeftButtonText, this);
    this->rotateButton = new QPushButton (this->rotateButtonText, this);
    this->dropButton = new QPushButton (this->dropButtonText, this);

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
    this->generalActionsLayout->addItem( this->difficultyLabelButtons );

    this->generalSettingsLabel->addWidget( this->difficultyLabel );
    this->generalSettingsLabel->addWidget( this->accountLabel );
    this->generalSettingsLabel->addWidget( this->notificationsLabel );

    this->difficultyLabelButtons->addWidget( this->easyButton );
    this->difficultyLabelButtons->addWidget( this->normalButton );
    this->difficultyLabelButtons->addWidget( this->hardButton );
    this->generalActionsLayout->addWidget( this->accountButton );
    this->generalActionsLayout->addWidget( this->notificationsBox );

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
    this->videoActionsLayout->addItem( this->displayModeButtons );

    this->videoSettingsLabel->addWidget( this->resolutionLabel );
    this->videoSettingsLabel->addWidget( this->displayModeLabel );
    this->videoSettingsLabel->addWidget( this->brightnessLabel );
    this->videoSettingsLabel->addWidget( this->shadowsLabel );

    this->displayModeButtons->addWidget( this->windowModeButton );
    this->displayModeButtons->addWidget( this->fullscreenButton );
    this->videoActionsLayout->addWidget( this->brightnessSlider );
    this->videoActionsLayout->addWidget( this->shadowsBox );

    this->upSettingsButtons->addWidget( this->controlsButton );
    this->upSettingsButtons->addItem( this->controlsSettingsLayout );

    this->controlsSettingsLayout->addItem( this->controlsSettingsLabel );
    this->controlsSettingsLayout->addItem( this->controlsActionsLayout );

    this->controlsSettingsLabel->addWidget( this->moveRightLabel );
    this->controlsSettingsLabel->addWidget( this->moveLeftLabel );
    this->controlsSettingsLabel->addWidget( this->rotateLabel );
    this->controlsSettingsLabel->addWidget( this->dropLabel );

    this->controlsActionsLayout->addWidget( this->moveRightButton );
    this->controlsActionsLayout->addWidget( this->moveLeftButton );
    this->controlsActionsLayout->addWidget( this->rotateButton );
    this->controlsActionsLayout->addWidget( this->dropButton );

    this->lowerButtonsLayout->addWidget( this->backButton );
    this->lowerButtonsLayout->addWidget( this->okButton );
    this->lowerButtonsLayout->addWidget( this->applyButton );

    this->resetButtonLayout->setAlignment(this->resetButton, Qt::AlignTop | Qt::AlignRight);
    this->upSettingsButtons->setAlignment(this->generalButton, Qt::AlignHCenter);
    this->upSettingsButtons->setAlignment(this->soundButton, Qt::AlignHCenter);
    this->upSettingsButtons->setAlignment(this->videoButton, Qt::AlignHCenter);
    this->upSettingsButtons->setAlignment(this->controlsButton, Qt::AlignHCenter);

    this->difficultyLabel->setAlignment(Qt::AlignRight);
    this->accountLabel->setAlignment(Qt::AlignRight);
    this->notificationsLabel->setAlignment(Qt::AlignRight);
    this->generalActionsLayout->setAlignment(this->notificationsBox, Qt::AlignLeft);
    this->difficultyLabelButtons->setAlignment(Qt::AlignLeft);
    this->generalSettingsLabel->setSpacing(5);
    this->generalActionsLayout->setSpacing(5);
    this->difficultyLabelButtons->setSpacing(15);
    this->generalSettingsLayout->setSpacing(35);

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
    this->videoActionsLayout->setAlignment(this->shadowsBox, Qt::AlignLeft);
    this->displayModeButtons->setAlignment(Qt::AlignLeft);
    this->videoSettingsLayout->setSpacing(35);
    this->displayModeButtons->setSpacing(15);

    this->moveRightLabel->setAlignment(Qt::AlignRight);
    this->moveLeftLabel->setAlignment(Qt::AlignRight);
    this->rotateLabel->setAlignment(Qt::AlignRight);
    this->dropLabel->setAlignment(Qt::AlignRight);

    this->controlsSettingsLayout->setSpacing(35);
    this->controlsActionsLayout->setAlignment(Qt::AlignLeft);

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

    this->easyButton->setMaximumWidth(110);
    this->normalButton->setMaximumWidth(110);
    this->hardButton->setMaximumWidth(110);

    this->easyButton->setMinimumWidth(110);
    this->normalButton->setMinimumWidth(110);
    this->hardButton->setMinimumWidth(110);

    this->easyButton->setFixedHeight(30);
    this->normalButton->setFixedHeight(30);
    this->hardButton->setFixedHeight(30);

    this->accountButton->setMaximumWidth(30);
    this->accountButton->setMinimumWidth(30);
    this->accountButton->setFixedHeight(20);

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

    this->windowModeButton->setMaximumWidth(120);
    this->fullscreenButton->setMaximumWidth(120);
    this->brightnessSlider->setMaximumWidth(200);

    this->windowModeButton->setMinimumWidth(120);
    this->fullscreenButton->setMinimumWidth(120);
    this->brightnessSlider->setMinimumWidth(200);

    this->moveRightButton->setMaximumWidth(100);
    this->moveLeftButton->setMaximumWidth(100);
    this->rotateButton->setMaximumWidth(100);
    this->dropButton->setMaximumWidth(100);

    this->moveRightButton->setMinimumWidth(100);
    this->moveLeftButton->setMinimumWidth(100);
    this->rotateButton->setMinimumWidth(100);
    this->dropButton->setMinimumWidth(100);

    this->moveRightButton->setFixedHeight(30);
    this->moveLeftButton->setFixedHeight(30);
    this->rotateButton->setFixedHeight(30);
    this->dropButton->setFixedHeight(30);
}

void Settings::styleComponents() noexcept {
    auto buttonStyle = Util::getStyle("GeneralButton.css");
    auto settingButtonStyle = Util::getStyle("SettingButtons.css");
    auto slidersStyle = Util::getStyle("Sliders.css");
    auto difficultyButtonsStyle = Util::getStyle("DifficultyButtons.css");
    auto displayButtonsStyle = Util::getStyle("DisplayModeButtons.css");
    auto controlsButtonsStyle = Util::getStyle("ControlsButtons.css");

    this->backButton->setStyleSheet(buttonStyle.c_str());
    this->okButton->setStyleSheet(buttonStyle.c_str());
    this->applyButton->setStyleSheet(buttonStyle.c_str());

    this->resetButton->setStyleSheet(buttonStyle.c_str());
    this->generalButton->setStyleSheet(settingButtonStyle.c_str());
    this->soundButton->setStyleSheet(settingButtonStyle.c_str());
    this->videoButton->setStyleSheet(settingButtonStyle.c_str());
    this->controlsButton->setStyleSheet(settingButtonStyle.c_str());

    this->easyButton->setStyleSheet(difficultyButtonsStyle.c_str());
    this->normalButton->setStyleSheet(difficultyButtonsStyle.c_str());
    this->hardButton->setStyleSheet(difficultyButtonsStyle.c_str());

    this->accountButton->setIcon(Util::getIcon("google play.png", 30, 20));
    this->accountButton->setIconSize(QSize (30, 20));

    this->soundMasterSlider->setStyleSheet(slidersStyle.c_str());
    this->soundMusicSlider->setStyleSheet(slidersStyle.c_str());
    this->soundFXSlider->setStyleSheet(slidersStyle.c_str());

    this->windowModeButton->setStyleSheet(displayButtonsStyle.c_str());
    this->fullscreenButton->setStyleSheet(displayButtonsStyle.c_str());
    this->brightnessSlider->setStyleSheet(slidersStyle.c_str());

    this->moveRightButton->setStyleSheet(controlsButtonsStyle.c_str());
    this->moveLeftButton->setStyleSheet(controlsButtonsStyle.c_str());
    this->rotateButton->setStyleSheet(controlsButtonsStyle.c_str());
    this->dropButton->setStyleSheet(controlsButtonsStyle.c_str());
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
    this->generalActionsLayout->removeItem(this->difficultyLabelButtons);

    this->generalSettingsLabel->removeWidget(this->difficultyLabel);
    this->generalSettingsLabel->removeWidget(this->accountLabel);
    this->generalSettingsLabel->removeWidget(this->notificationsLabel);

    this->difficultyLabelButtons->removeWidget(this->easyButton);
    this->difficultyLabelButtons->removeWidget(this->normalButton);
    this->difficultyLabelButtons->removeWidget(this->hardButton);
    this->generalActionsLayout->removeWidget(this->accountButton);
    this->generalActionsLayout->removeWidget(this->notificationsBox);

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
    this->videoActionsLayout->removeItem(this->displayModeButtons);

    this->videoSettingsLabel->removeWidget(this->resolutionLabel);
    this->videoSettingsLabel->removeWidget(this->displayModeLabel);
    this->videoSettingsLabel->removeWidget(this->brightnessLabel);
    this->videoSettingsLabel->removeWidget(this->shadowsLabel);

    this->displayModeButtons->removeWidget(this->windowModeButton);
    this->displayModeButtons->removeWidget(this->fullscreenButton);
    this->videoActionsLayout->removeWidget(this->brightnessSlider);
    this->videoActionsLayout->removeWidget(this->shadowsBox);

    this->upSettingsButtons->removeWidget(this->controlsButton);

    this->upSettingsButtons->removeItem(this->controlsSettingsLayout);

    this->controlsSettingsLayout->removeItem(this->controlsSettingsLabel);
    this->controlsSettingsLayout->removeItem(this->controlsActionsLayout);

    this->controlsSettingsLabel->removeWidget(this->moveRightLabel);
    this->controlsSettingsLabel->removeWidget(this->moveLeftLabel);
    this->controlsSettingsLabel->removeWidget(this->rotateLabel);
    this->controlsSettingsLabel->removeWidget(this->dropLabel);

    this->controlsActionsLayout->removeWidget(this->moveRightButton);
    this->controlsActionsLayout->removeWidget(this->moveLeftButton);
    this->controlsActionsLayout->removeWidget(this->rotateButton);
    this->controlsActionsLayout->removeWidget(this->dropButton);

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
    delete this->difficultyLabelButtons;

    delete this->difficultyLabel;
    delete this->accountLabel;
    delete this->notificationsLabel;

    delete this->easyButton;
    delete this->normalButton;
    delete this->hardButton;
    delete this->accountButton;
    delete this->notificationsBox;

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
    delete this->displayModeButtons;

    delete this->resolutionLabel;
    delete this->displayModeLabel;
    delete this->brightnessLabel;
    delete this->shadowsLabel;

    delete this->windowModeButton;
    delete this->fullscreenButton;
    delete this->brightnessSlider;
    delete this->shadowsBox;

    delete this->controlsSettingsLayout;

    delete this->controlsSettingsLabel;
    delete this->controlsActionsLayout;

    delete this->moveRightLabel;
    delete this->moveLeftLabel;
    delete this->rotateLabel;
    delete this->dropLabel;

    delete this->moveRightButton;
    delete this->moveLeftButton;
    delete this->rotateButton;
    delete this->dropButton;
}