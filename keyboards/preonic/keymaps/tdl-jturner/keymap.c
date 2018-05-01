/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "preonic.h"

/* From /u/cdaotgss : https://www.reddit.com/r/olkb/comments/72u8ou/qmk_mouse_keys_rock/ */
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0

enum preonic_layers {
  _QWERTY,
  _NUMLYR,
  _FUNCLYR,
  _SYSLYR,
  _MSLYR
};

enum preonic_keycodes {
  HELP = SAFE_RANGE,
  BACKLIT,
  CS_BSDEL,
  CS_SLSH,
  CS_DOTQUES,
  CS_COMPIPE,
  NUMLYR,
  FUNCLYR
};

//Tap Dance Declarations
enum {
  TD_LOCK_SLEEP = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_LOCK_SLEEP]  = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_L), KC_SLEP)
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |APPF01|APPF02|APPF03|APPF04|APPF05|APPF06|APPF07|APPF08|APPF09|APPF10|APPF11|APPF12|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | BSPC |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | ;^:  | '^"  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Sft|(|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  ,^| |  .^? | /^\  | Sft|)|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | MOUSE|CTRL|<| OS|[ | ALT|{|NUMLYR| ENTER| SPACE|SYMLYR| ALT|}| OS|] |CTRL|>| LKSLP|
 * `-----------------------------------------------------------------------------------'
 */

[_QWERTY] = {
  {LCAG(KC_F1),LCAG(KC_F2),LCAG(KC_F3),LCAG(KC_F4),LCAG(KC_F5),LCAG(KC_F6),LCAG(KC_F7),LCAG(KC_F8),LCAG(KC_F9),LCAG(KC_F10),LCAG(KC_F11),LCAG(KC_F12)},
  {              KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , CS_BSDEL},
  {              KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT},
  {MT(MOD_LSFT, KC_LPRN), KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , CS_COMPIPE, CS_DOTQUES , CS_SLSH, MT(MOD_RSFT, KC_RPRN)},
  {MO(_MSLYR), MT(MOD_LCTL, KC_LABK),MT(KC_LGUI, KC_LBRC), MT(KC_LALT, KC_LCBR), NUMLYR , KC_ENT , KC_SPC , FUNCLYR , MT(KC_RALT, KC_RCBR), MT(KC_RGUI, KC_RBRC), MT(MOD_LCTL, KC_RABK), TD(TD_LOCK_SLEEP)}
},

/* NUMLYR - Numbers
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  =   |  /   |  *   |  -   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  `   |  1   | 2    | 3    | 4    | 5    | 6    |  7   |  8   |  9   |  0   |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------|------|
 * |      |      |      |      |      |      |      |  4   |  5   |  6   |  +   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  1   |  2   |  3   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+  ENT +------|
 * |      |      |      |      |      |      |      |      0      |  .   |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMLYR] = {
  {_______, _______, _______, _______, _______, _______, _______, KC_PEQL, KC_PSLS, KC_PAST, KC_PMNS, _______ },
  {KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINUS},
  {_______, _______, _______, _______, _______, _______, _______, KC_4   , KC_5   , KC_6   , KC_PPLS, _______ },
  {_______, _______, _______, _______, _______, _______, _______, KC_1   , KC_2   , KC_3   , KC_PENT, _______ },
  {_______, _______, _______, _______, _______, _______, _______, KC_0   , KC_0   , KC_PDOT, KC_PENT, _______ }
},

/* FUNCLYR - Functions
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | PSCR | PGUP | UP   | PGDN |      | VOLU | PREV | STOP | PLAY | NEXT |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SLCK | LEFT | DOWN | RIGHT|      | VOLD | LEFT | DOWN | UP   | RIGHT|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | PAUS | HOME | DEL  | END  | INS  | MUTE |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 */
[_FUNCLYR] = {
  {KC_F1  , KC_F2  , KC_F3   , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10  , KC_F11, KC_F12},
  {KC_PSCR, KC_PGUP, KC_UP  , KC_PGDN , _______, _______, KC_VOLU, KC_MPLY, KC_MNXT, _______, _______, _______},
  {KC_SLCK, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, KC_VOLD, KC_MSTP, KC_MPRV, _______, _______, _______},
  {KC_PAUS, KC_HOME, KC_DEL , KC_END  , KC_INS , _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______ , _______, _______, _______, _______, _______, _______, _______, _______}
},

