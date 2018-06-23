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

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _LYMD,
  _LYFK,
  _LYMED,
  _LYNUM,
  _LYNAV,
  _LYMOS,
  _LYSYS,
  _LYLT
};

enum planck_keycodes {
  HELP = SAFE_RANGE,
  KC_BSDEL,
  KC_FBSLH,
  KC_DOTQ,
  KC_CPIPE,
  COLEMAK,
  QWERTY,
  KC_LYDEF
};


//Tap Dance Declarations
enum {
  TD_LOCK_SLEEP,
  TD_ABK,
  TD_BRC,
  TD_CBR,
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_LOCK_SLEEP]  = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_L), KC_SLEP),
  [TD_ABK] = ACTION_TAP_DANCE_DOUBLE(KC_LABK,KC_RABK),
  [TD_BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC,KC_RBRC),
  [TD_CBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR,KC_RCBR)
// Other declarations would go here, separated by commas, if you have them
};

//remaps for pretty layouts
#define ________ KC_TRNS
#define ___XX___ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  //QWERY - Base Layer
  [_QWERTY] = {
          {KC_TAB ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,  KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  ,KC_BSDEL}, //Custom shift Codes. Backspace ^ Delete
 {LT(_LYMD,KC_ESC),  KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G  ,  KC_H  ,  KC_J  ,  KC_K  ,  KC_L  ,KC_SCLN ,KC_QUOT },
          {KC_LSPO,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,  KC_N  ,  KC_M  ,KC_CPIPE,KC_DOTQ ,KC_FBSLH,KC_RSPC }, // Custom Shift Codes. ,^| .^?  /^|
       { KC_MEH ,KC_LCTL ,KC_LGUI ,KC_LALT ,MO(_LYNUM), KC_SPC , KC_ENT ,MO(_LYNAV),TD(TD_CBR) ,TD(TD_BRC),TD(TD_ABK),TD(TD_LOCK_SLEEP)}

  },

  //_COLEMAK - Colemak Layout - Identical to qwerty layer except for the layout changes
  [_COLEMAK] = {
          {KC_TAB ,  KC_Q  ,  KC_W  ,  KC_F  ,  KC_P  ,  KC_G  ,  KC_J  ,  KC_L  ,  KC_U  ,  KC_Y  ,KC_SCLN ,KC_BSDEL}, //Custom shift Codes. Backspace ^ Delete
 {LT(_LYMD,KC_ESC),  KC_A  ,  KC_R  ,  KC_S  ,  KC_T  ,  KC_D  ,  KC_H  ,  KC_N  ,  KC_E  ,  KC_I  ,  KC_O  ,KC_QUOT },
          {KC_LSPO,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,  KC_K  ,  KC_M  ,KC_CPIPE,KC_DOTQ ,KC_FBSLH,KC_RSPC }, // Custom Shift Codes. ,^| .^?  /^|
      {  KC_MEH ,KC_LCTL ,KC_LGUI ,KC_LALT ,MO(_LYNUM), KC_SPC , KC_ENT ,MO(_LYNAV),TD(TD_CBR) ,TD(TD_BRC),TD(TD_ABK),TD(TD_LOCK_SLEEP)}

  },

  // Decision Layer
  [_LYMD] =
     {
        {________,MO(_LYFK) ,MO(_LYMED),________  ,________,________,___XX___,___XX___,___XX___,___XX___,___XX___,________},
        {________,MO(_LYNUM),MO(_LYNAV),________  ,________,________,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___},
        {________,MO(_LYMOS),MO(_LYSYS),MO(_LYLT) ,________,________,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___},
        {________,________  ,________  ,________  ,________,________,________,___XX___,___XX___,___XX___,___XX___,___XX___}
      },

  //F Keys
  [_LYFK] =
     {
       {KC_LYDEF,________,________,________,________,________,___XX___,KC_F7   ,KC_F8   ,KC_F9   ,KC_F12  ,________},
       {________,________,________,________,________,________,___XX___,KC_F4   ,KC_F5   ,KC_F6   ,KC_F11  ,___XX___},
       {________,________,________,________,________,________,___XX___,KC_F1   ,KC_F2   ,KC_F3   ,KC_F10  ,___XX___},
       {________,________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,___XX___}
     },
 //Media Keys
 [_LYMED] =
    {
      {KC_LYDEF,________,________,________,________,________,___XX___,___XX___,KC_VOLU ,___XX___,___XX___,________},
      {________,________,________,________,________,________,___XX___,KC_MPRV ,KC_MUTE ,KC_MNXT ,___XX___,___XX___},
      {________,________,________,________,________,________,___XX___,___XX___,KC_VOLD ,___XX___,KC_MSTP ,___XX___},
      {________,________,________,________,________,________,___XX___,KC_MPLY ,___XX___,___XX___,___XX___,___XX___}
    },
 //Num Keys
 [_LYNUM] =
   {
     {KC_GRV  ,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,  KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  ,KC_MINUS},
     {________,________,________,________,________,________,___XX___,KC_4    ,KC_5    ,KC_6    ,KC_PPLS ,KC_PSLS },
     {________,________,________,________,________,________,___XX___,KC_1    ,KC_2    ,KC_3    ,KC_PENT ,KC_PAST },
     {________,________,________,________,________,________,________,KC_0    ,KC_0    ,KC_PDOT ,KC_PEQL ,___XX___}
   },
 //Navigation Keys
 [_LYNAV] =
  {
    {KC_LYDEF,________,________,________,________,________,___XX___,KC_HOME ,KC_UP   ,KC_PGUP ,KC_PSCR ,________},
    {________,________,________,________,________,________,___XX___,KC_LEFT ,KC_F5   ,KC_RIGHT,KC_SLCK ,___XX___},
    {________,________,________,________,________,________,___XX___,KC_END  ,KC_DOWN ,KC_PGDN ,KC_PAUS ,___XX___},
    {________,________,________,________,________,________,________,________,KC_INS  ,KC_DEL  ,___XX___,___XX___}
  },
  //Mouse Keys
  [_LYMOS] =
   {
     {KC_LYDEF,________,________,________,________,________,___XX___,___XX___,KC_MS_U ,KC_WH_U ,KC_ACL2 ,________},
     {________,________,________,________,________,________,___XX___,KC_MS_L ,KC_ACL0 ,KC_MS_R ,KC_ACL1 ,___XX___},
     {________,________,________,________,________,________,___XX___,___XX___,KC_MS_D ,KC_WH_D ,KC_BTN2 ,___XX___},
     {________,________,________,________,________,________,KC_BTN1 ,KC_BTN2 ,KC_BTN3 ,KC_BTN4 ,___XX___,___XX___}
   },
   //Systen Keys
   [_LYSYS] =
    {
      {KC_LYDEF,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,___XX___,________},
      {________,________,________,________,________,________,___XX___,___XX___,QWERTY  ,COLEMAK ,___XX___,RESET   },
      {________,________,________,________,________,________,___XX___,MU_ON   ,MU_OFF  ,MI_ON   ,MI_OFF  ,CK_TOGG },
      {________,________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,___XX___}
    },

 // Light Control
 [_LYLT] =
   {
      {KC_LYDEF,________,________,________,________,________,RGB_HUD ,RGB_HUI ,RGB_SAD ,RGB_SAI ,RGB_VAD ,RGB_VAI },
      {________,________,________,________,________,________,RGB_TOG ,RGB_RMOD,RGB_MOD ,___XX___,___XX___,___XX___},
      {________,________,________,________,________,________,BL_TOGG ,BL_DEC  ,BL_INC  ,BL_BRTG ,___XX___,___XX___},
      {________,________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,___XX___}
   }
 };

