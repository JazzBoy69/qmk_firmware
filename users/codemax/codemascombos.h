enum combo_events {
  DOT_BUL,
  CTRL_BKSP, 
  CTRL_BKSP2,
  R1_QUOTE,
  R2_QUOTE,
  L1_QUOTE,
  L2_QUOTE, 
  SHIFT_CAPS,
  RSHIFT_CAPS,
  SEMICOLON,
  ANDCOMBO, 
  PLUSCOMBO,
  PLPLCOMBO,
  PLPLENDCOMBO,
  ASTRCOMBO,
  EQLCOMBO, 
  LBRKCOMBO,
  EXCLCOMBO,
  BKSLASH, 
  ATCOMBO,
  HASHCOMBO, 
  DLRCOMBO,
  PERCCOMBO,
  FEM, 
  YOUCOMBO,
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
  MASC, 
  LBRACE, 
  RBRACE, 
  LPAREN,
  RPAREN,
  LSYMHOLD,
  RSYMHOLD, 
  DASHCOMBO,
  MASCOMBO,
  PARACOMBO,//50
};

#define RIGHTUNICODE KC_I, KC_O
#define LEFTUNICODE LT(NUMPAD,KC_A), KC_R
#define RIGHTSYMBOL KC_N, KC_E
#define LEFTSYMBOL KC_S, KC_T
#define RIGHTSHIFTSYMBOL KC_N, KC_E, KC_I
#define LEFTSHIFTSYMBOL KC_R, KC_S, KC_T
#define NUMMOD KC_Q



const uint16_t PROGMEM par_combo[] = {RIGHTUNICODE, KC_P, COMBO_END};
const uint16_t PROGMEM section_combo[] = {RIGHTUNICODE, KC_S, COMBO_END};
const uint16_t PROGMEM fem_combo[] = {RIGHTUNICODE, LT(NUMPAD,KC_A), COMBO_END};

const uint16_t PROGMEM emdash_combo[] = {LEFTUNICODE, MEH_T(KC_U), COMBO_END};
const uint16_t PROGMEM masc_combo[] = {LEFTUNICODE, KC_O, COMBO_END};
const uint16_t PROGMEM sdot_combo[] = {LEFTUNICODE, KC_DOT, COMBO_END};

const uint16_t PROGMEM parbksp_combo[] = {RIGHTSYMBOL, LT(MIRRORED,KC_BSPACE), COMBO_END};
const uint16_t PROGMEM l1quote_combo[] = {RIGHTSYMBOL, SC_QU, COMBO_END};
const uint16_t PROGMEM and_combo[] = {RIGHTSYMBOL, KC_W, COMBO_END};
const uint16_t PROGMEM plus_combo[] = {RIGHTSYMBOL, MEH_T(KC_F), COMBO_END};
const uint16_t PROGMEM astr_combo[] = {RIGHTSYMBOL, KC_P, COMBO_END};
const uint16_t PROGMEM eql_combo[] = {RIGHTSYMBOL, KC_G, COMBO_END};
const uint16_t PROGMEM lbrace_combo[] = {RIGHTSYMBOL, LT(NUMPAD,KC_A), COMBO_END};
const uint16_t PROGMEM lbrk_combo[] = {RIGHTSYMBOL, KC_R, COMBO_END};
const uint16_t PROGMEM lparen_combo[] = {RIGHTSYMBOL, KC_S, COMBO_END};
const uint16_t PROGMEM excl_combo[] = {RIGHTSYMBOL, KC_T, COMBO_END};
const uint16_t PROGMEM bkslash_combo[] = {RIGHTSYMBOL, KC_Z, COMBO_END};
const uint16_t PROGMEM at_combo[] = {RIGHTSYMBOL, KC_X, COMBO_END};
const uint16_t PROGMEM hash_combo[] = {RIGHTSYMBOL, KC_C, COMBO_END};
const uint16_t PROGMEM dlr_combo[] = {RIGHTSYMBOL, KC_V, COMBO_END};
const uint16_t PROGMEM perc_combo[] = {RIGHTSYMBOL, KC_B, COMBO_END};
const uint16_t PROGMEM rshiftcaps_combo[] = {RIGHTSYMBOL, OSM(MOD_LSFT), COMBO_END};

