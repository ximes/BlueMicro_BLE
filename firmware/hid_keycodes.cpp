/*
Copyright 2018-2021 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributsions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
/*
These keycodes are based on Universal Serial Bus HID Usage Tables Document
Version 1.12
Chapter 10: Keyboard/Keypad Page(0x07) - Page 53
https://www.usb.org/sites/default/files/documents/hut1_12v2.pdf
 */

#include "hid_keycodes.h"

char *keynameByKeycode(uint16_t keycode)
{
    switch (keycode)
    {
    case KC_LCTL:
        return "Left Control";
        break; //
               //     case KC_RCTL:
               //         return "Right Control";
               //         break; //
               //     case KC_LSFT:
               //         return "-";
               //         break; //
               //     case KC_RSFT:
               //         return "-";
               //         break; //
               //     case KC_ESC:
               //         return "-";
               //         break; //
               //     case KC_BSPC:
               //         return "-";
               //         break; //
               //     case KC_ENT:
               //         return "-";
               //         break; //
               //     case KC_DEL:
               //         return "-";
               //         break; //
               //     case KC_INS:
               //         return "-";
               //         break; //
               //     case KC_CAPS:
               //         return "-";
               //         break; //
               //     case KC_CLCK:
               //         return "-";
               //         break; //
               //     case KC_RGHT:
               //         return "-";
               //         break; //
               //     case KC_PGDN:
               //         return "-";
               //         break; //
               //     case KC_PSCR:
               //         return "-";
               //         break; //
               //     case KC_SLCK:
               //         return "-";
               //         break; //
               //     case KC_PAUS:
               //         return "-";
               //         break; //
               //     case KC_BRK:
               //         return "-";
               //         break; //
               //     case KC_NLCK:
               //         return "-";
               //         break; //
               //     case KC_SPC:
               //         return "-";
               //         break; //
               //     case KC_MINS:
               //         return "-";
               //         break; //
               //     case KC_EQL:
               //         return "-";
               //         break; //
               //     case KC_GRV:
               //         return "-";
               //         break; //
               //     case KC_RBRC:
               //         return "-";
               //         break; //
               //     case KC_LBRC:
               //         return "-";
               //         break; //
               //     case KC_COMM:
               //         return "-";
               //         break; //
               //     case KC_BSLS:
               //         return "-";
               //         break; //
               //     case KC_SLSH:
               //         return "-";
               //         break; //
               //     case KC_SCLN:
               //         return "-";
               //         break; //
               //     case KC_QUOT:
               //         return "-";
               //         break; //
               //     case KC_APP:
               //         return "-";
               //         break; //
               //     case KC_NUHS:
               //         return "-";
               //         break; //
               //     case KC_NUBS:
               //         return "-";
               //         break; //
               //     case KC_LCAP:
               //         return "-";
               //         break; //
               //     case KC_LNUM:
               //         return "-";
               //         break; //
               //     case KC_LSCR:
               //         return "-";
               //         break; //
               //     case KC_ERAS:
               //         return "-";
               //         break; //
               //     case KC_CLR:
               //         return "-";
               //         break; //
               //     /* Japanese specific */
               //     case KC_ZKHK:
               //         return "-";
               //         break; //
               //     case KC_RO:
               //         return "-";
               //         break; //
               //     case KC_KANA:
               //         return "-";
               //         break; //
               //     case KC_JYEN:
               //         return "-";
               //         break; //
               //     case KC_HENK:
               //         return "-";
               //         break; //
               //     case KC_MHEN:
               //         return "-";
               //         break; //
               //     /* Korean specific */
               //     case KC_HAEN:
               //         return "-";
               //         break; //
               //     case KC_HANJ:
               //         return "-";
               //         break; //
               //     /* Keypad */
               //     case KC_P1:
               //         return "-";
               //         break; //
               //     case KC_P2:
               //         return "-";
               //         break; //
               //     case KC_P3:
               //         return "-";
               //         break; //
               //     case KC_P4:
               //         return "-";
               //         break; //
               //     case KC_P5:
               //         return "-";
               //         break; //
               //     case KC_P6:
               //         return "-";
               //         break; //
               //     case KC_P7:
               //         return "-";
               //         break; //
               //     case KC_P8:
               //         return "-";
               //         break; //
               //     case KC_P9:
               //         return "-";
               //         break; //
               //     case KC_P0:
               //         return "-";
               //         break; //
               //     case KC_PDOT:
               //         return "-";
               //         break; //
               //     case KC_PCMM:
               //         return "-";
               //         break; //
               //     case KC_PSLS:
               //         return "-";
               //         break; //
               //     case KC_PAST:
               //         return "-";
               //         break; //
               //     case KC_PMNS:
               //         return "-";
               //         break; //
               //     case KC_PPLS:
               //         return "-";
               //         break; //
               //     case KC_PEQL:
               //         return "-";
               //         break; //
               //     case KC_PENT:
               //         return "-";
               //         break; //
               //     /* Unix function key */
               //     case KC_EXEC:
               //         return "-";
               //         break; //
               //     case KC_SLCT:
               //         return "-";
               //         break; //
               //     case KC_AGIN:
               //         return "-";
               //         break; //
               //     case KC_PSTE:
               //         return "-";
               //         break; //
               //     /* Mousekey */
               //     case KC_MS_U:
               //         return "-";
               //         break; //
               //     case KC_MS_D:
               //         return "-";
               //         break; //
               //     case KC_MS_L:
               //         return "-";
               //         break; //
               //     case KC_MS_R:
               //         return "-";
               //         break; //
               //     case KC_BTN1:
               //         return "-";
               //         break; //
               //     case KC_BTN2:
               //         return "-";
               //         break; //
               //     case KC_BTN3:
               //         return "-";
               //         break; //
               //     case KC_BTN4:
               //         return "-";
               //         break; //
               //     case KC_BTN5:
               //         return "-";
               //         break; //
               //     case KC_WH_U:
               //         return "-";
               //         break; //
               //     case KC_WH_D:
               //         return "-";
               //         break; //
               //     case KC_WH_L:
               //         return "-";
               //         break; //
               //     case KC_WH_R:
               //         return "-";
               //         break; //
               //     case KC_ACL0:
               //         return "-";
               //         break; //
               //     case KC_ACL1:
               //         return "-";
               //         break; //
               //     case KC_ACL2:
               //         return "-";
               //         break; //
               //     /* Transparent */
               //     case KC_TRANSPARENT:
               //         return "-";
               //         break; //
               //     case KC_TRNS:
               //         return "-";
               //         break; //
               //     /* GUI key aliases */
               //     case KC_LCMD:
               //         return "-";
               //         break; //
               //     case KC_LWIN:
               //         return "-";
               //         break; //
               //     case KC_RCMD:
               //         return "-";
               //         break; //
               //     case KC_RWIN:
               //         return "-";
               //         break; //
               //     case _______:
               //         return "-";
               //         break; //
               //     case XXXXXXX:
               //         return "-";
               //         break; //
               //     case KC_LABK:
               //         return "-";
               //         break; //
               //     case KC_RABK:
               //         return "-";
               //         break; //

        //     case KC_NO:
        //         return "-";
        //         break; //
        //     case KC_ROLL_OVER:
        //         return "-";
        //         break;
        //     case KC_POST_FAIL:
        //         return "-";
        //         break
        //     case KC_UNDEFINED:
        //         return "-";
        //         break
    case KC_A:
        return "A key";
        break;
    case KC_B:
        return "B key";
        break;
    case KC_C:
        return "C key";
        break;
    case KC_D:
        return "D key";
        break;
    case KC_E:
        return "E key";
        break;
    case KC_F:
        return "F key";
        break;
    case KC_G:
        return "G key";
        break;
    case KC_H:
        return "H key";
        break;
    case KC_I:
        return "I key";
        break;
    case KC_J:
        return "J key";
        break;
    case KC_K:
        return "K key";
        break;
    case KC_L:
        return "L key";
        break;
    case KC_M:
        return "M key";
        break;
    case KC_N:
        return "N key";
        break;
    case KC_O:
        return "O key";
        break;
    case KC_P:
        return "P key";
        break;
    case KC_Q:
        return "Q key";
        break;
    case KC_R:
        return "R key";
        break;
    case KC_S:
        return "S key";
        break;
    case KC_T:
        return "T key";
        break;
    case KC_U:
        return "U key";
        break;
    case KC_V:
        return "V key";
        break;
    case KC_W:
        return "W key";
        break;
    case KC_X:
        return "X key";
        break;
    case KC_Y:
        return "Y key";
        break;
    case KC_Z:
        return "Z key";
        break;
    case KC_1:
        return "1 key";
        break;
    case KC_2:
        return "2 key";
        break;
    case KC_3:
        return "3 key";
        break;
    case KC_4:
        return "4 key";
        break;
    case KC_5:
        return "5 key";
        break;
    case KC_6:
        return "6 key";
        break;
    case KC_7:
        return "7 key";
        break;
    case KC_8:
        return "8 key";
        break;
    case KC_9:
        return "9 key";
        break;
    case KC_0:
        return "0 key";
        break;
    case KC_ENTER:
        return "Enter";
        break;
    case KC_ESCAPE:
        return "ESC key";
        break;
    case KC_BSPACE:
        return "Backspace";
        break;
    case KC_TAB:
        return "Tab key";
        break;
    case KC_SPACE:
        return "Space key";
        break;
    case KC_MINUS:
        return "- key";
        break;
    case KC_EQUAL:
        return "= key";
        break;
        //     case KC_LBRACKET:
        //         return "-";
        //         break
        //     case KC_RBRACKET:
        //         return "-";
        //         break;
        //     case KC_BSLASH:
        //         return "-";
        //         break;
        //     case KC_NONUS_HASH:
        //         return "-";
        //         break;
    case KC_SCOLON:
        return "; key";
        break;
    case KC_QUOTE:
        return "' key";
        break;
    case KC_GRAVE:
        return "-";
        break;
    case KC_COMMA:
        return ", key";
        break;
    case KC_DOT:
        return ". key";
        break;
    case KC_SLASH:
        return "/ key";
        break;
        //     case KC_CAPSLOCK:
        //         return "-";
        //         break
        //     case KC_F1:
        //         return "-";
        //         break
        //     case KC_F2:
        //         return "-";
        //         break
        //     case KC_F3:
        //         return "-";
        //         break
        //     case KC_F4:
        //         return "-";
        //         break
        //     case KC_F5:
        //         return "-";
        //         break
        //     case KC_F6:
        //         return "-";
        //         break
        //     case KC_F7:
        //         return "-";
        //         break;
        //     case KC_F8:
        //         return "-";
        //         break
        //     case KC_F9:
        //         return "-";
        //         break
        //     case KC_F10:
        //         return "-";
        //         break
        //     case KC_F11:
        //         return "-";
        //         break
        //     case KC_F12:
        //         return "-";
        //         break
        //     case KC_PSCREEN:
        //         return "-";
        //         break
        //     case KC_SCROLLLOCK:
        //         return "-";
        //         break
        //     case KC_PAUSE:
        //         return "-";
        //         break
        //     case KC_INSERT:
        //         return "-";
        //         break
        //     case KC_HOME:
        //         return "-";
        //         break
        //     case KC_PGUP:
        //         return "-";
        //         break
        //     case KC_DELETE:
        //         return "-";
        //         break
        //     case KC_END:
        //         return "-";
        //         break
        //     case KC_PGDOWN:
        //         return "-";
        //         break
    case KC_RIGHT:
        return "Right Arrow";
        break;
    case KC_LEFT:
        return "Left Arrow";
        break;
    case KC_DOWN:
        return "Down arrow";
        break;
    case KC_UP:
        return "Up arrow";
        break;
    // case KC_KP_LT:
    //     return "< key";
    //     break;
    // case KC_KP_GT:
    //     return "> key";
    //     break;
    case KC_VOLUP:
        return "Volume Up";
        break;
    case KC_VOLDOWN:
        return "Volume Down";
        break;
    //     case KC_NUMLOCK:
    //         return "-";
    //         break
    //     case KC_KP_SLASH:
    //         return "-";
    //         break
    //     case KC_KP_ASTERISK:
    //         return "-";
    //         break
    //     case KC_KP_MINUS:
    //         return "-";
    //         break
    //     case KC_KP_PLUS:
    //         return "-";
    //         break
    //     case KC_KP_ENTER:
    //         return "-";
    //         break
    //     case KC_KP_1:
    //         return "-";
    //         break
    //     case KC_KP_2:
    //         return "-";
    //         break
    //     case KC_KP_3:
    //         return "-";
    //         break
    //     case KC_KP_4:
    //         return "-";
    //         break
    //     case KC_KP_5:
    //         return "-";
    //         break
    //     case KC_KP_6:
    //         return "-";
    //         break
    //     case KC_KP_7:
    //         return "-";
    //         break
    //     case KC_KP_8:
    //         return "-";
    //         break;
    //     case KC_KP_9:
    //         return "-";
    //         break
    //     case KC_KP_0:
    //         return "-";
    //         break
    //     case KC_KP_DOT:
    //         return "-";
    //         break
    //     case KC_NONUS_BSLASH:
    //         return "-";
    //         break
    // /* Non-US \ and | (Typically near the Left-Shift key) */
    //     case KC_APPLICATION:
    //         return "-";
    //         break
    //     case KC_POWER:
    //         return "-";
    //         break
    //     case KC_KP_EQUAL:
    //         return "-";
    //         break
    //     case KC_F13:
    //         return "-";
    //         break
    //     case KC_F14:
    //         return "-";
    //         break
    //     case KC_F15:
    //         return "-";
    //         break
    //     case KC_F16:
    //         return "-";
    //         break
    //     case KC_F17:
    //         return "-";
    //         break
    //     case KC_F18:
    //         return "-";
    //         break
    //     case KC_F19:
    //         return "-";
    //         break
    //     case KC_F20:
    //         return "-";
    //         break
    //     case KC_F21:
    //         return "-";
    //         break;
    //     case KC_F22:
    //         return "-";
    //         break
    //     case KC_F23:
    //         return "-";
    //         break
    //     case KC_F24:
    //         return "-";
    //         break
    //     case KC_EXECUTE:
    //         return "-";
    //         break
    //     case KC_HELP:
    //         return "-";
    //         break
    //     case KC_MENU:
    //         return "-";
    //         break
    //     case KC_SELECT:
    //         return "-";
    //         break
    //     case KC_STOP:
    //         return "-";
    //         break
    //     case KC_AGAIN:
    //         return "-";
    //         break
    //     case KC_UNDO:
    //         return "-";
    //         break
    //     case KC_CUT:
    //         return "-";
    //         break
    //     case KC_COPY:
    //         return "-";
    //         break
    //     case KC_PASTE:
    //         return "-";
    //         break
    //     case KC_FIND:
    //         return "-";
    //         break
    //     case KC_MUTE:
    //         return "-";
    //         break
        //     case KC_LOCKING_CAPS:
        //         return "-";
        //         break;
        //     case KC_LOCKING_NUM:
        //         return "-";
        //         break;
        //     case KC_LOCKING_SCROLL:
        //         return "-";
        //         break

        //     /* locking Scroll Lock */
        //     case KC_KP_COMMA:
        //         return "-";
        //         break
        //     case KC_KP_EQUAL_AS400:
        //         return "-";
        //         break

        //     /* equal sign on AS/400 */
        //     case KC_INT1:
        //         return "-";
        //         break
        //     case KC_INT2:
        //         return "-";
        //         break
        //     case KC_INT3:
        //         return "-";
        //         break
        //     case KC_INT4:
        //         return "-";
        //         break
        //     case KC_INT5:
        //         return "-";
        //         break
        //     case KC_INT6:
        //         return "-";
        //         break
        //     case KC_INT7:
        //         return "-";
        //         break
        //     case KC_INT8:
        //         return "-";
        //         break
        //     case KC_INT9:
        //         return "-";
        //         break
        //     case KC_LANG1:
        //         return "-";
        //         break;
        //     case KC_LANG2:
        //         return "-";
        //         break
        //     case KC_LANG3:
        //         return "-";
        //         break
        //     case KC_LANG4:
        //         return "-";
        //         break
        //     case KC_LANG5:
        //         return "-";
        //         break
        //     case KC_LANG6:
        //         return "-";
        //         break
        //     case KC_LANG7:
        //         return "-";
        //         break
        //     case KC_LANG8:
        //         return "-";
        //         break
        //     case KC_LANG9:
        //         return "-";
        //         break
        //     case KC_ALT_ERASE:
        //         return "-";
        //         break
        //     case KC_SYSREQ:
        //         return "-";
        //         break
        //     case KC_CANCEL:
        //         return "-";
        //         break
        //     case KC_CLEAR:
        //         return "-";
        //         break
        //     case KC_PRIOR:
        //         return "-";
        //         break
        //     case KC_RETURN:
        //         return "-";
        //         break
        //     case KC_SEPARATOR:
        //         return "-";
        //         break
        //     case KC_OUT:
        //         return "-";
        //         break;
        //     case KC_OPER:
        //         return "-";
        //         break
        //     case KC_CLEAR_AGAIN:
        //         return "-";
        //         break
        //     case KC_CRSEL:
        //         return "-";
        //         break
        //     case KC_EXSEL:
        //         return "-";
        //         break;

        //     case KC_RESERVED_A5:
        //         return "-";
        //         break

        //         /*0xA5 to 0xAF - RESERVED*/ // Used as macro identifier
        //     case KC_RESERVED_A6:
        //         return "-";
        //         break

        //         // this is used for special keyboard functions
        //     case KC_RESERVED_A7:
        //         return "-";
        //         break
        //     case KC_RESERVED_A8:
        //         return "-";
        //         break
        //     case KC_RESERVED_A9:
        //         return "-";
        //         break
        //     case KC_RESERVED_AA:
        //         return "-";
        //         break
        //     case KC_RESERVED_AB:
        //         return "-";
        //         break
        //     case KC_RESERVED_AC:
        //         return "-";
        //         break
        //     case KC_RESERVED_AD:
        //         return "-";
        //         break
        //     case KC_RESERVED_AE:
        //         return "-";
        //         break
        //     case KC_RESERVED_AF:
        //         return "-";
        //         break

        //     /* NOTE: Following codes(0xB0-DD) are not used but are in the HID Document. Leaving them for reference. */
        //     case KC_KP_00:
        //         return "-";
        //         break; //            = 0xB0,
        //     case KC_KP_000:
        //         return "-";
        //         break
        //     case KC_THOUSANDS_SEPARATOR:
        //         return "-";
        //         break
        //     case KC_DECIMAL_SEPARATOR:
        //         return "-";
        //         break
        //     case KC_CURRENCY_UNIT:
        //         return "-";
        //         break
        //     case KC_CURRENCY_SUB_UNIT:
        //         return "-";
        //         break
        //     case KC_KP_RPAREN:
        //         return "-";
        //         break; //
        //     case KC_KP_LCBRACKET:
        //         return "-";
        //         break;
        //     case KC_KP_RCBRACKET:
        //         return "-";
        //         break;
        //     case KC_KP_TAB:
        //         return "-";
        //         break
        //     case KC_KP_BSPACE:
        //         return "-";
        //         break
        //     case KC_KP_A:
        //         return "-";
        //         break
        //     case KC_KP_B:
        //         return "-";
        //         break
        //     case KC_KP_C:
        //         return "-";
        //         break
        //     case KC_KP_D:
        //         return "-";
        //         break
        //     case KC_KP_E:
        //         return "-";
        //         break;
        //     case KC_KP_F:
        //         return "-";
        //         break
        //     case KC_KP_XOR:
        //         return "-";
        //         break
        //     case KC_KP_HAT:
        //         return "-";
        //         break
        //     case KC_KP_PERC:
        //         return "-";
        //         break
        //     case KC_KP_AND:
        //         return "-";
        //         break
        //     case KC_KP_LAZYAND:
        //         return "-";
        //         break
        //     case KC_KP_OR:
        //         return "-";
        //         break
        //     case KC_KP_LAZYOR:
        //         return "-";
        //         break
        //     case KC_KP_COLON:
        //         return "-";
        //         break
        //     case KC_KP_HASH:
        //         return "-";
        //         break
        //     case KC_KP_SPACE:
        //         return "-";
        //         break
        //     case KC_KP_ATMARK:
        //         return "-";
        //         break
        //     case KC_KP_EXCLAMATION:
        //         return "-";
        //         break
        //     case KC_KP_MEM_STORE:
        //         return "-";
        //         break;
        //     case KC_KP_MEM_RECALL:
        //         return "-";
        //         break
        //     case KC_KP_MEM_CLEAR:
        //         return "-";
        //         break
        //     case KC_KP_MEM_ADD:
        //         return "-";
        //         break
        //     case KC_KP_MEM_SUB:
        //         return "-";
        //         break
        //     case KC_KP_MEM_MUL:
        //         return "-";
        //         break
        //     case KC_KP_MEM_DIV:
        //         return "-";
        //         break
        //     case KC_KP_PLUS_MINUS:
        //         return "-";
        //         break
        //     case KC_KP_CLEAR:
        //         return "-";
        //         break
        //     case KC_KP_CLEAR_ENTRY:
        //         return "-";
        //         break
        //     case KC_KP_BINARY:
        //         return "-";
        //         break
        //     case KC_KP_OCTAL:
        //         return "-";
        //         break
        //     case KC_KP_DECIMAL:
        //         return "-";
        //         break
        //     case KC_KP_HEXADECIMAL:
        //         return "-";
        //         break;

        //     /* Modifiers */
        //     case KC_LCTRL:
        //         return "-";
        //         break; //            = 0xE0,
        //     case KC_LSHIFT:
        //         return "-";
        //         break
        //     case KC_LALT:
        //         return "-";
        //         break
        //     case KC_LGUI:
        //         return "-";
        //         break
        //     case KC_RCTRL:
        //         return "-";
        //         break
        //     case KC_RSHIFT:
        //         return "-";
        //         break
        //     case KC_RALT:
        //         return "-";
        //         break
        //     case KC_RGUI:
        //         return "-";
        //         break
        //     case LAYER_0:
        //         return "-";
        //         break; //
            // case LAYER_1:
            //     return "Toggle Layer";
            //     break; //
        //     case LAYER_2:
        //         return "-";
        //         break; //
        //     case LAYER_3:
        //         return "-";
        //         break; //
        //     case LAYER_4:
        //         return "-";
        //         break; //
        //     case LAYER_5:
        //         return "-";
        //         break; //
        //     case LAYER_6:
        //         return "-";
        //         break; //
        //     case LAYER_7:
        //         return "-";
        //         break; //
        //     case LAYER_8:
        //         return "-";
        //         break; //
        //     case LAYER_9:
        //         return "-";
        //         break; //
        //     case LAYER_A:
        //         return "-";
        //         break; //
        //     case LAYER_B:
        //         return "-";
        //         break; //
        //     case LAYER_C:
        //         return "-";
        //         break; //
        //     case LAYER_D:
        //         return "-";
        //         break; //
        //     case LAYER_E:
        //         return "-";
        //         break; //
        //     case LAYER_F:
        //         return "-";
        //         break; //
        //     case RESET:
        //         return "-";
        //         break; //
        //     case DEBUG:
        //         return "-";
        //         break; //
        //     case EEPROM_RESET:
        //         return "-";
        //         break; //
        //     case EEP_RST:
        //         return "-";
        //         break; //
        //     case DFU:
        //         return "-";
        //         break; //
        //     case SERIAL_DFU:
        //         return "-";
        //         break; //
        //     case UF2_DFU:
        //         return "-";
        //         break; //
        //     case CLEAR_BONDS:
        //         return "-";
        //         break; //
        //     case BL_TOGG:
        //         return "-";
        //         break; //
        //     case BL_STEP:
        //         return "-";
        //         break; //
        //     case BL_ON:
        //         return "-";
        //         break; //
        //     case BL_OFF:
        //         return "-";
        //         break; //
        //     case BL_INC:
        //         return "-";
        //         break; //
        //     case BL_DEC:
        //         return "-";
        //         break; //
        //     case BL_BRTG:
        //         return "-";
        //         break; //
        //     case BL_REACT:
        //         return "-";
        //         break; //
        //     case BL_STEPINC:
        //         return "-";
        //         break; //
        //     case BL_STEPDEC:
        //         return "-";
        //         break; //
        //     case OUT_AUTO:
        //         return "-";
        //         break; //
        //     case OUT_USB:
        //         return "-";
        //         break; //
        //     case OUT_BT:
        //         return "-";
        //         break; //
        //     case RGB_TOG:
        //         return "-";
        //         break; //
        //     case RGB_MODE_FORWARD:
        //         return "-";
        //         break; //
        //     case RGB_MOD:
        //         return "-";
        //         break; //
        //     case RGB_MODE_REVERSE:
        //         return "-";
        //         break; //
        //     case RGB_RMOD:
        //         return "-";
        //         break; //
        //     case RGB_HUI:
        //         return "-";
        //         break; //
        //     case RGB_HUD:
        //         return "-";
        //         break; //
        //     case RGB_SAI:
        //         return "-";
        //         break; //
        //     case RGB_SAD:
        //         return "-";
        //         break; //
        //     case RGB_VAI:
        //         return "-";
        //         break; //
        //     case RGB_VAD:
        //         return "-";
        //         break; //
        //     case RGB_MODE_PLAIN:
        //         return "-";
        //         break; //
        //     case RGB_M_P:
        //         return "-";
        //         break; //
        //     case RGB_MODE_NIGHT:
        //         return "-";
        //         break; //
        //     case RGB_M_N:
        //         return "-";
        //         break; //
        //     case RGB_MODE_HELP:
        //         return "-";
        //         break; //
        //     case RGB_M_H:
        //         return "-";
        //         break; //
        //     case RGB_MODE_BREATHE:
        //         return "-";
        //         break; //
        //     case RGB_M_B:
        //         return "-";
        //         break; //
        //     case RGB_MODE_RAINBOW:
        //         return "-";
        //         break; //
        //     case RGB_M_R:
        //         return "-";
        //         break; //
        //     case RGB_MODE_SWIRL:
        //         return "-";
        //         break; //
        //     case RGB_M_SW:
        //         return "-";
        //         break; //
        //     case RGB_MODE_SNAKE:
        //         return "-";
        //         break; //
        //     case RGB_M_SN:
        //         return "-";
        //         break; //
        //     case RGB_MODE_KNIGHT:
        //         return "-";
        //         break; //
        //     case RGB_M_K:
        //         return "-";
        //         break; //
        //     case RGB_MODE_XMAS:
        //         return "-";
        //         break; //
        //     case RGB_M_X:
        //         return "-";
        //         break; //
        //     case RGB_MODE_GRADIENT:
        //         return "-";
        //         break; //
        //     case RGB_M_G:
        //         return "-";
        //         break; //
        //     case RGB_MODE_RGBTEST:
        //         return "-";
        //         break; //
        //     case RGB_M_T:
        //         return "-";
        //         break; //
        //     case RGB_SPI:
        //         return "-";
        //         break; //
        //     case RGB_SPD:
        //         return "-";
        //         break; //
        //     case PRINT_BATTERY:
        //         return "-";
        //         break; //
        //     case PRINT_INFO:
        //         return "-";
        //         break; //
        //     case PRINT_BLE:
        //         return "-";
        //         break; //
        //     case PRINT_HELP:
        //         return "-";
        //         break; //
        //     case BLEPROFILE_1:
        //         return "-";
        //         break; //
        //     case BLEPROFILE_2:
        //         return "-";
        //         break; //
        //     case BLEPROFILE_3:
        //         return "-";
        //         break; //
        //     case SLEEP_NOW:
        //         return "-";
        //         break; //
            // case HELP_MODE:
            //     return "Help mode";
            //     break; //
        //     case BATTERY_CALC_DEFAULT:
        //         return "-";
        //         break; //
        //     case BATTERY_CALC_TEST:
        //         return "-";
        //         break; //
        //     case BATTERY_CALC_FILTERED:
        //         return "-";
        //         break; //

        //     // Power Control
        //     case KC_SYSTEM_POWER:
        //         return "-";
        //         break; //
        //     case KC_SYSTEM_RESET:
        //         return "-";
        //         break; //
        //     case KC_SYSTEM_SLEEP:
        //         return "-";
        //         break; //

        //     // Screen Brightness
        //     case KC_DISPLAY_BRIGHTI:
        //         return "-";
        //         break; //
        //     case KC_DISPLAY_BRIGHTD:
        //         return "-";
        //         break; //

        //     // These HID usages operate only on mobile systems (battery powered) and
        //     // require Windows 8 (build 8302 or greater).
        //     case KC_RADIO_CONTROL:
        //         return "-";
        //         break; //
        //     case KC_RADIO_BUTTONS:
        //         return "-";
        //         break; //
        //     case KC_RADIO_LED:
        //         return "-";
        //         break; //
        //     case KC_RADIO_SWITCH:
        //         return "-";
        //         break; //

        //     // Media Control
        //     case KC_MEDIA_PLAY_PAUSE:
        //         return "-";
        //         break; //
        //     case KC_MEDIA_NEXT_TRACK:
        //         return "-";
        //         break; //
        //     case KC_MEDIA_PREV_TRACK:
        //         return "-";
        //         break; //
        //     case KC_MEDIA_STOP:
        //         return "-";
        //         break; //
        //     case KC_AUDIO_VOL:
        //         return "-";
        //         break; //
        //     case KC_AUDIO_MUTE:
        //         return "-";
        //         break; //
        //     case KC_AUDIO_BASS:
        //         return "-";
        //         break; //
        //     case KC_AUDIO_TREBLE:
        //         return "-";
        //         break; //
        //     case KC_AUDIO_BASS_BOOST:
        //         return "-";
        //         break; //
        //     case KC_AUDIO_VOL_UP:
        //         return "-";
        //         break; //
        //     case KC_AUDIO_VOL_DOWN:
        //         return "-";
        //         break; //
        //     case KC_AUDIO_BASS_UP:
        //         return "-";
        //         break; //
        //     case KC_AUDIO_BASS_DOWN:
        //         return "-";
        //         break; //
        //     case KC_AUDIO_TREBLE_UP:
        //         return "-";
        //         break; //
        //     case KC_AUDIO_TREBLE_DOWN:
        //         return "-";
        //         break; //

        //     // Application Launcher
        //     case KC_MSEL:
        //         return "-";
        //         break; //
        //     case KC_WWW:
        //         return "-";
        //         break; //
        //     case KC_MAIL:
        //         return "-";
        //         break; //
        //     case KC_CALCULATOR:
        //         return "-";
        //         break; //
        //     case KC_MYCM:
        //         return "-";
        //         break; //

        //     // Browser/Explorer Specific
        //     case KC_WWW_SEARCH:
        //         return "-";
        //         break; //
        //     case KC_WWW_HOME:
        //         return "-";
        //         break; //
        //     case KC_WWW_BACK:
        //         return "-";
        //         break; //
        //     case KC_WWW_FORWARD:
        //         return "-";
        //         break; //
        //     case KC_WWW_STOP:
        //         return "-";
        //         break; //
        //     case KC_WWW_REFRESH:
        //         return "-";
        //         break; //
        //     case KC_WWW_FAVORITES:
        //         return "-";
        //         break; //

        //     // Mouse Horizontal scroll
        //     case KC_AC_PAN:
        //         return "-";
        //         break; //
        //     case KC_PWR:
        //         return "-";
        //         break; //
        //     case KC_SLEP:
        //         return "-";
        //         break; //
        //     case KC_MUTE:
        //         return "-";
        //         break; //
        //     case KC_VOLU:
        //         return "-";
        //         break; //
        //     case KC_VOLD:
        //         return "-";
        //         break; //
        //     case KC_MNXT:
        //         return "-";
        //         break; //
        //     case KC_MPRV:
        //         return "-";
        //         break; //
        //     case KC_MSTP:
        //         return "-";
        //         break; //
        //     case KC_MPLY:
        //         return "-";
        //         break; //
        //     case KC_CALC:
        //         return "-";
        //         break; //
        //     case KC_WSCH:
        //         return "-";
        //         break; //
        //     case KC_WHOM:
        //         return "-";
        //         break; //
        //     case KC_WBAK:
        //         return "-";
        //         break; //
        //     case KC_WFWD:
        //         return "-";
        //         break; //
        //     case KC_WSTP:
        //         return "-";
        //         break; //
        //     case KC_WREF:
        //         return "-";
        //         break; //
        //     case KC_WFAV:
        //         return "-";
        //         break; //

        //     // Mouse keycodes...
        //     case KC_MS_OFF:
        //         return "-";
        //         break; //
        //     case KC_MS_UP:
        //         return "-";
        //         break; //
        //     case KC_MS_DOWN:
        //         return "-";
        //         break; //
        //     case KC_MS_LEFT:
        //         return "-";
        //         break; //
        //     case KC_MS_RIGHT:
        //         return "-";
        //         break; //
        //     case KC_MS_BTN1:
        //         return "-";
        //         break; //
        //     case KC_MS_BTN2:
        //         return "-";
        //         break; //
        //     case KC_MS_BTN3:
        //         return "-";
        //         break; //
        //     case KC_MS_BTN4:
        //         return "-";
        //         break; //
        //     case KC_MS_BTN5:
        //         return "-";
        //         break; //
        //     case KC_MS_WH_UP:
        //         return "-";
        //         break; //
        //     case KC_MS_WH_DOWN:
        //         return "-";
        //         break; //
        //     case KC_MS_WH_DN:
        //         return "-";
        //         break; //
        //     case KC_MS_WH_LEFT:
        //         return "-";
        //         break; //
        //     case KC_MS_WH_RIGHT:
        //         return "-";
        //         break; //
        //     case KC_MS_ACCEL0:
        //         return "-";
        //         break; //
        //     case KC_MS_ACCEL1:
        //         return "-";
        //         break; //
        //     case KC_MS_ACCEL2:
        //         return "-";
        //         break; //

        //     // these international characters work on windows
        //     case WIN_A_GRAVE:
        //         return "-";
        //         break; //
        //     case WIN_A_ACUTE:
        //         return "-";
        //         break; //
        //     case WIN_A_CIRCU:
        //         return "-";
        //         break; //
        //     case WIN_A_TILDE:
        //         return "-";
        //         break; //
        //     case WIN_A_UMLAU:
        //         return "-";
        //         break; //
        //     case WIN_A_GRAVE_CAP:
        //         return "-";
        //         break; //
        //     case WIN_A_ACUTE_CAP:
        //         return "-";
        //         break; //
        //     case WIN_A_CIRCU_CAP:
        //         return "-";
        //         break; //
        //     case WIN_A_TILDE_CAP:
        //         return "-";
        //         break; //
        //     case WIN_A_UMLAU_CAP:
        //         return "-";
        //         break; //
        //     case WIN_C_CEDIL:
        //         return "-";
        //         break; //
        //     case WIN_C_CEDIL_CAP:
        //         return "-";
        //         break; //
        //     case WIN_E_GRAVE:
        //         return "-";
        //         break; //
        //     case WIN_E_ACUTE:
        //         return "-";
        //         break; //
        //     case WIN_E_CIRCU:
        //         return "-";
        //         break; //
        //     case WIN_E_UMLAU:
        //         return "-";
        //         break; //
        //     case WIN_E_GRAVE_CAP:
        //         return "-";
        //         break; //
        //     case WIN_E_ACUTE_CAP:
        //         return "-";
        //         break; //
        //     case WIN_E_CIRCU_CAP:
        //         return "-";
        //         break; //
        //     case WIN_E_UMLAU_CAP:
        //         return "-";
        //         break; //
        //     case WIN_I_GRAVE:
        //         return "-";
        //         break; //
        //     case WIN_I_ACUTE:
        //         return "-";
        //         break; //
        //     case WIN_I_CIRCU:
        //         return "-";
        //         break; //
        //     case WIN_I_UMLAU:
        //         return "-";
        //         break; //
        //     case WIN_I_GRAVE_CAP:
        //         return "-";
        //         break; //
        //     case WIN_I_ACUTE_CAP:
        //         return "-";
        //         break; //
        //     case WIN_I_CIRCU_CAP:
        //         return "-";
        //         break; //
        //     case WIN_I_UMLAU_CAP:
        //         return "-";
        //         break; //
        //     case WIN_N_TILDE:
        //         return "-";
        //         break; //
        //     case WIN_N_TILDE_CAP:
        //         return "-";
        //         break; //
        //     case WIN_O_GRAVE:
        //         return "-";
        //         break; //
        //     case WIN_O_ACUTE:
        //         return "-";
        //         break; //
        //     case WIN_O_CIRCU:
        //         return "-";
        //         break; //
        //     case WIN_O_TILDE:
        //         return "-";
        //         break; //
        //     case WIN_O_UMLAU:
        //         return "-";
        //         break; //
        //     case WIN_O_GRAVE_CAP:
        //         return "-";
        //         break; //
        //     case WIN_O_ACUTE_CAP:
        //         return "-";
        //         break; //
        //     case WIN_O_CIRCU_CAP:
        //         return "-";
        //         break; //
        //     case WIN_O_TILDE_CAP:
        //         return "-";
        //         break; //
        //     case WIN_O_UMLAU_CAP:
        //         return "-";
        //         break; //
        //     case WIN_S_CARON:
        //         return "-";
        //         break; //
        //     case WIN_S_CARON_CAP:
        //         return "-";
        //         break; //
        //     case WIN_U_GRAVE:
        //         return "-";
        //         break; //
        //     case WIN_U_ACUTE:
        //         return "-";
        //         break; //
        //     case WIN_U_CIRCU:
        //         return "-";
        //         break; //
        //     case WIN_U_UMLAU:
        //         return "-";
        //         break; //
        //     case WIN_U_GRAVE_CAP:
        //         return "-";
        //         break; //
        //     case WIN_U_ACUTE_CAP:
        //         return "-";
        //         break; //
        //     case WIN_U_CIRCU_CAP:
        //         return "-";
        //         break; //
        //     case WIN_U_UMLAU_CAP:
        //         return "-";
        //         break; //
        //     case WIN_Y_ACUTE:
        //         return "-";
        //         break; //
        //     case WIN_Y_UMLAU:
        //         return "-";
        //         break; //
        //     case WIN_Y_ACUTE_CAP:
        //         return "-";
        //         break; //
        //     case WIN_Y_UMLAU_CAP:
        //         return "-";
        //         break; //
        //     case WIN_Z_CARON:
        //         return "-";
        //         break; //
        //     case WIN_Z_CARON_CAP:
        //         return "-";
        //         break; //
        //     case SYM_DEGREE:
        //         return "-";
        //         break;
    }

    return ".";
}