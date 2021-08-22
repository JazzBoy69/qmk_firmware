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
bool resume_capslock = false;
bool handle_keypress(uint16_t keycode);
bool handle_keyrelease(uint16_t keycode);
bool handle_unicode(uint16_t keycode);


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
 * Base Layer: COLEMAK
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
    ___, ___,  ___,  ___,  ___,  ___,                                  ___,  ___,  ___,  ___,     ___,       ___,
    ___, ___,  KC_R, KC_S, KC_T, ___,                                  ___,  ___, KC_E,  ___,     ___,       ___,
    ___, ___,  KC_X, ___,  ___,  ___,  ___, ___,          ___, ___,    ___,  ___,  ___,  KC_DOT,  ___,       ___,
               ___,  ___,  ___,  KC_BSPACE, KC_ENTER,     ___, ___, XXX,  XXX,  XXX   
  ), 
/*
 *                        `----------------------------------'  `----------------------------------'
 */
    [NUMPAD] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                                      _______, KC_KP_7,  KC_KP_8, KC_KP_9, KC_COLN,        KC_KP_MINUS,
      _______, _______, SC_AR,     SC_AS, _______, _______,                                                OSM(MOD_LALT), KC_KP_4,  KC_KP_5, KC_KP_6, KC_KP_ASTERISK, KC_KP_PLUS,
      _______, _______, _______, _______, _______, _______, LCTL(KC_Z), LCTL(KC_Y),       TO(COLEMAK), KC_NUMLOCK, _______, KC_KP_1,  KC_KP_2, KC_KP_3, KC_KP_SLASH,    KC_ENTER,
                                 _______, _______, _______,    _______,    _______,       KC_ESCAPE, KC_KP_0, KC_X, KC_KP_COMMA, KC_KP_DOT
    ),
