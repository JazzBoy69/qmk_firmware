#define COLEMAK 0
#define NUMPAD 1
#define NAV 2
#define GAME 3
#define FN 4
#define MIRRORED 5
#define MIRSYM 6
#define MIRUNI 7
#define SPANISH 8
#define SYMBOL 9

#define SP_RBKT KC_BSLASH
#define SP_LBKT KC_QUOT
#define SP_QUOTE KC_MINUS
#define SP_LPAREN KC_ASTR
#define SP_RPAREN KC_LPRN
#define ES_MINS KC_SLSH // -
#define ES_GRV  KC_LBRC // ` (dead)
#define ES_MORD KC_GRV  // º
#define ES_PLUS KC_RBRC // +
#define ES_FORD S(ES_MORD) // ª
#define ES_EXLM S(KC_1)    // !
#define ES_IEXL KC_EQL  // ¡
#define ES_DQUO S(KC_2)    // "
#define ES_BULT S(KC_3)    // ·
#define ES_DLR  S(KC_4)    // $
#define ES_PERC S(KC_5)    // %
#define ES_AMPR S(KC_6)    // &
#define ES_SLSH S(KC_7)    // /
#define ES_LPRN S(KC_8)    // (
#define ES_RPRN S(KC_9)    // )
#define ES_EQL  S(KC_0)    // =
#define ES_IQUE S(ES_IEXL) // ¿
#define ES_UNDS S(ES_MINS) // _
#define ES_BSLS ALGR(ES_MORD) // (backslash)
#define ES_PIPE ALGR(KC_1)    // |
#define ES_AT   ALGR(KC_2)    // @
#define ES_HASH ALGR(KC_3)    // #
#define ES_TILD ALGR(KC_4)    // ~
#define ES_LBRC ALGR(ES_GRV)  // [
#define ES_RBRC ALGR(ES_PLUS) // ]
#define ES_ASTR S(KC_RBRC) // *
#define ES_QUES S(KC_MINUS)
#define ES_COLON S(KC_DOT)
#define ES_SEMI S(KC_COMMA)

#define ESP_SLASH SS_LSFT(SS_TAP(X_7))
#define ESP_QUES SS_TAP(X_MINUS)
#define ESP_GT SS_LSFT(SS_TAP(X_NUBS))
#define ESP_LT SS_TAP(X_NUBS)
#define ESP_2QUOTE SS_LSFT(SS_TAP(X_2))

uint16_t OPEN1QUOTE[4] = { KC_KP_0, KC_KP_1, KC_KP_4, KC_KP_5 };
uint16_t CLOSE1QUOTE[4] = { KC_KP_0, KC_KP_1, KC_KP_4, KC_KP_6 };
uint16_t OPENQUOTE[4] = { KC_KP_0, KC_KP_1, KC_KP_4, KC_KP_7 };
uint16_t EMDASH[4] = { KC_KP_0, KC_KP_1, KC_KP_5, KC_KP_1 };
uint16_t CLOSEQUOTE[4] = { KC_KP_0, KC_KP_1, KC_KP_4, KC_KP_8 };
uint16_t SEC[4] = { KC_KP_0, KC_KP_1, KC_KP_6, KC_KP_7 };
uint16_t INVQUES[4] = { KC_KP_0, KC_KP_1, KC_KP_9, KC_KP_1 };
uint16_t PAR[4] = { KC_KP_0, KC_KP_1, KC_KP_8, KC_KP_2 };
uint16_t INVBANG[4] = { KC_KP_0, KC_KP_1, KC_KP_6, KC_KP_1 };
uint16_t COMMA[4] = { KC_KP_0, KC_KP_1, KC_KP_8, KC_KP_0 };
uint16_t DOT[4] = { KC_KP_0, KC_KP_1, KC_KP_8, KC_KP_3 };
uint16_t BULLET[4] = { KC_KP_0, KC_KP_1, KC_KP_4, KC_KP_9 };
uint16_t NONBREAKINGSPACE[3] = {KC_KP_2, KC_KP_5, KC_KP_5 };


#ifdef ERGODOX
    #define THIS_SAFE_RANGE EZ_SAFE_RANGE
  #else
    #define THIS_SAFE_RANGE SAFE_RANGE
  #endif

#define ___ KC_TRANSPARENT
#define XXX KC_NO

