#ifndef PROIECT_SETTINGS_H
#define PROIECT_SETTINGS_H

#include <QWidget>
#include <QLayout>
#include <QPushButton>

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
    QPushButton * soundButton    { nullptr };
    QPushButton * videoButton    { nullptr };
    QPushButton * controlsButton { nullptr };

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

    ~Settings() noexcept override;

signals:
    void back();
};

#endif //PROIECT_SETTINGS_H
