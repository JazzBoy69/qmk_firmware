
#include QMK_KEYBOARD_H
#include "version.h"
#include <stdlib.h>

// The layers for this keyboard.
#define BASE 0
#define TYPING 1
#define NUMPAD 2
#define NAV 3
#define GAME 4
#define FN 5
#define SYM 6
#define SYMPLUS 7
#define UNICODE 8
#define MIRRORED 9


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

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
  ST_MACRO_13,
  ST_MACRO_14,
  ST_MACRO_15,
  SC_EMDASH,
  ST_MACRO_17,
  ST_MACRO_18,
  ST_MACRO_19,
  ST_MACRO_20,
  ST_MACRO_21,
  ST_MACRO_22,
  ST_MACRO_23,
  ST_MACRO_24,
  SC_A,
  SC_SEC,
  SC_INVBANG,
  SC_PAR,
  SC_GU,
  SC_SHIFT,
  SC_DOT,
  SC_COMMA,
  SC_QUES,
  SC_N,
  SC_E,
  SC_I,
  SC_O,
  SC_U,
  SC_Y,
};


// A 'transparent' key code (that falls back to the layers below it).
#define ___ KC_TRANSPARENT

// A 'blocking' key code. Does nothing but prevent falling back to another layer.
#define XXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
    KC_ESCAPE,          KC_F1,            KC_F2,           KC_F3,        KC_F4,           KC_F5,          TG(GAME),  
    OSL(UNICODE),       KC_Q,             KC_W,            KC_F,         KC_P,             KC_G,           XXX,  
    OSL(SYM),           LT(NUMPAD,KC_A),  LALT_T(KC_R),   LCTL_T(KC_S),  LSFT_T(KC_T),   LT(NAV,KC_D), 
    OSM(MOD_LSFT),      KC_Z,             KC_X,            KC_C,         KC_V,             KC_B,        OSM(MOD_MEH),  
    KC_DELETE,        KC_MS_BTN1,       KC_MS_BTN2,     KC_ESCAPE,     KC_SPACE,                       
 // left thumb --------------------------------------------------------------------------------------------------
                                                                            LCTL(KC_Z),     LCTL(KC_Y),    
                                                                                              KC_TAB,        
                                                           LT(MIRRORED,KC_BSPACE),LT(FN,KC_ENTER), LSFT(KC_TAB),   
  // right hand --------------------------------------------------------------------------------------------------
TG(NUMPAD),          KC_F6,       KC_F7,                 KC_F8,         KC_F9,          KC_F10,      KC_CAPSLOCK,
   XXX,              KC_J,        KC_L,              LCTL_T(KC_U),       KC_Y,          KC_QUOTE,     OSL(UNICODE),
                     KC_H,        KC_N,                  KC_E,          KC_I,            KC_O,        OSL(6),
