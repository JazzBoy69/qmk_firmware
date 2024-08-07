#define COLEMAK 0
#define TYPING 1
#define NUMPAD 2
#define NAV 3
#define GAME 4
#define FN 5
#define MIRRORED 6
#define MIRSYM 7
#define MIRUNI 8

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
  SC_SEC,
  SC_INVBANG,
  SC_PAR,
  SC_DOT,
  SC_COMMA,
  SC_INVQUES,
  SC_MIRSHIFT,
  SC_AS,
  SC_AR,
  SC_SUPERSHIFT,
  SC_ARROW,
  SC_SUPERDOT,
  SC_SUPERQUES,
  SC_SUPERINVQUES,
  SC_SECTION,
  SP_SLASH,
  SP_CARET,
  SP_O,
  SP_I,
  SP_E,
  SP_N,
  SP_U,
  SP_Y,
};

//COMBOS

enum combo_events {
  DOT_BUL,
  A_TILDE,
  E_TILDE,
  I_TILDE,
  O_TILDE,
  U_TILDE,
  Y_TILDE,
  N_TILDE,
  G_TILDE,
  CTRL_BKSP,
  CTRL_BKSP2,
  R1_QUOTE,
  R2_QUOTE,
  L1_QUOTE,
  L2_QUOTE,
  SHIFT_CAPS,
  RSHIFT_CAPS,
  SEMICOLON,
  COLON,
  ANDCOMBO,
  PLUSCOMBO,
  PLPLCOMBO,
  PLPLENDCOMBO,
  ASTRCOMBO,
  EQLCOMBO,
  LBRKCOMBO,
  LBRKCOMBO2,
  EXCLCOMBO,
  EXCLCOMBO2,
  BKSLASH,
  ATCOMBO,
  HASHCOMBO,
  DLRCOMBO,
  PERCCOMBO,
  TILDCOMBO,
  SLASHCOMBO,
  MINUSCOMBO,
  MIMICOMBO,
  PIPECOMBO,
  SCOLONENTER,
  EQUALSCOMBO,
  RBRKCOMBO,
  CARETCOMBO,
  GRAVECOMBO,
  BKSLASH2,
  ENDTAG,
  EMDASHCOMBO,
  EXACTLYEQUAL,
  PARENSEMI,
  INVQUESCOMBO,
  INVEXLCOMBO,
  INVEXLCOMBO2,
  SUPERDOTCOMBO,
  SUPERQUES,
  SUPERINVQUES,
  PARCOMBO,
  SECTION,
  ACCENT,
  SEPARATOR,
  MASC,
  FEM,
};

