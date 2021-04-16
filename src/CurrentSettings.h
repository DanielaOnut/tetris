//
// Created by loghin on 03.04.2021.
//

#ifndef TETRIS_CURRENTSETTINGS_H
#define TETRIS_CURRENTSETTINGS_H

#define GEN_KEY(_key, _value) KEY_ ## _key = _value

/**
 * Todo : Celelalte butoane -done-
 * Todo : Attempt to integrate audio settings
 * Todo : Prepare Questions from this class
 */

#include <QKeyEvent>
class CurrentSettings {
public:
    enum DisplayMode {
        WINDOWED,
        FULLSCREEN
    };

    enum Difficulty {
        EASY,
        NORMAL,
        HARD
    };

    enum ControlKey {
        GEN_KEY(A, 'a'),
        GEN_KEY(B, 'b'),
        GEN_KEY(C, 'c'),
        GEN_KEY(D, 'd'),
        GEN_KEY(E, 'e'),
        GEN_KEY(F, 'f'),
        GEN_KEY(G, 'g'),
        GEN_KEY(H, 'h'),
        GEN_KEY(I, 'i'),
        GEN_KEY(J, 'j'),
        GEN_KEY(K, 'k'),
        GEN_KEY(L, 'l'),
        GEN_KEY(M, 'm'),
        GEN_KEY(N, 'n'),
        GEN_KEY(O, 'o'),
        GEN_KEY(P, 'p'),
        GEN_KEY(Q, 'q'),
        GEN_KEY(R, 'r'),
        GEN_KEY(S, 's'),
        GEN_KEY(T, 't'),
        GEN_KEY(U, 'u'),
        GEN_KEY(V, 'v'),
        GEN_KEY(W, 'w'),
        GEN_KEY(X, 'x'),
        GEN_KEY(Y, 'y'),
        GEN_KEY(Z, 'z'),

        GEN_KEY(0, '0'),
        GEN_KEY(1, '1'),
        GEN_KEY(2, '2'),
        GEN_KEY(3, '3'),
        GEN_KEY(4, '4'),
        GEN_KEY(5, '5'),
        GEN_KEY(6, '6'),
        GEN_KEY(7, '7'),
        GEN_KEY(8, '8'),
        GEN_KEY(9, '9'),

        GEN_KEY(LEFT_ARROW, 0),
        GEN_KEY(UP_ARROW, 1),
        GEN_KEY(RIGHT_ARROW, 2),
        GEN_KEY(DOWN_ARROW, 3),

        GEN_KEY(Escape, 4),
        GEN_KEY(Tab, 5),
        GEN_KEY(Backspace, 7),
        GEN_KEY(Return, 8),
        GEN_KEY(Insert, 10),
        GEN_KEY(Delete, 11),
        GEN_KEY(Shift, 36),
        GEN_KEY(Control, 37),
        GEN_KEY(Alt, 39),
        GEN_KEY(CapsLock, 40),

        GEN_KEY(SPACE, ' '),

        GEN_KEY(UNDEFINED, -1)
    };

private:
    struct VideoSettings {
        int         resolutionWidth  = 1280;
        int         resolutionHeight = 720;
        DisplayMode mode        {WINDOWED};
        float       brightness  {0.5f}; // [0.0f - 1.0f]
        bool        shadows     = true;
    };

    struct AudioSettings {
        float       masterVolume    {0.5f}; // [0.0f - 1.0f]
        float       musicVolume     {0.5f}; // [0.0f - 1.0f]
        float       fxVolume        {0.5f}; // [0.0f - 1.0f]
    };

    struct ControlSettings {
        ControlKey  moveRightKey    {KEY_RIGHT_ARROW};
        ControlKey  moveLeftKey     {KEY_LEFT_ARROW};
        ControlKey  rotateKey       {KEY_R};
        ControlKey  dropKey         {KEY_SPACE};

        void setMoveRightKey (Qt::Key qKey) noexcept;
        void setMoveLeftKey (Qt::Key qKey) noexcept;
        void setRotateKey (Qt::Key qKey) noexcept;
        void setDropKey (Qt::Key qKey) noexcept;
    };

    struct GeneralSettings {
        Difficulty  difficulty = NORMAL;
        bool        notificationsToggle = true;
    };

    static CurrentSettings _instance;

    GeneralSettings generalSettings;
    VideoSettings   videoSettings;
    AudioSettings   audioSettings;
    ControlSettings controlSettings;
public:

    static ControlKey getControlKeyForQKey ( Qt::Key ) noexcept;

    GeneralSettings & general () noexcept {
        return this->generalSettings;
    }

    VideoSettings & video () noexcept {
        return this->videoSettings;
    }

    AudioSettings & audio () noexcept {
        return this->audioSettings;
    }

    ControlSettings & control () noexcept {
        return this->controlSettings;
    }

    static CurrentSettings & instance() noexcept {
        return CurrentSettings::_instance;
    }

    static const char * controlKeyToString (ControlKey key) {
        switch (key) {
            case KEY_A:             return "A";
            case KEY_B:             return "B";
            case KEY_C:             return "C";
            case KEY_D:             return "D";
            case KEY_E:             return "E";
            case KEY_F:             return "F";
            case KEY_G:             return "G";
            case KEY_H:             return "H";
            case KEY_I:             return "I";
            case KEY_J:             return "J";
            case KEY_K:             return "K";
            case KEY_L:             return "L";
            case KEY_M:             return "M";
            case KEY_N:             return "N";
            case KEY_O:             return "O";
            case KEY_P:             return "P";
            case KEY_Q:             return "Q";
            case KEY_R:             return "R";
            case KEY_S:             return "S";
            case KEY_T:             return "T";
            case KEY_U:             return "U";
            case KEY_V:             return "V";
            case KEY_W:             return "W";
            case KEY_X:             return "X";
            case KEY_Y:             return "Y";
            case KEY_Z:             return "Z";
            case KEY_0:             return "0";
            case KEY_1:             return "1";
            case KEY_2:             return "2";
            case KEY_3:             return "3";
            case KEY_4:             return "4";
            case KEY_5:             return "5";
            case KEY_6:             return "6";
            case KEY_7:             return "7";
            case KEY_8:             return "8";
            case KEY_9:             return "9";
            case KEY_LEFT_ARROW:    return "Left Arrow";
            case KEY_UP_ARROW:      return "Up Arrow";
            case KEY_RIGHT_ARROW:   return "Right Arrow";
            case KEY_DOWN_ARROW:    return "Down Arrow";
            case KEY_Escape:        return "Escape";
            case KEY_Shift:         return "Shift";
            case KEY_Control:       return "Ctrl";
            case KEY_Alt:           return "Alt";
            case KEY_CapsLock:      return "CapsLock";
            case KEY_Tab:           return "Tab";
            case KEY_Backspace:     return "Backspace";
            case KEY_Return:        return "Enter";
            case KEY_Insert:        return "Insert";
            case KEY_Delete:        return "Delete";
            case KEY_SPACE:         return "Spacebar";
            default:                return "Key Undefined";
        }
    }
};


#endif //TETRIS_CURRENTSETTINGS_H
