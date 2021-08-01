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
 *  todo 4:    designs : statistics
 *
 * todo 3 :
 *      Look up ALL destructors for any mem. leak -done-
 *
 *
 */

class ShopListItem;

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

    /// Upper Right Buttons (and coin button)
    QLayout         * rightButtonsLayout     = nullptr;

    QPushButton     * coinButton            = nullptr;
    QPushButton     * profileButton         = nullptr;
    QPushButton     * settingsButton        = nullptr;

    const char      * coinButtonText        = "0";
    int coinsNumber = 0;
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

    bool gameScoreEdited = false;
    int gameScore = 0;
public:
    explicit Menu ( QWidget * parent ) noexcept : QWidget(parent) { }

    void init () noexcept;
//    auto init () noexcept -> void;
    void editCoinsNumber (int) noexcept;

    void createComponents () noexcept;
    void alignComponents () noexcept;
    void adjustComponents() noexcept;
    void styleComponents () noexcept;
    void connectComponents () noexcept;

    static std::string loadCoinsNumber () noexcept;
    int getCoinsNumber () const {
        return this->coinsNumber;
    }

    void setGameScore (int score) {
        this->gameScore = score;
    }

    ~Menu () noexcept override;

signals:
    void howToPlay(); // functia semnal
    // NU se defineste - numai in QT
    void settings ();
    void game ();

public slots:
//    void onPlayClick () noexcept;
};


#endif //TETRIS_MENU_H
