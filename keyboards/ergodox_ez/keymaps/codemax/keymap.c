
#include QMK_KEYBOARD_H
#include "version.h"
#include <stdlib.h>
#include "codemax.h"

#define ERGODOX yes

#define LAYOUT_wrapper(...)            LAYOUT_ergodox_pretty(__VA_ARGS__)
#define LAYOUT_ergodox_base( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,\
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,\
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D,\
    K40, K41, K42, K43, K44, K45, K46, K47, K48, K49,\
    K50, K51, K52, K53,\
    K60, K61,\
    K70, K71, K72, K73, K74, K75\
  ) \
  LAYOUT_wrapper( \
         K00,  K01,     K02,     K03,     K04,     K05,  K06,                              K07,     K08,     K09,     K0A,     K0B,     K0C,     K0D,\
         K10,  K11,     K12,     K13,     K14,     K15,  K16,                              K17,     K18,     K19,     K1A,     K1B,     K1C,     K1D,\
         K20,  K21,     K22,     K23,     K24,     K25,                                             K26,     K27,     K28,     K29,     K2A,     K2B,\
         K30,  K31,     K32,     K33,     K34,     K35,  K36,                              K37,     K38,     K39,     K3A,     K3B,     K3C,     K3D,\
         K40,  K41,     K42,     K43,     K44,                                                               K45,     K46,     K47,     K48,     K49,\
                                                            K50, K51,                 K52, K53,\
                                                                 K60,                 K61,\
                                                       K70, K71, K72,                 K73, K74, K75\
    )
/* Re-pass though to allow templates to be used */
#define LAYOUT_ergodox_base_wrapper(...)       LAYOUT_ergodox_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLEMAK] = LAYOUT_ergodox_base_wrapper(
        ________________BLOCK_____________________, XXX,          XXX, ________________BLOCK_____________________, 
        ________________COLEMAK_L1________________, XXX,          XXX, ________________COLEMAK_R1________________, 
        ________________COLEMAK_L2________________,                    ________________COLEMAK_R2________________,
        ________________COLEMAK_L3________________, XXX,          XXX, ________________COLEMAK_R3________________,
    XXX, XXX,     _________BOTTOM_L1_________,                                     _________BOTTOM_R1_________, XXX, XXX,
                                                   XXX, XXX,  XXX, XXX,
                                                      TH_L2,  TH_R2,
                                            THUMB_L1, TH_L3,  TH_R3, THUMB_R1
  ),
  [TYPING] = LAYOUT_ergodox_base_wrapper(
    ________________BLANK_____________________, ___,               ___, ________________BLANK_____________________, 
    ________________TYPING_L1_________________, ___,               ___, ________________TYPING_R1_________________, 
    ________________TYPING_L2_________________,                         ________________TYPING_R2_________________, 
    ________________TYPING_L3_________________, ___,               ___, ________________TYPING_R3_________________, 
    ___, ___,     ____TYPE_BOTTOM_L1_________,                               ____TYPE_BOTTOM_R1_________, ___, ___,
                                                     ___, ___,  ___, ___,
                                                        TYPE_L2,  TYPE_R2,
                                              TYPE_L1, TYPE_L3,   TYPE_R3, TYPE_R1

  ), 
  [NUMPAD] = LAYOUT_ergodox_base_wrapper(
    ________________BLANK_____________________,  ___,      ___, ________________BLANK_____________________,                       
    ___, ___, ___,    ___,    ___,    TG(GAME),  XXX,      ___, ________________NUMPAD_R1_________________,               
    ________________NUMPAD_L2_________________,                 ________________NUMPAD_R2_________________,  
    ________________NUMPAD_L3_________________,  ___,      ___, ________________NUMPAD_R3_________________,
    ___, ___,    _____NUM_BOTTOM_L1_________,                       _____NUM_BOTTOM_R1_________, ___, ___,       
                                             ___, ___,  ___, ___,
                                                NUM_L2,  NUM_R2,
                                        NUM_L1, NUM_L3,   NUM_R3, NUM_R1                                                                   
  ),
  [NAV] = LAYOUT_ergodox_base_wrapper(
    ________________BLANK_____________________,  ___,      ___, ________________BLANK_____________________,                       
    ________________NAV_L1____________________,  XXX,      ___, ________________NAV_R1____________________,               
    ________________NAV_L2____________________,                 ________________NAV_R2____________________,  
    ________________NAV_L3____________________,  ___,      ___, ________________NAV_R3____________________,
    ___, ___,     _____NAV_BOTTOM_L1_________,                    _____NAV_BOTTOM_R1_________, ___, ___,       
                                             ___, ___,  ___, ___,
                                                NAV_L2,  NAV_R2,
                                        NAV_L1, NAV_L3,   NAV_R3, NAV_R1   
  ),
  [GAME] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
    ___, KC_1,  KC_2,     KC_3,      KC_4,    KC_5, ___,             
    ___, KC_Y,  KC_Q,     KC_W,      KC_E,    KC_R, KC_T,               
   KC_X, KC_G,  KC_A,     KC_S,      KC_D,    KC_F,             
    ___, KC_B,  KC_Z,     KC_X,      KC_C,    KC_V, ___,                          
    ___, KC_DOT, ___,      ___,       ___,                                                                                        
 // left thumb --------------------------------------------------------------------------------------------------
                                  XXX,              ___, 
                                                    ___, 
                               KC_SPACE,  KC_SPACE, ___, 