const uint16_t PROGMEM sdot_combo[] = {KC_Q, KC_O, COMBO_END};
const uint16_t PROGMEM atilde_combo[] = {SP_RBKT, LT(NUMPAD,KC_A), COMBO_END};
const uint16_t PROGMEM etilde_combo[] = {SP_LBKT, KC_E, COMBO_END};
const uint16_t PROGMEM itilde_combo[] = {SP_LBKT, KC_I, COMBO_END};
const uint16_t PROGMEM otilde_combo[] = {SP_LBKT, KC_O, COMBO_END};
const uint16_t PROGMEM utilde_combo[] = {SP_LBKT, MEH_T(KC_U), COMBO_END};
const uint16_t PROGMEM ytilde_combo[] = {SP_LBKT, KC_Y, COMBO_END};
const uint16_t PROGMEM ntilde_combo[] = {SP_LBKT, KC_N, COMBO_END};
const uint16_t PROGMEM gtilde_combo[] = {SP_RBKT, KC_G, COMBO_END};
const uint16_t PROGMEM parbksp_combo[] = {SP_RPAREN, LT(MIRRORED,KC_BSPACE), COMBO_END};
const uint16_t PROGMEM bksp_combo[] = {SP_RPAREN, KC_BSPACE, COMBO_END};
const uint16_t PROGMEM r1quote_combo[] = {SP_LPAREN, SP_QUOTE, COMBO_END};
const uint16_t PROGMEM r2quote_combo[] = {SP_LPAREN, LT(NUMPAD,KC_A), SP_QUOTE, COMBO_END};
const uint16_t PROGMEM l1quote_combo[] = {SP_RPAREN, KC_Q, COMBO_END};
const uint16_t PROGMEM l2quote_combo[] = {SP_RPAREN, KC_O, KC_Q, COMBO_END};
const uint16_t PROGMEM shiftcaps_combo[] = {OSM(MOD_LSFT), SP_LPAREN, COMBO_END};
const uint16_t PROGMEM rshiftcaps_combo[] = {OSM(MOD_LSFT), SP_RPAREN, COMBO_END};
const uint16_t PROGMEM colon_combo[] = {SP_LPAREN, KC_DOT, COMBO_END};
const uint16_t PROGMEM semicolon_combo[] = {SP_LPAREN, KC_COMMA, COMBO_END};
const uint16_t PROGMEM and_combo[] = {SP_RPAREN, KC_W, COMBO_END};
const uint16_t PROGMEM plus_combo[] = {SP_RPAREN, MEH_T(KC_F), COMBO_END};
const uint16_t PROGMEM plusplus_combo[] = {SP_RPAREN, KC_O, MEH_T(KC_F), COMBO_END};
const uint16_t PROGMEM plusplusend_combo[] = {KC_COMMA, MEH_T(KC_F), COMBO_END};
const uint16_t PROGMEM astr_combo[] = {SP_RPAREN, KC_P, COMBO_END};
const uint16_t PROGMEM eql_combo[] = {SP_RPAREN, KC_G, COMBO_END};
const uint16_t PROGMEM lbrk_combo[] = {SP_RPAREN, KC_R, COMBO_END};
const uint16_t PROGMEM lbrk_combo2[] = {SP_RPAREN, LALT_T(KC_R), COMBO_END};
const uint16_t PROGMEM excl_combo[] = {SP_RPAREN, KC_T, COMBO_END};
const uint16_t PROGMEM excl_combo2[] = {SP_RPAREN, LSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM bkslash_combo[] = {SP_RPAREN, KC_Z, COMBO_END};
const uint16_t PROGMEM at_combo[] = {SP_RPAREN, KC_X, COMBO_END};
const uint16_t PROGMEM hash_combo[] = {SP_RPAREN, KC_C, COMBO_END};
const uint16_t PROGMEM dlr_combo[] = {SP_RPAREN, KC_V, COMBO_END};
const uint16_t PROGMEM perc_combo[] = {SP_RPAREN, KC_B, COMBO_END};
const uint16_t PROGMEM tilde_combo[] = {SP_LPAREN, KC_J, COMBO_END};
const uint16_t PROGMEM slash_combo[] = {SP_LPAREN, KC_L, COMBO_END};
const uint16_t PROGMEM minus_combo[] = {SP_LPAREN, MEH_T(KC_U), COMBO_END};
const uint16_t PROGMEM minusminus_combo[] = {SP_LPAREN, LT(NUMPAD,KC_A), MEH_T(KC_U), COMBO_END};
const uint16_t PROGMEM pipe_combo[] = {SP_LPAREN, KC_Y, COMBO_END};
const uint16_t PROGMEM scolonenter_combo[] = {SP_LPAREN, LT(NUMPAD,KC_A), KC_COMMA, COMBO_END};
const uint16_t PROGMEM equals_combo[] = {SP_LPAREN, KC_N, COMBO_END};
const uint16_t PROGMEM rbrk_combo[] = {SP_LPAREN, KC_I, COMBO_END};
const uint16_t PROGMEM caret_combo[] = {SP_LPAREN, KC_K, COMBO_END};
const uint16_t PROGMEM grave_combo[] = {SP_LPAREN, KC_M, COMBO_END};
const uint16_t PROGMEM bkslash_combo2[] = {SP_LPAREN, SP_SLASH, COMBO_END};
const uint16_t PROGMEM endtag_combo[] = {SP_LPAREN, LT(NUMPAD,KC_A), KC_L, COMBO_END};
const uint16_t PROGMEM emdash_combo[] = {SP_LBKT, KC_Q, MEH_T(KC_U), COMBO_END};
const uint16_t PROGMEM exactlyequal_combo[] = {SP_LPAREN, LT(NUMPAD,KC_A), KC_N, COMBO_END};
const uint16_t PROGMEM parensemi_combo[] = {SP_LPAREN, LT(NUMPAD,KC_A), SP_RPAREN, COMBO_END};
const uint16_t PROGMEM invques_combo[] = {SP_LBKT, SP_SLASH, COMBO_END};
const uint16_t PROGMEM invexcl_combo[] = {SP_RBKT, KC_T, COMBO_END};
const uint16_t PROGMEM invexcl_combo2[] = {SP_RBKT, LSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM superdot_combo[] = {SP_LPAREN, LCTL_T(KC_SPACE), COMBO_END};
const uint16_t PROGMEM superques_combo[] = {SP_LPAREN, ES_QUES, COMBO_END};
const uint16_t PROGMEM superinvques_combo[] = {SP_LBKT, ES_QUES, COMBO_END};
const uint16_t PROGMEM par_combo[] = {SP_RBKT, KC_P, COMBO_END};
const uint16_t PROGMEM section_combo[] = {SP_RBKT, LCTL_T(KC_S), COMBO_END};
const uint16_t PROGMEM accent_combo[] = {SP_LBKT, KC_COMMA, COMBO_END};
const uint16_t PROGMEM separator_combo[] = {SP_LBKT, KC_DOT, COMBO_END};
const uint16_t PROGMEM masc_combo[] = {SP_LBKT, KC_Q, KC_O, COMBO_END};
const uint16_t PROGMEM fem_combo[] = {SP_RBKT, SP_QUOTE, LT(NUMPAD,KC_A), COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [DOT_BUL] = COMBO(sdot_combo, XXX),
  [A_TILDE] = COMBO(atilde_combo, XXX),
  [E_TILDE] = COMBO(etilde_combo, XXX),
  [I_TILDE] = COMBO(itilde_combo, XXX),
  [O_TILDE] = COMBO(otilde_combo, XXX),
  [U_TILDE] = COMBO(utilde_combo, XXX),
  [Y_TILDE] = COMBO(ytilde_combo, XXX),
  [G_TILDE] = COMBO(gtilde_combo, XXX),
  [N_TILDE] = COMBO(ntilde_combo, XXX),
  [CTRL_BKSP] = COMBO(parbksp_combo, LCTL(KC_BSPACE)),
  [CTRL_BKSP2] = COMBO(bksp_combo, LCTL(KC_BSPACE)),
  [R1_QUOTE] = COMBO(r1quote_combo, SC_CLOSE1QUOTE),
  [R2_QUOTE] = COMBO(r2quote_combo, SC_CLOSEQUOTE),
  [L1_QUOTE] = COMBO(l1quote_combo, SC_OPEN1QUOTE),
  [L2_QUOTE] = COMBO(l2quote_combo, SC_OPENQUOTE),
  [SHIFT_CAPS] = COMBO(shiftcaps_combo, XXX),
  [RSHIFT_CAPS] = COMBO(rshiftcaps_combo, XXX),
  [COLON] = COMBO(colon_combo, XXX),
  [SEMICOLON] = COMBO(semicolon_combo, XXX),
  [ANDCOMBO] = COMBO(and_combo, ES_AMPR),
  [PLUSCOMBO] = COMBO(plus_combo, ES_PLUS),
  [PLPLCOMBO] = COMBO(plusplus_combo, XXX),
  [PLPLENDCOMBO] = COMBO(plusplusend_combo, XXX),
  [ASTRCOMBO] = COMBO(astr_combo, ES_ASTR),
  [EQLCOMBO] = COMBO(eql_combo, ES_EQL),
  [LBRKCOMBO] = COMBO(lbrk_combo, ES_LBRC),
  [LBRKCOMBO2] = COMBO(lbrk_combo2, ES_LBRC),
  [EXCLCOMBO] = COMBO(excl_combo, ES_EXLM),
  [EXCLCOMBO2] = COMBO(excl_combo2, ES_EXLM),
  [BKSLASH] = COMBO(bkslash_combo, ES_BSLS),
  [ATCOMBO] = COMBO(at_combo, ES_AT),
  [HASHCOMBO] = COMBO(hash_combo, ES_HASH),
  [DLRCOMBO] = COMBO(dlr_combo, ES_DLR),
  [PERCCOMBO] = COMBO(perc_combo, ES_PERC),
  [TILDCOMBO] = COMBO(tilde_combo, XXX),
  [SLASHCOMBO] = COMBO(slash_combo, SP_SLASH),
  [MINUSCOMBO] = COMBO(minus_combo, ES_MINS),
  [PIPECOMBO] = COMBO(pipe_combo, ES_PIPE),
  [SCOLONENTER] = COMBO(scolonenter_combo, XXX),
  [EQUALSCOMBO] = COMBO(equals_combo, XXX),
  [RBRKCOMBO] = COMBO(rbrk_combo, ES_RBRC),
  [CARETCOMBO] = COMBO(caret_combo, XXX),
  [GRAVECOMBO] = COMBO(grave_combo, XXX),
  [BKSLASH2] = COMBO(bkslash_combo2, ES_BSLS),
  [ENDTAG] = COMBO(endtag_combo, XXX),
  [EMDASHCOMBO] = COMBO(emdash_combo, XXX),
  [EXACTLYEQUAL] = COMBO(exactlyequal_combo, XXX),
  [PARENSEMI] = COMBO(parensemi_combo, XXX),
  [MIMICOMBO] = COMBO(minusminus_combo, XXX),
  [INVQUESCOMBO] = COMBO(invques_combo, ES_IQUE),
  [INVEXLCOMBO] = COMBO(invexcl_combo, ES_IEXL),
  [INVEXLCOMBO2] = COMBO(invexcl_combo2, ES_IEXL),
  [SUPERDOTCOMBO] = COMBO(superdot_combo, XXX),
  [SUPERQUES] = COMBO(superques_combo, XXX),
  [SUPERINVQUES] = COMBO(superinvques_combo, XXX),
  [PARCOMBO] = COMBO(par_combo, XXX),
  [SECTION] = COMBO(section_combo, XXX),
  [ACCENT] = COMBO(accent_combo, XXX),
  [SEPARATOR] = COMBO(separator_combo, XXX),
  [MASC] = COMBO(masc_combo, ES_MORD),
  [FEM] = COMBO(fem_combo, ES_FORD),
};

/*

*/



#define ________________BLOCK_____________________        XXX,     XXX,     XXX,     XXX,     XXX,    XXX
#define ________________BLANK_____________________        ___,     ___,     ___,     ___,     ___,    ___

#define ________________COLEMAK_L1________________       SP_LBKT, KC_Q,      KC_W,       MEH_T(KC_F),         KC_P,    KC_G
#define ________________COLEMAK_L2________________       SP_LPAREN,    LT(NUMPAD,KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T),    LT(NAV,KC_D)
#define ________________COLEMAK_L3________________       OSM(MOD_LSFT),      KC_Z,              KC_X,         KC_C,         KC_V,    KC_B

#define ________________COLEMAK_R1________________       KC_J,            KC_L, MEH_T(KC_U),          KC_Y, SP_QUOTE, SP_RBKT
#define ________________COLEMAK_R2________________       SCMD_T(KC_H),    KC_N,        KC_E,          KC_I,    KC_O, SP_RPAREN
#define ________________COLEMAK_R3________________       KC_K,            KC_M,    KC_COMMA,        KC_DOT, SP_SLASH, OSM(MOD_LSFT)

#define _________BOTTOM_L1_________                       KC_DELETE,    KC_ESCAPE,     KC_SPACE
#define _________BOTTOM_R1_________                       KC_LGUI,  TO(NUMPAD),  ___   
#define ________BLOCK_BOTTOM_______                       XXX,  XXX,  XXX
#define ________BLANK_BOTTOM_______                       ___,  ___,  ___
#define THUMB_L1                                          LT(MIRRORED,KC_BSPACE),LT(FN,KC_ENTER)
#define TH_L2                                             _______
#define TH_L3                                             _______
#define THUMB_R1                                          ES_QUES,    LCTL_T(KC_SPACE)
#define TH_R2                                             _______
#define TH_R3                                             _______

#define ________________TYPING_L1_________________        ________________BLANK_____________________
#define ________________TYPING_L2_________________        ___, ___,  KC_R, KC_S, KC_T, ___
#define ________________TYPING_L3_________________        ___, ___,  KC_X, ___,  ___,  ___
#define ________________TYPING_R1_________________        ________________BLANK_____________________
#define ________________TYPING_R2_________________        ___,   ___, KC_E,  ___, ___, ___
#define ________________TYPING_R3_________________        ___, ___,  ___, KC_DOT, ___, ___

#define ____TYPE_BOTTOM_L1_________                       ________BLANK_BOTTOM_______
#define ____TYPE_BOTTOM_R1_________                       ________BLOCK_BOTTOM_______
#define TYPE_L1                                           ___, KC_ENTER
#define TYPE_L2                                           ___
#define TYPE_L3                                           ___
#define TYPE_R1                                           ___, ___
#define TYPE_R2                                           ___
#define TYPE_R3                                           ___


#define ________________NUMPAD_L1_________________        KC_NUMLOCK,  ___,   ___,     ___, ___, ___
#define ________________NUMPAD_L2_________________        TO(COLEMAK), ___, SC_AR,   SC_AS, ___, ___
#define ________________NUMPAD_L3_________________        ________________BLANK_____________________

#define ________________NUMPAD_R1_________________        XXX,           KC_KP_7, KC_KP_8, KC_KP_9, ES_COLON, KC_KP_MINUS
#define ________________NUMPAD_R2_________________        OSM(MOD_LALT), KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_ASTERISK,  KC_KP_PLUS
#define ________________NUMPAD_R3_________________        XXX,           KC_KP_1, KC_KP_2, KC_KP_3,    KC_KP_SLASH,    KC_ENTER

#define _____NUM_BOTTOM_L1_________                       ________BLANK_BOTTOM_______
#define _____NUM_BOTTOM_R1_________                       KC_X,    KC_KP_COMMA,  KC_KP_DOT


#define NUM_L1                                            LSFT(KC_TAB), KC_TAB
#define NUM_L2                                            ___
#define NUM_L3                                            ___
#define NUM_R1                                            KC_ESCAPE,  KC_KP_0
#define NUM_R2                                            ___
#define NUM_R3                                            ___

#define ________________NAV_L1____________________        KC_SCROLLLOCK, ___,  ___,       ___,       ___, ___
#define ________________NAV_L2____________________        TO(COLEMAK),   ___,  ___,  KC_LCTRL, KC_LSHIFT, ___
#define ________________NAV_L3____________________        ________________BLANK_____________________

#define ________________NAV_R1____________________        LCTL(KC_HOME),  OSM(MOD_LCTL),   KC_UP,      KC_PGUP,      XXX,        KC_MS_WH_UP
#define ________________NAV_R2____________________        LCTL(KC_LEFT),     KC_LEFT,     KC_DOWN,    KC_RIGHT,  LCTL(KC_RIGHT), KC_MS_WH_DOWN
#define ________________NAV_R3____________________          DELWORD,        KC_DELETE, SC_SELECTLINE,KC_PGDOWN,  LCTL(KC_END),  OSM(MOD_LSFT)


#define _____NAV_BOTTOM_L1_________                       ________BLANK_BOTTOM_______
#define _____NAV_BOTTOM_R1_________                       KC_X,    KC_KP_COMMA,  KC_KP_DOT

#define NAV_L1                                            KC_MS_BTN2,  KC_MS_BTN1
#define NAV_L2                                            _______
#define NAV_L3                                            _______
#define NAV_R1                                            KC_HOME,  KC_END
#define NAV_R2                                            _______
#define NAV_R3                                            _______


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


#define ________________MIR_L1____________________        OSL(MIRUNI),     SP_QUOTE,          KC_Y,           KC_U,        KC_L,         KC_J
#define ________________MIR_L2____________________        OSL(MIRSYM),      KC_O,             KC_I,           KC_E,        KC_N,         KC_H
#define ________________MIR_L3____________________        ___,             KC_QUES,          KC_DOT,        KC_COMMA,      KC_M,         KC_K

#define ________________MIR_R1____________________         SC_ARROW,   SC_ENDTAG,         SC_EMDASH,               ___, SC_OPENQUOTE,   SC_SURROUNDBRKT
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


uint8_t caps_lock_on(void);
uint8_t shift_pressed(void);
uint8_t current_layer = 0;
uint16_t change_time = 0;
uint16_t pressed_time = 0;
uint16_t shift_time = 0;
bool handle_keypress(uint16_t keycode);
bool handle_keyrelease(uint16_t keycode);
bool handle_unicode(uint16_t keycode);
void SendShiftedAltCode(uint16_t shifted[], uint16_t unshifted[]);
void SendAltCode(uint16_t code[], int length);
bool handle_shiftedsymbols(uint16_t keycode);

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

#define HANDLE_MATRIX_SCAN if (current_layer == COLEMAK) {\
        if (get_current_wpm()>30) {\
        layer_on(TYPING);\
        }\
        return;\
    }\
    if (current_layer == TYPING) {\
        if ((timer_elapsed(pressed_time) > 1000)) {\
        shift_time = 0;\
        layer_off(TYPING);\
        set_current_wpm(0);\
        }\
        return;\
    }\


#define HANDLE_RETRO_TAPPING  if ((keycode == LCTL_T(KC_S)) \
    || (keycode == LSFT_T(KC_T))\
    || (keycode == MEH_T(KC_SPACE))\
    || (keycode == MEH_T(KC_F)) || (keycode == MEH_T(KC_U))) {\
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
  if (shift_time != 0) {//add shift to capitalize first letter of sentence
      if (!caps_lock_on() && (timer_elapsed(shift_time) < 2000)) {
        set_oneshot_mods(MOD_BIT(KC_LSHIFT));
      }
      shift_time = 0;
  }
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
    case SP_CARET:
      SEND_STRING(SS_LSFT(SS_TAP(X_LBRC)) SS_TAP(X_SPACE));
      return true;
    break;
    case SP_LBKT:
      register_code(KC_RALT);
      tap_code(SP_LBKT);
      unregister_code(KC_RALT);
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
      tap_code(KC_EQUAL);
      tap_code(KC_EQUAL);
    break;
    case SC_ENDTAG:
      SEND_STRING("</");
    break;
    case SC_OPENQUOTE:
      SendAltCode(OPENQUOTE, 4);
    break;
    case SC_SECTION:
      SEND_STRING(SS_TAP(X_END) SS_DELAY(20) SS_TAP(X_SPACE) SS_DELAY(20) SS_RALT(SS_TAP(X_QUOTE)) SS_DELAY(20) SS_TAP(X_ENTER) SS_TAP(X_ENTER) SS_DELAY(20) SS_RALT(SS_TAP(X_BSLASH)) SS_DELAY(20) SS_TAP(X_UP) SS_DELAY(20) SS_TAP(X_TAB));
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
    case SC_AS:
        SEND_STRING("as");
    break;
    case SC_ARROW:
        SEND_STRING(SS_LSFT(SS_TAP(X_0) SS_TAP(X_NUBS)));
    break;
    case SC_AR:
      if (get_current_wpm()>35)
        SEND_STRING("ar");
      else
        register_code(KC_LALT);
    break;
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
        SEND_STRING(ESP_2QUOTE);
        return true;
      }
      tap_code(SP_QUOTE);
      return true;
    break;
    case KC_COMMA:
      if (shift_pressed()) {
        clear_mods();
        clear_oneshot_mods();
        SEND_STRING(ESP_LT);
        return true;
      }
      SEND_STRING(SS_TAP(X_COMMA));
      return true;
    break;
    case KC_DOT:
      if (shift_pressed()) {
        SEND_STRING(ESP_GT);
        return true;
      } 
      SEND_STRING(SS_TAP(X_DOT));
      return true;
    break;
    case SP_SLASH:
      if (shift_pressed()) {
        SEND_STRING(ESP_QUES);
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
  case SC_SEC:
      SendAltCode(SEC, 4);
      return true;
    break;
    case SC_PAR:
      SendAltCode(PAR, 4);;
      return true;
    break;
    case SC_COMMA:
      SendAltCode(COMMA, 4);
      return true;
    break;
    case SC_DOT:
      SendAltCode(DOT, 4);
      return true;
    break;
    case SP_E:
      if (shift_pressed()) {
        clear_oneshot_mods();
        clear_mods();
        SEND_STRING(SS_TAP(X_QUOTE) SS_LSFT(SS_TAP(X_E)));
        return true;
      }
      SEND_STRING(SS_TAP(X_QUOTE) SS_TAP(X_E));
      return true;
    break;
    case SP_I:
      if (shift_pressed()) {
        clear_oneshot_mods();
        clear_mods();
        SEND_STRING(SS_TAP(X_QUOTE) SS_LSFT(SS_TAP(X_I)));
        return true;
      }
      SEND_STRING(SS_TAP(X_QUOTE) SS_TAP(X_I));
      return true;
    break;
    case SP_O:
      if (shift_pressed()) {
        clear_oneshot_mods();
        clear_mods();
        SEND_STRING(SS_TAP(X_QUOTE) SS_LSFT(SS_TAP(X_O)));
        return true;
      }
      SEND_STRING(SS_TAP(X_QUOTE) SS_TAP(X_O));
      return true;
    break;
    case SP_U:
        if (shift_pressed()) {
          clear_oneshot_mods();
          clear_mods();
          SEND_STRING(SS_TAP(X_QUOTE) SS_LSFT(SS_TAP(X_U)));
          return true;
        }
        SEND_STRING(SS_TAP(X_QUOTE) SS_TAP(X_U));
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


void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case DOT_BUL:
      if (pressed) {
        SendAltCode(BULLET, 4);
      }
    break;
    case A_TILDE:
      if (pressed) {
        if (shift_pressed()) {
          clear_oneshot_mods();
          clear_mods();
          SEND_STRING(SS_TAP(X_QUOTE) SS_LSFT(SS_TAP(X_A)));
          return;
        }
        SEND_STRING(SS_TAP(X_QUOTE) SS_TAP(X_A));
      }
    break;
    case E_TILDE:
      if (pressed) {
        if (shift_pressed()) {
          clear_oneshot_mods();
          clear_mods();
          SEND_STRING(SS_TAP(X_QUOTE) SS_LSFT(SS_TAP(X_E)));
          return;
        }
        SEND_STRING(SS_TAP(X_QUOTE) SS_TAP(X_E));
      }
    break;
    case I_TILDE:
      if (pressed) {
        if (shift_pressed()) {
          clear_oneshot_mods();
          clear_mods();
          SEND_STRING(SS_TAP(X_QUOTE) SS_LSFT(SS_TAP(X_I)));
          return;
        }
        SEND_STRING(SS_TAP(X_QUOTE) SS_TAP(X_I));
      }
    break;
    case O_TILDE:
      if (pressed) {
        if (shift_pressed()) {
          clear_oneshot_mods();
          clear_mods();
          SEND_STRING(SS_TAP(X_QUOTE) SS_LSFT(SS_TAP(X_O)));
          return;
        }
        SEND_STRING(SS_TAP(X_QUOTE) SS_TAP(X_O));
      }
    break;
    case U_TILDE:
      if (pressed) {
        if (shift_pressed()) {
          clear_oneshot_mods();
          clear_mods();
          SEND_STRING(SS_TAP(X_QUOTE) SS_LSFT(SS_TAP(X_U)));
          return;
        }
        SEND_STRING(SS_TAP(X_QUOTE) SS_TAP(X_U));
      }
    break;
    case Y_TILDE:
      if (pressed) {
        if (shift_pressed()) {
          SEND_STRING(SS_TAP(X_QUOTE) SS_LSFT(SS_TAP(X_U)));
          return;
        }
        SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE)) SS_TAP(X_U));
      }
    break;
    case N_TILDE:
      if (pressed) {
        SEND_STRING(SS_TAP(X_SCOLON));
      }
    break;
    case G_TILDE:
      if (pressed) {
        if (shift_pressed()) {
          SEND_STRING(SS_LSFT(SS_TAP(X_G) SS_TAP(X_QUOTE) SS_TAP(X_U)));
          return;
        }
        SEND_STRING(SS_TAP(X_G) SS_LSFT(SS_TAP(X_QUOTE)) SS_TAP(X_U));
      }
    break;
    case SHIFT_CAPS:
      if (pressed) {
        register_code(KC_CAPSLOCK);
        unregister_code(KC_CAPSLOCK);
        tap_code(KC_LSHIFT);
      }
    break;
    case RSHIFT_CAPS:
      if (pressed) {
        register_code(KC_CAPSLOCK);
        unregister_code(KC_CAPSLOCK);
        tap_code(KC_LSHIFT);
      }
    break;
    case COLON:
      if (pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_DOT)));
      }
    break;
    case SEMICOLON:
      if (pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_COMMA)));
      }
    break;
    case TILDCOMBO:
      if (pressed) {
        SEND_STRING(SS_RALT(SS_TAP(X_4)) SS_TAP(X_SPACE));
      }
    break;
    case SCOLONENTER:
      if (pressed) {
        SEND_STRING(SS_TAP(X_END) SS_LSFT(SS_TAP(X_COMMA)) SS_TAP(X_ENTER));
      }
    break;
    case EQUALSCOMBO:
      if (pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_0) SS_TAP(X_0)));
      }
    break;
    case CARETCOMBO:
      if (pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_LBRACKET)) SS_TAP(X_SPACE));
      }
    break;
    case GRAVECOMBO:
      if (pressed) {
        SEND_STRING(SS_TAP(X_LBRACKET) SS_TAP(X_SPACE));
      }
    break;
    case PLPLCOMBO:
      if (pressed) {
        SEND_STRING(SS_TAP(X_RBRACKET) SS_TAP(X_RBRACKET));
      }
    break;
    case PLPLENDCOMBO:
      if (pressed) {
        SEND_STRING(SS_TAP(X_RBRACKET) SS_TAP(X_RBRACKET) SS_LSFT(SS_TAP(X_COMMA)));
      }
    break;
    case ENDTAG:
      if (pressed) {
        SEND_STRING(SS_TAP(X_NUBS) SS_LSFT(SS_TAP(X_7)));
      }
    break;
    case EMDASHCOMBO:
      if (pressed) {
        SendAltCode(EMDASH, 4);
      }
    break;
    case EXACTLYEQUAL:
      if (pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_0)));
      }
    break;
    case PARENSEMI:
      if (pressed) {
        SEND_STRING(SS_TAP(X_9) SS_TAP(X_COMMA));
      }
    break;
    case MIMICOMBO:
      if (pressed) {
        SEND_STRING(SS_TAP(X_SLASH) SS_TAP(X_SLASH));
      }
    break;
    case SUPERDOTCOMBO:
      if (pressed) {
        tap_code(KC_DOT);
        tap_code(KC_SPACE);
        shift_time = timer_read();
      }
    break;
    case SUPERINVQUES:
      if (pressed) {
        set_oneshot_mods(0);
        SEND_STRING(SS_LSFT(SS_TAP(X_EQUAL)));
        shift_time = timer_read();
      }
    break;   
    case SUPERQUES:
      if (pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_MINUS)) SS_TAP(X_SPACE));
        shift_time = timer_read();
      }
    break;
    case SECTION:
      if (pressed) {
        SendAltCode(SEC, 4);
      }
    break;
    case PARCOMBO:
      if (pressed) {
        SendAltCode(PAR, 4);;
      }
    break;
    case ACCENT:
      if (pressed) {
        SendAltCode(COMMA, 4);
      }
    break;
    case SEPARATOR:
      if (pressed) {
        SendAltCode(DOT, 4);
      }
    break;
  }
}
