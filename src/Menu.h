//
// Created by loghin on 30.01.2021.
//

#ifndef TETRIS_MENU_H
#define TETRIS_MENU_H

#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QSpacerItem>

/**
 * todo : inbox section for lower part
 *        friends
 *        exit civilizat
 *        shop
 *
 *        designs : settings, statistics, friends ( in page ), profile ( in page ), inbox ( in page )
 */
class Menu : public QWidget {
    Q_OBJECT

private:
    QLayout         * generalLayout         = nullptr;

    /// Central Buttons
    QLayout         * centralButtonsLayout  = nullptr;

    QPushButton     * playButton            = nullptr;
    QPushButton     * statisticsButton      = nullptr;
    QPushButton     * tutorialButton        = nullptr;

    const char      * playButtonText        = "Play";
    const char      * statisticsButtonText  = "Statistics";
    const char      * tutorialButtonText    = "How to Play";

    /// Upper Right Buttons
    QLayout         * rightButtonsLayout     = nullptr;

    QPushButton     * profileButton         = nullptr;
    QPushButton     * settingsButton        = nullptr;

    const char      * profileButtonText     = "PH_P";
    const char      * settingsButtonText    = "PH_S";

public:
    explicit Menu ( QWidget * parent ) noexcept : QWidget(parent) { }

    void init () noexcept;

    void createComponents () noexcept;
    void alignComponents () noexcept;
    void adjustComponents() noexcept;
    void styleComponents () noexcept;

    ~Menu () noexcept;
};


#endif //TETRIS_MENU_H