OSM(MOD_MEH),        KC_K,        KC_M,                  KC_COMMA,      KC_DOT,         KC_QUES,      OSM(MOD_LSFT),
                                 KC_LGUI,                KC_F11,        KC_F12,      KC_APPLICATION,  ST_MACRO_1,
  // right thumb -------------------------------------------------------------------------------------------------
  KC_PSCREEN,     KC_HOME,
  KC_F23,
  KC_F24,      SCMD_T(KC_END),         LT(7,KC_SPACE)
  ),
  [TYPING] = LAYOUT_ergodox_pretty(
    ___, XXX,  XXX,  XXX,  XXX,  XXX, XXX,                 ___, XXX,  XXX,  XXX,  XXX,  XXX,       ___,
    ___, ___,  ___,  ___,  ___,  ___, XXX,                 ___, ___,  ___,  ___,  ___,  ___,       ___,
    ___, ___,  KC_R, KC_S, KC_T, ___,                           ___,  ___,  ___,  ___,  ___,      ___,
    ___, ___,  ___,  ___,  ___,  ___,  ___,                ___, ___,  ___,  ___,  ___,  ___,       ___,
    ___, ___,  ___,  ___,  ___,                                 XXX,  XXX,  XXX,  XXX,  TO(BASE),
                                             ___, ___,                 ___, ___,
                                                  ___,                 ___,
                                        ___, ___, ___,                 ___, ___, ___
  ), 
  [NUMPAD] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
    ___, ___,     ___,  ___, ___,    ___,     ___,                              
    ___, ___,     ___,  ___, ___,    ___,     XXX,                    
    ___, ___, KC_LALT,  ___, ___,   MO(NAV),              
    ___, ___,     ___,  ___, ___,    ___,     ___,     
    ___, ___,     XXX,  ___, ___,          
 // left thumb --------------------------------------------------------------------------------------------------
                                                           XXX,  KC_NUMLOCK,   
                                                                        ___, 
                                                           ___,  ___,   ___,
  // right hand --------------------------------------------------------------------------------------------------
                              ___,     XXX,           XXX,       XXX,        XXX,           XXX,       KC_KP_ASTERISK,
                    KC_CALCULATOR,  LCTL(KC_V),    KC_KP_7,     KC_KP_8,    KC_KP_9,       KC_COLN,     KC_KP_MINUS,
                                       XXX,         KC_KP_4,    KC_KP_5,    KC_KP_6,        KC_X,         KC_KP_PLUS,
                       ST_MACRO_0,     XXX,        KC_KP_1,     KC_KP_2,    KC_KP_3,     KC_KP_SLASH,    KC_ENTER,
                                                   KC_SPACE,  KC_KP_COMMA,  KC_KP_DOT,      ___,          TO(BASE),
  // right thumb -------------------------------------------------------------------------------------------------
                         ___,   TG(NAV),
                                  ___,
                ___,     ___,  KC_KP_0
  ),
  [NAV] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
    ___, ___,  ___,    ___,      ___,     ___, ___, 
    ___, ___,  ___,    ___,      ___,     ___, ___, 
    ___, ___,  ___,  KC_LCTRL, KC_LSHIFT, ___,                  
    ___, ___,  ___,    ___,      ___,     ___, ___,    
    ___, ___,  XXX,    ___,      ___,        
 // left thumb --------------------------------------------------------------------------------------------------
                        XXX,    KC_SCROLLLOCK, 
                                          ___,
                        ___,     ___,     ___, 
// right hand --------------------------------------------------------------------------------------------------
                                ___,       ___,            ___,         ___,         ___,        ___,            ___,
                                ___,  LCTL(KC_HOME),  OSM(MOD_LCTL),   KC_UP,      KC_PGUP,      XXX,        KC_MS_WH_UP,
                                      LCTL(KC_LEFT),     KC_LEFT,     KC_DOWN,    KC_RIGHT,  LCTL(KC_RIGHT), KC_MS_WH_DOWN,
                                ___,       XXX,         KC_DELETE,      XXX,      KC_PGDOWN,  LCTL(KC_END),      ___,
                                                           XXX,         XXX,         XXX,        ___,           TO(BASE),
  // right thumb -------------------------------------------------------------------------------------------------
                        ___,   ___,
                        ___,
                        ___,   ___,   ___
  ),
  [GAME] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
    ___, ___,    ___,     ___,      ___,    ___, ___,             
    ___, ___,   KC_Q,    KC_UP,    KC_E,    ___, ___,               
    ___, ___, KC_LEFT,  KC_DOWN,  KC_RIGHT, ___,             
    ___, ___,    ___,     ___,      ___,    ___, ___,                          
    ___, ___,    XXX,     ___,      ___,                                                                                        
 // left thumb --------------------------------------------------------------------------------------------------
                                  XXX,          ___, 
                                                ___, 
                               KC_SPACE,   ___, ___, 
// right hand --------------------------------------------------------------------------------------------------
                                 ___, ___,  ___,   ___,    ___, ___,  KC_LOCK,
                                 ___, KC_Q, KC_W,  KC_E,  KC_R, KC_T, KC_Y,
                                      KC_A, KC_S,  KC_D,  KC_F, KC_G,  ___,
                                 ___, KC_Z, KC_X,  KC_C,  KC_V, KC_B,  ___,
                                           ___,        ___,     ___, ___, TO(BASE),
// right thumb -------------------------------------------------------------------------------------------------
                          ___, XXX,
                          ___,
                          ___,  ___,   ___
  ),
  [FN] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
    LALT(LCTL(KC_DELETE)),   ___,   ___,   ___,        ___,     ___,    ___, 
             ___,            ___,   ___,  SC_EMDASH,   ___,     ___,    ___, 
             ___,           KC_1,  KC_2,   KC_3,      KC_4,    KC_5,   
             ___,           KC_6,  KC_7,   KC_8,      KC_9,    KC_0,   ___,      
             ___,            ___,   ___,   ___,        ___,      
 // left thumb --------------------------------------------------------------------------------------------------
                           ___, ___,
                                ___,
                      ___, ___, ___,
