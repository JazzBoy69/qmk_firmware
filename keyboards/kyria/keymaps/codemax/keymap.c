/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include QMK_KEYBOARD_H


// The layers for this keyboard.
#define COLEMAK 0
#define TYPING 1
#define NUMPAD 2
#define NAV 3
#define GAME 4
#define FN 5
#define SYM 6
#define SYMPLUS 7
#define UNICODE 8
#define MIRRORED 9
#define MIRSYM 10
#define MIRUNI 11


enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

void handle_supershift(void);
uint8_t caps_lock_on(void);
uint8_t shift_pressed(void);
void flash(uint16_t time, uint8_t leds);
void run(uint16_t speed);
uint8_t current_layer = 0;
uint16_t change_time = 0;
uint16_t pressed_time = 0;
uint16_t shift_time = 0;
uint8_t shift_count = 0;


#define CAP_ENE SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_0) SS_TAP(X_KP_9) ))
#define ENE SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_TAP(X_KP_1) ))
#define CAP_ACCENTA SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_3) ))
#define ACCENTA SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_5) ))
#define CAP_ACCENTE SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_0) SS_TAP(X_KP_1) ))
#define ACCENTE SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_3) ))
#define CAP_ACCENTI SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_0) SS_TAP(X_KP_5) ))
#define ACCENTI SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_7) ))
#define CAP_ACCENTO SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_1) ))
#define ACCENTO SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_TAP(X_KP_3) ))
#define CAP_ACCENTU SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_8) ))
#define ACCENTU SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_5) SS_TAP(X_KP_0) ))
#define CAP_ACCENTY SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_0) ))
#define ACCENTY SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_5) SS_TAP(X_KP_2) ))
#define CAP_ACCENTGU SEND_STRING(SS_LSFT(SS_TAP(X_G)) SS_DELAY(50) SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_0) ))
#define ACCENTGU SEND_STRING(SS_TAP(X_G) SS_DELAY(50) SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_5) SS_TAP(X_KP_2) ))


#define SEND_UNICODE(upper, lower) uint8_t caps = caps_lock_on();\
uint8_t shift = shift_pressed();\
if (caps) {\
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(30));\
          }\
if ((caps + shift) == 1) {\
          clear_oneshot_mods();\
        upper;\
        }\
        else {\
          lower;\
        }\
  if (caps) {\
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(30));\
          }\

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,
  SC_FEM,
  SC_OPEN1QUOTE,
  SC_CLOSE1QUOTE,
  SC_MASC,
  SC_SEMICLNENTER,
  SC_EQUALS,
  SC_ENDTAG,
  SC_OPENQUOTE,
  SC_OPENCLOSEPAREN,
  SC_NOTEQUAL,
  SC_ENDSECTION,
  SC_EMDASH,
  SC_CLOSEQUOTE,
  SC_EXACTLYEQUAL,
  SC_PARENSEMICOLON,
  SC_LESSOREQUAL,
  SC_GREATOREQUAL,
  DEL_LINE,
  SC_SURROUNDBRKT,
  SC_SELECTLINE,
  OPENCLOSEBRACKETS,
  DELWORD,
  LOCKALT,
  SC_A,
  SC_SEC,
  SC_INVBANG,
  SC_PAR,
  SC_GU,
  SC_SHIFT,
  SC_DOT,
  SC_COMMA,
  SC_INVQUES,
  SC_N,
  SC_E,
  SC_I,
  SC_O,
  SC_U,
  SC_Y,
  SC_MIRSHIFT,
  SC_AS,
  SC_AR,
  SC_SUPERSHIFT,
  SC_ARROW,
  SC_SUPERDOT,
  SC_SUPERQUES,
  SC_SUPERINVQUES,
  SC_SECTION,
};

// A 'transparent' key code (that falls back to the layers below it).
#define ___ KC_TRANSPARENT

