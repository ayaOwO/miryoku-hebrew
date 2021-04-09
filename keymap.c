/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "keymap_hebrew.h"
#include "keymap_dvorak.h"

#include QMK_KEYBOARD_H
#define KC_COMPILE LCTL(KC_F5)
#define KC_TASKMANAGER LCTL(LSFT(KC_ESC))
#define KC_COLORPICKER LGUI(LSFT(KC_C))

#define englishLay 0
#define ctrlQwerty 1
#define guiQwerty 2
#define lowerEng 3

#define qwerty 4
#define qwertyLower 5

#define hebrewLay 6
#define lowerHeb 7



#define LEN 10
enum custom_keycodes {
    changeToEng = SAFE_RANGE,
    changeToHeb,
    changeToQwerty
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // english - dvorak
  [englishLay] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,   KC_L,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N, KC_S,  KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LM(ctrlQwerty, MOD_LCTL), KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,  KC_MUTE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LM(guiQwerty, MOD_LGUI), KC_LALT,  KC_SPC,     KC_ENT,   MO(lowerEng), KC_EQL
                                      //`--------------------------'  `--------------------------'
  ),
    [lowerEng] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,  KC_TASKMANAGER, KC_7,    KC_8,   KC_9,   KC_RBRC,               KC_LBRC, KC_SLSH  , KC_UP  ,KC_BSLS, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_COMPILE,  KC_4,    KC_5,   KC_6, KC_RPRN,                      KC_LPRN,  KC_LEFT, KC_DOWN,KC_RIGHT,KC_COLORPICKER, KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,  KC_0,    KC_1,     KC_2,    KC_3,  changeToHeb ,                 KC_MPLY, KC_MNXT, KC_MPRV, XXXXXXX, XXXXXXX, changeToQwerty,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_LALT,  KC_SPC,     KC_ENT, KC_TRNS, KC_EQL
                                      //`--------------------------'  `--------------------------'
  ),
  [ctrlQwerty] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, DV_QUOT, DV_COMM,  DV_DOT,  DV_P,   DV_Y,                         DV_F,    DV_G,    DV_C,    DV_R,   DV_L,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  DV_A,    DV_O,    DV_E,    DV_U,    DV_I,                         DV_D,    DV_H,    DV_T,    DV_N,    DV_S,  KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, DV_SCLN, DV_Q,    DV_J,    DV_K,    DV_X,                          DV_B,    DV_M,    DV_W,  DV_V, DV_Z,   KC_MUTE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_LALT,  KC_SPC,     KC_ENT, MO(lowerEng), KC_EQL
                                      //`--------------------------'  `--------------------------'
  ),
  [guiQwerty] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, DV_QUOT, DV_COMM, DV_DOT,  DV_P,     DV_Y,                         DV_F,   DV_G,    DV_C,    DV_R,   DV_L,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  DV_A,    DV_O,    DV_E,    DV_U,    DV_I,                         DV_D,    DV_H,    DV_T,    DV_N,   DV_S,  KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, DV_SCLN,  DV_Q,    DV_J,    DV_K,    DV_X,                                 DV_B,    DV_M, DV_W,  DV_V, DV_Z,   KC_MUTE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_LALT,  KC_SPC,     KC_ENT, MO(lowerEng), KC_EQL
                                      //`--------------------------'  `--------------------------'
  ),

  // qwerty
  [qwerty] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_MUTE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_LALT,  KC_SPC,     KC_ENT,   MO(qwertyLower), KC_EQL
                                      //`--------------------------'  `--------------------------'
  ),
  [qwertyLower] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,  KC_TASKMANAGER, KC_7,    KC_8,   KC_9,   KC_RBRC,                       KC_LBRC, KC_SLSH , KC_UP  ,KC_BSLS, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_COMPILE,  KC_4,    KC_5,   KC_6, KC_RPRN,                      KC_LPRN,  KC_LEFT, KC_DOWN,KC_RIGHT,KC_COLORPICKER, KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,  KC_0,    KC_1,     KC_2,    KC_3,  changeToHeb ,                    KC_MPLY, KC_MNXT, KC_MPRV, XXXXXXX, XXXXXXX, changeToEng,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_LALT,  KC_SPC,     KC_ENT, KC_TRNS, KC_QUES
                                      //`--------------------------'  `--------------------------'
  ),
  // hebrew
  [hebrewLay] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, IL_SLSH,    IL_QUOT,    IL_QOF,    IL_RESH,    IL_ALEF,          IL_TET,    IL_VAV,    IL_FNUN,    IL_FMEM,   IL_PE,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  IL_SHIN,    IL_DALT,    IL_GIML,    IL_KAF,    IL_AYIN,         IL_YOD,    IL_HET,    IL_LAMD,    IL_FKAF, IL_FPE,  IL_COMM,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, IL_ZAYN,  IL_SMKH, IL_BET,    IL_HE,  IL_NUN,                 IL_MEM,    IL_TSDI, IL_TAV,  IL_FTSD, IL_DOT,   KC_MUTE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_LALT,  KC_SPC,     KC_ENT,   MO(lowerHeb), IL_EQL
                                      //`--------------------------'  `--------------------------'
  ),
  [lowerHeb] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,  KC_TASKMANAGER, KC_7,    KC_8,   KC_9,   IL_RBRC,                       IL_LBRC, IL_SLSH  , KC_UP  ,IL_BSLS, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_COMPILE,  KC_4,    KC_5,   KC_6, IL_RPRN,                      IL_LPRN,  KC_LEFT, KC_DOWN,KC_RIGHT,KC_COLORPICKER, KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,  KC_0,    KC_1,     KC_2,    KC_3,  changeToEng ,                 KC_MPLY, KC_MNXT, KC_MPRV, XXXXXXX, XXXXXXX, changeToQwerty,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_LALT,  KC_SPC,     KC_ENT, KC_TRNS, IL_EQL  // LM(lowerheb, )
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master ){ // is_keyboard_left()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return OLED_ROTATION_270;//rotation;
}