// right hand --------------------------------------------------------------------------------------------------
                                 ___, KC_6, KC_7,     KC_8,    KC_9,    KC_0,  KC_LOCK,
                                 ___, ___,  ___,      KC_UP,    ___,     ___,  TO(COLEMAK),
                                      ___, KC_LEFT,  KC_DOWN, KC_RIGHT,  ___,   ___,
                                 ___, ___,  ___,      ___,      ___,     ___,   ___,
                                            ___,      ___,      ___,     ___,   ___,
// right thumb -------------------------------------------------------------------------------------------------
                          ___, XXX,
                          ___,
                        TO(COLEMAK),  ___,   ___
  ),
  [FN] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
             ___,           ___,           ___,         ___,        ___,     ___,    ___, 
           RESET,           ___,           ___,     SC_EMDASH,      ___,     ___,    ___, 
     KC_SYSTEM_SLEEP,      KC_1,  LALT_T(KC_2), LCTL_T(KC_3), LSFT_T(KC_4), KC_5,   
         KC_PSCREEN,           KC_6,         KC_7,         KC_8,       KC_9,    KC_0,   ___,      
             ___,            ___,          ___,          ___,        ___,      
 // left thumb --------------------------------------------------------------------------------------------------
                           ___, ___,
                                ___,
                      ___, ___, ___,
// right hand --------------------------------------------------------------------------------------------------
                        ___,        ___, ___,   ___,  ___, ___,  ___,
                        ___,        XXX, KC_F7, KC_F8, KC_F9, XXX,  KC_F12,
                                    XXX, KC_F4, KC_F5, KC_F6, XXX,  XXX,
                        ___,        XXX, KC_F1, KC_F2, KC_F3, XXX,  ___,
                                         ___,   ___,   ___, ___,    ___,
// right thumb -------------------------------------------------------------------------------------------------
               ___, ___,
               ___,
               ___, KC_F11, KC_F10 
  ),
  [SYM] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
            ___,                 ___,           ___,           ___,            ___,            ___,        ___,                                
          SC_FEM,        SC_OPEN1QUOTE,      KC_AMPR,       KC_PLUS,        KC_ASTR,        KC_EQUAL,     ___,     
            ___,              KC_LCBR,       KC_LBRACKET,    KC_LPRN,        KC_EXLM,        KC_UNDS,             
            ___,              KC_BSLASH,       KC_AT,        KC_HASH,        KC_DLR,         KC_PERC,      ___,     
            ___,                 ___,           ___,           ___,           ___,                                                                                            
 // left thumb --------------------------------------------------------------------------------------------------
                                                                                               ___, ___,
                                                                                                    ___,
                                                                   LCTL(KC_BSPACE),            ___, ___,