enum custom_keycodes {
  SC_OPEN1QUOTE = THIS_SAFE_RANGE,
  SC_CLOSE1QUOTE,
  SC_SEMICLNENTER,
  SC_EQUALS,
  SC_ENDTAG,
  SC_OPENQUOTE,
  SC_OPENCLOSEPAREN,
  SC_NOTEQUAL,
  SC_EMDASH,
  SC_CLOSEQUOTE,
  SC_LESSOREQUAL,
  SC_GREATOREQUAL,
  DEL_LINE,
  SC_SURROUNDBRKT,
  SC_SELECTLINE,
  OPENCLOSEBRACKETS,
  DELWORD,
  LOCKALT,
  SC_INVBANG,
  SC_DOT,
  SC_COMMA,
  SC_INVQUES,
  SC_MIRSHIFT,
  SC_AS,
  SC_AR,
  SC_ARROW,
  SC_SUPERDOT,
  SC_SUPERQUES,
  SC_SUPERINVQUES,
  SC_SECTION,
  SP_SLASH,
  SP_CARET,
  SP_GRAVE,
  SP_A,
  SP_O,
  SP_I,
  SP_E,
  SP_N,
  SP_U,
  SP_Y,
  SP_G,
  SC_CLOSESEMI,
  SC_OPENCLOSESEMI,
  SC_QUE,
  SC_QUIEN,
  SP_CUA,
  SP_CO,
};



#define ________________BLOCK_____________________        XXX,     XXX,     XXX,     XXX,     XXX,    XXX
#define ________________BLANK_____________________        ___,     ___,     ___,     ___,     ___,    ___

#define ________________COLEMAK_L1________________       OSL(NUMPAD),          KC_Q,     KC_W, MEH_T(KC_F), KC_P,    KC_G
#define ________________COLEMAK_L2________________       OSL(SPANISH),         KC_A,     KC_R, KC_S,        KC_T,    LT(NAV,KC_D)
#define ________________COLEMAK_L3________________       OSM(MOD_LSFT),        KC_Z,     KC_X, KC_C,        KC_V,    KC_B

#define ________________COLEMAK_R1________________       KC_J,            KC_L, MEH_T(KC_U),          KC_Y, SP_QUOTE, LGUI_T(KC_CAPSLOCK)
#define ________________COLEMAK_R2________________       SCMD_T(KC_H),    KC_N,        KC_E,          KC_I,    KC_O,  OSL(SPANISH)
#define ________________COLEMAK_R3________________       KC_K,            KC_M,    KC_COMMA,        KC_DOT, SP_SLASH, OSM(MOD_LSFT)

#define _________BOTTOM_L1_________                       LALT_T(KC_DELETE),   LCTL_T(KC_ESCAPE),  LSFT_T(KC_SPACE)
#define _________BOTTOM_R1_________                       SC_CLOSESEMI,        ES_SEMI,            ES_COLON  
#define ________BLOCK_BOTTOM_______                       XXX,  XXX,  XXX
#define ________BLANK_BOTTOM_______                       ___,  ___,  ___
#define THUMB_L1                                          LT(MIRRORED,KC_BSPACE),LT(FN,KC_ENTER)
#define TH_L2                                             XXX
#define TH_L3                                             XXX
#define THUMB_R1                                          SC_SUPERQUES,    LCTL_T(KC_SPACE)
#define TH_R2                                             _______
#define TH_R3                                             _______


#define ________________NUMPAD_L1_________________        TO(COLEMAK),     ___,     ___, S(KC_F),    ___,   ___
#define ________________NUMPAD_L2_________________        XXX,         S(KC_A),     ___, S(KC_E),    ___, S(KC_D)
#define ________________NUMPAD_L3_________________        TO(NUMPAD),      ___,     ___, S(KC_C),    ___, S(KC_B)

#define ________________NUMPAD_R1_________________        ES_HASH,      KC_KP_7, KC_KP_8, KC_KP_9, ES_COLON,     KC_KP_MINUS
#define ________________NUMPAD_R2_________________        ES_DLR,       KC_KP_4, KC_KP_5, KC_KP_6, ES_SEMI,      KC_KP_PLUS
#define ________________NUMPAD_R3_________________        ES_AMPR,      KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_SLASH,  KC_ENTER