// right hand --------------------------------------------------------------------------------------------------
                        ___,        ___, ___,  RESET,  ___, ___,  ___,
                        ___,        ___, ___,   ___,   ___, ___,  ___,
                                    ___, ___,   ___,   ___, ___,  ___,
                   KC_SYSTEM_SLEEP, ___, ___,   ___,   ___, ___,  ___,
                                         ___,   ___,   ___, ___, TO(BASE),
// right thumb -------------------------------------------------------------------------------------------------
               ___, ___,
               ___,
               ___, ___, ___ 
  ),
  [SYM] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
            ___,                KC_1,          KC_2,          KC_3,           KC_4,           KC_5,        ___,                                
          ST_MACRO_2,        ST_MACRO_3,      KC_AMPR,       KC_PLUS,        KC_ASTR,        KC_EQUAL,     LCTL(KC_X),     
            ___,              KC_LCBR,       KC_LBRACKET,    KC_LPRN,        KC_EXLM,        KC_UNDS,             
            ___,              KC_BSLASH,       KC_AT,        KC_HASH,        KC_DLR,         KC_PERC,      ___,     
            ___,                 ___,           ___,           ___,           ___,                                                                                            
 // left thumb --------------------------------------------------------------------------------------------------
                                                                                               ___, ___,
                                                                                                    ___,
                                                                   LCTL(KC_BSPACE),LCTL(KC_DELETE), ___,
// right hand --------------------------------------------------------------------------------------------------
                                 ___,        KC_6,        KC_7,          KC_8,             KC_9,          KC_0,          ___,
                                 ___,      KC_TILD,      KC_SLASH,      KC_MINUS,         KC_PIPE,      ST_MACRO_4,   ST_MACRO_5,
                                          ST_MACRO_6,   ST_MACRO_7,     KC_RPRN,        KC_RBRACKET,     KC_RCBR,        ___,
                                 ___,      KC_CIRC,        ___,         KC_SCOLON,        KC_COLN,     KC_BSLASH,      ___,
                                                           ___,           ___,              ___,           ___,          TO(BASE),
// right thumb -------------------------------------------------------------------------------------------------
               ___, ___,
               ___,
               ___, KC_HOME, ___ 
  ),
  [SYMPLUS] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
    ___,    ___,          ___,          ___,       LALT(KC_F4),  ___, ___, 
    ___, ST_MACRO_9,   ST_MACRO_10,  ST_MACRO_11,     ___,       ___, ___, 
    ___, ST_MACRO_12,     ___,       ST_MACRO_13,  ST_MACRO_14,  ___, 
    ___, ST_MACRO_15,     ___,          ___,       LCTL(KC_V),   ___, ___,  
    ___,    ___,          ___,          ___,          ___,   
 // left thumb --------------------------------------------------------------------------------------------------
                                                                              ___, ___,
                                                                                   ___,
                                                                         ___, ___, ___,
// right hand --------------------------------------------------------------------------------------------------
                                 ___, ___,    ___,           ___,         ___,          ___,        ___,
                                 ___, ___,  ST_MACRO_8,  SC_EMDASH,  ST_MACRO_17,  ST_MACRO_18,   ___,
                                      ___, ST_MACRO_19,  ST_MACRO_20,     ___,       ST_MACRO_24,   ___,
                                 ___, ___,    ___,       ST_MACRO_21,  ST_MACRO_22,  ST_MACRO_23,   ___,
                                              ___,           ___,         ___,          ___,      TO(BASE),
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
                                 ___, ___,    ___,  SC_COMMA, SC_DOT, SC_QUES, SC_SHIFT,
                                              ___,   ___,      ___,     ___,   ___,
// right thumb -------------------------------------------------------------------------------------------------
               ___, ___,
               ___,
               ___, ___, ___ 
  ),
