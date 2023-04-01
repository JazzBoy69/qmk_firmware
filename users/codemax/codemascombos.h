enum combo_events {
  DOT_BUL,
  CTRL_BKSP, 
  CTRL_BKSP2,
  R1_QUOTE,
  R2_QUOTE,
  L1_QUOTE,
  L2_QUOTE, 
  ANDCOMBO, 
  PLPLENDCOMBO,
  LBRKCOMBO,
  BKSLASH, 
  ATCOMBO,
  HASHCOMBO, 
  DLRCOMBO,
  PERCCOMBO,
  FEM, 
  YOUCOMBO,
  TILDCOMBO, 
  MIMICOMBO,
  PIPECOMBO,
  SCOLONENTER, 
  EQUALSCOMBO,
  CARETCOMBO,
  NUMMULTI,
  GRAVECOMBO,
  BKSLASH2, 
  EMDASHCOMBO,
  EXCLCOMBO,
  EQLCOMBO, 
  EXACTLYEQUAL,
  NOTEXACTLYEQUAL,
  NOTEQUAL, 
  NUMEXCLCOMBO,
  NUMEQLCOMBO, 
  NUMEQUALSCOMBO,
  NUMEXACTLYEQUAL,
  NUMNOTEXACTLYEQUAL,
  NUMNOTEQUAL, 
  MASC, 
  LBRACE, 
  LPAREN,
  RPAREN,
  RBRACE, 
  RBRKCOMBO,
  NUMRPAREN,
  NUMRBRACE, 
  NUMRBRKCOMBO,
  NUMBACKTAB, 
  NUMTAB,
  DASHCOMBO,
  MASCOMBO,
  PARACOMBO,
  TIMESCOMBO,
  NUMLPAREN,
  NUMLBRACE,
  NUMLBRKCOMBO,
  QUACOMBO,
  QUECOMBO,
  QUICOMBO,
  QUOCOMBO,
  QUISPA,
  TABCOMBO,
  STABCOMBO,
  NUMLOCKCOMBO,
  NUMLAYERCOMBO,
  CANCELNUMLAYER,
  CAPSLOCKCOMBO,
  SECCOMBO,
  PARCOMBO,
  FIVEBACK,
  THREEBACK,
  NONBREAKING,
  HEXA,
  HEXB,
  HEXC,
  HEXD,
  HEXE,
  HEXF,
  NUMBKSP,
  AQUI,
  //83
};

#define RIGHTUNICODE KC_I, KC_O
#define LEFTUNICODE KC_A, KC_R
#define RIGHTSYMBOL KC_N, KC_E
#define LEFTSYMBOL KC_S, KC_T
#define RIGHTSHIFTSYMBOL KC_N, KC_E, KC_I
#define LEFTSHIFTSYMBOL KC_R, KC_S, KC_T
#define NUMMOD KC_Q
#define DASH KC_COMMA, KC_DOT


const uint16_t PROGMEM fem_combo[] = {RIGHTSYMBOL, KC_A, COMBO_END};
const uint16_t PROGMEM parbksp_combo[] = {RIGHTSYMBOL, LT(MIRRORED,KC_BSPACE), COMBO_END};
const uint16_t PROGMEM l1quote_combo[] = {RIGHTSYMBOL, KC_Q, COMBO_END};
const uint16_t PROGMEM and_combo[] = {RIGHTSYMBOL, KC_W, COMBO_END};
const uint16_t PROGMEM bkslash_combo[] = {RIGHTSYMBOL, KC_Z, COMBO_END};
const uint16_t PROGMEM at_combo[] = {RIGHTSYMBOL, KC_X, COMBO_END};
const uint16_t PROGMEM hash_combo[] = {RIGHTSYMBOL, KC_C, COMBO_END};
const uint16_t PROGMEM dlr_combo[] = {RIGHTSYMBOL, KC_V, COMBO_END};
const uint16_t PROGMEM perc_combo[] = {RIGHTSYMBOL, KC_B, COMBO_END};
const uint16_t PROGMEM par_combo[] = {RIGHTSYMBOL, KC_P, COMBO_END};
const uint16_t PROGMEM sec_combo[] = {RIGHTSYMBOL, KC_S, COMBO_END};
const uint16_t PROGMEM pipe_combo[] = {RIGHTSYMBOL, KC_F, COMBO_END};

