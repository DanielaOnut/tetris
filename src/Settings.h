#ifndef PROIECT_SETTINGS_H
#define PROIECT_SETTINGS_H

#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QSlider>
#include <QLabel>

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

    QLabel      * difficultyLabel   { nullptr };
    QLabel      * accountLabel   { nullptr };
    QLabel      * notificationsLabel   { nullptr };

    ///...actions

    void inline setGeneralSettingsVisibility ( bool visibility ) noexcept {
        this->difficultyLabel->setVisible(visibility);
        this->accountLabel->setVisible(visibility);
        this->notificationsLabel->setVisible(visibility);
    }

    const char  * difficultyLabelText = "Difficulty";
    const char  * accountLabelText = "Account";
    const char  * notificationsLabelText = "Notifications";

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

    QLabel      * resolutionLabel  { nullptr };
    QLabel      * displayModeLabel { nullptr };
    QLabel      * brightnessLabel  { nullptr };
    QLabel      * shadowsLabel     { nullptr };

    QSlider     * brightnessSlider  { nullptr };

    void inline setVideoSettingsVisibility ( bool visibility ) noexcept {
        this->resolutionLabel->setVisible(visibility);
        this->displayModeLabel->setVisible(visibility);
        this->brightnessLabel->setVisible(visibility);
        this->shadowsLabel->setVisible(visibility);
        this->brightnessSlider->setVisible(visibility);
    }

    const char  * resolutionLabelText = "Resolution";
    const char  * displayModeLabelText = "Display Mode";
    const char  * brightnessLabelText = "Brightness";
    const char  * shadowsLabelText = "Shadows";

    QPushButton * controlsButton { nullptr };

    QLayout     * controlsSettingsLayout { nullptr };

    QLayout     * controlsSettingsLabel { nullptr };
    QLayout     * controlsActionsLayout { nullptr };

    QLabel      * moveRightLabel  { nullptr };
    QLabel      * moveLeftLabel   { nullptr };
    QLabel      * rotateLabel     { nullptr };
    QLabel      * dropLabel       { nullptr };

    void inline setControlsSettingsVisibility ( bool visibility ) noexcept {
        this->moveRightLabel->setVisible(visibility);
        this->moveLeftLabel->setVisible(visibility);
        this->rotateLabel->setVisible(visibility);
        this->dropLabel->setVisible(visibility);
    }

    const char * moveRightLabelText = "MOVE RIGHT";
    const char * moveLeftLabelText = "MOVE LEFT";
    const char * rotateLabelText = "ROTATE";
    const char * dropLabelText = "DROP";

    const char  * generalButtonText  = "GENERAL";
    const char  * soundButtonText    = "SOUND";
    const char  * videoButtonText    = "VIDEO";
    const char  * controlsButtonText = "CONTROLS";

    /// Bottom Buttons
    QLayout     * lowerButtonsLayout   { nullptr };

    QPushButton * backButton  { nullptr };
    QPushButton * okButton    { nullptr };
    QPushButton * applyButton { nullptr };

    const char * backButtonText     = "Back";
    const char * okButtonText       = "OK";
    const char * applyButtonText    = "Apply";

public:
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
};

#endif //PROIECT_SETTINGS_H
