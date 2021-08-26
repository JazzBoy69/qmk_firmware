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
  layer_off(UNICODE);\
  layer_off(MIRUNI);\

#ifdef ERGODOX
    #define THIS_SAFE_RANGE EZ_SAFE_RANGE
  #else
    #define THIS_SAFE_RANGE SAFE_RANGE
  #endif

// A 'transparent' key code (that falls back to the layers below it).
#define ___ KC_TRANSPARENT

// A 'blocking' key code. Does nothing but prevent falling back to another layer.
#define XXX KC_NO

enum custom_keycodes {
  SC_FEM = THIS_SAFE_RANGE,
  SC_OPEN1QUOTE,
  SC_CLOSE1QUOTE,
  SC_MASC,
  SC_SEMICLNENTER,
  SC_EQUALS,
  SC_ENDTAG,
  SC_OPENQUOTE,
  SC_OPENCLOSEPAREN,
  SC_NOTEQUAL,
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

#define ________________BLOCK_____________________        XXX,     XXX,     XXX,     XXX,     XXX,    XXX
#define ________________BLANK_____________________        ___,     ___,     ___,     ___,     ___,    ___

#define ________________COLEMAK_L1________________       OSL(UNICODE), KC_Q,      KC_W,         KC_F,         KC_P,    KC_G
#define ________________COLEMAK_L2________________       OSL(SYM),    LT(NUMPAD,KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T),    LT(NAV,KC_D)
#define ________________COLEMAK_L3________________       SC_SUPERSHIFT,KC_Z,             MEH_T(KC_X),         KC_C,         KC_V,    KC_B

#define ________________COLEMAK_R1________________       KC_J,    KC_L,        KC_U,          KC_Y, KC_QUOT, OSL(UNICODE)
#define ________________COLEMAK_R2________________       KC_H,    KC_N,        KC_E,          KC_I,    KC_O, OSL(SYM)   
#define ________________COLEMAK_R3________________       KC_K,    KC_M,    KC_COMMA, MEH_T(KC_DOT), KC_SLSH, SC_SUPERSHIFT

#define _________BOTTOM_L1_________                       KC_DELETE,    KC_ESCAPE,     LT(SYMPLUS,KC_SPACE)
#define _________BOTTOM_R1_________                       OSM(MOD_LCTL),  KC_LGUI,     TO(NUMPAD)
#define ________BLOCK_BOTTOM_______                       XXX,  XXX,  XXX
#define ________BLANK_BOTTOM_______                       ___,  ___,  ___
#define THUMB_L1                                          LT(MIRRORED,KC_BSPACE),LT(FN,KC_ENTER)
#define TH_L2                                             KC_TAB
#define TH_L3                                             LSFT(KC_TAB)
#define THUMB_R1                                          KC_QUES,       KC_SPACE
#define TH_R2                                             KC_F23
#define TH_R3                                             KC_F24

#define ________________TYPING_L1_________________        ________________BLANK_____________________
#define ________________TYPING_L2_________________        ___, ___,  KC_R, KC_S, KC_T, ___
#define ________________TYPING_L3_________________        ___, ___,  KC_X, ___,  ___,  ___
#define ________________TYPING_R1_________________        ________________BLANK_____________________
#define ________________TYPING_R2_________________        ___,   ___, KC_E,  ___, ___, ___
#define ________________TYPING_R3_________________        ___, ___,  ___, KC_DOT, ___, ___

#define ____TYPE_BOTTOM_L1_________                       ________BLANK_BOTTOM_______
#define ____TYPE_BOTTOM_R1_________                       ________BLOCK_BOTTOM_______
#define TYPE_L1                                           KC_BSPACE, KC_ENTER
#define TYPE_L2                                           ___
#define TYPE_L3                                           ___
#define TYPE_R1                                           ___, ___
#define TYPE_R2                                           ___
#define TYPE_R3                                           ___


#define ________________NUMPAD_L1_________________        ________________BLANK_____________________
#define ________________NUMPAD_L2_________________        ___, ___, SC_AR,     SC_AS, ___, ___
#define ________________NUMPAD_L3_________________        ________________BLANK_____________________

#define ________________NUMPAD_R1_________________        XXX,           KC_KP_7, KC_KP_8, KC_KP_9,        KC_COLN, KC_KP_MINUS
#define ________________NUMPAD_R2_________________        OSM(MOD_LALT), KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_ASTERISK,  KC_KP_PLUS
#define ________________NUMPAD_R3_________________        XXX,           KC_KP_1, KC_KP_2, KC_KP_3,    KC_KP_SLASH,    KC_ENTER

#define _____NUM_BOTTOM_L1_________                       ________BLANK_BOTTOM_______
#define _____NUM_BOTTOM_R1_________                       KC_X,    KC_KP_COMMA,  KC_KP_DOT


#define NUM_L1                                            ___, ___
#define NUM_L2                                            LCTL(KC_Z)
#define NUM_L3                                            LCTL(KC_Y)
#define NUM_R1                                            KC_ESCAPE,  KC_KP_0
#define NUM_R2                                            KC_NUMLOCK
#define NUM_R3                                            TO(COLEMAK)

#define ________________NAV_L1____________________        ________________BLANK_____________________
#define ________________NAV_L2____________________        ___, ___,  ___,  KC_LCTRL, KC_LSHIFT, ___
#define ________________NAV_L3____________________        ________________BLANK_____________________

#define ________________NAV_R1____________________        LCTL(KC_HOME),  OSM(MOD_LCTL),   KC_UP,      KC_PGUP,      XXX,        KC_MS_WH_UP
#define ________________NAV_R2____________________        LCTL(KC_LEFT),     KC_LEFT,     KC_DOWN,    KC_RIGHT,  LCTL(KC_RIGHT), KC_MS_WH_DOWN
#define ________________NAV_R3____________________          DELWORD,        KC_DELETE,      XXX,      KC_PGDOWN,  LCTL(KC_END),  OSM(MOD_LSFT)


#define _____NAV_BOTTOM_L1_________                       ________BLANK_BOTTOM_______
#define _____NAV_BOTTOM_R1_________                       KC_X,    KC_KP_COMMA,  KC_KP_DOT

#define NAV_L1                                            KC_MS_BTN2,  KC_MS_BTN1
#define NAV_L2                                            _______
#define NAV_L3                                            _______
#define NAV_R1                                            KC_HOME,  KC_END
#define NAV_R2                                            KC_SCROLLLOCK
#define NAV_R3                                            TO(COLEMAK)


#define ________________FN_L1_____________________        RESET,           ___,           ___,     SC_EMDASH,      ___,     ___
#define ________________FN_L2_____________________        KC_SYSTEM_SLEEP,      KC_1,  LALT_T(KC_2), LCTL_T(KC_3), LSFT_T(KC_4), KC_5
#define ________________FN_L3_____________________        KC_PSCREEN,           KC_6,         KC_7,         KC_8,       KC_9,    KC_0

#define ________________FN_R1_____________________        XXX, KC_F7, KC_F8, KC_F9, XXX,  KC_F12
#define ________________FN_R2_____________________        XXX, KC_F4, KC_F5, KC_F6, XXX,  XXX
#define ________________FN_R3_____________________        XXX, KC_F1, KC_F2, KC_F3, XXX,  ___


#define _____FN_BOTTOM_L1__________                       ________BLANK_BOTTOM_______
#define _____FN_BOTTOM_R1__________                       ________BLANK_BOTTOM_______

#define FN_L1                                             ___, ___
#define FN_L2                                             _______
#define FN_L3                                             _______
#define FN_R1                                             KC_F11, KC_F10
#define FN_R2                                             _______
#define FN_R3                                             _______

#define ________________SYM_L1____________________        SC_FEM,        SC_OPEN1QUOTE,      KC_AMPR,       KC_PLUS,        KC_ASTR,        KC_EQUAL
#define ________________SYM_L2____________________        ___,              KC_LCBR,       KC_LBRACKET,    KC_LPRN,        KC_EXLM,        KC_UNDS
#define ________________SYM_L3____________________        ___,              KC_BSLASH,       KC_AT,        KC_HASH,        KC_DLR,         KC_PERC

#define ________________SYM_R1____________________         KC_TILD,      KC_SLASH,      KC_MINUS,         KC_PIPE,      SC_CLOSE1QUOTE,   SC_MASC
#define ________________SYM_R2____________________        SC_SEMICLNENTER,   SC_EQUALS,  KC_RPRN,        KC_RBRACKET,     KC_RCBR,         ___
#define ________________SYM_R3____________________          KC_CIRC,        ___,         KC_SCOLON,        KC_COLN,     KC_BSLASH,          ___


#define _____SYM_BOTTOM_L1_________                       ________BLANK_BOTTOM_______
#define _____SYM_BOTTOM_R1_________                       ________BLANK_BOTTOM_______

#define SYM_L1                                            LCTL(KC_BSPACE),  ___
#define SYM_L2                                            _______
#define SYM_L3                                            _______
#define SYM_R1                                            SC_SUPERQUES, SC_SUPERDOT
#define SYM_R2                                            _______
#define SYM_R3                                            _______


#define ________________SYMP_L1___________________        ___,         ___,   KC_UP,      ___,   ___, ___
#define ________________SYMP_L2___________________        KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT,   ___, ___
#define ________________SYMP_L3___________________        KC_END,      ___,     ___,      ___,   ___, ___

#define ________________SYMP_R1___________________        ___,       SC_ENDTAG,         SC_EMDASH,             ___,   SC_CLOSEQUOTE,   ___
#define ________________SYMP_R2___________________        ___, SC_EXACTLYEQUAL, SC_PARENSEMICOLON,   SC_SELECTLINE, SC_SURROUNDBRKT,   ___
#define ________________SYMP_R3___________________        ___,             ___,    SC_LESSOREQUAL, SC_GREATOREQUAL,        DEL_LINE,   ___


#define _____SYMP_BOTTOM_L1________                       ________BLANK_BOTTOM_______
#define _____SYMP_BOTTOM_R1________                       ________BLANK_BOTTOM_______

#define SYMP_L1                                            ___,  ___
#define SYMP_L2                                            _______
#define SYMP_L3                                            _______
#define SYMP_R1                                            ___,  ___
#define SYMP_R2                                            _______
#define SYMP_R3                                            _______


#define ________________UNI_L1____________________        ___,      ___,   ___,  ___,  SC_PAR,     SC_GU
#define ________________UNI_L2____________________        ___,      SC_A,  ___, SC_SEC, SC_INVBANG, ___
#define ________________UNI_L3____________________        SC_SHIFT, ___,   ___,  ___,   ___,        ___

#define ________________UNI_R1____________________         ___,    ___,  SC_U,     SC_Y,     ___,   ___
#define ________________UNI_R2____________________         ___,   SC_N,  SC_E,     SC_I,    SC_O,   ___
#define ________________UNI_R3____________________         ___,    ___,  SC_COMMA, SC_DOT, SC_INVQUES, SC_SHIFT


#define _____UNI_BOTTOM_L1_________                       ________BLANK_BOTTOM_______
#define _____UNI_BOTTOM_R1_________                       ________BLANK_BOTTOM_______

#define UNI_L1                                            ___,  ___
#define UNI_L2                                            _______
#define UNI_L3                                            _______
#define UNI_R1                                            SC_SUPERINVQUES, ___
#define UNI_R2                                            _______
#define UNI_R3                                            _______


#define ________________MIR_L1____________________        OSL(MIRUNI),     KC_QUOTE,          KC_Y,           KC_U,        KC_L,         KC_J
#define ________________MIR_L2____________________        OSL(MIRSYM),      KC_O,             KC_I,           KC_E,        KC_N,         KC_H
#define ________________MIR_L3____________________        ___,             KC_QUES,          KC_DOT,        KC_COMMA,      KC_M,         KC_K

#define ________________MIR_R1____________________         SC_ARROW,   SC_ENDTAG,         SC_EMDASH,               ___, SC_OPENQUOTE,   ___
#define ________________MIR_R2____________________              ___, SC_NOTEQUAL, SC_OPENCLOSEPAREN, OPENCLOSEBRACKETS,   SC_SECTION,   ___
#define ________________MIR_R3____________________              ___,         ___,    SC_LESSOREQUAL,   SC_GREATOREQUAL,     DEL_LINE,   ___


#define _____MIR_BOTTOM_L1_________                       ________BLANK_BOTTOM_______
#define _____MIR_BOTTOM_R1_________                       ________BLANK_BOTTOM_______

#define MIR_L1                                            ___,  ___
#define MIR_L2                                            _______
#define MIR_L3                                            _______
#define MIR_R1                                            ___, ___
#define MIR_R2                                            _______
#define MIR_R3                                            _______


#define ________________MRU_L1____________________        ___,        ___, SC_Y, SC_U, SC_PAR, SC_GU
#define ________________MRU_L2____________________        ___,       SC_O, SC_I, SC_E,   SC_N,   ___
#define ________________MRU_L3____________________        ___, SC_INVQUES,  ___,  ___,    ___,   ___

#define ________________MRU_R1____________________         ________________BLANK_____________________
#define ________________MRU_R2____________________         ________________BLANK_____________________
#define ________________MRU_R3____________________         ________________BLANK_____________________ 


#define _____MRU_BOTTOM_L1_________                       ________BLANK_BOTTOM_______
#define _____MRU_BOTTOM_R1_________                       ________BLANK_BOTTOM_______

#define MRU_L1                                            ___,  ___
#define MRU_L2                                            _______
#define MRU_L3                                            _______
#define MRU_R1                                            ___, ___
#define MRU_R2                                            _______
#define MRU_R3                                            _______


#define ________________MRS_L1____________________        SC_FEM, SC_CLOSE1QUOTE,     KC_PIPE,  KC_MINUS,  KC_SLASH,         KC_TILD
#define ________________MRS_L2____________________           ___,        KC_RCBR, KC_RBRACKET,   KC_RPRN, SC_EQUALS, SC_SEMICLNENTER
#define ________________MRS_L3____________________           ___,      KC_BSLASH,     KC_COLN, KC_SCOLON,       ___,         KC_CIRC

#define ________________MRS_R1____________________         ________________BLANK_____________________
#define ________________MRS_R2____________________         ________________BLANK_____________________
#define ________________MRS_R3____________________         ________________BLANK_____________________ 


#define _____MRS_BOTTOM_L1_________                       ________BLANK_BOTTOM_______
#define _____MRS_BOTTOM_R1_________                       ________BLANK_BOTTOM_______

#define MRS_L1                                            ___,  ___
#define MRS_L2                                            _______
#define MRS_L3                                            _______
#define MRS_R1                                            ___, ___
#define MRS_R2                                            _______
#define MRS_R3                                            _______


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
bool resume_capslock = true;
bool handle_keypress(uint16_t keycode);
bool handle_keyrelease(uint16_t keycode);
bool handle_unicode(uint16_t keycode);
void handle_matrix_scan(void);
bool capslock_desactivated(void);


#define HANDLE_MATRIX_SCAN if (current_layer == COLEMAK) {\
        if (get_current_wpm()>40) {\
        layer_on(TYPING);\
        }\
        return;\
    }\
    if (current_layer == TYPING) {\
        if ((get_current_wpm()<=40) || (timer_elapsed(pressed_time) > 1000)) {\
        shift_time = 0;\
        layer_off(TYPING);\
        set_current_wpm(0);\
        }\
        return;\
    }\