[MIRRORED] = LAYOUT_ergodox(
// left hand ---------------------------------------------------------------------------------------------------
    ___,       ___,            ___,            ___,         ___,          ___,         ___,  
    ___,     KC_QUOTE,        KC_Y,           KC_U,         KC_L,         KC_J,        ___,  
    ___,      KC_O,           KC_I,           KC_E,         KC_N,         KC_H, 
    ___,    KC_QUES,          KC_DOT,        KC_COMMA,      KC_M,         KC_K,        ___,  
    ___,     ___,              ___,            ___,          ___,                       
 // left thumb --------------------------------------------------------------------------------------------------
                                                                         ___,        ___,    
                                                                                     ___,        
                                                                          ___,  ___, ___,   
  // right hand --------------------------------------------------------------------------------------------------
                                 ___, ___,    ___,           ___,         ___,          ___,        ___,
                                 ___, ___,  ST_MACRO_8,  SC_EMDASH,  ST_MACRO_17,  ST_MACRO_18,   ___,
                                      ___, ST_MACRO_19,  ST_MACRO_20,     ___,       ST_MACRO_24,   ___,
                                 ___, ___,    ___,       ST_MACRO_21,  ST_MACRO_22,  ST_MACRO_23,   ___,
                                              ___,           ___,         ___,          ___,      TO(BASE),
  // right thumb -------------------------------------------------------------------------------------------------
  ___,     ___,
  ___,
  ___,     ___,     ___
  ),
};
uint32_t layer_state_set_user(uint32_t state);
uint8_t caps_lock_on(void);
uint8_t shift_pressed(void);
void flash(uint16_t time, uint8_t leds);
void run(uint16_t speed);
uint8_t current_layer = 0;
uint16_t change_time = 0;
uint16_t pressed_time = 0;

// The state of the LEDs requested by the system, as a bitmask.
static uint8_t sys_led_state = 0;

// Use these masks to read the system LEDs state.
static const uint8_t sys_led_mask_num_lock = 1 << USB_LED_NUM_LOCK;
static const uint8_t sys_led_mask_caps_lock = 1 << USB_LED_CAPS_LOCK;
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

uint8_t caps_lock_on() {
  if (sys_led_state & sys_led_mask_caps_lock) {
    return 1;
  }
  return 0;
}

uint8_t shift_pressed() {
  if ((get_oneshot_mods() & MOD_BIT(KC_LSHIFT)) == MOD_BIT(KC_LSHIFT)) {
    return 1;
  }
  return 0;
}