void oled_render_layer_state(void) {

  static const char PROGMEM dvorak_logo[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0xff, 0xff, 0xff, 0x03, 0x03, 0x03, 0x03, 0x07, 0x07, 0x0e, 0x1e, 0xfc, 0xf8, 0xe0, 0x00, 
0x01, 0x0f, 0x7f, 0xfc, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xfc, 0x7f, 0x0f, 0x03, 0x00, 
0x00, 0xff, 0xff, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0x70, 0x78, 0x3f, 0x1f, 0x07, 0x00, 
0x00, 0x00, 0x00, 0x03, 0x0f, 0x7f, 0xfc, 0xe0, 0xf8, 0x7f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const char PROGMEM hebrew_logo[] = {
0x00, 0x01, 0x03, 0x0f, 0x1f, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xf0, 0xc0, 0x80, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xf9, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xfc, 
0xf8, 0xe0, 0xc0, 0xe0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x1f, 0x07, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x03, 0x00, 0x00, 0x01, 0x03, 0x07, 0x1f, 
0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xe1, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x01, 0x07, 0x0f, 0x1f, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0xf8, 0xf0, 0xc0, 0x80, 0x00
};

static const char PROGMEM qwerty_logo[] = {
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 
0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 
0xff, 0xff, 0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x00, 0x00, 0x00, 
0xff, 0xff, 0xff, 0x07, 0x1f, 0x7e, 0xf8, 0xe0, 0x80, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 
0xff, 0xff, 0xff, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 
0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x01, 0x07, 0x1f, 0x7e, 0xf8, 0xe0, 0xff, 0xff, 0xff, 0x00, 
0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 
0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x00
};

static const char PROGMEM lower_logo[] = {
// 'lower', 32x16px
0xf8, 0x00, 0x00, 0x80, 0xc0, 0x40, 0xc0, 0xc0, 0x00, 0x40, 0xc0, 0x00, 0x00, 0xc0, 0xc0, 0x00, 
0x00, 0xc0, 0x00, 0x00, 0x80, 0xc0, 0x40, 0x40, 0xc0, 0x00, 0x00, 0xc0, 0xc0, 0x40, 0x40, 0x00, 
0x1f, 0x00, 0x07, 0x0f, 0x18, 0x10, 0x18, 0x1f, 0x07, 0x00, 0x07, 0x1e, 0x1f, 0x03, 0x03, 0x1e, 
0x1f, 0x07, 0x00, 0x07, 0x0f, 0x1a, 0x12, 0x12, 0x1b, 0x0b, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


static const char PROGMEM cleared[] = {
// 'lower', 32x16px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

    
    oled_set_cursor(0, 6);
    switch (get_highest_layer(layer_state)) {
      case englishLay: case ctrlQwerty: case guiQwerty:
      {
        oled_write_raw_P(dvorak_logo, 128);
        oled_set_cursor(0, 10);
        oled_write_raw_P(cleared, 128);
        break;
      }
      case lowerEng:
      {
        oled_write_raw_P(dvorak_logo, 128);
        oled_set_cursor(0, 10);
        oled_write_raw_P(lower_logo, 128);
        break;
      }
      case hebrewLay:
      {
        oled_write_raw_P(hebrew_logo, 128);
        oled_set_cursor(0, 10);
        oled_write_raw_P(cleared, 128);
        break;
      }
      case lowerHeb:
      {
        oled_write_raw_P(hebrew_logo, 128);
        oled_set_cursor(0, 10);
        oled_write_raw_P(lower_logo, 128);
        break;
      }
      case qwerty:
      {
        oled_write_raw_P(qwerty_logo, 128);
        oled_set_cursor(0, 10);
        oled_write_raw_P(cleared, 128);
        break;
      }
      case qwertyLower:
      {
        oled_write_raw_P(qwerty_logo, 128);
        oled_set_cursor(0, 10);
        oled_write_raw_P(lower_logo, 128);
        break;
      }
      /* text
      case englishLay:
      {
        //oled_write_ln_P(PSTR("Dvorak        "), false);
        break;
      }
      case lowerEng:
      {
        oled_write_ln_P(PSTR("Dvorak - Lower"), false);
        break;
      }
      case ctrlQwerty:
      {
        oled_write_ln_P(PSTR("Dvorak - Ctrl"), false);
        break;
      }
      case guiQwerty:
      {
        oled_write_ln_P(PSTR("Dvorak - GUI  "), false);
        break;
      }
      case hebrewLay:
      {
        oled_write_ln_P(PSTR("Hebrew        "), false);
        break;
      }
      case lowerHeb:
      {
        oled_write_ln_P(PSTR("Hebrew - Lower"), false);
        break;
      }
      case qwerty:
      {
        oled_write_ln_P(PSTR("Qwerty        "), false);
        break;
      }
      case qwertyLower:
      {
        oled_write_ln_P(PSTR("Qwerty - Lower"), false);
        break;
      }
      */
    }
    //oled_write_P(PSTR("\n\n"), false);
}


//char keylog_str[LEN] = {};
//unsigned long counter = 0;
/* 
const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};
*/
/*
void set_keylog(uint16_t keycode, keyrecord_t *record) {
  
   key logger :)
  char name = ' ';
  int i = 0;
  int len = 0;
  if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];

    len = strlen(keylog_str);
    if (len < LEN - 1)
    {
        keylog_str[len] = name;
        keylog_str[len + 1] = '\0';
    }
    else
    {
        for (i = 0; i < LEN - 1; i++)
        {
            keylog_str[i] = keylog_str[i + 1];
        }
        keylog_str[LEN - 2] = name;
    }

  }

  // update keylog
  //snprintf(keylog_str, sizeof(keylog_str), "Key: %d       ", keycode);
  

  //counter += 1;
  //snprintf(keylog_str, sizeof(keylog_str), "%lu", counter);
}
*/
/*
void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}
*/
 /*
void render_bootmagic_status(bool status) {
    Show Ctrl-Gui Swap options
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}
 */

// render right disp
void render_YOUR_logo(void) {
  static const char PROGMEM YOUR_logo[] = { 
// 'sheika eye + apple logo + hands ', 128x32px
0x00, 0x00, 0x00, 0x00, 0x40, 0x60, 0x30, 0x10, 0x98, 0x8c, 0x04, 0x00, 0x43, 0x64, 0xeb, 0xcb, 
0x04, 0x23, 0x50, 0xaa, 0x52, 0x26, 0x0c, 0x18, 0x10, 0x20, 0x60, 0xc0, 0x80, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0x80, 0x80, 0x80, 
0x80, 0x80, 0xc0, 0xc0, 0xe0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x10, 0x14, 0x55, 0x55, 0x55, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0x7f, 0x7f, 
0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x0c, 0x12, 0x2d, 0x2d, 0x12, 0x0c, 0x80, 0xc0, 0xe1, 0x03, 0xf1, 0x8c, 0xc6, 0x23, 0x81, 0x81, 
0x23, 0xc6, 0x98, 0xe0, 0x80, 0x81, 0xc3, 0xc6, 0xec, 0xe8, 0xe8, 0xc8, 0xcd, 0x87, 0x00, 0x0c, 
0x1c, 0x7c, 0x7c, 0xf8, 0xf0, 0xe0, 0xcf, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x00, 
0x00, 0xf0, 0xf8, 0xfc, 0xfe, 0xfe, 0xfc, 0xf8, 0xf0, 0xe2, 0xc3, 0x83, 0x01, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x30, 0x48, 0xb4, 0xb4, 0x48, 0x30, 0x01, 0x03, 0x87, 0xc0, 0x8f, 0x31, 0x63, 0xc4, 0x81, 0x81, 
0xc4, 0x63, 0x19, 0x07, 0x81, 0xc1, 0x73, 0x33, 0x77, 0x67, 0xc7, 0x83, 0x43, 0x81, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x78, 0x00, 
0x00, 0x0f, 0x1f, 0x3f, 0x7f, 0x7f, 0x3f, 0x1f, 0x0f, 0x47, 0xc3, 0xc1, 0x80, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x0c, 0x08, 0x19, 0x31, 0x20, 0x00, 0xc2, 0x26, 0xd7, 0xd3, 
0x20, 0xc0, 0x04, 0x8e, 0xdb, 0x71, 0x23, 0x06, 0x2c, 0x50, 0xa9, 0x52, 0x25, 0x02, 0x01, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 
0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x08, 0x2a, 0xaa, 0xaa, 0xaa, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xfe, 
0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
  oled_write_raw_P(YOUR_logo, sizeof(YOUR_logo));
}
/*
void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}
*/

// render displays
void oled_task_user(void) {
    if (is_master) {//is_keyboard_left()) {
        oled_render_layer_state();
        //oled_render_keylog();
    } else {
        render_YOUR_logo();
    }
}

// custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    //set_keylog(keycode, record);
    switch (keycode) {
    case changeToEng:
    {
      // change language
      if (layer_state_is(lowerHeb))
      {
      	register_code(KC_LALT);
      	register_code(KC_LSFT);
      	unregister_code(KC_LALT);
      	unregister_code(KC_LSFT);
      }
    	layer_move(englishLay);
    	return false;

      break;
    }
    case changeToHeb:
    {
      // change language
    	register_code(KC_LALT);
    	register_code(KC_LSFT);
    	unregister_code(KC_LALT);
    	unregister_code(KC_LSFT);
    	layer_move(hebrewLay);
    	return false;
      break;
    }
    case changeToQwerty:
    {
      // change language
      if (layer_state_is(lowerHeb)){
        register_code(KC_LALT);
        register_code(KC_LSFT);
        unregister_code(KC_LALT);
        unregister_code(KC_LSFT);
      }
  	  layer_move(qwerty);
      return false;
      break;
    }
  }
  }
  return true;
}

#endif // OLED_DRIVER_ENABLE
/*
layer_state_t layer_state_set_user(layer_state_t state) {
 
switch (get_highest_layer(state)) {
    case ctrlQwerty:
    {
      unregister_code(KC_LGUI);
      register_code(KC_LCTL);
      break;
    }
    case guiQwerty: case guiLowerQwerty:
    {
      unregister_code(KC_LCTL);
      register_code(KC_LGUI);
      break;
    }
    default:
    {
      unregister_code(KC_LGUI);
      unregister_code(KC_LCTL);
      break;
    }
 }

 //lastLayer = get_highest_layer(state);
 return state;
 } */

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(HSV_TEAL); // or even sth. like rgblight_sethsv_noeeprom(HSV_TEAL);
}

/*

void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}

void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
}
*/