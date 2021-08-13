//
// Created by danie on 04.08.2021.
//

#ifndef PROIECT_STATISTICS_H
#define PROIECT_STATISTICS_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPushButton>

class Statistics : public QWidget {
    Q_OBJECT
private:
    QLayout * generalLayout {nullptr};

    QLayout * labelsLayout {nullptr};

    QLayout * bestScoreLayout {nullptr};
    QLabel  * bestScoreTitleLabel {nullptr};
    QLabel  * bestScoreLabel {nullptr};

    QLayout * worstScoreLayout {nullptr};
    QLabel  * worstScoreTitleLabel {nullptr};
    QLabel  * worstScoreLabel {nullptr};

    QLayout * mostTimePlayedLayout {nullptr};
    QLabel  * mostTimePlayedTitleLabel {nullptr};
    QLabel  * mostTimePlayedLabel {nullptr};

    QLayout * coinsEarnedLayout {nullptr};
    QLabel  * coinsEarnedTitleLabel {nullptr};
    QLabel  * coinsEarnedLabel {nullptr};

//    QLayout * backButtonLayout {nullptr};
    QPushButton * backButton {nullptr};
public:
    explicit Statistics ( QWidget * parent ) noexcept : QWidget(parent) { }

    void init () noexcept;

    void createComponents () noexcept;
    void alignComponents () noexcept;
    void adjustComponents() noexcept;
    void styleComponents () noexcept;
    void connectComponents () noexcept;

    void loadDataFromFile () noexcept;

    ~Statistics() noexcept override;
signals:
    void back ();
};


#endif //PROIECT_STATISTICS_H