// right hand --------------------------------------------------------------------------------------------------
                                 ___,         ___,         ___,          ___,              ___,           ___,             ___,
                                 ___,      KC_TILD,      KC_SLASH,      KC_MINUS,         KC_PIPE,      SC_CLOSE1QUOTE,   SC_MASC,
                                          SC_SEMICLNENTER,   SC_EQUALS,  KC_RPRN,        KC_RBRACKET,     KC_RCBR,         ___,
                                 ___,      KC_CIRC,        ___,         KC_SCOLON,        KC_COLN,     KC_BSLASH,          ___,
                                                           ___,           ___,              ___,           ___,            ___,
// right thumb -------------------------------------------------------------------------------------------------
               ___, ___,
               ___,
               ___, SC_SUPERQUES, SC_SUPERDOT
  ),
  [SYMPLUS] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
    ___,     ___,     ___,      ___,   ___, ___,  ___, 
    ___,     ___,   KC_UP,      ___,   ___, ___,  ___, 
    ___, KC_LEFT, KC_DOWN, KC_RIGHT,   ___, ___, 
    ___,     ___,     ___,      ___,   ___, ___,  ___,  
    ___,     ___,     ___,      ___,   ___,   
 // left thumb --------------------------------------------------------------------------------------------------
                                                                              ___, ___,
                                                                                   ___,
                                                                         ___, ___, ___,
// right hand --------------------------------------------------------------------------------------------------
                                 ___, ___,             ___,               ___,             ___,             ___,   ___,
                                 ___, ___,       SC_ENDTAG,         SC_EMDASH,             ___,   SC_CLOSEQUOTE,   ___,
                                      ___, SC_EXACTLYEQUAL, SC_PARENSEMICOLON,   SC_SELECTLINE, SC_SURROUNDBRKT,   ___,
                                 ___, ___,             ___,    SC_LESSOREQUAL, SC_GREATOREQUAL,        DEL_LINE,   ___,
                                                       ___,               ___,             ___,             ___,   ___,
// right thumb -------------------------------------------------------------------------------------------------
               ___, ___,
               ___,
               ___, ___, ___ 
  ),
  [UNICODE] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
    ___,      ___,   ___,  ___,    ___,        ___,  ___, 
    ___,      ___,   ___,  ___,  SC_PAR,     SC_GU,  ___, 
    ___,      SC_A,  ___, SC_SEC, SC_INVBANG, ___, 
    SC_SHIFT, ___,   ___,  ___,   ___,        ___,   ___,  
    ___,      ___,   ___,  ___,   ___,   
 // left thumb --------------------------------------------------------------------------------------------------
                                                                              ___, ___,
                                                                                   ___,
                                                                         XXX, ___, ___,
// right hand --------------------------------------------------------------------------------------------------
                                 ___, ___,    ___,   ___,     ___,      ___,   ___,
                                 ___, ___,    ___,  SC_U,     SC_Y,     ___,   ___,
                                      ___,   SC_N,  SC_E,     SC_I,    SC_O,   ___,
                                 ___, ___,    ___,  SC_COMMA, SC_DOT, SC_INVQUES, SC_SHIFT,
                                              ___,   ___,      ___,     ___,   ___,
// right thumb -------------------------------------------------------------------------------------------------
               ___, ___,
               ___,
               ___, SC_SUPERINVQUES, ___ 
  ),