/*
 */
    [NAV] = LAYOUT(
      _______, _______, _______,  _______,  _______,  _______,                                          LCTL(KC_HOME), _______, KC_UP,    KC_PGUP, _______,  KC_MS_WH_UP,
      _______, _______, _______, KC_LCTRL, KC_LSHIFT, _______,                                          LCTL(KC_LEFT), KC_LEFT, KC_DOWN, KC_RIGHT, LCTL(KC_RIGHT),  KC_MS_WH_DOWN,
      _______, _______, _______,  _______,  _______,  _______, _______, _______,           TO(COLEMAK), KC_SCROLLLOCK, DELWORD, KC_DELETE, _______, KC_PGDOWN, LCTL(KC_END), OSM(MOD_LSFT),
                                  _______,  _______,  _______, KC_MS_BTN2, KC_MS_BTN1,       KC_HOME,          KC_END, _______, _______, _______
    ),
    /*
 */
    [FN] = LAYOUT(
                RESET, _______,      _______,    SC_EMDASH,      _______, _______,                                          XXX, KC_F7, KC_F8, KC_F9, XXX,  KC_F12,
      KC_SYSTEM_SLEEP,    KC_1, LALT_T(KC_2), LCTL_T(KC_3), LSFT_T(KC_4),    KC_5,                                          XXX, KC_F4, KC_F5, KC_F6, XXX,     XXX,
           KC_PSCREEN,    KC_6,         KC_7,         KC_8,         KC_9,    KC_0, _______, _______,      _______, _______, XXX, KC_F1, KC_F2, KC_F3, XXX, _______,
                                                   _______,      _______,     ___, _______, _______,      _______, _______, ___, ___,     ___
    ), 
        /*
 */
    [SYM] = LAYOUT(
      SC_FEM,  SC_OPEN1QUOTE,     KC_AMPR, KC_PLUS, _______, _______,                                                                    KC_TILD,  KC_SLASH,  KC_MINUS,     KC_PIPE, SC_CLOSE1QUOTE, SC_MASC,
      _______,       KC_LCBR, KC_LBRACKET, KC_LPRN, _______, _______,                                                            SC_SEMICLNENTER, SC_EQUALS,   KC_RPRN, KC_RBRACKET,        KC_RCBR, _______,
      _______,     KC_BSLASH,       KC_AT, KC_HASH, _______, _______, _______,         _______,            _______,     _______,         KC_CIRC,   _______, KC_SCOLON,     KC_COLN,      KC_BSLASH, _______,
                                           _______, _______, _______, LCTL(KC_BSPACE), _______,       SC_SUPERQUES, SC_SUPERDOT,         _______,   _______, _______
    ),
        /*
 */
    [SYMPLUS] = LAYOUT(
      _______, SC_OPENQUOTE,           _______,           _______,     _______, SC_ARROW,                                           _______,         SC_ENDTAG,         SC_EMDASH,         _______,   SC_CLOSEQUOTE, _______,
      _______,   SC_SECTION, OPENCLOSEBRACKETS, SC_OPENCLOSEPAREN, SC_NOTEQUAL,  _______,                                           _______,   SC_EXACTLYEQUAL, SC_PARENSEMICOLON,   SC_SELECTLINE, SC_SURROUNDBRKT, _______,   
      _______,      _______,           _______,           _______,     _______,  _______,_______,  _______,       _______, _______, _______,           _______,    SC_LESSOREQUAL, SC_GREATOREQUAL,        DEL_LINE, _______,
                                                          _______,     _______,  _______, _______, _______,       _______, _______, _______,           _______,           _______
    ),
    [UNICODE] = LAYOUT(
      _______,  _______, _______, _______,     SC_PAR,   SC_GU,                                                   _______, _______,     SC_U,    SC_Y,    _______, _______,
      _______,     SC_A, _______,  SC_SEC, SC_INVBANG, _______,                                                   _______,    SC_N,     SC_E,    SC_I,       SC_O, _______,
      SC_SHIFT, _______, _______, _______,    _______, _______,_______, _______,        _______,         _______, _______, _______, SC_COMMA,  SC_DOT, SC_INVQUES, SC_SHIFT,
                                 _______,     _______, _______, _______, _______,       _______, SC_SUPERINVQUES, _______, _______, _______
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
      _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,_______, _______,        _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
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
      _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,_______, _______,        _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
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
      _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,_______, _______,        _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
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
        case COLEMAK:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case TYPING:
            oled_write_P(PSTR("Typing\n"), false);
            break;
        case NUMPAD:
            oled_write_P(PSTR("Numpad\n"), false);
            break;
        case NAV:
            oled_write_P(PSTR("Navigate\n"), false);
            break;
        case FN:
            oled_write_P(PSTR("Function\n"), false);
            break;
        case SYM:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case SYMPLUS:
            oled_write_P(PSTR("Symbols+\n"), false);
            break;
        case MIRRORED:
            oled_write_P(PSTR("Mirrored\n"), false);
            break;
        case MIRSYM:
            oled_write_P(PSTR("Mirrored symbols\n"), false);
            break;
        case MIRUNI:
            oled_write_P(PSTR("Mirrored unicode\n"), false);
            break;
        case UNICODE:
            oled_write_P(PSTR("Unicode\n"), false);
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
    resume_capslock = true;
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
  if (record->event.pressed) {
    return handle_keypress(keycode);
  }
  return handle_keyrelease(keycode);
}