// A 'blocking' key code. Does nothing but prevent falling back to another layer.
#define XXX KC_NO


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: BASE
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |   Q  |   W  |   F  |   P  |   G  |                              |   J  |   L  |   U  |   Y  |   '  |    `   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | [] []  |123/A |ALT/R |CTL/S |SHFT/T|   D  |                              |SCMD/H|   N  |   E  |   I  |   O  | [] []  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Shift |[]+/Z |MEH/X |   C  |   V  |   B  |  TAB |SFTTAB|  | F23  | F24  |   K  |   M  | ,  < | . >  | /  ? |  SHIFT |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | DEL  | ESC  | SPACE| BACKS| ENTER|  |   ?  | Space| CTRL | GUI  |NUMPAD|
 *                        |      |      |      | MIRR |  FN  |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
 
    [COLEMAK] = LAYOUT(
    OSL(UNICODE),     KC_Q,            KC_W,          KC_F,       KC_P,           KC_G,                                                                       KC_J,        KC_L,     KC_U,          KC_Y,          KC_QUOTE,              OSL(UNICODE),
    OSL(SYM),       LT(NUMPAD,KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), LT(NAV,KC_D),                                                              SCMD_T(KC_H),    KC_N,     KC_E,          KC_I,            KC_O,                   OSL(SYM),
    SC_SUPERSHIFT, LT(SYMPLUS,KC_Z), MEH_T(KC_X),     KC_C,       KC_V,           KC_B,                       KC_TAB,LSFT(KC_TAB),       KC_F23,  KC_F24,     KC_K,        KC_M,   KC_COMMA,  MEH_T(KC_DOT),  LT(SYMPLUS,KC_SLASH),   SC_SUPERSHIFT,
                                     KC_DELETE,      KC_ESCAPE,  KC_SPACE,                    LT(MIRRORED,KC_BSPACE),LT(FN,KC_ENTER),   KC_QUES,  KC_SPACE, OSM(MOD_LCTL), KC_LGUI, TO(NUMPAD)                    
                                                                                

  // right thumb --------------------------------d-----------------------------------------------------------------
 
          
  ),