const uint16_t PROGMEM tilde_combo[] = {LEFTSYMBOL, KC_J, COMBO_END};
const uint16_t PROGMEM slash_combo[] = {LEFTSYMBOL, KC_L, COMBO_END};
const uint16_t PROGMEM minus_combo[] = {LEFTSYMBOL, MEH_T(KC_U), COMBO_END};
const uint16_t PROGMEM pipe_combo[] = {LEFTSYMBOL, KC_Y, COMBO_END};
const uint16_t PROGMEM r1quote_combo[] = {LEFTSYMBOL, SP_QUOTE, COMBO_END};
const uint16_t PROGMEM equals_combo[] = {LEFTSYMBOL, KC_N, COMBO_END};
const uint16_t PROGMEM rparen_combo[] = {LEFTSYMBOL, KC_E, COMBO_END};
const uint16_t PROGMEM rbrk_combo[] = {LEFTSYMBOL, KC_I, COMBO_END};
const uint16_t PROGMEM rbrace_combo[] = {LEFTSYMBOL, KC_O, COMBO_END};
const uint16_t PROGMEM caret_combo[] = {LEFTSYMBOL, KC_K, COMBO_END};
const uint16_t PROGMEM grave_combo[] = {LEFTSYMBOL, KC_M, COMBO_END};
const uint16_t PROGMEM shiftcaps_combo[] = {LEFTSYMBOL, OSM(MOD_LSFT), COMBO_END};
const uint16_t PROGMEM bkslash_combo2[] = {LEFTSYMBOL, SP_SLASH, COMBO_END};
const uint16_t PROGMEM semicolon_combo[] = {LEFTSYMBOL, KC_COMMA, COMBO_END};

const uint16_t PROGMEM endtag_combo[] = {LEFTSHIFTSYMBOL, KC_L, COMBO_END};
const uint16_t PROGMEM exactlyequal_combo[] = {LEFTSHIFTSYMBOL, KC_N, COMBO_END};
const uint16_t PROGMEM parensemi_combo[] = {LEFTSHIFTSYMBOL, KC_E, COMBO_END};
const uint16_t PROGMEM scolonenter_combo[] = {LEFTSHIFTSYMBOL, KC_COMMA, COMBO_END};
const uint16_t PROGMEM minusminus_combo[] = {LEFTSHIFTSYMBOL, MEH_T(KC_U), COMBO_END};
const uint16_t PROGMEM r2quote_combo[] = {LEFTSHIFTSYMBOL, SP_QUOTE, COMBO_END};

const uint16_t PROGMEM l2quote_combo[] = {RIGHTSHIFTSYMBOL, SC_QU, COMBO_END};
const uint16_t PROGMEM plusplus_combo[] = {RIGHTSHIFTSYMBOL, MEH_T(KC_F), COMBO_END};

const uint16_t PROGMEM plusplusend_combo[] = {KC_COMMA, MEH_T(KC_F), COMBO_END};
const uint16_t PROGMEM you_combo[] = {KC_L, MEH_T(KC_U), KC_Y, COMBO_END};
const uint16_t PROGMEM para_combo[] = {KC_W, MEH_T(KC_F), KC_P, COMBO_END};
const uint16_t PROGMEM dash_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM mas_combo[] = {KC_X, KC_C, COMBO_END};