[MIRRORED] = LAYOUT_ergodox(
// left hand ---------------------------------------------------------------------------------------------------
    ___,               ___,             ___,            ___,         ___,          ___,         ___,  
    OSL(MIRUNI),     KC_QUOTE,          KC_Y,           KC_U,        KC_L,         KC_J,        ___,  
    OSL(MIRSYM),      KC_O,             KC_I,           KC_E,        KC_N,         KC_H, 
    ___,             KC_QUES,          KC_DOT,        KC_COMMA,      KC_M,         KC_K,        ___,  
    ___,               ___,              ___,            ___,          ___,                       
 // left thumb --------------------------------------------------------------------------------------------------
                                                                         ___,        ___,    
                                                                                     ___,        
                                                                          ___,  ___, ___,   
  // right hand --------------------------------------------------------------------------------------------------
                                 ___,      ___,         ___,               ___,               ___,          ___,   ___,
                                 ___, SC_ARROW,   SC_ENDTAG,         SC_EMDASH,               ___, SC_OPENQUOTE,   ___,
                                           ___, SC_NOTEQUAL, SC_OPENCLOSEPAREN, OPENCLOSEBRACKETS,   SC_SECTION,   ___,
                                 ___,      ___,         ___,    SC_LESSOREQUAL,   SC_GREATOREQUAL,     DEL_LINE,   ___,
                                                        ___,               ___,               ___,          ___,   ___,
  // right thumb -------------------------------------------------------------------------------------------------
  ___,     ___,
  ___,
  ___,     ___,     ___
  ),
  [MIRUNI] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
    TO(COLEMAK),     ___,      ___,  ___,    ___,        ___,  ___, 
    ___,          ___,     SC_Y, SC_U,  SC_PAR,     SC_GU,  ___, 
    ___,          SC_O,    SC_I, SC_E,  SC_N,         ___, 
    SC_MIRSHIFT, SC_INVQUES,    ___,  ___,   ___,         ___,   ___,  
    ___,           ___,      ___,  ___,   ___,   
 // left thumb --------------------------------------------------------------------------------------------------
                                                                              ___, ___,
                                                                                   ___,
                                                                         XXX, ___, ___,
// right hand --------------------------------------------------------------------------------------------------
                                 ___, ___,    ___,   ___,     ___,     ___,   ___,
                                 ___, ___,    ___,   ___,     ___,     ___,   ___,
                                      ___,    ___,   ___,     ___,     ___,   ___,
                                 ___, ___,    ___,   ___,     ___,     ___,   ___,
                                              ___,   ___,     ___,     ___,   ___,
// right thumb -------------------------------------------------------------------------------------------------
               ___, ___,
               ___,
               ___, ___, ___ 
  ),
  [MIRSYM] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
         TO(COLEMAK),                KC_1,          KC_2,          KC_3,           KC_4,           KC_5,        ___,                                
          SC_FEM,        SC_CLOSE1QUOTE,      KC_PIPE,       KC_MINUS,        KC_SLASH,      KC_TILD,      ___,     
            ___,              KC_RCBR,       KC_RBRACKET,    KC_RPRN,        SC_EQUALS,    SC_SEMICLNENTER,             
            ___,             KC_BSLASH,       KC_COLN,       KC_SCOLON,       ___,           KC_CIRC,        ___,     
            ___,                 ___,           ___,           ___,           ___,                                                                                            
 // left thumb --------------------------------------------------------------------------------------------------
                                                                                               ___, ___,
                                                                                                    ___,
                                                                                           ___,___, ___,
// right hand --------------------------------------------------------------------------------------------------
                                 ___,      ___,    ___,      ___,   ___,    ___,      ___,
                                 ___,      ___,    ___,      ___,   ___,    ___,      ___,
                                           ___,    ___,      ___,   ___,    ___,      ___,
                                 ___,      ___,    ___,      ___,   ___,    ___,      ___,
                                                   ___,      ___,   ___,    ___,      ___,
// right thumb -------------------------------------------------------------------------------------------------
               ___, ___,
               ___,
               ___, ___, ___ 
  ),
};