/*
 * Lower Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |  R   |  S   |  T   |      |                              |      |      |   E  |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |  X   |      |      |      |      |      |  |      |      |      |      |      |  .   |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      | SPACE|ENTER |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [TYPING] = LAYOUT(
    ___, ___,  ___,  ___,  ___,  ___,                           ___,  ___,  ___,  ___,     ___,       ___,
    ___, ___,  KC_R, KC_S, KC_T, ___,                           ___,  ___, KC_E,  ___,     ___,       ___,
    ___, ___,  KC_X, ___,  ___,  ___,  ___, ___,   ___, ___,    ___,  ___,  ___,  KC_DOT,  ___,       ___,
               ___,  ___,  ___,  KC_BSPACE, KC_ENTER, ___, ___, XXX,  XXX,  XXX   
  ), 
/*
 * Raise Layer: Number keys, media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                              |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | Prev | Play | Next | VolUp|                              | Left | Down | Up   | Right|      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      | Mute | VolDn|      |      |  |      |      | MLeft| Mdown| MUp  |MRight|      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [NUMPAD] = LAYOUT(
      _______, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
      _______, _______, _______, _______, KC_MUTE, KC_VOLD, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Adjust Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      |      | F11  | F12  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [NAV] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, KC_F11,  KC_F12,  _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    /*
 * Adjust Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      |      | F11  | F12  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [FN] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, KC_F11,  KC_F12,  _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
        /*
 * Adjust Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      |      | F11  | F12  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [SYM] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, KC_F11,  KC_F12,  _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
        /*
 * Adjust Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      |      | F11  | F12  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [SYMPLUS] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, KC_F11,  KC_F12,  _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
            /*
 * Adjust Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      |      | F11  | F12  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [UNICODE] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, KC_F11,  KC_F12,  _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
            /*
 * Adjust Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      |      | F11  | F12  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [MIRRORED] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, KC_F11,  KC_F12,  _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
            /*
 * Adjust Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      |      | F11  | F12  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [MIRSYM] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, KC_F11,  KC_F12,  _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
            /*
 * Adjust Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      |      | F11  | F12  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [MIRUNI] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, KC_F11,  KC_F12,  _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    current_layer = biton32(state);
    change_time = timer_read();
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif



uint8_t caps_lock_on() {
  if (IS_LED_ON(host_keyboard_leds(), USB_LED_CAPS_LOCK)) {
    return 1;
  }
  return 0;
}

uint8_t shift_pressed() {
  if (((get_oneshot_mods() & MOD_BIT(KC_LSHIFT)) == MOD_BIT(KC_LSHIFT)) || 
  ((get_oneshot_locked_mods() & MOD_BIT(KC_LSHIFT)) == MOD_BIT(KC_LSHIFT)) ||
  ((get_mods() & MOD_BIT(KC_LSHIFT)) == MOD_BIT(KC_LSHIFT)))
  {
    return 1;
  }
  return 0;
}



void matrix_scan_user(void) {
  if (current_layer == COLEMAK) {
    if (get_current_wpm()>40) {
      layer_on(TYPING);
    }
    return;
  }
  if (current_layer == TYPING) {
    if ((get_current_wpm()<=40) || (timer_elapsed(pressed_time) > 1000)) {
      shift_time = 0;
      layer_off(TYPING);
      set_current_wpm(0);
    }
    return;
  }
};



bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    if ((keycode == LCTL_T(KC_CAPSLOCK)) || (keycode == LCTL_T(KC_S)) || (keycode == LSFT_T(KC_T))
    || (keycode == OSL(SYM)) || (keycode == OSL(UNICODE)) || (keycode == MEH_T(KC_SPACE))
    || (keycode == MEH_T(KC_X)) || (keycode == MEH_T(KC_DOT))) {
        return false;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    if (keycode == LT(NUMPAD,KC_A)) {
      return 170;
    }
     if ((current_layer == TYPING) ||
       (keycode == OSM(MOD_LSFT)) 
     ) {
      return 300;
    }
    if ((keycode == LALT_T(KC_R)) || 
        (keycode == MEH_T(KC_SPACE)) || 
        (keycode == LSFT_T(KC_T)) ||
        (keycode == LCTL_T(KC_S))
    ) {
      return 150;
    }
    return TAPPING_TERM;
}

void oneshot_mods_changed_user(uint8_t mods) {
 if (!(mods & MOD_MASK_SHIFT)) {
   shift_count = 0;
 }
}

void handle_supershift() {
  if (caps_lock_on()) {
    tap_code(KC_CAPSLOCK);
    return;
  }
  if (shift_count > 0) {
    set_oneshot_mods(0);
    shift_count = 0;
    tap_code(KC_CAPSLOCK);
    return;
  }
  add_mods(MOD_BIT(KC_LSHIFT));
  set_oneshot_mods(MOD_BIT(KC_LSHIFT));
  shift_count = 1;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  pressed_time = timer_read();
  if (record->event.pressed && (shift_time != 0)) {
      if (!caps_lock_on() && (timer_elapsed(shift_time) < 1000)) {
        set_oneshot_mods(MOD_BIT(KC_LSHIFT));
      }
      shift_time = 0;
    }
  switch (keycode) {
    case SC_SHIFT:
      if (record->event.pressed) {
        set_oneshot_mods(MOD_BIT(KC_LSHIFT));
        reset_oneshot_layer();
        layer_on(UNICODE);
      }
      return true;
    break;
    case KC_COLN:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_SCOLON)));
      }
      return false;
    break;
    case KC_LCBR:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_LBRACKET)));
      }
      return false;
    break;
    case KC_AMPR:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_7)));
      }
      return false;
    break;
    case KC_PLUS:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_EQUAL)));
      }
      return false;
    break;
    case KC_ASTR:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_8)));
      }
      return false;
    break;
    case KC_AT:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_2)));
      }
      return false;
    break;
    case KC_PERC:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_5)));
      }
      return false;
    break;
    case KC_HASH:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_3)));
      }
      return false;
    break;
    case KC_DLR:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_4)));
      }
      return false;
    break;
    case KC_TILD:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_GRV)));
      }
      return false;
    break;
    case KC_PIPE:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_BSLASH)));
      }
      return false;
    break;
    case KC_RCBR:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_RBRACKET)));
      }
      return false;
    break;
    case KC_RPRN:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_0)));
      }
      return false;
    break;
    case KC_LPRN:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_9)));
      }
      return false;
    break;
    case KC_EXLM:
      if (record->event.pressed) {
        SEND_STRING("!");//  SS_LSFT(SS_TAP(X_1)));
      }
      return false;
    break;
    case KC_UNDS:
      if (record->event.pressed) {
        SEND_STRING("_");
      }
      return false;
    break;
    case SC_SUPERDOT:
      if (record->event.pressed) {
        SEND_STRING(". ");//SS_TAP(X_DOT)SS_DELAY(50)SS_TAP(X_SPACE));
        shift_time = timer_read();
      }
      return true;
    break;
    case SC_SUPERSHIFT:
      if (record->event.pressed) {
        handle_supershift();
      }
      else {
        del_mods(MOD_BIT(KC_LSHIFT));
      }
      return true;
    break;
    case SC_SUPERINVQUES:
      if (record->event.pressed) {
        set_oneshot_mods(0);
        SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_1)));
        layer_off(UNICODE);
        layer_off(MIRUNI);
        shift_time = timer_read();
      }
      return false;
    break;   
    case SC_SUPERQUES:
      if (record->event.pressed) {
        SEND_STRING("? ");//SS_LSFT(SS_TAP(X_SLASH)) SS_DELAY(50) SS_TAP(X_SPACE));
        shift_time = timer_read();
      }
      return true;
    break;
    case KC_ESCAPE:
      if (record->event.pressed) {
        clear_oneshot_mods(); 
        clear_mods();
        shift_time = 0;
        SEND_STRING(SS_TAP(X_ESCAPE));
      }
      return true;
    break; 
    case SC_MIRSHIFT:
      if (record->event.pressed) {
        set_oneshot_mods(MOD_BIT(KC_LSHIFT));
        reset_oneshot_layer();
        layer_on(MIRUNI);
      }
      return true;
    break;      
    case SC_A:
      if (record->event.pressed) {
        SEND_UNICODE(CAP_ACCENTA, ACCENTA);
        layer_off(UNICODE);
        layer_off(MIRUNI);
      }
      return false;
    break;
    case SC_E:
      if (record->event.pressed) {
        SEND_UNICODE(CAP_ACCENTE, ACCENTE);
        layer_off(UNICODE);
        layer_off(MIRUNI);
      }
      return false;
    break;
    case SC_I:
      if (record->event.pressed) {
        SEND_UNICODE(CAP_ACCENTI, ACCENTI);
        layer_off(UNICODE);
        layer_off(MIRUNI);
      }
      return false;
    break;
    case SC_O:
      if (record->event.pressed) {
        SEND_UNICODE(CAP_ACCENTO, ACCENTO);
        layer_off(UNICODE);
        layer_off(MIRUNI);
      }
      return false;
    break;
    case SC_U:
      if (record->event.pressed) {
        SEND_UNICODE(CAP_ACCENTU, ACCENTU);
        layer_off(UNICODE);
        layer_off(MIRUNI);
      }
      return false;
    break;
    case SC_Y:
      if (record->event.pressed) {
        SEND_UNICODE(CAP_ACCENTY, ACCENTY);
        layer_off(UNICODE);
        layer_off(MIRUNI);
      }
      return false;
    break;
    case SC_GU:
      if (record->event.pressed) {
        SEND_UNICODE(CAP_ACCENTGU, ACCENTGU);
        layer_off(UNICODE);
        layer_off(MIRUNI);
      }
      return false;
    break;
    case SC_N:
      if (record->event.pressed) {
        SEND_UNICODE(CAP_ENE, ENE);
        layer_off(UNICODE);
        layer_off(MIRUNI);
      }
      return false;
    break; 
    case SC_SEC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_7) ));
        layer_off(UNICODE);
        layer_off(MIRUNI);
      }
      return false;
    break;
    case SC_INVQUES:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_1) ));
        layer_off(UNICODE);
        layer_off(MIRUNI);
      }
      return false;
    break;
    case SC_PAR:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_2) ));
        layer_off(UNICODE);
        layer_off(MIRUNI);
      }
      return false;
    break;
    case SC_INVBANG:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_1) ));
        layer_off(UNICODE);
        layer_off(MIRUNI);
      }
      return false;
    break;
    case SC_COMMA:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_0) ));
        layer_off(UNICODE);
        layer_off(MIRUNI);
      }
      return false;
    break;
    case SC_DOT:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_3) ));
        layer_off(UNICODE);
        layer_off(MIRUNI);
      }
      return false;
    break;
    case SC_FEM:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_6) ));

    }
    break;
    case SC_OPEN1QUOTE:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_5) ));

    }
    break;
    case SC_CLOSE1QUOTE:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_6) ));

    }
    break;
    case SC_MASC:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_7) ));

    }
    break;
    case SC_SEMICLNENTER:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_END) SS_DELAY(50) SS_TAP(X_SCOLON) SS_DELAY(50) SS_TAP(X_ENTER));

    }
    break;
    case SC_EQUALS:
    if (record->event.pressed) {
      SEND_STRING("==");//SS_TAP(X_EQUAL) SS_DELAY(50) SS_TAP(X_EQUAL));

    }
    break;
    case SC_ENDTAG:
    if (record->event.pressed) {
      SEND_STRING("</");//SS_LSFT(SS_TAP(X_COMMA)) SS_DELAY(50) SS_TAP(X_SLASH));

    }
    break;
    case SC_OPENQUOTE:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_7) ));

    }
    break;
    case SC_SECTION:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_END) SS_DELAY(20) SS_TAP(X_SPACE) SS_DELAY(20) SS_LSFT(SS_TAP(X_LBRACKET)) SS_DELAY(20) SS_TAP(X_ENTER) SS_TAP(X_ENTER) SS_DELAY(20) SS_LSFT(SS_TAP(X_RBRACKET)) SS_DELAY(20) SS_TAP(X_UP) SS_DELAY(20) SS_TAP(X_TAB));

    }
    break;
    case SC_OPENCLOSEPAREN:
    if (record->event.pressed) {
      SEND_STRING("()");//SS_LSFT(SS_TAP(X_9)) SS_DELAY(50) SS_LSFT(SS_TAP(X_0)));

    }
    break;
    case SC_NOTEQUAL:
    if (record->event.pressed) {
      SEND_STRING("!=");//SS_LSFT(SS_TAP(X_1)) SS_DELAY(50) SS_TAP(X_EQUAL));

    }
    break;
    case SC_ENDSECTION:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ENTER) SS_DELAY(20) SS_LSFT(SS_TAP(X_RBRACKET)) SS_DELAY(20) SS_TAP(X_UP) SS_DELAY(20) SS_TAP(X_TAB));

    }
    break;
    case SC_EMDASH:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_1) ));

    }
    break;
    case SC_CLOSEQUOTE:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_8) ));

    }
    break;
    case SC_EXACTLYEQUAL:
    if (record->event.pressed) {
      SEND_STRING("===");//SS_TAP(X_EQUAL) SS_DELAY(50) SS_TAP(X_EQUAL) SS_DELAY(50) SS_TAP(X_EQUAL));

    }
    break;
    case SC_PARENSEMICOLON:
    if (record->event.pressed) {
      SEND_STRING("();");//SS_LSFT(SS_TAP(X_9)) SS_DELAY(50) SS_LSFT(SS_TAP(X_0)) SS_DELAY(50) SS_TAP(X_SCOLON));

    }
    break;
    case SC_LESSOREQUAL:
    if (record->event.pressed) {
      SEND_STRING("<=");//SS_LSFT(SS_TAP(X_COMMA)) SS_DELAY(50) SS_TAP(X_EQUAL));

    }
    break;
    case SC_GREATOREQUAL:
    if (record->event.pressed) {
      SEND_STRING(">=");//SS_LSFT(SS_TAP(X_DOT)) SS_DELAY(50) SS_TAP(X_EQUAL));

    }
    break;
    case DEL_LINE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_END) SS_DELAY(50) SS_LSFT(SS_TAP(X_HOME) SS_TAP(X_HOME)) SS_DELAY(50) SS_TAP(X_DELETE) SS_DELAY(50) SS_TAP(X_DELETE));

    }
    break;
    case SC_SURROUNDBRKT:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_X)) SS_DELAY(20) SS_LSFT(SS_TAP(X_TAB)) SS_DELAY(20) SS_LSFT(SS_TAP(X_LBRACKET)) SS_DELAY(20) SS_TAP(X_ENTER) SS_DELAY(20) SS_LSFT(SS_TAP(X_RBRACKET)) SS_TAP(X_UP) SS_DELAY(20) SS_TAP(X_ENTER) SS_DELAY(20) SS_TAP(X_TAB) SS_DELAY(20) SS_LCTL(SS_TAP(X_V)));

    }
    break;
    case SC_SELECTLINE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_END) SS_DELAY(50) SS_LSFT(SS_TAP(X_HOME)));
    }
    break;
    case OPENCLOSEBRACKETS:
    if (record->event.pressed) {
      SEND_STRING("[]"); //SS_TAP(X_LBRACKET) SS_DELAY(50) SS_TAP(X_RBRACKET));
    }
    break;
    case DELWORD:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)) SS_DELAY(50) SS_LSFT(SS_LCTL(SS_TAP(X_LEFT))) SS_DELAY(50) SS_TAP(X_DELETE));
    }
    break;
    case SC_AS:
       if (record->event.pressed) {
        SEND_STRING("AS");//SS_TAP(X_A) SS_DELAY(50) SS_TAP(X_S));
      }
    break;
    case SC_ARROW:
       if (record->event.pressed) {
        SEND_STRING("=>");//SS_TAP(X_EQUAL) SS_DELAY(50) SS_LSFT(SS_TAP(X_DOT)));
      }
    break;
    case SC_AR:
    if (record->event.pressed) {
      SEND_STRING("AR");//SS_TAP(X_A) SS_DELAY(50) SS_TAP(X_R));
    }
    break;
  }
  if (record->event.pressed) {
    layer_off(UNICODE);
    layer_off(MIRUNI);
  }
  return true;
}