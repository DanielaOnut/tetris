//
// Created by loghin on 30.01.2021.
//

#ifndef TETRIS_MENU_H
#define TETRIS_MENU_H

#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QSpacerItem>
#include <Popup.h>

/**
 *
 *  todo 4:    designs : settings, statistics, friends ( in page ), profile ( in page ), inbox ( in page )
 *
 *
 * todo 2 : Look over code, prepare questions
 *
 *          Populate Tutorial, separate init into createComponents ... (same as in Menu) -done-
 *          Same thing that was done for Tutorial, but for Settings. -done-
 *                 Implement panel switching for settings
 *                 Populate Settings ( same as window => init = createComponents, alignComponents etc.-done-
 *
 * todo 3 :
 *      Settings Panel - populate  -> resolution , name , sound fx etc. - almost done-
 *      Look up ALL destructors for any mem. leak -done-
 *
 *
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

    /// Lower Buttons
    QLayout         * leftButtonsLayout     = nullptr;

    QPushButton     * friendsButton         = nullptr;
    QPushButton     * inboxButton           = nullptr;
    QPushButton     * shopButton            = nullptr;
    QPushButton     * exitButton            = nullptr;

    const char      * friendsButtonText     = "PH_F";
    const char      * inboxButtonText       = "PH_I";
    const char      * shopButtonText        = "PH_SH";
    const char      * exitButtonText        = "PH_E";

    Popup           * currentPopup          = nullptr;

public:
    explicit Menu ( QWidget * parent ) noexcept : QWidget(parent) { }

    void init () noexcept;
//    auto init () noexcept -> void;

    void createComponents () noexcept;
    void alignComponents () noexcept;
    void adjustComponents() noexcept;
    void styleComponents () noexcept;
    void connectComponents () noexcept;

    ~Menu () noexcept override;

signals:
    void howToPlay(); // functia semnal
    // NU se defineste - numai in QT
    void settings ();

public slots:
//    void onPlayClick () noexcept;
};


#endif //TETRIS_MENU_H