void set_indicator(void) {
	if (current_layer > NAV) {
		return;
	}
	led_1_off();
	if ((current_layer == BASE) || (current_layer == TYPING)) {
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
  if (current_layer == BASE) {
    if (get_current_wpm()>40) {
      layer_on(TYPING);
    }
    return;
  }
  if (current_layer == TYPING) {
    if ((get_current_wpm()<=40) || (timer_elapsed(pressed_time) > 1000)) {
      layer_off(TYPING);
      set_current_wpm(0);
    }
    return;
  }
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    if (keycode == LT(1,KC_A)) {
      return 190;
    }
     if ((keycode == LCTL_T(KC_U))  
        || (keycode == LT(7,KC_SPACE)) || (keycode == LT(7,KC_BSPACE))) {
      return 300;
    }
    if ((keycode == LALT_T(KC_R)) || (keycode == SCMD_T(KC_END))) {
      return 200;
    }
    return TAPPING_TERM;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  pressed_time = timer_read();
  switch (keycode) {
    case SC_SHIFT:
      if (record->event.pressed) {
        set_oneshot_mods(MOD_BIT(KC_LSHIFT));
        reset_oneshot_layer();
        layer_on(UNICODE);
      }
      return true;
    break;    
    case SC_A:
      if (record->event.pressed) {
        SEND_UNICODE(CAP_ACCENTA, ACCENTA);
        layer_off(UNICODE);
      }
      return false;
    break;
    case SC_E:
      if (record->event.pressed) {
        SEND_UNICODE(CAP_ACCENTE, ACCENTE);
        layer_off(UNICODE);
      }
      return false;
    break;
    case SC_I:
      if (record->event.pressed) {
        SEND_UNICODE(CAP_ACCENTI, ACCENTI);
        layer_off(UNICODE);
      }
      return false;
    break;
    case SC_O:
      if (record->event.pressed) {
        SEND_UNICODE(CAP_ACCENTO, ACCENTO);
        layer_off(UNICODE);
      }
      return false;
    break;
    case SC_U:
      if (record->event.pressed) {
        SEND_UNICODE(CAP_ACCENTU, ACCENTU);
        layer_off(UNICODE);
      }
      return false;
    break;
    case SC_Y:
      if (record->event.pressed) {
        SEND_UNICODE(CAP_ACCENTY, ACCENTY);
        layer_off(UNICODE);
      }
      return false;
    break;
    case SC_GU:
      if (record->event.pressed) {
        SEND_UNICODE(CAP_ACCENTGU, ACCENTGU);
        layer_off(UNICODE);
      }
      return false;
    break;
    case SC_N:
      if (record->event.pressed) {
        SEND_UNICODE(CAP_ENE, ENE);
        layer_off(UNICODE);
      }
      return false;
    break;
    case SC_SEC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_7) ));
        layer_off(UNICODE);
      }
      return false;
    break;
    case SC_QUES:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_1) ));
        layer_off(UNICODE);
      }
      return false;
    break;
    case SC_PAR:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_2) ));
        layer_off(UNICODE);
      }
      return false;
    break;
    case SC_INVBANG:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_1) ));
        layer_off(UNICODE);
      }
      return false;
    break;
    case SC_COMMA:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_0) ));
        layer_off(UNICODE);
      }
      return false;
    break;
    case SC_DOT:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_3) ));
        layer_off(UNICODE);
      }
      return false;
    break;
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_C)) SS_DELAY(50) SS_LALT(SS_TAP(X_F4)));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_SPACE)) SS_DELAY(50) SS_TAP(X_N));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_6) ));

    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_5) ));

    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_6) ));

    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_7) ));

    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_END) SS_DELAY(50) SS_TAP(X_SCOLON) SS_DELAY(50) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_EQUAL) SS_DELAY(50) SS_TAP(X_EQUAL));

    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_COMMA)) SS_DELAY(50) SS_TAP(X_SLASH));

    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_7) ));

    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_7)) SS_DELAY(50) SS_LSFT(SS_TAP(X_7)));

    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_EQUAL)) SS_DELAY(50) SS_LSFT(SS_TAP(X_EQUAL)) SS_DELAY(50) SS_TAP(X_SCOLON) SS_DELAY(50) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_END) SS_DELAY(50) SS_TAP(X_SPACE) SS_DELAY(50) SS_LSFT(SS_TAP(X_LBRACKET)) SS_DELAY(50) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_9)) SS_DELAY(50) SS_LSFT(SS_TAP(X_0)));

    }
    break;
    case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_1)) SS_DELAY(50) SS_TAP(X_EQUAL));

    }
    break;
    case ST_MACRO_15:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ENTER) SS_DELAY(50) SS_LSFT(SS_TAP(X_RBRACKET)) SS_DELAY(50) SS_TAP(X_UP));

    }
    break;
    case SC_EMDASH:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_1) ));

    }
    break;
    case ST_MACRO_17:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_BSLASH)) SS_DELAY(50) SS_LSFT(SS_TAP(X_BSLASH)));

    }
    break;
    case ST_MACRO_18:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_8) ));

    }
    break;
    case ST_MACRO_19:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_EQUAL) SS_DELAY(50) SS_TAP(X_EQUAL) SS_DELAY(50) SS_TAP(X_EQUAL));

    }
    break;
    case ST_MACRO_20:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_9)) SS_DELAY(50) SS_LSFT(SS_TAP(X_0)) SS_DELAY(50) SS_TAP(X_SCOLON) SS_DELAY(50) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_21:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_COMMA)) SS_DELAY(50) SS_TAP(X_EQUAL));

    }
    break;
    case ST_MACRO_22:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_DOT)) SS_DELAY(50) SS_TAP(X_EQUAL));

    }
    break;
    case ST_MACRO_23:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_END) SS_DELAY(50) SS_LSFT(SS_TAP(X_HOME)) SS_DELAY(50) SS_TAP(X_DELETE) SS_DELAY(50) SS_TAP(X_DELETE));

    }
    break;
    case ST_MACRO_24:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_X)) SS_DELAY(50) SS_LSFT(SS_TAP(X_LBRACKET)) SS_DELAY(50) SS_LSFT(SS_TAP(X_RBRACKET)) SS_DELAY(50) SS_TAP(X_LEFT) SS_DELAY(50) SS_TAP(X_ENTER) SS_DELAY(50) SS_LCTL(SS_TAP(X_V)) SS_DELAY(50) SS_TAP(X_ENTER) SS_DELAY(50) SS_TAP(X_UP));

    }
    break;
  }
  if (record->event.pressed) {
    layer_off(UNICODE);
  }
  return true;
}
