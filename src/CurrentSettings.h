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
#include <iostream>
#include <fstream>
//static std::ofstream fout ("SavedSettings.txt");
//extern std::ofstream fout;

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

    void load() noexcept;
    void save() noexcept;

private:
    struct VideoSettings {
        int         resolutionWidth  = 1280;
        int         resolutionHeight = 720;
        DisplayMode mode        {WINDOWED};
        float       brightness  {0.5f}; // [0.0f - 1.0f]
        bool        shadows     = false;

        std::string toString () const noexcept {
            return
                "VS{resWidth=" + std::to_string(this->resolutionWidth) +
                ";resHeight=" + std::to_string(this->resolutionHeight) +
                ";mode=" + std::to_string((int)this->mode) +
                ";brightness=" + std::to_string(this->brightness) +
                ";shadows=" + std::to_string(this->shadows) + "}";
        }

        void fromString(std::string const & str) noexcept(false) {
            auto c = str;
            c = c.substr(3);
            c = c.substr(0, c.length() - 1);


            auto p = strtok ( & c[0], ";" );
            while ( p != nullptr ) {
                char * optName = p;
                char * optValue = strchr(p, '=') + 1;
                * (optValue - 1) = 0;

                if (! strcmp(optName,"resWidth"))
                    this->resolutionWidth = atoi (optValue);
                if (! strcmp(optName,"resHeight"))
                    this->resolutionHeight = atoi (optValue);
                if (! strcmp (optName,"mode"))
                    this->mode = static_cast<DisplayMode>(atoi(optValue));
                if (! strcmp (optName,"brightness"))
                    this->brightness = atof (optValue);
                if (! strcmp (optName,"shadows"))
                    this->shadows = atoi (optValue);
                p = strtok (nullptr, ";");
            }
        }
    };

    struct AudioSettings {
        float       masterVolume    {0.5f}; // [0.0f - 1.0f]
        float       musicVolume     {0.5f}; // [0.0f - 1.0f]
        float       fxVolume        {0.5f}; // [0.0f - 1.0f]

        std::string toString () const noexcept {
            return "AS{masterVolume=" + std::to_string (this->masterVolume) +
                    ";musicVolume=" + std::to_string(this->musicVolume) +
                    ";fxVolume=" + std::to_string(this->fxVolume) + "}";
        }

        void fromString(std::string const & str) noexcept {
            auto c = str;
            c = c.substr(3);
            c = c.substr(0, c.length() - 1);


            auto p = strtok ( & c[0], ";" );
            while ( p != nullptr ) {
                char * optName = p;
                char * optValue = strchr(p, '=') + 1;
                * (optValue - 1) = 0;

                if (! strcmp (optName,"masterVolume"))
                    this->masterVolume = atof (optValue);
                if (! strcmp (optName,"musicVolume"))
                    this->musicVolume = atof (optValue);
                if (! strcmp (optName,"fxVolume"))
                    this->fxVolume = atof (optValue);

                p = strtok (nullptr, ";");
            }
        }
    };

    struct ControlSettings {
        ControlKey  moveRightKey    {KEY_RIGHT_ARROW};
        ControlKey  moveLeftKey     {KEY_LEFT_ARROW};
        ControlKey  rotateKey       {KEY_R};
        ControlKey  dropKey         {KEY_DOWN_ARROW};

        void setMoveRightKey (Qt::Key qKey) noexcept;
        void setMoveLeftKey (Qt::Key qKey) noexcept;
        void setRotateKey (Qt::Key qKey) noexcept;
        void setDropKey (Qt::Key qKey) noexcept;

        std::string toString () const noexcept {
            return "CS{moveRightKey=" + std::string (CurrentSettings::controlKeyToString(this->moveRightKey)) +
                    ";moveLeftKey=" + std::string (CurrentSettings::controlKeyToString(this->moveLeftKey)) +
                    ";rotateKey=" + std::string (CurrentSettings::controlKeyToString(this->rotateKey)) +
                    ";dropKey=" + std::string (CurrentSettings::controlKeyToString(this->dropKey)) + "}";
        }

        void fromString(std::string const & str) noexcept {
            auto c = str;
            c = c.substr(3);
            c = c.substr(0, c.length() - 1);


            auto p = strtok ( & c[0], ";" );
            while ( p != nullptr ) {
                char * optName = p;
                char * optValue = strchr(p, '=') + 1;
                * (optValue - 1) = 0;

                if (! strcmp (optName, "moveRightKey"))
                    this->moveRightKey = CurrentSettings::stringToControlKey(optValue);
                if (! strcmp (optName, "moveLeftKey"))
                    this->moveLeftKey = CurrentSettings::stringToControlKey(optValue);
                if (! strcmp (optName, "rotateKey"))
                    this->rotateKey = CurrentSettings::stringToControlKey(optValue);
                if (! strcmp (optName, "dropKey"))
                    this->dropKey = CurrentSettings::stringToControlKey(optValue);

                p = strtok (nullptr, ";");
            }
        }
    };

    struct GeneralSettings {
        Difficulty  difficulty = NORMAL;
        bool        notificationsToggle = true;

        std::string toString () noexcept {
            return "GS{difficulty=" + std::to_string(this->difficulty) +
                    ";notificationToggle=" + std::to_string(this->notificationsToggle) + "}";
        }

        void fromString(std::string const & str) noexcept {
            auto c = str;
            c = c.substr(3);
            c = c.substr(0, c.length() - 1);


            auto p = strtok ( & c[0], ";" );
            while ( p != nullptr ) {
                char * optName = p;
                char * optValue = strchr(p, '=') + 1;
                * (optValue - 1) = 0;

                if (! strcmp (optName, "difficulty"))
                    this->difficulty = static_cast<Difficulty>(atoi(optValue));
                if (! strcmp (optName, "notificationToggle"))
                    this->notificationsToggle = atoi (optValue);

                p = strtok (nullptr, ";");
            }
        }
    };

    CurrentSettings () noexcept = default;
    CurrentSettings (bool) noexcept;

    static CurrentSettings _instance;
    static CurrentSettings const _defaultInstance;

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

    GeneralSettings const & general () const noexcept {
        return this->generalSettings;
    }

    VideoSettings const & video () const noexcept {
        return this->videoSettings;
    }

    AudioSettings const & audio () const noexcept {
        return this->audioSettings;
    }

    ControlSettings const & control () const noexcept {
        return this->controlSettings;
    }

    static CurrentSettings & instance() noexcept {
        return CurrentSettings::_instance;
    }

    static CurrentSettings const & defaults () noexcept {
        return CurrentSettings::_defaultInstance;
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

    static ControlKey stringToControlKey (const char * str) {
        if (strlen(str) == 1) {
            char c = str[0];
            if (c >= 'A' && c <= 'Z')
                return static_cast<ControlKey>(c + 32);
            if (c >= '0' && c <= '9')
                return static_cast <ControlKey> (c);
        }
        if (! strcmp (str, "Left Arrow"))
            return static_cast<ControlKey> (0);
        if (! strcmp (str, "Up Arrow"))
            return static_cast<ControlKey> (1);
        if (! strcmp (str, "Right Arrow"))
            return static_cast<ControlKey> (2);
        if (! strcmp (str, "Down Arrow"))
            return static_cast<ControlKey> (3);
        if (! strcmp (str, "Escape"))
            return static_cast<ControlKey> (4);
        if (! strcmp (str, "Tab"))
            return static_cast<ControlKey> (5);
        if (! strcmp (str, "Backspace"))
            return static_cast<ControlKey> (7);
        if (! strcmp (str, "Enter"))
            return static_cast<ControlKey> (8);
        if (! strcmp (str, "Insert"))
            return static_cast<ControlKey> (10);
        if (! strcmp (str, "Delete"))
            return static_cast<ControlKey> (11);
        if (! strcmp (str, "Shift"))
            return static_cast<ControlKey> (36);
        if (! strcmp (str, "Ctrl"))
            return static_cast<ControlKey> (37);
        if (! strcmp (str, "Alt"))
            return static_cast<ControlKey> (39);
        if (! strcmp (str, "CapsLock"))
            return static_cast<ControlKey> (40);
        if (! strcmp (str, "Spacebar"))
            return static_cast<ControlKey> (' ');
        if (! strcmp (str, "Key Undefined"))
            return static_cast<ControlKey> (-1);
    }
};


#endif //TETRIS_CURRENTSETTINGS_H