const uint16_t PROGMEM tilde_combo[] = {LEFTSYMBOL, KC_J, COMBO_END};
const uint16_t PROGMEM r1quote_combo[] = {LEFTSYMBOL, SP_QUOTE, COMBO_END};
const uint16_t PROGMEM caret_combo[] = {LEFTSYMBOL, KC_K, COMBO_END};
const uint16_t PROGMEM grave_combo[] = {LEFTSYMBOL, KC_M, COMBO_END};
const uint16_t PROGMEM bkslash_combo2[] = {LEFTSYMBOL, SP_SLASH, COMBO_END};
const uint16_t PROGMEM emdash_combo[] = {LEFTSYMBOL, DASH, COMBO_END};
const uint16_t PROGMEM nonbreaking[] = {LEFTSYMBOL, LCTL_T(KC_SPACE), COMBO_END};
const uint16_t PROGMEM scolonenter_combo[] = {LEFTSYMBOL, KC_COMMA, COMBO_END};
const uint16_t PROGMEM masc_combo[] = {LEFTSYMBOL, KC_O, COMBO_END};
const uint16_t PROGMEM sdot_combo[] = {LEFTSYMBOL, KC_DOT, COMBO_END};


const uint16_t PROGMEM r2quote_combo[] = {LEFTSHIFTSYMBOL, SP_QUOTE, COMBO_END};
const uint16_t PROGMEM l2quote_combo[] = {RIGHTSHIFTSYMBOL, KC_Q, COMBO_END};

