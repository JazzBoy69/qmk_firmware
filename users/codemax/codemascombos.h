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
  PLPLENDCOMBO,
  EQLCOMBO, 
  LBRKCOMBO,
  EXCLCOMBO,
  BKSLASH, 
  ATCOMBO,
  HASHCOMBO, 
  NUMHASHCOMBO,
  DLRCOMBO,
  PERCCOMBO,
  FEM, 
  YOUCOMBO,
  TILDCOMBO, 
  MIMICOMBO,
  PIPECOMBO,
  SCOLONENTER, 
  EQUALSCOMBO,
  RBRKCOMBO,
  CARETCOMBO,
  NUMCARET,
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
  PARACOMBO,
  TIMESCOMBO,
  NOTEQUAL, 
  NUMDASHCOMBO,
  NUMMASCOMBO,
  NUMTIMESCOMBO, 
  NUMXCOMBO, 
  NUMRPAREN,
  NUMLPAREN,//55
};

#define RIGHTUNICODE KC_I, KC_O
#define LEFTUNICODE LT(NUMPAD,KC_A), KC_R
#define RIGHTSYMBOL KC_N, KC_E
#define LEFTSYMBOL KC_S, KC_T
#define RIGHTSHIFTSYMBOL KC_N, KC_E, KC_I
#define LEFTSHIFTSYMBOL KC_R, KC_S, KC_T
#define NUMMOD KC_Q
#define DASH KC_COMMA, KC_DOT



const uint16_t PROGMEM par_combo[] = {RIGHTUNICODE, KC_P, COMBO_END};
const uint16_t PROGMEM section_combo[] = {RIGHTUNICODE, KC_S, COMBO_END};
const uint16_t PROGMEM fem_combo[] = {RIGHTUNICODE, LT(NUMPAD,KC_A), COMBO_END};

const uint16_t PROGMEM masc_combo[] = {LEFTUNICODE, KC_O, COMBO_END};
const uint16_t PROGMEM sdot_combo[] = {LEFTUNICODE, KC_DOT, COMBO_END};

const uint16_t PROGMEM parbksp_combo[] = {RIGHTSYMBOL, LT(MIRRORED,KC_BSPACE), COMBO_END};
const uint16_t PROGMEM l1quote_combo[] = {RIGHTSYMBOL, KC_Q, COMBO_END};
const uint16_t PROGMEM and_combo[] = {RIGHTSYMBOL, KC_W, COMBO_END};
const uint16_t PROGMEM bkslash_combo[] = {RIGHTSYMBOL, KC_Z, COMBO_END};
const uint16_t PROGMEM at_combo[] = {RIGHTSYMBOL, KC_X, COMBO_END};
const uint16_t PROGMEM hash_combo[] = {RIGHTSYMBOL, KC_C, COMBO_END};
const uint16_t PROGMEM numhash_combo[] = {KC_KP_4, KC_KP_5, COMBO_END};
const uint16_t PROGMEM dlr_combo[] = {RIGHTSYMBOL, KC_V, COMBO_END};
const uint16_t PROGMEM perc_combo[] = {RIGHTSYMBOL, KC_B, COMBO_END};
const uint16_t PROGMEM rshiftcaps_combo[] = {RIGHTSYMBOL, OSM(MOD_LSFT), COMBO_END};

const uint16_t PROGMEM tilde_combo[] = {LEFTSYMBOL, KC_J, COMBO_END};
const uint16_t PROGMEM pipe_combo[] = {LEFTSYMBOL, KC_Y, COMBO_END};
const uint16_t PROGMEM r1quote_combo[] = {LEFTSYMBOL, SP_QUOTE, COMBO_END};
const uint16_t PROGMEM caret_combo[] = {LEFTSYMBOL, KC_K, COMBO_END};
const uint16_t PROGMEM grave_combo[] = {LEFTSYMBOL, KC_M, COMBO_END};
const uint16_t PROGMEM shiftcaps_combo[] = {LEFTSYMBOL, OSM(MOD_LSFT), COMBO_END};
const uint16_t PROGMEM bkslash_combo2[] = {LEFTSYMBOL, SP_SLASH, COMBO_END};
const uint16_t PROGMEM semicolon_combo[] = {LEFTSYMBOL, KC_COMMA, COMBO_END};
const uint16_t PROGMEM emdash_combo[] = {LEFTSYMBOL, DASH, COMBO_END};

const uint16_t PROGMEM endtag_combo[] = {LEFTSHIFTSYMBOL, KC_L, COMBO_END};
const uint16_t PROGMEM parensemi_combo[] = {LEFTSHIFTSYMBOL, KC_E, COMBO_END};
const uint16_t PROGMEM scolonenter_combo[] = {LEFTSHIFTSYMBOL, KC_COMMA, COMBO_END};
const uint16_t PROGMEM minusminus_combo[] = {LEFTSHIFTSYMBOL, MEH_T(KC_U), COMBO_END};
const uint16_t PROGMEM r2quote_combo[] = {LEFTSHIFTSYMBOL, SP_QUOTE, COMBO_END};