/* SYSTEM - System Commands
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | RESET|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | TOGG | BL+  | BL-  | BRTG |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 */
[_SYSLYR] = {
  {_______, _______, _______, _______ , _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______ , _______, _______, _______, _______, _______, _______, _______, RESET},
  {_______, _______, _______, _______ , _______, _______, BL_TOGG, BL_INC , BL_DEC , BL_BRTG, _______, _______},
  {_______, _______, _______, _______ , _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______ , _______, _______, _______, _______, _______, _______, _______, _______}
},

/* MOUSE - Mouse Commands
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | MSWH-| MSUP | MSWH+|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | MS_LT|MS_DN | MS_RT|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |ACEL0 |ACEL1 |ACEL2 |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |LTBTN | RTBTN|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 */
[_SYSLYR] = {
  {_______, _______, _______, _______ , _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_WH_U, KC_MS_U, KC_WH_D , _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_MS_L, KC_MS_D, KC_MS_R , _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_ACL0, KC_ACL1, KC_ACL2 , _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______ , _______, KC_BTN1, KC_BTN2, _______, _______, _______, _______, _______}
}

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /* custom shifts example
  switch (keycode) {
    case KC_7:
      if ((record->event.pressed) && (LShiftPressed)) {
        unregister_code(KC_LSFT);
        register_code(KC_QUOT);
      } else {
        unregister_code(KC_QUOT);
        register_code(KC_LSFT);
      }
      return false;
  }*/

  //Custom Shifts
  static bool cshift_mods = false;
  uint8_t cshift_kc = KC_NO;

  //Const for shift
  const uint8_t shift = MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT);

  switch(keycode) {
    case NUMLYR:
      if (record->event.pressed) {
        layer_on(_NUMLYR);
        update_tri_layer(_FUNCLYR, _NUMLYR, _SYSLYR);
      } else {
        layer_off(_NUMLYR);
        update_tri_layer(_FUNCLYR, _NUMLYR, _SYSLYR);
      }
      return false;
      break;
    case FUNCLYR:
      if (record->event.pressed) {
        layer_on(_FUNCLYR);
        update_tri_layer(_FUNCLYR, _NUMLYR, _SYSLYR);
      } else {
        layer_off(_FUNCLYR);
        update_tri_layer(_FUNCLYR, _NUMLYR, _SYSLYR);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        PORTE &= ~(1<<6);
      } else {
        unregister_code(KC_RSFT);
        PORTE |= (1<<6);
      }
      return false;
      break;
    case CS_BSDEL:
      cshift_kc = KC_BSPC;
      if (record->event.pressed) {
        if (keyboard_report->mods & shift) {
          cshift_kc = KC_DEL;
        }
        register_code (cshift_kc);
        cshift_mods = keyboard_report->mods;
      }
      else {
        if (cshift_mods) {
          cshift_kc = KC_DEL;
        }
        unregister_code (cshift_kc);
      }
      return false;
      break;
    case CS_SLSH:
      cshift_kc = KC_SLSH;
      if (record->event.pressed) {
        if (keyboard_report->mods & shift) {
          cshift_kc = KC_BSLASH;
        }
        register_code (cshift_kc);
        cshift_mods = keyboard_report->mods;
      }
      else {
        if (cshift_mods) {
          cshift_kc = KC_BSLASH;
        }
        unregister_code (cshift_kc);
      }
      return false;
      break;
    case CS_DOTQUES:
      cshift_kc = KC_DOT;
      if (record->event.pressed) {
        if (keyboard_report->mods & shift) {
          cshift_kc = KC_SLSH;
          register_code(KC_LSFT);
        }
        register_code (cshift_kc);
        cshift_mods = keyboard_report->mods;
      }
      else {
        if (cshift_mods) {
          cshift_kc = KC_SLSH;
          unregister_code(KC_LSFT);
        }
        unregister_code (cshift_kc);
      }
      return false;
      break;
    case CS_COMPIPE:
      cshift_kc = KC_COMM;
      if (record->event.pressed) {
        if (keyboard_report->mods & shift) {
          cshift_kc = KC_BSLS;
          register_code(KC_LSFT);
        }
        register_code (cshift_kc);
        cshift_mods = keyboard_report->mods;
      }
      else {
        if (cshift_mods) {
          cshift_kc = KC_BSLS;
          unregister_code(KC_LSFT);
        }
        unregister_code (cshift_kc);
      }
      return false;
      break;
    }
    return true;
};
