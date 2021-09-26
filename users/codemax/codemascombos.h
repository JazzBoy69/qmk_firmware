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
  YOUCOMBO,
  YOUCOMBO2,
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
const uint16_t PROGMEM you_combo[] = {KC_L, KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM you_combo2[] = {KC_L, KC_Y, MEH_T(KC_U), COMBO_END};

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
  [YOUCOMBO] = COMBO(you_combo, XXX),
  [YOUCOMBO2] = COMBO(you_combo2, XXX),
};




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
    case YOUCOMBO:
      if (pressed) {
        SEND_STRING(SS_TAP(X_Y) SS_TAP(X_O) SS_TAP(X_U));
      }
    break;
    case YOUCOMBO2:
      if (pressed) {
        SEND_STRING(SS_TAP(X_Y) SS_TAP(X_O) SS_TAP(X_U));
      }
    break;
  }
}