const uint16_t PROGMEM lsymhold_combo[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM rsymhold_combo[] = {KC_N, KC_E, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [DOT_BUL] = COMBO(sdot_combo, XXX),
  [CTRL_BKSP] = COMBO(parbksp_combo, LCTL(KC_BSPACE)),
  [R1_QUOTE] = COMBO(r1quote_combo, SC_CLOSE1QUOTE),
  [R2_QUOTE] = COMBO(r2quote_combo, SC_CLOSEQUOTE),
  [L1_QUOTE] = COMBO(l1quote_combo, SC_OPEN1QUOTE),
  [L2_QUOTE] = COMBO(l2quote_combo, SC_OPENQUOTE),
  [SHIFT_CAPS] = COMBO(shiftcaps_combo, XXX),
  [RSHIFT_CAPS] = COMBO(rshiftcaps_combo, XXX),
  [SEMICOLON] = COMBO(semicolon_combo, XXX),
  [ANDCOMBO] = COMBO(and_combo, ES_AMPR),
  [PLUSCOMBO] = COMBO(plus_combo, ES_PLUS),
  [PLPLCOMBO] = COMBO(plusplus_combo, XXX),
  [PLPLENDCOMBO] = COMBO(plusplusend_combo, XXX),
  [ASTRCOMBO] = COMBO(astr_combo, ES_ASTR),
  [EQLCOMBO] = COMBO(eql_combo, ES_EQL),
  [LBRKCOMBO] = COMBO(lbrk_combo, ES_LBRC),
  [EXCLCOMBO] = COMBO(excl_combo, ES_EXLM),
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
  [MASC] = COMBO(masc_combo, ES_MORD),
  [FEM] = COMBO(fem_combo, ES_FORD),
  [YOUCOMBO] = COMBO(you_combo, XXX),
  [LBRACE] = COMBO(lbrace_combo, SP_LBKT),
  [LPAREN] = COMBO(lparen_combo, ES_LPRN),
  [RBRACE] = COMBO(rbrace_combo, SP_RBKT),
  [RPAREN] = COMBO(rparen_combo, ES_RPRN),
  [LSYMHOLD] = COMBO(lsymhold_combo, XXX),
  [RSYMHOLD] = COMBO(rsymhold_combo, XXX),
  [DASHCOMBO] = COMBO(dash_combo, ES_MINS),
  [MASCOMBO] = COMBO(mas_combo, ES_PLUS),
  [PARACOMBO] = COMBO(para_combo, XXX),
};


uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case YOUCOMBO:
            return 250;
    }
    return COMBO_TERM;
}

bool get_combo_must_hold(uint16_t index, combo_t *combo) {
    switch (index) {
        case LSYMHOLD...RSYMHOLD:
            return true;
    }

    return false;
}

void process_combo_event(uint16_t combo_index, bool pressed) {
  handle_shifttimer();
  switch(combo_index) {
    case DOT_BUL:
      if (pressed) {
        SendAltCode(BULLET, 4);
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
        SEND_STRING(SS_LSFT(SS_TAP(X_8) SS_TAP(X_9) SS_TAP(X_COMMA)));
      }
    break;
    case MIMICOMBO:
      if (pressed) {
        SEND_STRING(SS_TAP(X_SLASH) SS_TAP(X_SLASH));
      }
    break;   
    case YOUCOMBO:
      if (pressed) {
        if (shift_pressed()) {
          SEND_STRING(SS_LSFT(SS_TAP(X_Y)) SS_TAP(X_O) SS_TAP(X_U));
          return;
        }
        SEND_STRING(SS_TAP(X_Y) SS_TAP(X_O) SS_TAP(X_U));
      }
    break;
    case PARACOMBO:
      if (pressed) {
        SEND_STRING(SS_TAP(X_P) SS_TAP(X_A) SS_TAP(X_R) SS_TAP(X_A));
      }
    break;
    case LSYMHOLD...RSYMHOLD:
      if (pressed) {
        layer_on(SYMBOL);
      }
      else {
        layer_off(SYMBOL);
      }
    break;
  }
}