#define _____NUM_BOTTOM_L1_________                       ________BLANK_BOTTOM_______
#define _____NUM_BOTTOM_R1_________                       KC_SPACE,    KC_COMMA,  KC_DOT


#define NUM_L1                                            LALT_T(KC_BSPACE), ___
#define NUM_L2                                            ___
#define NUM_L3                                            ___
#define NUM_R1                                            KC_ESCAPE,  KC_KP_0
#define NUM_R2                                            ___
#define NUM_R3                                            ___



#define ________________SPANSH_L1_________________        ___,  S(KC_F18),  ___,     ___,     ___, SP_G
#define ________________SPANSH_L2_________________        ___,   SP_A,     S(KC_TAB),  KC_TAB, ES_IEXL, ___
#define ________________SPANSH_L3_________________        OSM(MOD_LSFT),   ___,     ___,     ___, ___, ___

#define ________________SPANSH_R1_________________        ___,  KC_LALT,  SP_U, SP_Y, SP_CUA,   ___
#define ________________SPANSH_R2_________________        SC_QUE, SP_N, SP_E, SP_I,  SP_O, ___
#define ________________SPANSH_R3_________________        SC_QUIEN, SP_CO, KC_F18, SC_DOT,  ES_IQUE, OSM(MOD_LSFT)

#define _____SPA_BOTTOM_L1_________                       ________BLANK_BOTTOM_______
#define _____SPA_BOTTOM_R1_________                       ________BLANK_BOTTOM_______


#define SPA_L1                                            TO(COLEMAK), ___
#define SPA_L2                                            ___
#define SPA_L3                                            ___
#define SPA_R1                                            SC_SUPERINVQUES,  SC_SUPERDOT
#define SPA_R2                                            ___
#define SPA_R3                                            ___

#define ________________SYM_L1_________________        ___,   SC_OPEN1QUOTE,  ES_AMPR,  ES_PLUS, ES_ASTR, ES_EQL
#define ________________SYM_L2_________________        ___,   SP_LBKT,  ES_LBRC,  ES_LPRN, ES_EXLM, ___
#define ________________SYM_L3_________________        ___,   ES_SLSH,  ES_AT,  ES_HASH, ES_DLR, ES_PERC

#define ________________SYM_R1_________________        ES_TILD,  ES_SLSH,  ES_MINS, ES_PIPE, SC_CLOSE1QUOTE,   ___
#define ________________SYM_R2_________________        ___, SC_EQUALS, ES_RPRN, ES_RBRC,  SP_RBKT, ___
#define ________________SYM_R3_________________        SP_CARET, SP_GRAVE, ES_SEMI, ES_COLON, ES_BSLS, ___

#define _____SYM_BOTTOM_L1_________                       ________BLANK_BOTTOM_______
#define _____SYM_BOTTOM_R1_________                       ________BLANK_BOTTOM_______


#define SYM_L1                                            LCTL(KC_BSPACE), ___
#define SYM_L2                                            ___
#define SYM_L3                                            ___
#define SYM_R1                                            SC_SUPERQUES,  SC_SUPERDOT
#define SYM_R2                                            ___
#define SYM_R3                                            ___

#define ________________NAV_L1____________________        KC_SCROLLLOCK, ___,  ___,       ___,       ___, ___
#define ________________NAV_L2____________________        TO(COLEMAK),   ___,  KC_LALT,  KC_LCTRL, KC_LSHIFT, ___
#define ________________NAV_L3____________________        ________________BLANK_____________________

#define ________________NAV_R1____________________        LCTL(KC_HOME),  OSM(MOD_LCTL),   KC_UP,      KC_PGUP,      XXX,        KC_MS_WH_UP
#define ________________NAV_R2____________________        LCTL(KC_LEFT),     KC_LEFT,     KC_DOWN,    KC_RIGHT,  LCTL(KC_RIGHT), KC_MS_WH_DOWN
#define ________________NAV_R3____________________          DELWORD,        KC_DELETE, SC_SELECTLINE,KC_PGDOWN,  LCTL(KC_END),  OSM(MOD_LSFT)


#define _____NAV_BOTTOM_L1_________                       ________BLANK_BOTTOM_______
#define _____NAV_BOTTOM_R1_________                       ___,  ___, DEL_LINE

#define NAV_L1                                            KC_MS_BTN2,  KC_MS_BTN1
#define NAV_L2                                            _______
#define NAV_L3                                            _______
#define NAV_R1                                            KC_HOME,  KC_END
#define NAV_R2                                            KC_SCROLLLOCK
#define NAV_R3                                            TO(COLEMAK)


