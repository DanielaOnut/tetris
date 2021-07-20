#ifndef PROIECT_SETTINGS_H
#define PROIECT_SETTINGS_H

#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QCheckBox>
#include <QComboBox>
#include <QStringList>
#include <CurrentSettings.h>

class ControlButton : public QPushButton {
    Q_OBJECT

public:
    // QWidget * p = ...;
    // auto x = p;
    // auto y = ControlButton { p }; apel explicit
    // auto z = { p }; eroare ambiguitate, facem QWidget(QWidget *) sau facem CBut(QWidget *)

    // Integer ... conversie std::string
    // explicit : std::string("Ceva") + (std::string)(Integer(5));
    // implicit : std::string("Ceva") + Integer(5);
    explicit ControlButton ( QWidget * parent ) noexcept : QPushButton( parent ) { }
    ControlButton ( const char * text, QWidget * parent ) noexcept : QPushButton( text, parent ) {}

    void keyPressEvent(QKeyEvent *) override {}
};

class Settings : public QWidget {
    Q_OBJECT

private:
    QLayout     * mainLayout { nullptr };

    /// Reset Button
    QLayout     * resetButtonLayout { nullptr };

    QPushButton * resetButton       { nullptr };

    const char  * resetButtonText   = "Reset to Default";

    /// Up Settings Buttons
    QLayout     * upSettingsButtons { nullptr };

    QPushButton * generalButton  { nullptr };

    QLayout     * generalSettingsLayout { nullptr };

    QLayout     * generalSettingsLabel { nullptr };
    QLayout     * generalActionsLayout { nullptr };
    QLayout     * difficultyLabelButtons { nullptr };

    QLabel      * difficultyLabel   { nullptr };
    QLabel      * accountLabel   { nullptr };
    QLabel      * notificationsLabel   { nullptr };

    QPushButton * easyButton    { nullptr };
    QPushButton * normalButton  { nullptr };
    QPushButton * hardButton    { nullptr };
    QPushButton * accountButton { nullptr };
    QCheckBox   * notificationsBox  { nullptr };

    CurrentSettings::Difficulty   difficultyMode = {CurrentSettings::instance().general().difficulty};
    bool        notificationsBoxStatus = {CurrentSettings::instance().general().notificationsToggle};

    void inline setGeneralSettingsVisibility ( bool visibility ) noexcept {
        this->difficultyLabel->setVisible(visibility);
        this->accountLabel->setVisible(false);
        this->notificationsLabel->setVisible(false);
        this->easyButton->setVisible(visibility);
        this->normalButton->setVisible(visibility);
        this->hardButton->setVisible(visibility);
        this->accountButton->setVisible(false);
        this->notificationsBox->setVisible(false);
    }

    const char  * difficultyLabelText = "Difficulty";
    const char  * accountLabelText = "Account";
    const char  * notificationsLabelText = "Notifications";

    const char  * easyButtonText = "Easy";
    const char  * normalButtonText = "Normal";
    const char  * hardButtonText = "Hard";

    QPushButton * soundButton    { nullptr };

    QLayout     * soundSettingsLayout { nullptr };

    QLayout     * soundSettingsLabelsLayout { nullptr };
    QLayout     * soundSettingsSlidersLayout { nullptr };

    QLabel      * soundMasterLabel { nullptr };
    QLabel      * soundMusicLabel { nullptr };
    QLabel      * soundFXLabel { nullptr };

    QSlider     * soundMasterSlider { nullptr };
    QSlider     * soundMusicSlider { nullptr };
    QSlider     * soundFXSlider { nullptr };

    void inline setSoundSettingsVisibility ( bool visibility ) noexcept {
        this->soundMasterLabel->setVisible(visibility);
        this->soundMusicLabel->setVisible(visibility);
        this->soundFXLabel->setVisible(visibility);
        this->soundMasterSlider->setVisible(visibility);
        this->soundMusicSlider->setVisible(visibility);
        this->soundFXSlider->setVisible(visibility);
    }

    char  const * soundMasterLabelText { "Master Volume" };
    char  const * soundMusicLabelText { "Music Volume" };
    char  const * soundFXLabelText { "Effects Volume" };

    QPushButton * videoButton    { nullptr };

    QLayout     * videoSettingsLayout { nullptr };

    QLayout     * videoSettingsLabel { nullptr };
    QLayout     * videoActionsLayout { nullptr };
    QLayout     * displayModeButtons  { nullptr };

    QLabel      * resolutionLabel  { nullptr };
    QLabel      * displayModeLabel { nullptr };
    QLabel      * brightnessLabel  { nullptr };
    QLabel      * shadowsLabel     { nullptr };

