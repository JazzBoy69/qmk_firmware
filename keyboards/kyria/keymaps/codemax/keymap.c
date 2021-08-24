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
#include "codemax.h"


#define LAYOUT_wrapper(...)            LAYOUT(__VA_ARGS__)
#define LAYOUT_kyria_base( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F,\
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39\
  ) \
  LAYOUT_wrapper( \
         K00,  K01,     K02,     K03,     K04,     K05,                                             K06,     K07,     K08,     K09,     K0A,     K0B, \
         K10,  K11,     K12,     K13,     K14,     K15,                                             K16,     K17,     K18,     K19,     K1A,     K1B, \
         K20,  K21,     K22,     K23,     K24,     K25,  K26, K27,                        K28, K29, K2A,     K2B,     K2C,     K2D,     K2E,     K2F, \
                                 K30,     K31,     K32,  K33, K34,                        K35, K36,  K37,    K38,     K39 \
    )
/* Re-pass though to allow templates to be used */
#define LAYOUT_kyria_base_wrapper(...)       LAYOUT_kyria_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [COLEMAK] = LAYOUT_kyria_base_wrapper( 
    ________________COLEMAK_L1________________,                                ________________COLEMAK_R1________________,
    ________________COLEMAK_L2________________,                                ________________COLEMAK_R2________________,
    ________________COLEMAK_L3________________, TH_L2, TH_L3,    TH_R2, TH_R3, ________________COLEMAK_R3________________,
                     _________BOTTOM_L1_________, THUMB_L1,          THUMB_R1, _________BOTTOM_R1_________
),
/*
 */
    [TYPING] = LAYOUT_kyria_base_wrapper(
    ________________TYPING_L1_________________,                                       ________________TYPING_R1_________________, 
    ________________TYPING_L2_________________,                                       ________________TYPING_R2_________________, 
    ________________TYPING_L3_________________, TYPE_L2, TYPE_L3,  TYPE_R2, TYPE_R3,  ________________TYPING_R3_________________, 
                  ____TYPE_BOTTOM_L1_________,            TYPE_L1,  TYPE_R1,             ____TYPE_BOTTOM_R1_________   
  ), 
/*
 *                        `----------------------------------'  `----------------------------------'
 */
    [NUMPAD] = LAYOUT_kyria_base_wrapper(
      ________________NUMPAD_L1_________________,                                     ________________NUMPAD_R1_________________,
      ________________NUMPAD_L2_________________,                                     ________________NUMPAD_R2_________________,
      ________________NUMPAD_L3_________________,   NUM_L2, NUM_L3,  NUM_R2, NUM_R3,  ________________NUMPAD_R3_________________,
                    _____NUM_BOTTOM_L1_________,        NUM_L1,         NUM_R1,          _____NUM_BOTTOM_R1_________
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
 *                        `----------------------------------'  `----------------------------------'
 */
    [MIRRORED] = LAYOUT(
      OSL(MIRUNI), KC_QUOTE,   KC_Y,     KC_U,    KC_L,    KC_J,                                             _______,       SC_ENDTAG,         SC_EMDASH,         _______,   SC_CLOSEQUOTE, _______,
      OSL(MIRSYM),     KC_O,   KC_I,     KC_E,    KC_N,    KC_H,                                             _______, SC_EXACTLYEQUAL, SC_PARENSEMICOLON,   SC_SELECTLINE, SC_SURROUNDBRKT, _______,   
          _______,  KC_QUES, KC_DOT, KC_COMMA,    KC_M,    KC_K, _______, _______,        _______, _______,  _______,         _______,    SC_LESSOREQUAL, SC_GREATOREQUAL,        DEL_LINE, _______,
                                      _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
    ),
            /*
 */
    [MIRSYM] = LAYOUT(
       SC_FEM, SC_CLOSE1QUOTE,     KC_PIPE,  KC_MINUS,  KC_SLASH,         KC_TILD,                                           _______, _______, _______, _______, _______, _______,
      _______,        KC_RCBR, KC_RBRACKET,   KC_RPRN, SC_EQUALS, SC_SEMICLNENTER,                                           _______, _______, _______, _______, _______, _______,
      _______,      KC_BSLASH,     KC_COLN, KC_SCOLON,   _______,         KC_CIRC, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______,
                                              _______,   _______,         _______, _______, _______,       _______, _______, _______, _______, _______
    ),
            /*
 */
    [MIRUNI] = LAYOUT(
          _______,    _______,    SC_Y,    SC_U,  SC_PAR,   SC_GU,                                           _______, _______, _______, _______, _______, _______,
          _______,       SC_O,    SC_I,    SC_E,    SC_N, _______,                                           _______, _______, _______, _______, _______, _______,
      SC_MIRSHIFT, SC_INVQUES, _______, _______, _______, _______,_______, _______,        _______, _______, _______, _______, _______, _______, _______, _______,
                                        _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    current_layer = biton32(state);
    change_time = timer_read();
    return update_tri_layer_state(state, COLEMAK, SYM, NUMPAD);
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




void matrix_scan_user(void) {
  HANDLE_MATRIX_SCAN
};



bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
  HANDLE_RETRO_TAPPING
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    HANDLE_TAPPING_TERM
}

void oneshot_mods_changed_user(uint8_t mods) {
  HANDLE_ONESHOT_MODS
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  HANDLE_KEY_PRESS
}