#define ________________FN_L1_____________________        RESET,                 ___,           ___,          ___,          ___,     ___
#define ________________FN_L2_____________________        KC_SYSTEM_SLEEP,      KC_1,  LALT_T(KC_2), LCTL_T(KC_3), LSFT_T(KC_4), KC_5
#define ________________FN_L3_____________________        KC_PSCREEN,           KC_6,         KC_7,         KC_8,       KC_9,    KC_0

#define ________________FN_R1_____________________        XXX, KC_F7, KC_F8, KC_F9, XXX,  KC_F12
#define ________________FN_R2_____________________        XXX, KC_F4, KC_F5, KC_F6, XXX,  LALT(LCTL(KC_DEL))
#define ________________FN_R3_____________________        XXX, KC_F1, KC_F2, KC_F3, XXX,  KC_SYSTEM_POWER


#define _____FN_BOTTOM_L1__________                       ________BLANK_BOTTOM_______
#define _____FN_BOTTOM_R1__________                       ________BLANK_BOTTOM_______

#define FN_L1                                             ___, ___
#define FN_L2                                             _______
#define FN_L3                                             _______
#define FN_R1                                             KC_F11, KC_F10
#define FN_R2                                             _______
#define FN_R3                                             _______


#define ________________MIR_L1____________________        OSL(MIRUNI),     SP_QUOTE,          KC_Y,           KC_U,        KC_L,         KC_J
#define ________________MIR_L2____________________        OSL(MIRSYM),      KC_O,     LALT_T(KC_I),   LCTL_T(KC_E), LSFT_T(KC_N),         KC_H
#define ________________MIR_L3____________________        ___,             SP_SLASH,        KC_DOT,        KC_COMMA,      KC_M,         KC_K

#define ________________MIR_R1____________________         SC_ARROW,   SC_ENDTAG,         SC_EMDASH,               ___,       ___,   SC_SURROUNDBRKT
#define ________________MIR_R2____________________              ___, SC_NOTEQUAL, SC_OPENCLOSEPAREN, OPENCLOSEBRACKETS,   SC_SECTION,   ___
#define ________________MIR_R3____________________              ___,         ___,    SC_LESSOREQUAL,   SC_GREATOREQUAL,     ___,   ___


#define _____MIR_BOTTOM_L1_________                       ________BLANK_BOTTOM_______
#define _____MIR_BOTTOM_R1_________                       SC_OPENCLOSESEMI, ___, ___

#define MIR_L1                                            ___,  ___
#define MIR_L2                                            _______
#define MIR_L3                                            _______
#define MIR_R1                                            LSFT(KC_TAB), KC_TAB
#define MIR_R2                                            _______
#define MIR_R3                                            _______


#define ________________MRU_L1____________________        ___,  ___, SP_Y, SP_U,   ___,   ___
#define ________________MRU_L2____________________        ___, SP_O, SP_I, SP_E,  SP_N,   ___
#define ________________MRU_L3____________________        ___,  ___,  ___,  ___,   ___,   ___

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


#define ________________MRS_L1____________________           SP_RBKT,      ___,  ES_PIPE, ES_MINS,  ES_SLSH,  ES_TILD
#define ________________MRS_L2____________________           ES_RPRN,      ___,  ES_RBRC,     ___,   ES_EQL,    ___
#define ________________MRS_L3____________________           ___,      ES_BSLS, ES_COLON, ES_SEMI,   ES_GRV,   SP_CARET

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


#define ________________MEDIA_____________________           KC_MSTP,   KC_MPRV, KC_F17, KC_MPLY,  KC_MNXT,  ___

uint8_t caps_lock_on(void);
uint8_t shift_pressed(void);
bool shift_held(void);
uint8_t current_layer = 0;
uint16_t change_time = 0;
bool handle_keypress(uint16_t keycode);
bool handle_keyrelease(uint16_t keycode);
bool handle_unicode(uint16_t keycode);
void SendShiftedAltCode(uint16_t shifted[], uint16_t unshifted[]);
void SendAltCode(uint16_t code[], int length);
bool handle_shiftedsymbols(uint16_t keycode);
void press_tilde_and_letter(uint8_t keycode);
uint16_t pressed_time = 0;
uint16_t shift_time = 0;
void handle_shifttimer(void);