bool handle_keypress(uint16_t keycode) {
  pressed_time = timer_read();
  if (shift_time != 0) {
      if (!caps_lock_on() && (timer_elapsed(shift_time) < 1000)) {
        set_oneshot_mods(MOD_BIT(KC_LSHIFT));
      }
      shift_time = 0;
    }

    switch (keycode) {
    case SC_SUPERSHIFT:
        handle_supershift();
      return true;
    break;
    case KC_QUOTE:
      if (resume_capslock) {
        resume_capslock = false;
        SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE)));
        tap_code(KC_CAPSLOCK);
        return false;
      }
      SEND_STRING(SS_TAP(X_QUOTE));
      return false;
    break;
    case KC_COMMA:
      if (resume_capslock) {
        resume_capslock = false;
        SEND_STRING(SS_LSFT(SS_TAP(X_COMMA)));
        tap_code(KC_CAPSLOCK);
        return false;
      }
      SEND_STRING(SS_TAP(X_COMMA));
      return false;
    break;
    case MEH_T(KC_DOT):
      if (resume_capslock) {
        resume_capslock = false;
        SEND_STRING(SS_LSFT(SS_TAP(X_DOT)));
        tap_code(KC_CAPSLOCK);
        return false;
      }
      return true;
    break;
    case LT(SYMPLUS,KC_SLASH):
      if (resume_capslock) {
        resume_capslock = false;
        SEND_STRING(SS_LSFT(SS_TAP(X_SLASH)));
        tap_code(KC_CAPSLOCK);
        return false;
      }
      return true;
    break;
  }
  resume_capslock = false;
  if (handle_unicode(keycode)) {
    layer_off(UNICODE);
    layer_off(MIRUNI);
    return false;
  }
  switch (keycode) {
    case SC_SHIFT:
      set_oneshot_mods(MOD_BIT(KC_LSHIFT));
      reset_oneshot_layer();
      layer_on(UNICODE);
      return true;
    break;
    case KC_COLN:
      SEND_STRING(SS_LSFT(SS_TAP(X_SCOLON)));
      return false;
    break;
    case KC_LCBR:
      SEND_STRING(SS_LSFT(SS_TAP(X_LBRACKET)));
      return false;
    break;
    case KC_AMPR:
      SEND_STRING(SS_LSFT(SS_TAP(X_7)));
      return false;
    break;
    case KC_PLUS:
      SEND_STRING(SS_LSFT(SS_TAP(X_EQUAL)));
      return false;
    break;
    case KC_ASTR:
      SEND_STRING(SS_LSFT(SS_TAP(X_8)));
      return false;
    break;
    case KC_AT:
      SEND_STRING(SS_LSFT(SS_TAP(X_2)));
      return false;
    break;
    case KC_PERC:
      SEND_STRING(SS_LSFT(SS_TAP(X_5)));
      return false;
    break;
    case KC_HASH:
      SEND_STRING(SS_LSFT(SS_TAP(X_3)));
      return false;
    break;
    case KC_DLR:
      SEND_STRING(SS_LSFT(SS_TAP(X_4)));
      return false;
    break;
    case KC_TILD:
      SEND_STRING(SS_LSFT(SS_TAP(X_GRV)));
      return false;
    break;
    case KC_PIPE:
      SEND_STRING(SS_LSFT(SS_TAP(X_BSLASH)));
      return false;
    break;
    case KC_RCBR:
      SEND_STRING(SS_LSFT(SS_TAP(X_RBRACKET)));
      return false;
    break;
    case KC_RPRN:
      SEND_STRING(SS_LSFT(SS_TAP(X_0)));
      return false;
    break;
    case KC_LPRN:
      SEND_STRING(SS_LSFT(SS_TAP(X_9)));
      return false;
    break;
    case KC_EXLM:
      SEND_STRING("!");
      return false;
    break;
    case KC_UNDS:
      SEND_STRING("_");
      return false;
    break;
    case SC_SUPERDOT:
      SEND_STRING(". ");
      shift_time = timer_read();
      return true;
    break;
    case SC_SUPERINVQUES:
      set_oneshot_mods(0);
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_1)));
      layer_off(UNICODE);
      layer_off(MIRUNI);
      shift_time = timer_read();
      return false;
    break;   
    case SC_SUPERQUES:
      SEND_STRING("? ");
      shift_time = timer_read();
      return true;
    break;
    case KC_ESCAPE:
      clear_oneshot_mods(); 
      clear_mods();
      shift_time = 0;
      SEND_STRING(SS_TAP(X_ESCAPE));
      return true;
    break; 
    case SC_MIRSHIFT:
      set_oneshot_mods(MOD_BIT(KC_LSHIFT));
      reset_oneshot_layer();
      layer_on(MIRUNI);
      return true;
    break;      
    case SC_A:
    {
      SEND_UNICODE(CAP_ACCENTA, ACCENTA);
      return false;
    }
    break;
    case SC_E:
    {
      SEND_UNICODE(CAP_ACCENTE, ACCENTE);
      return false;
    }
    break;
    case SC_I:
    {
      SEND_UNICODE(CAP_ACCENTI, ACCENTI);
      return false;
    }
    break;
    case SC_O:
    {
      SEND_UNICODE(CAP_ACCENTO, ACCENTO);
      return false;
    }
    break;
    case SC_U:
    {
      SEND_UNICODE(CAP_ACCENTU, ACCENTU);
      return false;
    }
    break;
    case SC_Y:
    {
      SEND_UNICODE(CAP_ACCENTY, ACCENTY);
      return false;
    }
    break;
    case SC_GU:
    {
      SEND_UNICODE(CAP_ACCENTGU, ACCENTGU);
      return false;
    }
    break;
    case SC_N:
    {
      SEND_UNICODE(CAP_ENE, ENE);
      return false;
    }
    break;
    case SC_FEM:
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_6) ));
    break;
    case SC_OPEN1QUOTE:
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_5) ));
    break;
    case SC_CLOSE1QUOTE:
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_6) ));
    break;
    case SC_MASC:
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_7) ));
    break;
    case SC_SEMICLNENTER:
      SEND_STRING(SS_TAP(X_END) SS_DELAY(50) SS_TAP(X_SCOLON) SS_DELAY(50) SS_TAP(X_ENTER));
    break;
    case SC_EQUALS:
      SEND_STRING("==");
    break;
    case SC_ENDTAG:
      SEND_STRING("</");
    break;
    case SC_OPENQUOTE:
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_7) ));
    break;
    case SC_SECTION:
      SEND_STRING(SS_TAP(X_END) SS_DELAY(20) SS_TAP(X_SPACE) SS_DELAY(20) SS_LSFT(SS_TAP(X_LBRACKET)) SS_DELAY(20) SS_TAP(X_ENTER) SS_TAP(X_ENTER) SS_DELAY(20) SS_LSFT(SS_TAP(X_RBRACKET)) SS_DELAY(20) SS_TAP(X_UP) SS_DELAY(20) SS_TAP(X_TAB));
    break;
    case SC_OPENCLOSEPAREN:
      SEND_STRING("()");
    break;
    case SC_NOTEQUAL:
      SEND_STRING("!=");
    break;
    case SC_ENDSECTION:
      SEND_STRING(SS_TAP(X_ENTER) SS_DELAY(20) SS_LSFT(SS_TAP(X_RBRACKET)) SS_DELAY(20) SS_TAP(X_UP) SS_DELAY(20) SS_TAP(X_TAB));
    break;
    case SC_EMDASH:
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_1) ));
    break;
    case SC_CLOSEQUOTE:
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_8) ));
    break;
    case SC_EXACTLYEQUAL:
      SEND_STRING("===");
    break;
    case SC_PARENSEMICOLON:
      SEND_STRING("();");
    break;
    case SC_LESSOREQUAL:
      SEND_STRING("<=");
    break;
    case SC_GREATOREQUAL:
      SEND_STRING(">=");
    break;
    case DEL_LINE:
      SEND_STRING(SS_TAP(X_END) SS_DELAY(50) SS_LSFT(SS_TAP(X_HOME) SS_TAP(X_HOME)) SS_DELAY(50) SS_TAP(X_DELETE) SS_DELAY(50) SS_TAP(X_DELETE));
    break;
    case SC_SURROUNDBRKT:
      SEND_STRING(SS_LCTL(SS_TAP(X_X)) SS_DELAY(20) SS_LSFT(SS_TAP(X_TAB)) SS_DELAY(20) SS_LSFT(SS_TAP(X_LBRACKET)) SS_DELAY(20) SS_TAP(X_ENTER) SS_DELAY(20) SS_LSFT(SS_TAP(X_RBRACKET)) SS_TAP(X_UP) SS_DELAY(20) SS_TAP(X_ENTER) SS_DELAY(20) SS_TAP(X_TAB) SS_DELAY(20) SS_LCTL(SS_TAP(X_V)));
    break;
    case SC_SELECTLINE:
      SEND_STRING(SS_TAP(X_END) SS_DELAY(50) SS_LSFT(SS_TAP(X_HOME)));
    break;
    case OPENCLOSEBRACKETS:
      SEND_STRING("[]");
    break;
    case DELWORD:
      SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)) SS_DELAY(50) SS_LSFT(SS_LCTL(SS_TAP(X_LEFT))) SS_DELAY(50) SS_TAP(X_DELETE));
    break;
    case SC_AS:
        SEND_STRING("AS");
    break;
    case SC_ARROW:
        SEND_STRING("=>");
    break;
    case SC_AR:
      SEND_STRING("AR");
    break;
  }
  layer_off(UNICODE);
  layer_off(MIRUNI);
  return true;
}
bool handle_unicode(uint16_t keycode) {
  switch (keycode) {
  case SC_SEC:
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_7) ));
      return true;
    break;
    case SC_INVQUES:
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_1) ));
      return true;
    break;
    case SC_PAR:
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_2) ));
      return true;
    break;
    case SC_INVBANG:
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_1) ));
      return true;
    break;
    case SC_COMMA:
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_0) ));
      return true;
    break;
    case SC_DOT:
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_3) ));
      return true;
    break;
  }
  return false;
}

bool handle_keyrelease(uint16_t keycode) {
  if (keycode == SC_SUPERSHIFT)
  {
    del_mods(MOD_BIT(KC_LSHIFT));
  }
  return true;
}