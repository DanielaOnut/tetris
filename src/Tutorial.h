//
// Created by loghin on 05.03.2021.
//

#ifndef TETRIS_TUTORIAL_H
#define TETRIS_TUTORIAL_H

#include <QWidget>
#include <QLayout>
#include <QPushButton>

class Tutorial : public QWidget {
    Q_OBJECT

private:
    QLayout * mainLayout { nullptr };

    QPushButton * backButton { nullptr };

    const char * backButtonText = "Back";

public:
    explicit Tutorial (QWidget * parent) noexcept : QWidget(parent) {

    }

    void init ();

    ~Tutorial() noexcept override;

signals:
    void back();
};


#endif //TETRIS_TUTORIAL_H
