//
// Created by loghin on 03.04.2021.
//

#ifndef TETRIS_CURRENTSETTINGS_H
#define TETRIS_CURRENTSETTINGS_H

#define GEN_KEY(_key, _value) KEY_ ## _key = _value

/**
 * Todo : Celelalte butoane
 * Todo : Complete space mapping
 * Todo : Assign all used buttons ( digits too, shift, control, tab, capslock ? )
 * Todo : Attempt to integrate audio settings
 * Todo : DDown List for Resolutions
 * Todo : Prepare Questions from this class
 */

#include <QKeyEvent>
class CurrentSettings {
public:
    enum DisplayMode {
        WINDOWED,
        FULLSCREEN
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

        GEN_KEY(LEFT_ARROW, 0),
        GEN_KEY(UP_ARROW, 1),
        GEN_KEY(RIGHT_ARROW, 2),
        GEN_KEY(DOWN_ARROW, 3),

        GEN_KEY(SPACE, ' ')
    };

private:
    struct VideoSettings {
        int         resolutionWidth;
        int         resolutionHeight;
        DisplayMode mode;
        bool        shadows;
        float       brightness; // [0.0f - 1.0f]
    };

    struct AudioSettings {
        float       masterVolume; // [0.0f - 1.0f]
        float       musicVolume;  // [0.0f - 1.0f]
        float       fxVolume;     // [0.0f - 1.0f]
    };

    struct ControlSettings {
        ControlKey  moveRightKey    {KEY_RIGHT_ARROW};
        ControlKey  moveLeftKey     {KEY_LEFT_ARROW};
        ControlKey  rotateKey       {KEY_R};
        ControlKey  dropKey         {KEY_SPACE};

        void setMoveRightKey (Qt::Key qKey) noexcept;
    };

    enum Difficulty {
        EASY,
        MEDIUM,
        HARD
    };

    struct GeneralSettings {
        Difficulty  difficulty;
        bool        notificationsToggle;
    };

private:
    static CurrentSettings _instance;

    GeneralSettings generalSettings;
    VideoSettings   videoSettings;
    AudioSettings   audioSettings;
    ControlSettings controlSettings;
public:
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
            case KEY_A:             return "a";
            case KEY_B:             return "b";
            case KEY_C:             return "c";
            case KEY_D:             return "d";
            case KEY_E:             return "e";
            case KEY_F:             return "f";
            case KEY_G:             return "g";
            case KEY_H:             return "h";
            case KEY_I:             return "i";
            case KEY_J:             return "j";
            case KEY_K:             return "k";
            case KEY_L:             return "l";
            case KEY_M:             return "m";
            case KEY_N:             return "n";
            case KEY_O:             return "o";
            case KEY_P:             return "p";
            case KEY_Q:             return "q";
            case KEY_R:             return "r";
            case KEY_S:             return "s";
            case KEY_T:             return "t";
            case KEY_U:             return "u";
            case KEY_V:             return "v";
            case KEY_W:             return "w";
            case KEY_X:             return "x";
            case KEY_Y:             return "y";
            case KEY_Z:             return "z";
            case KEY_LEFT_ARROW:    return "Left Arrow";
            case KEY_UP_ARROW:      return "Up Arrow";
            case KEY_RIGHT_ARROW:   return "Right Arrow";
            case KEY_DOWN_ARROW:    return "Down Arrow";
            case KEY_SPACE:         return "Spacebar";
            default:                return "Key Undefined";
        }
    }
};


#endif //TETRIS_CURRENTSETTINGS_H
