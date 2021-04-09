//
// Created by loghin on 03.04.2021.
//

#include "CurrentSettings.h"

CurrentSettings CurrentSettings::_instance;

#include <QKeyEvent>

CurrentSettings::ControlKey CurrentSettings::getControlKeyForQKey (Qt::Key key) noexcept {
    switch (key) {
        case Qt::Key_Escape:
        case Qt::Key_Tab:
        case Qt::Key_Backspace:
        case Qt::Key_Return:
        case Qt::Key_Insert:
        case Qt::Key_Delete:
        case Qt::Key_Shift:
        case Qt::Key_Control:
        case Qt::Key_Alt:
        case Qt::Key_CapsLock:  return static_cast<ControlKey>(key - Qt::Key_Escape + 4);
        case Qt::Key_Left:
        case Qt::Key_Up:
        case Qt::Key_Right:
        case Qt::Key_Down:      return static_cast<ControlKey>(key - Qt::Key_Left);
        case Qt::Key_0:
        case Qt::Key_1:
        case Qt::Key_2:
        case Qt::Key_3:
        case Qt::Key_4:
        case Qt::Key_5:
        case Qt::Key_6:
        case Qt::Key_7:
        case Qt::Key_8:
        case Qt::Key_9:         return static_cast<ControlKey>(key);
        case Qt::Key_A:
        case Qt::Key_B:
        case Qt::Key_C:
        case Qt::Key_D:
        case Qt::Key_E:
        case Qt::Key_F:
        case Qt::Key_G:
        case Qt::Key_H:
        case Qt::Key_I:
        case Qt::Key_J:
        case Qt::Key_K:
        case Qt::Key_L:
        case Qt::Key_M:
        case Qt::Key_N:
        case Qt::Key_O:
        case Qt::Key_P:
        case Qt::Key_Q:
        case Qt::Key_R:
        case Qt::Key_S:
        case Qt::Key_T:
        case Qt::Key_U:
        case Qt::Key_V:
        case Qt::Key_W:
        case Qt::Key_X:
        case Qt::Key_Y:
        case Qt::Key_Z:         return static_cast<ControlKey>(key + 32);
        case Qt::Key_Space:     return static_cast<ControlKey>(key);
    }

    return ControlKey::KEY_UNDEFINED;
}

void CurrentSettings::ControlSettings::setMoveRightKey(Qt::Key qKey) noexcept {
    this->moveRightKey = CurrentSettings::getControlKeyForQKey(qKey);
}

void CurrentSettings::ControlSettings::setMoveLeftKey(Qt::Key qKey) noexcept {
    this->moveLeftKey = CurrentSettings::getControlKeyForQKey(qKey);
}

void CurrentSettings::ControlSettings::setRotateKey(Qt::Key qKey) noexcept {
    this->rotateKey = CurrentSettings::getControlKeyForQKey(qKey);
}

void CurrentSettings::ControlSettings::setDropKey(Qt::Key qKey) noexcept {
    this->dropKey = CurrentSettings::getControlKeyForQKey(qKey);
}