#define HANDLE_RETRO_TAPPING  if ((keycode == LCTL_T(KC_CAPSLOCK)) || (keycode == LCTL_T(KC_S)) \
    || (keycode == LSFT_T(KC_T))\
    || (keycode == OSL(SYM)) || (keycode == OSL(UNICODE)) || (keycode == MEH_T(KC_SPACE))\
    || (keycode == MEH_T(KC_X)) || (keycode == MEH_T(KC_DOT))) {\
        return false;\
    }\
    return true;\

#define HANDLE_TAPPING_TERM if (keycode == LT(NUMPAD,KC_A)) {\
      return 170;\
    }\
     if ((current_layer == TYPING) ||\
       (keycode == OSM(MOD_LSFT)) \
     ) {\
      return 300;\
    }\
    if (keycode == MEH_T(KC_X)) {\
      return 250;\
    }\
    if ((keycode == LALT_T(KC_R)) || \
        (keycode == MEH_T(KC_SPACE)) || \
        (keycode == LSFT_T(KC_T)) ||\
        (keycode == LCTL_T(KC_S))\
    ) {\
      return 150;\
    }\
    return TAPPING_TERM;\



#define HANDLE_KEY_PRESS if (record->event.pressed) {\
    return handle_keypress(keycode);\
  }\
  return handle_keyrelease(keycode);\


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
      SEND_STRING(SS_TAP(X_QUOTE));
      return false;
    break;
    case KC_COMMA:
      SEND_STRING(SS_TAP(X_COMMA));
      return false;
    break;
    case MEH_T(KC_DOT):
      SEND_STRING(SS_TAP(X_DOT));
      return false;
    break;
    case KC_SLASH:
      SEND_STRING(SS_TAP(X_SLASH));
      return false;
    break;
  }
  if (capslock_desactivated()) {
    tap_code(KC_CAPSLOCK);
  }
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
      SEND_STRING(SS_TAP(X_END) SS_TAP(X_SCOLON) SS_TAP(X_ENTER));
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
    if (shift_count > 0) {
      set_oneshot_mods(0);
      shift_count = 0;
      tap_code(KC_CAPSLOCK);
      return true;
    }
    shift_count = 1;
  }
  return true;
}

#define HANDLE_ONESHOT_MODS  if (!(mods & MOD_MASK_SHIFT)) {\
   shift_count = 0;\
 }\


 void handle_supershift() {
  add_mods(MOD_BIT(KC_LSHIFT));
  set_oneshot_mods(MOD_BIT(KC_LSHIFT));
}

bool capslock_desactivated() {
  return caps_lock_on() && ((get_oneshot_mods() & MOD_BIT(KC_LSHIFT)) == MOD_BIT(KC_LSHIFT)) && (!((get_mods() & MOD_BIT(KC_LSHIFT)) == MOD_BIT(KC_LSHIFT)));
}
  
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
