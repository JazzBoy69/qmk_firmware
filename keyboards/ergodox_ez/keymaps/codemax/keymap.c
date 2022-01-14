
#include QMK_KEYBOARD_H
#include "version.h"
#include <stdlib.h>
#include "codemas.h"
#include "codemascombos.h"

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
        ________________COLEMAK_L3________________, XXX,      XXX, ________________COLEMAK_R3________________,
    XXX, XXX,     _________BOTTOM_L1_________,                                     _________BOTTOM_R1_________, XXX, XXX,
                                                    XXX,XXX,  KC_PSCREEN, XXX,
                                                      TH_L2,  TH_R2,
                                            THUMB_L1, TH_L3,  TH_R3, THUMB_R1
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
  [FN] = LAYOUT_ergodox_base_wrapper(
    ________________BLANK_____________________,  ___,      ___, ________________BLANK_____________________,                       
    ________________FN_L1_____________________,  XXX,      ___, ________________FN_R1_____________________,               
    ________________FN_L2_____________________,                 ________________FN_R2_____________________,  
    ________________FN_L3_____________________,  ___,      ___, ________________FN_R3_____________________,
    ___, ___,     _____FN_BOTTOM_L1__________,                    _____FN_BOTTOM_R1__________, ___, ___,       
                                             ___, ___,  ___, ___,
                                                FN_L2,  FN_R2,
                                        FN_L1, FN_L3,   FN_R3, FN_R1      
  ),
[MIRRORED] = LAYOUT_ergodox_base_wrapper(
    ________________BLANK_____________________,  ___,      ___, ________________BLANK_____________________,                       
    ________________MIR_L1____________________,  XXX,      ___, ________________MIR_R1____________________,               
    ________________MIR_L2____________________,                 ________________MIR_R2____________________,  
    ________________MIR_L3____________________,  ___,      ___, ________________MIR_R3____________________,
    ___, ___,     _____MIR_BOTTOM_L1_________,                    _____MIR_BOTTOM_R1_________, ___, ___,       
                                             ___, ___,  ___, ___,
                                                MIR_L2,  MIR_R2,
                                        MIR_L1, MIR_L3,   MIR_R3, MIR_R1        
  ),
  [MIRUNI] = LAYOUT_ergodox_base_wrapper(
    ________________BLANK_____________________,  ___,      ___, ________________BLANK_____________________,                       
    ________________MRU_L1____________________,  XXX,      ___, ________________MRU_R1____________________,               
    ________________MRU_L2____________________,                 ________________MRU_R2____________________,  
    ________________MRU_L3____________________,  ___,      ___, ________________MRU_R3____________________,
    ___, ___,     _____MRU_BOTTOM_L1_________,                    _____MRU_BOTTOM_R1_________, ___, ___,       
                                             ___, ___,  ___, ___,
                                                MRU_L2,  MRU_R2,
                                        MRU_L1, MRU_L3,   MRU_R3, MRU_R1   
  ),
  [MIRSYM] = LAYOUT_ergodox_base_wrapper(
    ________________BLANK_____________________,  ___,      ___, ________________BLANK_____________________,                       
    ________________MRS_L1____________________,  XXX,      ___, ________________MRS_R1____________________,               
    ________________MRS_L2____________________,                 ________________MRS_R2____________________,  
    ________________MRS_L3____________________,  ___,      ___, ________________MRS_R3____________________,
    ___, ___,     _____MRS_BOTTOM_L1_________,                    _____MRS_BOTTOM_R1_________, ___, ___,       
                                             ___, ___,  ___, ___,
                                                MRS_L2,  MRS_R2,
                                        MRS_L1, MRS_L3,   MRS_R3, MRS_R1                                                                                       
  ),
  [SPANISH] = LAYOUT_ergodox_base_wrapper(
    ________________BLANK_____________________,  ___,       ___, ________________BLANK_____________________,                       
    ________________SPANSH_L1_________________,  XXX,       ___, ________________SPANSH_R1_________________,                 
    ________________SPANSH_L2_________________,                  ________________SPANSH_R2_________________,     
    ________________SPANSH_L3_________________,  ES_IEXL,   ___, ________________SPANSH_R3_________________,    
    ___, ___,     _____SPA_BOTTOM_L1_________,                     _____SPA_BOTTOM_R1_________, ___, ___,       
                                             ___, ___,  ___, ___,
                                                SPA_L2,  SPA_R2,
                                        SPA_L1, SPA_L3,   SPA_R3, SPA_R1                                                                                       
  ),
  [SYMBOL] = LAYOUT_ergodox_base_wrapper(
    ________________BLANK_____________________,  ___,       ___, ________________BLANK_____________________,                       
    ________________SYM_L1_________________,  XXX,       ___, ________________SYM_R1_________________,                 
    ________________SYM_L2_________________,                  ________________SYM_R2_________________,     
    ________________SYM_L3_________________,  ___,       ___, ________________SYM_R3_________________,    
    ___, ___,     _____SYM_BOTTOM_L1_________,                     _____SYM_BOTTOM_R1_________, ___, ___,       
                                             ___, ___,  ___, ___,
                                                SYM_L2,  SYM_R2,
                                        SYM_L1, SYM_L3,   SYM_R3, SYM_R1                                                                                       
  ),
};

void flash(uint16_t time, uint8_t leds);
void run(uint16_t speed);

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
	if (current_layer == COLEMAK) {
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
  if ((current_layer == COLEMAK) && (get_current_wpm() <= 40)) {
      led_2_off();
      led_3_off();
  }
  if (current_layer == GAME) {
		run(512);
		return;
	}
	if (((current_layer == MIRRORED)) && (timer_elapsed(change_time) > 500)) {
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

 }



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  HANDLE_KEY_PRESS
}