// The state of the LEDs requested by the system, as a bitmask.
static uint8_t sys_led_state = 0;

// Use these masks to read the system LEDs state.
static const uint8_t sys_led_mask_num_lock = 1 << USB_LED_NUM_LOCK;
static const uint8_t sys_led_mask_scroll_lock = 1 << USB_LED_SCROLL_LOCK;

// Value to use to switch LEDs on. The default value of 255 is far too bright.
static const uint8_t max_led_value = 20;
#define right_led 1
#define middle_led 2

void led_1_on(void) {
  ergodox_right_led_1_on();
  ergodox_right_led_1_set(max_led_value);
}

void led_2_on(void) {
  ergodox_right_led_2_on();
  ergodox_right_led_2_set(max_led_value);
}

void led_3_on(void) {
  ergodox_right_led_3_on();
  ergodox_right_led_3_set(max_led_value);
}

void led_1_off(void) {
  ergodox_right_led_1_off();
}

void led_2_off(void) {
  ergodox_right_led_2_off();
}

void led_3_off(void) {
  ergodox_right_led_3_off();
}

void set_indicator(void) {
	if (current_layer > NAV) {
		return;
	}
	led_1_off();
	if ((current_layer == COLEMAK) || (current_layer == TYPING)) {
		if (caps_lock_on()) {
		  led_1_on();
		}
		return;
  }
  if (current_layer == NUMPAD) {
    if (!(sys_led_state & sys_led_mask_num_lock)) {
      led_1_on();
    } 
	return;
  }
  if (current_layer == NAV) {
    if (sys_led_state & sys_led_mask_scroll_lock) {
      led_1_on();
    }
	return;
  }
}

void led_set_user(uint8_t usb_led) {
  sys_led_state = usb_led;
	set_indicator();
 }
 
 void breathe(void) {
	 	uint8_t level = abs((timer_read() % 4000)/100 - 20);
		ergodox_led_all_set(level);
 }
 
 void run(uint16_t speed)  {
	uint8_t level = (timer_read() % (4 * speed))/speed ;
	switch (level) {
		case 0:
			led_1_off();
			led_2_off();
			led_3_off();
			break;
		case 1:
			led_1_on();
			led_2_off();
			led_3_off();
			break;
		case 2:
			led_1_off();
			led_2_on();
			led_3_off();
			break;
		case 3:
			led_1_off();
			led_2_off();
			led_3_on();
			break;
		default:
		  break;
	 }
 }
 
 void flash(uint16_t time, uint8_t leds) {
	 uint8_t state = (timer_read() % time) / (time / 2);
	 led_1_off();
	 if (state ==  0) {
		 led_2_off();
		 led_3_off();
		 return;
	 }
	 if (leds & middle_led) {
		 led_2_on();
	 }
	 if (leds & right_led) {
		 led_3_on();
	 }
 }


void matrix_scan_user(void) {
  HANDLE_MATRIX_SCAN
  if (current_layer == GAME) {
		run(512);
		return;
	}
	if ((current_layer == SYM) && (timer_elapsed(change_time) > 500)) {
		flash(512, right_led);
		return;
	}
	if (((current_layer == SYMPLUS) || (current_layer == MIRRORED)) && (timer_elapsed(change_time) > 500)) {
		flash(512, right_led | middle_led);
		return;
	}
};


uint32_t layer_state_set_user(uint32_t state) {
  current_layer = biton32(state);
  change_time = timer_read();
  set_indicator();
	led_2_off();
	led_3_off();
  switch (current_layer) {
    case NUMPAD:
      led_3_on();
      break;
    case NAV:
      led_2_on();
	  break;
    case TYPING:
      led_2_on();
      led_3_on();
      break;
    case FN:
      led_1_on();
	    led_2_on();
      led_3_on();
      break;
    default:
      break;
  }
  return state;
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