void handle_shifttimer() {
  pressed_time = timer_read();
  if (shift_time != 0) {//add shift to capitalize first letter of sentence
      if (!caps_lock_on() && (timer_elapsed(shift_time) < 2000)) {
        set_oneshot_mods(MOD_BIT(KC_LSHIFT));
      }
      shift_time = 0;
  }
}

void press_tilde_and_letter(uint8_t keycode) {
    if (shift_pressed()) {
        clear_oneshot_mods();
        clear_mods();
        tap_code(KC_QUOTE);
        register_code(KC_LSHIFT);
        tap_code(keycode);
        unregister_code(KC_LSHIFT);
        return;
    }
    tap_code(KC_QUOTE);
    tap_code(keycode);
}

void SendShiftedAltCode(uint16_t shifted[], uint16_t unshifted[]) {
  uint8_t caps = caps_lock_on();
  uint8_t shift = shift_pressed();
  if (caps) {
    SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(30));
  }
  if ((caps + shift) == 1) {
    clear_oneshot_mods();
    SendAltCode(shifted, 4);
  }
    else {
      SendAltCode(unshifted, 4);
  }
  if (caps) {
    SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(30));
  }
  layer_off(MIRUNI);
}

void SendAltCode(uint16_t code[], int length) {
  register_code(KC_LALT);
  for (int i = 0; i < length; i++) {
    tap_code(code[i]);
  }
  unregister_code(KC_LALT);
}


#define HANDLE_RETRO_TAPPING  if ((keycode == LCTL_T(KC_S)) \
    || (keycode == LSFT_T(KC_T))\
    || (keycode == MEH_T(KC_SPACE))\
    || (keycode == MEH_T(KC_F)) || (keycode == MEH_T(KC_U))) {\
        return false;\
    }\
    return true;\

#define HANDLE_TAPPING_TERM if (keycode == LT(NUMPAD,KC_ESCAPE)) {\
      return 125;\
    }\
    return TAPPING_TERM;\



#define HANDLE_KEY_PRESS if (record->event.pressed) {\
    return handle_keypress(keycode);\
  }\
  return handle_keyrelease(keycode);\