//Const for shift
const uint8_t shift = MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch(keycode) {
    case KC_LYDEF:
      layer_clear();
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case KC_BSDEL:
      if (record->event.pressed) {
        if (keyboard_report->mods & shift) {
          if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
            unregister_code(KC_LSHIFT);
          }
          else {
            unregister_code(KC_RSHIFT);
          }
          register_code(KC_DEL);
        }
        else {
          register_code(KC_BSPC);
        }
      }
      else {
        unregister_code(KC_DEL);
        unregister_code (KC_BSPC);
      }
      return false;
      break;
    case KC_FBSLH:
      if (record->event.pressed) {
        if (keyboard_report->mods & shift) {
            if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
              unregister_code(KC_LSHIFT);
            }
            else {
              unregister_code(KC_RSHIFT);
            }
          register_code(KC_BSLASH);
        }
        else {
          register_code(KC_SLSH);
        }
      }
      else {
        unregister_code(KC_BSLASH);
        unregister_code (KC_SLSH);
      }
      return false;
      break;
    case KC_DOTQ:
      if (record->event.pressed) {
        if (keyboard_report->mods & shift) {
          register_code(KC_SLSH); // shifted slash = ?
        }
        else {
          register_code(KC_DOT);
        }
      }
      else {
        unregister_code(KC_SLSH); // shifted slash = ?
        unregister_code (KC_DOT);
      }
      return false;
      break;
    case KC_CPIPE:
      if (record->event.pressed) {
        if (keyboard_report->mods & shift) {
          register_code(KC_BSLS);
        }
        else {
          register_code(KC_COMM);
        }
      }
      else {
        unregister_code(KC_BSLS);
        unregister_code (KC_COMM);
      }
      return false;
      break;
    }
    return true;
};