    QStringList   resolutions      { nullptr };
    QComboBox   * dropDownList     { nullptr };
    QPushButton * windowModeButton { nullptr };
    QPushButton * fullscreenButton { nullptr };
    QSlider     * brightnessSlider  { nullptr };
    QCheckBox   * shadowsBox        { nullptr };

    void inline setVideoSettingsVisibility ( bool visibility ) noexcept {
        this->resolutionLabel->setVisible(visibility);
        this->displayModeLabel->setVisible(visibility);
        this->brightnessLabel->setVisible(false);
        this->shadowsLabel->setVisible(false);
        this->dropDownList->setVisible(visibility);
        this->windowModeButton->setVisible(visibility);
        this->fullscreenButton->setVisible(visibility);
        this->brightnessSlider->setVisible(false);
        this->shadowsBox->setVisible(false);
    }

    const char  * resolutionLabelText = "Resolution";
    const char  * displayModeLabelText = "Display Mode";
    const char  * brightnessLabelText = "Brightness";
    const char  * shadowsLabelText = "Shadows";
    const char  * windowModeButtonText = "Window";
    const char  * fullscreenButtonText = "Fullscreen";

    int         height = {CurrentSettings::instance().video().resolutionHeight};
    int         width  = {CurrentSettings::instance().video().resolutionWidth};
    CurrentSettings::DisplayMode displayModeKey {CurrentSettings::instance().video().mode};
    bool        shadowsBoxStatus {CurrentSettings::instance().video().shadows};

    QPushButton * controlsButton { nullptr };

    QLayout     * controlsSettingsLayout { nullptr };

    QLayout     * controlsSettingsLabel { nullptr };
    QLayout     * controlsActionsLayout { nullptr };

    QLabel      * moveRightLabel  { nullptr };
    QLabel      * moveLeftLabel   { nullptr };
    QLabel      * rotateLabel     { nullptr };
    QLabel      * dropLabel       { nullptr };

    QPushButton * moveRightButton { nullptr };
    QPushButton * moveLeftButton { nullptr };
    QPushButton * rotateButton { nullptr };
    QPushButton * dropButton { nullptr };

    QPushButton * controlAwaitingInput {nullptr};

    void inline setControlsSettingsVisibility ( bool visibility ) noexcept {
        this->moveRightLabel->setVisible(visibility);
        this->moveLeftLabel->setVisible(visibility);
        this->rotateLabel->setVisible(visibility);
        this->dropLabel->setVisible(visibility);
        this->moveRightButton->setVisible(visibility);
        this->moveLeftButton->setVisible(visibility);
        this->rotateButton->setVisible(visibility);
        this->dropButton->setVisible(visibility);
    }

    constexpr static char const * controlButtonAwaitingInputText = "Press a key";

    const char * moveRightLabelText = "MOVE RIGHT";
    const char * moveLeftLabelText = "MOVE LEFT";
    const char * rotateLabelText = "ROTATE";
    const char * dropLabelText = "DROP";

    const char * moveRightButtonText = "Right Arrow";
    const char * moveLeftButtonText = "Left Arrow";
    const char * rotateButtonText = "R";
    const char * dropButtonText = "Spacebar";

    CurrentSettings::ControlKey moveRightKey {CurrentSettings::instance().control().moveRightKey};
    CurrentSettings::ControlKey moveLeftKey  {CurrentSettings::instance().control().moveLeftKey};
    CurrentSettings::ControlKey rotateKey    {CurrentSettings::instance().control().rotateKey};
    CurrentSettings::ControlKey dropKey      {CurrentSettings::instance().control().dropKey};

    const char * generalButtonText  = "GENERAL";
    const char * soundButtonText    = "SOUND";
    const char * videoButtonText    = "VIDEO";
    const char * controlsButtonText = "CONTROLS";

    /// Bottom Buttons
    QLayout     * lowerButtonsLayout   { nullptr };

    QPushButton * backButton  { nullptr };
    QPushButton * okButton    { nullptr };
    QPushButton * applyButton { nullptr };

    const char * backButtonText     = "Back";
    const char * okButtonText       = "OK";
    const char * applyButtonText    = "Apply";

public:
    bool eventFilter(QObject *, QEvent *) noexcept override;

    explicit Settings (QWidget * parent) noexcept : QWidget(parent) {

    }

    void init ();

    void createComponents () noexcept;
    void alignComponents () noexcept;
    void adjustComponents () noexcept;
    void styleComponents () noexcept;
    void connectComponents () noexcept;

    /// Settings * p = new Settings ();
    /// QWidget * q = p;

    /// delete q; -> ~QWidget
    /// delete q; -> ~Settings -> ~QWidget
    ~Settings() noexcept override;

signals:
    void back();
    void resolutionChanged();
};

#endif //PROIECT_SETTINGS_H