bool handle_keypress(uint16_t keycode) {
  handle_shifttimer();
  if (handle_shiftedsymbols(keycode)) {
    return false;
  }
  if (caps_lock_on() && (get_oneshot_mods() & MOD_BIT(KC_LSHIFT))) {
    clear_oneshot_mods();
    register_code(KC_CAPSLOCK);
    unregister_code(KC_CAPSLOCK);
  }
  if (handle_unicode(keycode)) {
    layer_off(MIRUNI);
    return false;
  }
  switch (keycode) {
    case SC_SUPERINVQUES:
      set_oneshot_mods(0);
      SEND_STRING(SS_LSFT(SS_TAP(X_EQUAL)));
      shift_time = timer_read();
    break; 
    case SC_SUPERDOT:
      SEND_STRING(SS_TAP(X_DOT) SS_TAP(X_SPACE));
      shift_time = timer_read();
    break;  
    case SC_SUPERQUES:
      SEND_STRING(SS_LSFT(SS_TAP(X_MINUS)) SS_TAP(X_SPACE));
      shift_time = timer_read();
    break;  
    case SP_CARET:
      SEND_STRING(SS_LSFT(SS_TAP(X_LBRC)) SS_TAP(X_SPACE));
      return true;
    break;
    case SP_GRAVE:
      SEND_STRING(SS_TAP(X_LBRACKET) SS_TAP(X_SPACE));
      return true;
    break;
    case SC_QUE:      
      SEND_STRING(SS_TAP(X_Q) SS_TAP(X_U));
      press_tilde_and_letter(KC_E);
      reset_oneshot_layer();
      layer_off(SPANISH);
      layer_on(COLEMAK);
      return true;
    break;
    case SC_QUIEN:      
      SEND_STRING(SS_TAP(X_Q) SS_TAP(X_U) SS_TAP(X_I));
      press_tilde_and_letter(KC_E);
      SEND_STRING(SS_TAP(X_N));
      reset_oneshot_layer();
      layer_off(SPANISH);
      layer_on(COLEMAK);
      return false;
    break;
    case SP_LBKT:
      register_code(KC_RALT);
      tap_code(SP_LBKT);
      unregister_code(KC_RALT);
      return false;
    break;
    case SC_CLOSESEMI:
      SEND_STRING(SS_LSFT(SS_TAP(X_9) SS_TAP(X_COMMA)));
      return false;
    break;
    case SC_OPENCLOSESEMI:
      SEND_STRING(SS_LSFT(SS_TAP(X_8) SS_TAP(X_9) SS_TAP(X_COMMA)));
      return false;
    break;
    case SP_RBKT:
      register_code(KC_RALT);
      tap_code(SP_RBKT);
      unregister_code(KC_RALT);
      return false;
    break;
    case KC_ESCAPE:
      clear_oneshot_mods(); 
      clear_mods();
      shift_time = 0;
      tap_code(KC_ESCAPE);
      return true;
    break; 
    case SC_MIRSHIFT:
      set_oneshot_mods(MOD_BIT(KC_LSHIFT));
      reset_oneshot_layer();
      layer_on(MIRUNI);
      return true;
    break;      
    case SC_OPEN1QUOTE:
      SendAltCode(OPEN1QUOTE, 4);
    break;
    case SC_CLOSE1QUOTE:
      SendAltCode(CLOSE1QUOTE, 4);
    break;
    case SC_SEMICLNENTER:
      SEND_STRING(SS_TAP(X_END) SS_TAP(X_SCOLON) SS_TAP(X_ENTER));
    break;
    case SC_EQUALS:
      SEND_STRING(SS_LSFT(SS_TAP(X_0) SS_TAP(X_0)));
    break;
    case SC_ENDTAG:
      SEND_STRING(SS_TAP(X_NUBS) SS_LSFT(SS_TAP(X_7)));
    break;
    case SC_OPENQUOTE:
      SendAltCode(OPENQUOTE, 4);
    break;
    case SC_SECTION:
      SEND_STRING(SS_TAP(X_END) SS_DELAY(20) SS_TAP(X_SPACE) SS_DELAY(20) SS_RALT(SS_TAP(X_QUOTE)) SS_DELAY(50) SS_TAP(X_ENTER) SS_DELAY(50) SS_TAP(X_ENTER) SS_DELAY(50) SS_RALT(SS_TAP(X_BSLASH)) SS_DELAY(50) SS_TAP(X_UP) SS_DELAY(50) SS_TAP(X_TAB));
    break;
    case SC_OPENCLOSEPAREN:
      SEND_STRING(SS_LSFT(SS_TAP(X_8) SS_TAP(X_9)));
    break;
    case SC_NOTEQUAL:
      SEND_STRING(SS_LSFT(SS_TAP(X_1) SS_TAP(X_0)));
    break;
    case SC_EMDASH:
      SendAltCode(EMDASH, 4);
    break;
    case SC_CLOSEQUOTE:
      SendAltCode(CLOSEQUOTE, 4);
    break;
    case SC_LESSOREQUAL:
      SEND_STRING(SS_TAP(X_NUBS) SS_LSFT(SS_TAP(X_0)));
    break;
    case SC_GREATOREQUAL:
      SEND_STRING(SS_LSFT(SS_TAP(X_NUBS) SS_TAP(X_0)));
    break;
    case DEL_LINE:
      SEND_STRING(SS_TAP(X_END) SS_DELAY(50) SS_LSFT(SS_TAP(X_HOME) SS_TAP(X_HOME)) SS_DELAY(50) SS_TAP(X_DELETE) SS_DELAY(50) SS_TAP(X_DELETE));
    break;
    case SC_SURROUNDBRKT:
      SEND_STRING(SS_LCTL(SS_TAP(X_X)) SS_DELAY(20) SS_LSFT(SS_TAP(X_TAB)) SS_DELAY(20) SS_RALT(SS_TAP(X_QUOTE)) SS_DELAY(20) SS_TAP(X_ENTER) SS_DELAY(20) SS_RALT(SS_TAP(X_BSLASH)) SS_TAP(X_UP) SS_DELAY(20) SS_TAP(X_ENTER) SS_DELAY(20) SS_TAP(X_TAB) SS_DELAY(20) SS_LCTL(SS_TAP(X_V)));
    break;
    case SC_SELECTLINE:
      SEND_STRING(SS_TAP(X_END) SS_DELAY(50) SS_LSFT(SS_TAP(X_HOME)));
    break;
    case OPENCLOSEBRACKETS:
      tap_code16(ES_LBRC);
      tap_code16(ES_RBRC);
    break;
    case DELWORD:
      SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)) SS_DELAY(50) SS_LSFT(SS_LCTL(SS_TAP(X_LEFT))) SS_DELAY(50) SS_TAP(X_DELETE));
    break;
    case SC_ARROW:
        SEND_STRING(SS_LSFT(SS_TAP(X_0) SS_TAP(X_NUBS)));
    break;
    case SP_CO:
      SEND_STRING(SS_TAP(X_C));
      press_tilde_and_letter(KC_O);
      SEND_STRING(SS_TAP(X_M) SS_DELAY(20) SS_TAP(X_O) SS_DELAY(20) SS_TAP(X_SPACE));
    break;
    case SP_CUA:
      SEND_STRING(SS_TAP(X_C) SS_TAP(X_U));
      press_tilde_and_letter(KC_A);
  }
  layer_off(MIRUNI);
  return true;
}
bool handle_shiftedsymbols(uint16_t keycode) {
    switch (keycode) {
    case LCTL_T(KC_SPACE):
      if (shift_pressed()) {
        tap_code(KC_SLASH);
        return true;
      }
      return false;
    break;
    case SP_QUOTE:
      if (shift_pressed()) {
        bool held = shift_held();
        SEND_STRING(ESP_2QUOTE);
        if (held)  {
            register_code(KC_LSHIFT);
          }
        return true;
      }
      tap_code(SP_QUOTE);
      return true;
    break;
    case KC_COMMA:
      if (shift_pressed()) {
        bool held = shift_held();
        clear_mods();
        clear_oneshot_mods();
        SEND_STRING(ESP_LT);
        if (held)  {
            register_code(KC_LSHIFT);
        }
        return true;
      }
      SEND_STRING(SS_TAP(X_COMMA));
      return true;
    break;
    case KC_DOT:
      if (shift_pressed()) {
        bool held = shift_held();
        SEND_STRING(ESP_GT);
        if (held)  {
          register_code(KC_LSHIFT);
        }
        return true;
      } 
      SEND_STRING(SS_TAP(X_DOT));
      return true;
    break;
    case SP_SLASH:
      if (shift_pressed()) {
        bool held = shift_held();
        SEND_STRING(ESP_QUES);
        if (held) {
          register_code(KC_LSHIFT);
        }
        return true;
      }
      SEND_STRING(ESP_SLASH);
      return true;
    break;
  }
  return false;
}

