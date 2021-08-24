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

#define ________________BLOCK_____________________        XXX,     XXX,     XXX,     XXX,    XXX
#define ________________BLANK_____________________        ___,     ___,     ___,     ___,    ___

#define ________________COLEMAK_L1________________       KC_Q,                    KC_W,         KC_F,         KC_P,    KC_G
#define ________________COLEMAK_L2________________       LT(NUMPAD,KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T),    LT(NAV,KC_D)
#define ________________COLEMAK_L3________________       KC_Z,             MEH_T(KC_X),         KC_C,         KC_V,    KC_B

#define ________________COLEMAK_R1________________       KC_J,    KC_L,        KC_U,          KC_Y, KC_QUOT
#define ________________COLEMAK_R2________________       KC_H,    KC_N,        KC_E,          KC_I,    KC_O    
#define ________________COLEMAK_R3________________       KC_K,    KC_M,    KC_COMMA, MEH_T(KC_DOT), KC_SLSH

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

#define ________________TYPING_L2_________________        ___,  KC_R, KC_S, KC_T, ___
#define ________________TYPING_L3_________________        ___,  KC_X, ___,  ___,  ___
#define ________________TYPING_R2_________________        ___,   ___, KC_E,  ___, ___
#define ________________TYPING_R3_________________        ___, ___,  ___, KC_DOT, ___
#define TYPE_THUMB_L1                                     KC_BSPACE, KC_ENTER





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
void handle_matrix_scan(void);


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
    if ((keycode == LALT_T(KC_R)) || \
        (keycode == MEH_T(KC_SPACE)) || \
        (keycode == LSFT_T(KC_T)) ||\
        (keycode == LCTL_T(KC_S))\
    ) {\
      return 150;\
    }\
    return TAPPING_TERM;\


#define HANDLE_ONESHOT_MODS  if (!(mods & MOD_MASK_SHIFT)) {\
   shift_count = 0;\
 }\


 void handle_supershift() {
  if (caps_lock_on()) {
    tap_code(KC_CAPSLOCK);
    resume_capslock = true;
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
  }
  return true;
}