const uint16_t PROGMEM you_combo[] = {KC_L, KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM para_combo[] = {KC_W, KC_F, KC_P, COMBO_END};

const uint16_t PROGMEM notequal_combo[] = {KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM exactlyequal_combo[] = {KC_Z, KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM notexactlyequal_combo[] = {KC_Z, KC_X, KC_C, KC_V, COMBO_END};
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
const uint16_t PROGMEM minusminus_combo[] = {DASH, SP_SLASH, COMBO_END};
const uint16_t PROGMEM rparen_combo[] = {KC_DOT, SP_SLASH, COMBO_END};
const uint16_t PROGMEM rbrk_combo[] = {KC_COMMA, SP_SLASH, COMBO_END};
const uint16_t PROGMEM rbrace_combo[] = {KC_M, SP_SLASH, COMBO_END};

const uint16_t PROGMEM nummulti_combo[] = {ES_SEMI, KC_KP_PLUS, COMBO_END};

const uint16_t PROGMEM numnotequal_combo[] = {ES_EXLM, ES_AT, ES_HASH, COMBO_END};
const uint16_t PROGMEM numexactlyequal_combo[] = {ES_BSLS, ES_EXLM, ES_AT, COMBO_END};
const uint16_t PROGMEM numnotexactlyequal_combo[] = {ES_BSLS, ES_EXLM, ES_AT, ES_HASH, COMBO_END};
const uint16_t PROGMEM numequals_combo[] = {ES_EXLM, ES_HASH, COMBO_END};
const uint16_t PROGMEM numexcl_combo[] = {ES_AT, ES_HASH, COMBO_END};
const uint16_t PROGMEM numeql_combo[] = {ES_EXLM, ES_AT, COMBO_END};
const uint16_t PROGMEM numlparen_combo[] = {ES_BSLS,  ES_EXLM, COMBO_END};
const uint16_t PROGMEM numlbrk_combo[] = {ES_BSLS, ES_AT, COMBO_END};
const uint16_t PROGMEM numlbrace_combo[] = {ES_BSLS, ES_HASH, COMBO_END};
const uint16_t PROGMEM numbksp_combo[] = {KC_KP_4, KC_KP_5, LALT_T(KC_BSPACE), COMBO_END};
const uint16_t PROGMEM numbacktab_combo[] = {SP_SPACEEND, KC_ESCAPE, COMBO_END};
const uint16_t PROGMEM numtab_combo[] = {SP_SPACEEND, KC_KP_0, COMBO_END};

const uint16_t PROGMEM numrparen_combo[] = {KC_KP_3, KC_KP_SLASH, COMBO_END};
const uint16_t PROGMEM numrbrk_combo[] = {KC_KP_2, KC_KP_SLASH, COMBO_END};
const uint16_t PROGMEM numrbrace_combo[] = {KC_KP_1, KC_KP_SLASH, COMBO_END};

const uint16_t PROGMEM hexa[] = {SP_CARET, KC_KP_1, COMBO_END};
const uint16_t PROGMEM hexb[] = {SP_CARET, KC_KP_2, COMBO_END};
const uint16_t PROGMEM hexc[] = {SP_CARET, KC_KP_3, COMBO_END};
const uint16_t PROGMEM hexd[] = {SP_CARET, KC_KP_4, COMBO_END};
const uint16_t PROGMEM hexe[] = {SP_CARET, KC_KP_5, COMBO_END};
const uint16_t PROGMEM hexf[] = {SP_CARET, KC_KP_6, COMBO_END};


const uint16_t PROGMEM quacombo[] = {KC_Q, SP_QUOTE, COMBO_END};
const uint16_t PROGMEM quecombo[] = {KC_Q, KC_E, COMBO_END};
const uint16_t PROGMEM quicombo[] = {KC_Q, KC_I, COMBO_END};
const uint16_t PROGMEM quocombo[] = {KC_Q, KC_O, COMBO_END};
const uint16_t PROGMEM aquicombo[] = {SP_A, SC_QUI, COMBO_END};

const uint16_t PROGMEM tabcombo[] = {LT(FN,KC_ENTER), LCTL_T(KC_SPACE), COMBO_END};
const uint16_t PROGMEM stabcombo[] = {LT(FN,KC_ENTER), SC_SUPERQUES, COMBO_END};
const uint16_t PROGMEM numlockcombo[] = {LEFTSYMBOL, KC_KP_4, COMBO_END};
const uint16_t PROGMEM numlayercombo[] = {LEFTSYMBOL, KC_E, COMBO_END};
const uint16_t PROGMEM cancelnumlayer[] = {LEFTSYMBOL, KC_KP_5, COMBO_END};
const uint16_t PROGMEM capslockcombo[] = {LEFTSYMBOL, KC_N, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [DOT_BUL] = COMBO(sdot_combo, XXX),
  [CTRL_BKSP] = COMBO(parbksp_combo, LCTL(KC_BSPACE)),
  [NUMBKSP] = COMBO(numbksp_combo, LCTL(KC_BSPACE)),
  [R1_QUOTE] = COMBO(r1quote_combo, SC_CLOSE1QUOTE),
  [R2_QUOTE] = COMBO(r2quote_combo, SC_CLOSEQUOTE),
  [L1_QUOTE] = COMBO(l1quote_combo, SC_OPEN1QUOTE),
  [L2_QUOTE] = COMBO(l2quote_combo, SC_OPENQUOTE),
  [ANDCOMBO] = COMBO(and_combo, ES_AMPR),
  [PLPLENDCOMBO] = COMBO(plusplusend_combo, XXX),
  [BKSLASH] = COMBO(bkslash_combo, ES_BSLS),
  [ATCOMBO] = COMBO(at_combo, ES_AT),
  [HASHCOMBO] = COMBO(hash_combo, ES_HASH),
  [DLRCOMBO] = COMBO(dlr_combo, ES_DLR),
  [PERCCOMBO] = COMBO(perc_combo, ES_PERC),
  [TILDCOMBO] = COMBO(tilde_combo, XXX),
  [PIPECOMBO] = COMBO(pipe_combo, ES_PIPE),
  [SCOLONENTER] = COMBO(scolonenter_combo, XXX),
  [NUMEQUALSCOMBO] = COMBO(numequals_combo, XXX),
  [NUMEQLCOMBO] = COMBO(numeql_combo, ES_EQL),
  [NUMEXCLCOMBO] = COMBO(numexcl_combo, ES_EXLM),
  [NUMEXACTLYEQUAL] = COMBO(numexactlyequal_combo, XXX),
  [NUMNOTEXACTLYEQUAL] = COMBO(numnotexactlyequal_combo, XXX),
  [EQUALSCOMBO] = COMBO(equals_combo, XXX),
  [EQLCOMBO] = COMBO(eql_combo, ES_EQL),
  [EXCLCOMBO] = COMBO(excl_combo, ES_EXLM),
  [EXACTLYEQUAL] = COMBO(exactlyequal_combo, XXX),
  [NOTEXACTLYEQUAL] = COMBO(notexactlyequal_combo, XXX),
  [NOTEQUAL] = COMBO(notequal_combo, XXX),
  [NUMNOTEQUAL] = COMBO(numnotequal_combo, XXX),
  [CARETCOMBO] = COMBO(caret_combo, XXX),
  [GRAVECOMBO] = COMBO(grave_combo, XXX),
  [BKSLASH2] = COMBO(bkslash_combo2, ES_BSLS),
  [EMDASHCOMBO] = COMBO(emdash_combo, XXX),
  [MIMICOMBO] = COMBO(minusminus_combo, XXX),
  [MASC] = COMBO(masc_combo, XXX),
  [FEM] = COMBO(fem_combo, XXX),
  [YOUCOMBO] = COMBO(you_combo, XXX),
  [LBRACE] = COMBO(lbrace_combo, SP_LBKT),
  [LBRKCOMBO] = COMBO(lbrk_combo, ES_LBRC),
  [LPAREN] = COMBO(lparen_combo, ES_LPRN),
  [RBRACE] = COMBO(rbrace_combo, SP_RBKT),
  [RPAREN] = COMBO(rparen_combo, ES_RPRN),
  [RBRKCOMBO] = COMBO(rbrk_combo, ES_RBRC),
  [NUMRBRACE] = COMBO(numrbrace_combo, SP_RBKT),
  [NUMRBRKCOMBO] = COMBO(numrbrk_combo, ES_RBRC),
  [DASHCOMBO] = COMBO(dash_combo, ES_MINS),
  [MASCOMBO] = COMBO(mas_combo, ES_PLUS),
  [TIMESCOMBO] = COMBO(times_combo, ES_ASTR),
  [PARACOMBO] = COMBO(para_combo, XXX),
  [NUMRPAREN] = COMBO(numrparen_combo, ES_RPRN),
  [NUMLPAREN] = COMBO(numlparen_combo, ES_LPRN),
  [NUMLBRACE] = COMBO(numlbrace_combo, SP_LBKT),
  [NUMLBRKCOMBO] = COMBO(numlbrk_combo, ES_LBRC),
  [QUACOMBO] = COMBO(quacombo, XXX),
  [QUECOMBO] = COMBO(quecombo, XXX),
  [QUICOMBO] = COMBO(quicombo, XXX),
  [QUOCOMBO] = COMBO(quocombo, XXX),
  [AQUI] = COMBO(aquicombo, XXX),
  [TABCOMBO] = COMBO(tabcombo, KC_TAB),
  [STABCOMBO] = COMBO(stabcombo, S(KC_TAB)),
  [NUMTAB] = COMBO(numtab_combo, KC_TAB),
  [NUMBACKTAB] = COMBO(numbacktab_combo, S(KC_TAB)),
  [NUMLOCKCOMBO] = COMBO(numlockcombo, KC_NUMLOCK),
  [NUMLAYERCOMBO] = COMBO(numlayercombo, XXX),
  [CAPSLOCKCOMBO] = COMBO(capslockcombo, KC_CAPSLOCK),
  [SECCOMBO] = COMBO(sec_combo, XXX),
  [PARCOMBO] = COMBO(par_combo, XXX),
  [CANCELNUMLAYER] = COMBO(cancelnumlayer, XXX),
  [NONBREAKING] = COMBO(nonbreaking, XXX),
  [NUMMULTI] = COMBO(nummulti_combo, ES_ASTR),
  [HEXA] = COMBO(hexa, S(KC_A)),
  [HEXB] = COMBO(hexb, S(KC_B)),
  [HEXC] = COMBO(hexc, S(KC_C)),
  [HEXD] = COMBO(hexd, S(KC_D)),
  [HEXE] = COMBO(hexe, S(KC_E)),
  [HEXF] = COMBO(hexf, S(KC_F)),
};


uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case YOUCOMBO:
            return 250;
    }
    return COMBO_TERM;
}


void process_combo_event(uint16_t combo_index, bool pressed) {
  handle_shifttimer();
  if (!pressed) return;
  switch(combo_index) {
    case MASC: 
      SendAltCode(MASCORD, 4); 
    break;
    case FEM: 
      SendAltCode(FEMORD, 4); 
    break;
    case SECCOMBO:
      SendAltCode(SEC, 4);
    break;
    case PARCOMBO:
      SendAltCode(PAR, 4);;
    break;
    case DOT_BUL:
      SendAltCode(BULLET, 4);
    break;
    case TILDCOMBO:
      SEND_STRING(ESP_TILDE);
    break;
    case SCOLONENTER:
      SEND_STRING(SS_TAP(X_END) ESP_SEMICOLON SS_TAP(X_ENTER));
    break;
    case EQUALSCOMBO:
    case NUMEQUALSCOMBO:
      SEND_STRING(ESP_EQUAL ESP_EQUAL);
    break;
    case NOTEQUAL:
    case NUMNOTEQUAL:
      SEND_STRING(ESP_EXCL ESP_EQUAL);
    break;
    case CARETCOMBO:
      SEND_STRING(ESP_CARET);
    break;
    case GRAVECOMBO:
      SEND_STRING(ESP_GRAVE);
    break;
    case PLPLENDCOMBO:
      SEND_STRING(ESP_PLUS ESP_PLUS ESP_SEMICOLON);
    break;
    case EMDASHCOMBO:
      SendAltCode(EMDASH, 4);
    break;
    case EXACTLYEQUAL:
    case NUMEXACTLYEQUAL:
      SEND_STRING(ESP_EQUAL ESP_EQUAL ESP_EQUAL);
    break;
    case NOTEXACTLYEQUAL:
    case NUMNOTEXACTLYEQUAL:
      SEND_STRING(ESP_EXCL ESP_EQUAL ESP_EQUAL);
    break;
    case MIMICOMBO:
      SEND_STRING(ESP_MINUS ESP_MINUS ESP_SEMICOLON);
    break;   
    case YOUCOMBO:
      if (shift_pressed()) {
        SEND_STRING(SS_LSFT(SS_TAP(X_Y)) SS_TAP(X_O) SS_TAP(X_U));
        return;
      }
      SEND_STRING(SS_TAP(X_Y) SS_TAP(X_O) SS_TAP(X_U));
    break;
    case PARACOMBO:
      SEND_STRING(SS_TAP(X_P) SS_TAP(X_A) SS_TAP(X_R) SS_TAP(X_A));
    break;
    case QUACOMBO:
      SEND_STRING(SS_TAP(X_Q) SS_TAP(X_U) SS_TAP(X_A));
    break;
    case QUECOMBO:
      SEND_STRING(SS_TAP(X_Q) SS_TAP(X_U) SS_TAP(X_E));
    break;
    case QUICOMBO:
      SEND_STRING(SS_TAP(X_Q) SS_TAP(X_U) SS_TAP(X_I));
    break;
    case QUOCOMBO:
      SEND_STRING(SS_TAP(X_Q) SS_TAP(X_U) SS_TAP(X_O));
    break;
    case AQUI:
      SEND_STRING(SS_TAP(X_A) SS_TAP(X_Q) SS_TAP(X_U));
      press_tilde_and_letter(KC_I);
      reset_oneshot_layer();
      layer_off(SPANISH);
      layer_on(COLEMAK);
    break;
    case NUMLAYERCOMBO:
      layer_on(NUMPAD);
    break;
    case CANCELNUMLAYER:
      layer_off(NUMPAD);
    break;
    case FIVEBACK:
      SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC));
    break;
    case THREEBACK:
      SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC));
    break;
    case NONBREAKING:
      SendAltCode(NONBREAKINGSPACE, 3);
    break;
  }
}