bool handle_unicode(uint16_t keycode) {
  switch (keycode) {
    case SC_COMMA:
      SendAltCode(COMMA, 4);
      return true;
    break;
    case SC_DOT:
      SendAltCode(DOT, 4);
      return true;
    break;
    case SP_E:
      press_tilde_and_letter(KC_E);
      return true;
    break;
    case SP_I:
      press_tilde_and_letter(KC_I);
      return true;
    break;
    case SP_O:
      press_tilde_and_letter(KC_O);
      return true;
    break;
    case SP_U:
        press_tilde_and_letter(KC_U);
        return true;
    break;
    case SP_Y:
      if (shift_pressed()) {
        SEND_STRING(SS_TAP(X_QUOTE) SS_LSFT(SS_TAP(X_U)));
        return true;
      }
      SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE)) SS_TAP(X_U));
      return true;
    break;
    case SP_N:
        SEND_STRING(SS_TAP(X_SCOLON));
        return true;
    break;
    case SP_A:
        press_tilde_and_letter(KC_A);
        return true;
    break;
    case SP_G:
        if (shift_pressed()) {
          SEND_STRING(SS_LSFT(SS_TAP(X_G) SS_TAP(X_QUOTE) SS_TAP(X_U)));
          return true;
        }
        SEND_STRING(SS_TAP(X_G) SS_LSFT(SS_TAP(X_QUOTE)) SS_TAP(X_U));
        return true;
    break;
  }
  return false;
}

bool handle_keyrelease(uint16_t keycode) {
  if (keycode == SC_AR) {
    unregister_code(KC_LALT);
  }
  return true;
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
bool shift_held() {
    return ((get_mods() & MOD_BIT(KC_LSHIFT)) == MOD_BIT(KC_LSHIFT));
  }
