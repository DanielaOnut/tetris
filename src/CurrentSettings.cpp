//
// Created by loghin on 03.04.2021.
//

#include "CurrentSettings.h"

CurrentSettings CurrentSettings::_instance;

#include <QKeyEvent>
void CurrentSettings::ControlSettings::setMoveRightKey(Qt::Key qKey) noexcept {
    switch (qKey) {
// region Unused Cases
        case Qt::Key_Escape:
            break;
        case Qt::Key_Tab:
            break;
        case Qt::Key_Backtab:
            break;
        case Qt::Key_Backspace:
            break;
        case Qt::Key_Return:
            break;
        case Qt::Key_Enter:
            break;
        case Qt::Key_Insert:
            break;
        case Qt::Key_Delete:
            break;
        case Qt::Key_Pause:
            break;
        case Qt::Key_Print:
            break;
        case Qt::Key_SysReq:
            break;
        case Qt::Key_Clear:
            break;
        case Qt::Key_Home:
            break;
        case Qt::Key_End:
            break;
// endregion
        case Qt::Key_Left:
        case Qt::Key_Up:
        case Qt::Key_Right:
        case Qt::Key_Down:
            this->moveRightKey = static_cast<ControlKey>(qKey - Qt::Key_Left);
            break;
// region Unused Cases
        case Qt::Key_PageUp:
            break;
        case Qt::Key_PageDown:
            break;
        case Qt::Key_Shift:
            break;
        case Qt::Key_Control:
            break;
        case Qt::Key_Meta:
            break;
        case Qt::Key_Alt:
            break;
        case Qt::Key_CapsLock:
            break;
        case Qt::Key_NumLock:
            break;
        case Qt::Key_ScrollLock:
            break;
        case Qt::Key_F1:
            break;
        case Qt::Key_F2:
            break;
        case Qt::Key_F3:
            break;
        case Qt::Key_F4:
            break;
        case Qt::Key_F5:
            break;
        case Qt::Key_F6:
            break;
        case Qt::Key_F7:
            break;
        case Qt::Key_F8:
            break;
        case Qt::Key_F9:
            break;
        case Qt::Key_F10:
            break;
        case Qt::Key_F11:
            break;
        case Qt::Key_F12:
            break;
        case Qt::Key_F13:
            break;
        case Qt::Key_F14:
            break;
        case Qt::Key_F15:
            break;
        case Qt::Key_F16:
            break;
        case Qt::Key_F17:
            break;
        case Qt::Key_F18:
            break;
        case Qt::Key_F19:
            break;
        case Qt::Key_F20:
            break;
        case Qt::Key_F21:
            break;
        case Qt::Key_F22:
            break;
        case Qt::Key_F23:
            break;
        case Qt::Key_F24:
            break;
        case Qt::Key_F25:
            break;
        case Qt::Key_F26:
            break;
        case Qt::Key_F27:
            break;
        case Qt::Key_F28:
            break;
        case Qt::Key_F29:
            break;
        case Qt::Key_F30:
            break;
        case Qt::Key_F31:
            break;
        case Qt::Key_F32:
            break;
        case Qt::Key_F33:
            break;
        case Qt::Key_F34:
            break;
        case Qt::Key_F35:
            break;
        case Qt::Key_Super_L:
            break;
        case Qt::Key_Super_R:
            break;
        case Qt::Key_Menu:
            break;
        case Qt::Key_Hyper_L:
            break;
        case Qt::Key_Hyper_R:
            break;
        case Qt::Key_Help:
            break;
        case Qt::Key_Direction_L:
            break;
        case Qt::Key_Direction_R:
            break;
        case Qt::Key_Space:
            break;
        case Qt::Key_Exclam:
            break;
        case Qt::Key_QuoteDbl:
            break;
        case Qt::Key_NumberSign:
            break;
        case Qt::Key_Dollar:
            break;
        case Qt::Key_Percent:
            break;
        case Qt::Key_Ampersand:
            break;
        case Qt::Key_Apostrophe:
            break;
        case Qt::Key_ParenLeft:
            break;
        case Qt::Key_ParenRight:
            break;
        case Qt::Key_Asterisk:
            break;
        case Qt::Key_Plus:
            break;
        case Qt::Key_Comma:
            break;
        case Qt::Key_Minus:
            break;
        case Qt::Key_Period:
            break;
        case Qt::Key_Slash:
            break;
        case Qt::Key_0:
            break;
        case Qt::Key_1:
            break;
        case Qt::Key_2:
            break;
        case Qt::Key_3:
            break;
        case Qt::Key_4:
            break;
        case Qt::Key_5:
            break;
        case Qt::Key_6:
            break;
        case Qt::Key_7:
            break;
        case Qt::Key_8:
            break;
        case Qt::Key_9:
            break;
        case Qt::Key_Colon:
            break;
        case Qt::Key_Semicolon:
            break;
        case Qt::Key_Less:
            break;
        case Qt::Key_Equal:
            break;
        case Qt::Key_Greater:
            break;
        case Qt::Key_Question:
            break;
        case Qt::Key_At:
            break;
// endregion
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
        case Qt::Key_Z:
            this->moveRightKey = static_cast<ControlKey>(qKey + 32);
            break;
// region Unused Cases
        case Qt::Key_BracketLeft:
            break;
        case Qt::Key_Backslash:
            break;
        case Qt::Key_BracketRight:
            break;
        case Qt::Key_AsciiCircum:
            break;
        case Qt::Key_Underscore:
            break;
        case Qt::Key_QuoteLeft:
            break;
        case Qt::Key_BraceLeft:
            break;
        case Qt::Key_Bar:
            break;
        case Qt::Key_BraceRight:
            break;
        case Qt::Key_AsciiTilde:
            break;
        case Qt::Key_nobreakspace:
            break;
        case Qt::Key_exclamdown:
            break;
        case Qt::Key_cent:
            break;
        case Qt::Key_sterling:
            break;
        case Qt::Key_currency:
            break;
        case Qt::Key_yen:
            break;
        case Qt::Key_brokenbar:
            break;
        case Qt::Key_section:
            break;
        case Qt::Key_diaeresis:
            break;
        case Qt::Key_copyright:
            break;
        case Qt::Key_ordfeminine:
            break;
        case Qt::Key_guillemotleft:
            break;
        case Qt::Key_notsign:
            break;
        case Qt::Key_hyphen:
            break;
        case Qt::Key_registered:
            break;
        case Qt::Key_macron:
            break;
        case Qt::Key_degree:
            break;
        case Qt::Key_plusminus:
            break;
        case Qt::Key_twosuperior:
            break;
        case Qt::Key_threesuperior:
            break;
        case Qt::Key_acute:
            break;
        case Qt::Key_mu:
            break;
        case Qt::Key_paragraph:
            break;
        case Qt::Key_periodcentered:
            break;
        case Qt::Key_cedilla:
            break;
        case Qt::Key_onesuperior:
            break;
        case Qt::Key_masculine:
            break;
        case Qt::Key_guillemotright:
            break;
        case Qt::Key_onequarter:
            break;
        case Qt::Key_onehalf:
            break;
        case Qt::Key_threequarters:
            break;
        case Qt::Key_questiondown:
            break;
        case Qt::Key_Agrave:
            break;
        case Qt::Key_Aacute:
            break;
        case Qt::Key_Acircumflex:
            break;
        case Qt::Key_Atilde:
            break;
        case Qt::Key_Adiaeresis:
            break;
        case Qt::Key_Aring:
            break;
        case Qt::Key_AE:
            break;
        case Qt::Key_Ccedilla:
            break;
        case Qt::Key_Egrave:
            break;
        case Qt::Key_Eacute:
            break;
        case Qt::Key_Ecircumflex:
            break;
        case Qt::Key_Ediaeresis:
            break;
        case Qt::Key_Igrave:
            break;
        case Qt::Key_Iacute:
            break;
        case Qt::Key_Icircumflex:
            break;
        case Qt::Key_Idiaeresis:
            break;
        case Qt::Key_ETH:
            break;
        case Qt::Key_Ntilde:
            break;
        case Qt::Key_Ograve:
            break;
        case Qt::Key_Oacute:
            break;
        case Qt::Key_Ocircumflex:
            break;
        case Qt::Key_Otilde:
            break;
        case Qt::Key_Odiaeresis:
            break;
        case Qt::Key_multiply:
            break;
        case Qt::Key_Ooblique:
            break;
        case Qt::Key_Ugrave:
            break;
        case Qt::Key_Uacute:
            break;
        case Qt::Key_Ucircumflex:
            break;
        case Qt::Key_Udiaeresis:
            break;
        case Qt::Key_Yacute:
            break;
        case Qt::Key_THORN:
            break;
        case Qt::Key_ssharp:
            break;
        case Qt::Key_division:
            break;
        case Qt::Key_ydiaeresis:
            break;
        case Qt::Key_AltGr:
            break;
        case Qt::Key_Multi_key:
            break;
        case Qt::Key_Codeinput:
            break;
        case Qt::Key_SingleCandidate:
            break;
        case Qt::Key_MultipleCandidate:
            break;
        case Qt::Key_PreviousCandidate:
            break;
        case Qt::Key_Mode_switch:
            break;
        case Qt::Key_Kanji:
            break;
        case Qt::Key_Muhenkan:
            break;
        case Qt::Key_Henkan:
            break;
        case Qt::Key_Romaji:
            break;
        case Qt::Key_Hiragana:
            break;
        case Qt::Key_Katakana:
            break;
        case Qt::Key_Hiragana_Katakana:
            break;
        case Qt::Key_Zenkaku:
            break;
        case Qt::Key_Hankaku:
            break;
        case Qt::Key_Zenkaku_Hankaku:
            break;
        case Qt::Key_Touroku:
            break;
        case Qt::Key_Massyo:
            break;
        case Qt::Key_Kana_Lock:
            break;
        case Qt::Key_Kana_Shift:
            break;
        case Qt::Key_Eisu_Shift:
            break;
        case Qt::Key_Eisu_toggle:
            break;
        case Qt::Key_Hangul:
            break;
        case Qt::Key_Hangul_Start:
            break;
        case Qt::Key_Hangul_End:
            break;
        case Qt::Key_Hangul_Hanja:
            break;
        case Qt::Key_Hangul_Jamo:
            break;
        case Qt::Key_Hangul_Romaja:
            break;
        case Qt::Key_Hangul_Jeonja:
            break;
        case Qt::Key_Hangul_Banja:
            break;
        case Qt::Key_Hangul_PreHanja:
            break;
        case Qt::Key_Hangul_PostHanja:
            break;
        case Qt::Key_Hangul_Special:
            break;
        case Qt::Key_Dead_Grave:
            break;
        case Qt::Key_Dead_Acute:
            break;
        case Qt::Key_Dead_Circumflex:
            break;
        case Qt::Key_Dead_Tilde:
            break;
        case Qt::Key_Dead_Macron:
            break;
        case Qt::Key_Dead_Breve:
            break;
        case Qt::Key_Dead_Abovedot:
            break;
        case Qt::Key_Dead_Diaeresis:
            break;
        case Qt::Key_Dead_Abovering:
            break;
        case Qt::Key_Dead_Doubleacute:
            break;
        case Qt::Key_Dead_Caron:
            break;
        case Qt::Key_Dead_Cedilla:
            break;
        case Qt::Key_Dead_Ogonek:
            break;
        case Qt::Key_Dead_Iota:
            break;
        case Qt::Key_Dead_Voiced_Sound:
            break;
        case Qt::Key_Dead_Semivoiced_Sound:
            break;
        case Qt::Key_Dead_Belowdot:
            break;
        case Qt::Key_Dead_Hook:
            break;
        case Qt::Key_Dead_Horn:
            break;
        case Qt::Key_Dead_Stroke:
            break;
        case Qt::Key_Dead_Abovecomma:
            break;
        case Qt::Key_Dead_Abovereversedcomma:
            break;
        case Qt::Key_Dead_Doublegrave:
            break;
        case Qt::Key_Dead_Belowring:
            break;
        case Qt::Key_Dead_Belowmacron:
            break;
        case Qt::Key_Dead_Belowcircumflex:
            break;
        case Qt::Key_Dead_Belowtilde:
            break;
        case Qt::Key_Dead_Belowbreve:
            break;
        case Qt::Key_Dead_Belowdiaeresis:
            break;
        case Qt::Key_Dead_Invertedbreve:
            break;
        case Qt::Key_Dead_Belowcomma:
            break;
        case Qt::Key_Dead_Currency:
            break;
        case Qt::Key_Dead_a:
            break;
        case Qt::Key_Dead_A:
            break;
        case Qt::Key_Dead_e:
            break;
        case Qt::Key_Dead_E:
            break;
        case Qt::Key_Dead_i:
            break;
        case Qt::Key_Dead_I:
            break;
        case Qt::Key_Dead_o:
            break;
        case Qt::Key_Dead_O:
            break;
        case Qt::Key_Dead_u:
            break;
        case Qt::Key_Dead_U:
            break;
        case Qt::Key_Dead_Small_Schwa:
            break;
        case Qt::Key_Dead_Capital_Schwa:
            break;
        case Qt::Key_Dead_Greek:
            break;
        case Qt::Key_Dead_Lowline:
            break;
        case Qt::Key_Dead_Aboveverticalline:
            break;
        case Qt::Key_Dead_Belowverticalline:
            break;
        case Qt::Key_Dead_Longsolidusoverlay:
            break;
        case Qt::Key_Back:
            break;
        case Qt::Key_Forward:
            break;
        case Qt::Key_Stop:
            break;
        case Qt::Key_Refresh:
            break;
        case Qt::Key_VolumeDown:
            break;
        case Qt::Key_VolumeMute:
            break;
        case Qt::Key_VolumeUp:
            break;
        case Qt::Key_BassBoost:
            break;
        case Qt::Key_BassUp:
            break;
        case Qt::Key_BassDown:
            break;
        case Qt::Key_TrebleUp:
            break;
        case Qt::Key_TrebleDown:
            break;
        case Qt::Key_MediaPlay:
            break;
        case Qt::Key_MediaStop:
            break;
        case Qt::Key_MediaPrevious:
            break;
        case Qt::Key_MediaNext:
            break;
        case Qt::Key_MediaRecord:
            break;
        case Qt::Key_MediaPause:
            break;
        case Qt::Key_MediaTogglePlayPause:
            break;
        case Qt::Key_HomePage:
            break;
        case Qt::Key_Favorites:
            break;
        case Qt::Key_Search:
            break;
        case Qt::Key_Standby:
            break;
        case Qt::Key_OpenUrl:
            break;
        case Qt::Key_LaunchMail:
            break;
        case Qt::Key_LaunchMedia:
            break;
        case Qt::Key_Launch0:
            break;
        case Qt::Key_Launch1:
            break;
        case Qt::Key_Launch2:
            break;
        case Qt::Key_Launch3:
            break;
        case Qt::Key_Launch4:
            break;
        case Qt::Key_Launch5:
            break;
        case Qt::Key_Launch6:
            break;
        case Qt::Key_Launch7:
            break;
        case Qt::Key_Launch8:
            break;
        case Qt::Key_Launch9:
            break;
        case Qt::Key_LaunchA:
            break;
        case Qt::Key_LaunchB:
            break;
        case Qt::Key_LaunchC:
            break;
        case Qt::Key_LaunchD:
            break;
        case Qt::Key_LaunchE:
            break;
        case Qt::Key_LaunchF:
            break;
        case Qt::Key_MonBrightnessUp:
            break;
        case Qt::Key_MonBrightnessDown:
            break;
        case Qt::Key_KeyboardLightOnOff:
            break;
        case Qt::Key_KeyboardBrightnessUp:
            break;
        case Qt::Key_KeyboardBrightnessDown:
            break;
        case Qt::Key_PowerOff:
            break;
        case Qt::Key_WakeUp:
            break;
        case Qt::Key_Eject:
            break;
        case Qt::Key_ScreenSaver:
            break;
        case Qt::Key_WWW:
            break;
        case Qt::Key_Memo:
            break;
        case Qt::Key_LightBulb:
            break;
        case Qt::Key_Shop:
            break;
        case Qt::Key_History:
            break;
        case Qt::Key_AddFavorite:
            break;
        case Qt::Key_HotLinks:
            break;
        case Qt::Key_BrightnessAdjust:
            break;
        case Qt::Key_Finance:
            break;
        case Qt::Key_Community:
            break;
        case Qt::Key_AudioRewind:
            break;
        case Qt::Key_BackForward:
            break;
        case Qt::Key_ApplicationLeft:
            break;
        case Qt::Key_ApplicationRight:
            break;
        case Qt::Key_Book:
            break;
        case Qt::Key_CD:
            break;
        case Qt::Key_Calculator:
            break;
        case Qt::Key_ToDoList:
            break;
        case Qt::Key_ClearGrab:
            break;
        case Qt::Key_Close:
            break;
        case Qt::Key_Copy:
            break;
        case Qt::Key_Cut:
            break;
        case Qt::Key_Display:
            break;
        case Qt::Key_DOS:
            break;
        case Qt::Key_Documents:
            break;
        case Qt::Key_Excel:
            break;
        case Qt::Key_Explorer:
            break;
        case Qt::Key_Game:
            break;
        case Qt::Key_Go:
            break;
        case Qt::Key_iTouch:
            break;
        case Qt::Key_LogOff:
            break;
        case Qt::Key_Market:
            break;
        case Qt::Key_Meeting:
            break;
        case Qt::Key_MenuKB:
            break;
        case Qt::Key_MenuPB:
            break;
        case Qt::Key_MySites:
            break;
        case Qt::Key_News:
            break;
        case Qt::Key_OfficeHome:
            break;
        case Qt::Key_Option:
            break;
        case Qt::Key_Paste:
            break;
        case Qt::Key_Phone:
            break;
        case Qt::Key_Calendar:
            break;
        case Qt::Key_Reply:
            break;
        case Qt::Key_Reload:
            break;
        case Qt::Key_RotateWindows:
            break;
        case Qt::Key_RotationPB:
            break;
        case Qt::Key_RotationKB:
            break;
        case Qt::Key_Save:
            break;
        case Qt::Key_Send:
            break;
        case Qt::Key_Spell:
            break;
        case Qt::Key_SplitScreen:
            break;
        case Qt::Key_Support:
            break;
        case Qt::Key_TaskPane:
            break;
        case Qt::Key_Terminal:
            break;
        case Qt::Key_Tools:
            break;
        case Qt::Key_Travel:
            break;
        case Qt::Key_Video:
            break;
        case Qt::Key_Word:
            break;
        case Qt::Key_Xfer:
            break;
        case Qt::Key_ZoomIn:
            break;
        case Qt::Key_ZoomOut:
            break;
        case Qt::Key_Away:
            break;
        case Qt::Key_Messenger:
            break;
        case Qt::Key_WebCam:
            break;
        case Qt::Key_MailForward:
            break;
        case Qt::Key_Pictures:
            break;
        case Qt::Key_Music:
            break;
        case Qt::Key_Battery:
            break;
        case Qt::Key_Bluetooth:
            break;
        case Qt::Key_WLAN:
            break;
        case Qt::Key_UWB:
            break;
        case Qt::Key_AudioForward:
            break;
        case Qt::Key_AudioRepeat:
            break;
        case Qt::Key_AudioRandomPlay:
            break;
        case Qt::Key_Subtitle:
            break;
        case Qt::Key_AudioCycleTrack:
            break;
        case Qt::Key_Time:
            break;
        case Qt::Key_Hibernate:
            break;
        case Qt::Key_View:
            break;
        case Qt::Key_TopMenu:
            break;
        case Qt::Key_PowerDown:
            break;
        case Qt::Key_Suspend:
            break;
        case Qt::Key_ContrastAdjust:
            break;
        case Qt::Key_LaunchG:
            break;
        case Qt::Key_LaunchH:
            break;
        case Qt::Key_TouchpadToggle:
            break;
        case Qt::Key_TouchpadOn:
            break;
        case Qt::Key_TouchpadOff:
            break;
        case Qt::Key_MicMute:
            break;
        case Qt::Key_Red:
            break;
        case Qt::Key_Green:
            break;
        case Qt::Key_Yellow:
            break;
        case Qt::Key_Blue:
            break;
        case Qt::Key_ChannelUp:
            break;
        case Qt::Key_ChannelDown:
            break;
        case Qt::Key_Guide:
            break;
        case Qt::Key_Info:
            break;
        case Qt::Key_Settings:
            break;
        case Qt::Key_MicVolumeUp:
            break;
        case Qt::Key_MicVolumeDown:
            break;
        case Qt::Key_New:
            break;
        case Qt::Key_Open:
            break;
        case Qt::Key_Find:
            break;
        case Qt::Key_Undo:
            break;
        case Qt::Key_Redo:
            break;
        case Qt::Key_MediaLast:
            break;
        case Qt::Key_Select:
            break;
        case Qt::Key_Yes:
            break;
        case Qt::Key_No:
            break;
        case Qt::Key_Cancel:
            break;
        case Qt::Key_Printer:
            break;
        case Qt::Key_Execute:
            break;
        case Qt::Key_Sleep:
            break;
        case Qt::Key_Play:
            break;
        case Qt::Key_Zoom:
            break;
        case Qt::Key_Exit:
            break;
        case Qt::Key_Context1:
            break;
        case Qt::Key_Context2:
            break;
        case Qt::Key_Context3:
            break;
        case Qt::Key_Context4:
            break;
        case Qt::Key_Call:
            break;
        case Qt::Key_Hangup:
            break;
        case Qt::Key_Flip:
            break;
        case Qt::Key_ToggleCallHangup:
            break;
        case Qt::Key_VoiceDial:
            break;
        case Qt::Key_LastNumberRedial:
            break;
        case Qt::Key_Camera:
            break;
        case Qt::Key_CameraFocus:
            break;
        case Qt::Key_unknown:
            break;
// endregion
    }
}