const uint16_t PROGMEM l2quote_combo[] = {RIGHTSHIFTSYMBOL, KC_Q, COMBO_END};

const uint16_t PROGMEM you_combo[] = {KC_L, MEH_T(KC_U), KC_Y, COMBO_END};
const uint16_t PROGMEM para_combo[] = {KC_W, MEH_T(KC_F), KC_P, COMBO_END};

const uint16_t PROGMEM lsymhold_combo[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM rsymhold_combo[] = {KC_N, KC_E, COMBO_END};

const uint16_t PROGMEM notequal_combo[] = {KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM exactlyequal_combo[] = {KC_Z, KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM equals_combo[] = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM excl_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM eql_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM lparen_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM lbrk_combo[] = {KC_Z, KC_C, COMBO_END};
const uint16_t PROGMEM lbrace_combo[] = {KC_Z, KC_V, COMBO_END};

const uint16_t PROGMEM dash_combo[] = {DASH, COMBO_END};
const uint16_t PROGMEM mas_combo[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM times_combo[] = {KC_M, KC_DOT, COMBO_END};
const uint16_t PROGMEM plusplusend_combo[] = {KC_M, KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM rparen_combo[] = {KC_DOT, SP_SLASH, COMBO_END};
const uint16_t PROGMEM rbrk_combo[] = {KC_COMMA, SP_SLASH, COMBO_END};
const uint16_t PROGMEM rbrace_combo[] = {KC_M, SP_SLASH, COMBO_END};

const uint16_t PROGMEM nummas_combo[] = {KC_KP_1, KC_KP_2, COMBO_END};
const uint16_t PROGMEM numtimes_combo[] = {KC_KP_1, KC_KP_3, COMBO_END};
const uint16_t PROGMEM numdash_combo[] = {KC_KP_2, KC_KP_3, COMBO_END};
const uint16_t PROGMEM numx_combo[] = {KC_KP_5, KC_KP_6, COMBO_END};
const uint16_t PROGMEM numrparen_combo[] = {KC_KP_3, KC_KP_SLASH, COMBO_END};
const uint16_t PROGMEM numlparen_combo[] = {KC_KP_6, ES_SEMI, COMBO_END};
const uint16_t PROGMEM numcaret_combo[] = {KC_KP_1, KC_KP_2, KC_KP_3, COMBO_END};

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
  [PLPLENDCOMBO] = COMBO(plusplusend_combo, XXX),
  [EQLCOMBO] = COMBO(eql_combo, ES_EQL),
  [LBRKCOMBO] = COMBO(lbrk_combo, ES_LBRC),
  [EXCLCOMBO] = COMBO(excl_combo, ES_EXLM),
  [BKSLASH] = COMBO(bkslash_combo, ES_BSLS),
  [ATCOMBO] = COMBO(at_combo, ES_AT),
  [HASHCOMBO] = COMBO(hash_combo, ES_HASH),
  [NUMHASHCOMBO] = COMBO(numhash_combo, ES_HASH),
  [DLRCOMBO] = COMBO(dlr_combo, ES_DLR),
  [PERCCOMBO] = COMBO(perc_combo, ES_PERC),
  [TILDCOMBO] = COMBO(tilde_combo, XXX),
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
  [TIMESCOMBO] = COMBO(times_combo, ES_ASTR),
  [NUMDASHCOMBO] = COMBO(numdash_combo, ES_MINS),
  [NUMMASCOMBO] = COMBO(nummas_combo, ES_PLUS),
  [NUMTIMESCOMBO] = COMBO(numtimes_combo, ES_ASTR),
  [PARACOMBO] = COMBO(para_combo, XXX),
  [NOTEQUAL] = COMBO(notequal_combo, XXX),
  [NUMXCOMBO] = COMBO(numx_combo, KC_X),
  [NUMRPAREN] = COMBO(numrparen_combo, ES_RPRN),
  [NUMLPAREN] = COMBO(numlparen_combo, ES_LPRN),
  [NUMCARET] = COMBO(numcaret_combo, XXX),
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
    case CARETCOMBO...NUMCARET:
      if (pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_LBRACKET)) SS_TAP(X_SPACE));
      }
    break;
    case GRAVECOMBO:
      if (pressed) {
        SEND_STRING(SS_TAP(X_LBRACKET) SS_TAP(X_SPACE));
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
    case NOTEQUAL:
      if (pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_1) SS_TAP(X_0)));
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
