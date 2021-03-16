//
// Created by loghin on 05.03.2021.
//

#ifndef TETRIS_TUTORIAL_H
#define TETRIS_TUTORIAL_H

#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>

class Tutorial : public QWidget {
    Q_OBJECT

private:
    QLayout     * mainLayout    { nullptr };

    QLayout     * textLayout    { nullptr };
    QLabel      * tutorialText  { nullptr };

    QLayout     * lowerButtonsLayout { nullptr };
    QPushButton * backButton         { nullptr };

    const char * backButtonText = "Back";

public:
    explicit Tutorial (QWidget * parent) noexcept : QWidget(parent) {

    }

    void init ();

    void createComponents () noexcept;
    void alignComponents () noexcept;
    void adjustComponents () noexcept;
    void styleComponents () noexcept;
    void connectComponents () noexcept;

    ~Tutorial() noexcept override;

signals:
    void back();
};


#endif //TETRIS_TUTORIAL_H
