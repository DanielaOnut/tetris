#ifndef PROIECT_SETTINGS_H
#define PROIECT_SETTINGS_H

#include <QWidget>
#include <QLayout>
#include <QPushButton>

class Settings : public QWidget {
    Q_OBJECT

private:
    QLayout * mainLayout { nullptr };

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
    void styleComponents () noexcept;
    void connectComponents () noexcept;

    ~Settings() noexcept override;

signals:
    void back();
};

#endif //PROIECT_SETTINGS_H
