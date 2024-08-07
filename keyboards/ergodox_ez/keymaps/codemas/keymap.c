
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
#define MIRSYM 10
#define MIRUNI 11


enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  SC_FEM,
  SC_OPEN1QUOTE,
  SC_CLOSE1QUOTE,
  SC_MASC,
  SC_SEMICLNENTER,
  SC_EQUALS,
  SC_ENDTAG,
  SC_OPENQUOTE,
  SC_OPENCLOSEPAREN,
  SC_NOTEQUAL,
  SC_ENDSECTION,
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


// A 'transparent' key code (that falls back to the layers below it).
#define ___ KC_TRANSPARENT

// A 'blocking' key code. Does nothing but prevent falling back to another layer.
#define XXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
         XXX,         XXX,             XXX,             XXX,            XXX,               XXX,       XXX,  
    OSL(UNICODE),     KC_Q,            KC_W,            KC_F,            KC_P,             KC_G,      XXX,  
    OSL(SYM),       LT(NUMPAD,KC_A),  LALT_T(KC_R),   LCTL_T(KC_S),  LSFT_T(KC_T),   LT(NAV,KC_D), 
    SC_SUPERSHIFT, LT(SYMPLUS,KC_Z),  MEH_T(KC_X),            KC_C,       KC_V,             KC_B,     XXX,  
      XXX,            XXX,          KC_DELETE,      KC_ESCAPE,          KC_SPACE,                       
 // left thumb --------------------------------------------------------------------------------------------------
                                                                                                   XXX,     XXX,    
                                                                                                         KC_TAB,        
                                                           LT(MIRRORED,KC_BSPACE),LT(FN,KC_ENTER), LSFT(KC_TAB),   
  // right hand --------------------------------------------------------------------------------------------------
   XXX,         XXX,         XXX,                  XXX,           XXX,            XXX,                     XXX,
   XXX,        KC_J,        KC_L,                  KC_U,          KC_Y,          KC_QUOTE,              OSL(UNICODE),
              SCMD_T(KC_H), KC_N,                  KC_E,          KC_I,            KC_O,                   OSL(SYM),
      XXX,        KC_K,        KC_M,              KC_COMMA,  MEH_T(KC_DOT),  LT(SYMPLUS,KC_SLASH),   SC_SUPERSHIFT,
                              OSM(MOD_LCTL),       KC_LGUI,       TO(NUMPAD),      XXX,                     XXX,
  // right thumb --------------------------------d-----------------------------------------------------------------
  XXX,     XXX,
  KC_F23,
  KC_F24,        KC_QUES,       KC_SPACE
  ),
  [TYPING] = LAYOUT_ergodox_pretty(
    ___, ___,  ___,  ___,  ___,  XXX, XXX,                 XXX, XXX,  ___,  ___,  ___,  ___,       ___,
    ___, ___,  ___,  ___,  ___,  ___, XXX,                 ___, ___,  ___,  ___,  ___,  ___,       ___,
    ___, ___,  KC_R, KC_S, KC_T, ___,                           ___,  ___, KC_E,  ___,  ___,       ___,
    ___, ___,  KC_X, ___,  ___,  ___,  ___,                ___, ___,  ___,  ___,  KC_DOT,  ___,       ___,
    ___, ___,  ___,  ___,  ___,                                       XXX,  XXX,  XXX,     XXX,   ___,
                                             ___, ___,                 ___, ___,
                                                  ___,                 ___,
                             KC_BSPACE, KC_ENTER, ___,                 ___, ___, ___
  ), 
  [NUMPAD] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
    ___, ___,     ___,  ___,  ___,    ___,     ___,                              
    ___, ___,     ___,  ___,  ___,    ___,     XXX,                    
    ___, ___,   SC_AR, SC_AS, ___,   MO(NAV),              
    ___, ___,     ___,  ___,  ___,    ___,     ___,     
    ___, ___,     XXX,  ___,  ___,          
 // left thumb --------------------------------------------------------------------------------------------------
                                                                    XXX,        ___,   
                                                                          LCTL(KC_Z), 
                                                           ___, TG(GAME), LCTL(KC_Y),
  // right hand --------------------------------------------------------------------------------------------------
                              ___,     XXX,           XXX,       XXX,        XXX,           XXX,       XXX,
                              ___,     XXX,         KC_KP_7,     KC_KP_8,    KC_KP_9,       KC_COLN,     KC_KP_MINUS,
                                 OSM(MOD_LALT),     KC_KP_4,     KC_KP_5,    KC_KP_6,   KC_KP_ASTERISK,  KC_KP_PLUS,
                              ___,     XXX,       KC_KP_1,     KC_KP_2,    KC_KP_3,   KC_KP_SLASH,    KC_ENTER,
                                                     KC_X,    KC_KP_COMMA,  KC_KP_DOT,         ___,         XXX,
  // right thumb -------------------------------------------------------------------------------------------------
                           ___,   ___,
              KC_NUMLOCK,
              TO(BASE),   KC_ESCAPE,  KC_KP_0
  ),
  [NAV] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
    ___, ___,  ___,    ___,      ___,     ___, ___, 
    ___, ___,  ___,    ___,      ___,     ___, ___, 
    ___, ___,  ___,  KC_LCTRL, KC_LSHIFT, ___,                  
    ___, ___,  ___,    ___,      ___,     ___, ___,    
    ___, ___,  XXX,    ___,      ___,        
 // left thumb --------------------------------------------------------------------------------------------------
                         XXX, ___, 
                                        ___,
     KC_MS_BTN2,  KC_MS_BTN1,           ___, 
// right hand --------------------------------------------------------------------------------------------------
                                ___,       ___,            ___,         ___,         ___,        ___,            ___,
                                ___,  LCTL(KC_HOME),  OSM(MOD_LCTL),   KC_UP,      KC_PGUP,      XXX,        KC_MS_WH_UP,
                                      LCTL(KC_LEFT),     KC_LEFT,     KC_DOWN,    KC_RIGHT,  LCTL(KC_RIGHT), KC_MS_WH_DOWN,
                                ___,    DELWORD,        KC_DELETE,      XXX,      KC_PGDOWN,  LCTL(KC_END),  OSM(MOD_LSFT),
                                                           XXX,         XXX,         XXX,        ___,           TO(BASE),
  // right thumb -------------------------------------------------------------------------------------------------
                        ___,      ___,
                  KC_SCROLLLOCK,
                    TO(BASE),   KC_HOME,  KC_END
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
                                 ___, ___,  ___,      KC_UP,    ___,     ___,  TO(BASE),
                                      ___, KC_LEFT,  KC_DOWN, KC_RIGHT,  ___,   ___,
                                 ___, ___,  ___,      ___,      ___,     ___,   ___,
                                            ___,      ___,      ___,     ___,   ___,
// right thumb -------------------------------------------------------------------------------------------------
                          ___, XXX,
                          ___,
                        TO(BASE),  ___,   ___
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
                                                                   LCTL(KC_BSPACE),LCTL(KC_DELETE), ___,
// right hand --------------------------------------------------------------------------------------------------
                                 ___,         ___,         ___,          ___,              ___,           ___,             ___,
                                 ___,      KC_TILD,      KC_SLASH,      KC_MINUS,         KC_PIPE,      SC_CLOSE1QUOTE,   SC_MASC,
                                          SC_SEMICLNENTER,   SC_EQUALS,  KC_RPRN,        KC_RBRACKET,     KC_RCBR,         ___,
                                 ___,      KC_CIRC,        ___,         KC_SCOLON,        KC_COLN,     KC_BSLASH,          ___,
                                                           ___,           ___,              ___,           ___,          TO(BASE),
// right thumb -------------------------------------------------------------------------------------------------
               ___, ___,
               ___,
               ___, SC_SUPERQUES, SC_SUPERDOT
  ),
  [SYMPLUS] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
    ___,    ___,            ___,              ___,             ___,         ___,     ___, 
    ___, SC_OPENQUOTE,      ___,              ___,            ___,       SC_ARROW,  ___, 
    ___, SC_SECTION,  OPENCLOSEBRACKETS, SC_OPENCLOSEPAREN,  SC_NOTEQUAL,   ___, 
    ___, ___,     ___,              ___,             ___,         ___,     ___,  
    ___,    ___,            ___,              ___,             ___,   
 // left thumb --------------------------------------------------------------------------------------------------
                                                                              ___, ___,
                                                                                   ___,
                                                                         ___, ___, ___,
// right hand --------------------------------------------------------------------------------------------------
                                 ___, ___,    ___,           ___,         ___,          ___,       ___,
                                 ___, ___,  SC_ENDTAG,  SC_EMDASH,        ___,  SC_CLOSEQUOTE,   ___,
                                      ___, SC_EXACTLYEQUAL,  SC_PARENSEMICOLON, SC_SELECTLINE,  SC_SURROUNDBRKT,   ___,
                                 ___, ___,    ___,       SC_LESSOREQUAL,  SC_GREATOREQUAL,   DEL_LINE,    ___,
                                              ___,           ___,         ___,          ___,      ___,
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
                                 ___, ___,    ___,           ___,         ___,          ___,        ___,
                                 ___, ___,  SC_ENDTAG,  SC_EMDASH,  ___,  SC_CLOSEQUOTE,   ___,
                                      ___, SC_EXACTLYEQUAL,  SC_PARENSEMICOLON,     ___,       SC_SURROUNDBRKT,   ___,
                                 ___, ___,    ___,       SC_LESSOREQUAL,  SC_GREATOREQUAL,  DEL_LINE,   ___,
                                              ___,           ___,         ___,          ___,      TO(BASE),
  // right thumb -------------------------------------------------------------------------------------------------
  ___,     ___,
  ___,
  ___,     ___,     ___
  ),
  [MIRUNI] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
    TO(BASE),     ___,      ___,  ___,    ___,        ___,  ___, 
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
         TO(BASE),                KC_1,          KC_2,          KC_3,           KC_4,           KC_5,        ___,                                
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
uint32_t layer_state_set_user(uint32_t state);
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
  if (((get_oneshot_mods() & MOD_BIT(KC_LSHIFT)) == MOD_BIT(KC_LSHIFT)) || 
  ((get_oneshot_locked_mods() & MOD_BIT(KC_LSHIFT)) == MOD_BIT(KC_LSHIFT)) ||
  ((get_mods() & MOD_BIT(KC_LSHIFT)) == MOD_BIT(KC_LSHIFT)))
  {
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
      shift_time = 0;
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


bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    if ((keycode == LCTL_T(KC_CAPSLOCK)) || (keycode == LCTL_T(KC_S)) || (keycode == LSFT_T(KC_T))
    || (keycode == OSL(SYM)) || (keycode == OSL(UNICODE)) || (keycode == MEH_T(KC_SPACE))
    || (keycode == MEH_T(KC_X)) || (keycode == MEH_T(KC_DOT))) {
        return false;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    if (keycode == LT(NUMPAD,KC_A)) {
      return 170;
    }
     if ((current_layer == TYPING) ||
       (keycode == OSM(MOD_LSFT)) 
     ) {
      return 300;
    }
    if ((keycode == LALT_T(KC_R)) || 
        (keycode == MEH_T(KC_SPACE)) || 
        (keycode == LSFT_T(KC_T)) ||
        (keycode == MEH_T(KC_X)) || 
        (keycode == LCTL_T(KC_S))
    ) {
      return 150;
    }
    return TAPPING_TERM;
}

void oneshot_mods_changed_user(uint8_t mods) {
 if (!(mods & MOD_MASK_SHIFT)) {
   shift_count = 0;
 }
}

void handle_supershift() {
  if (caps_lock_on()) {
    tap_code(KC_CAPSLOCK);
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  pressed_time = timer_read();
  if (record->event.pressed && (shift_time != 0)) {
      if (!caps_lock_on() && (timer_elapsed(shift_time) < 1000)) {
        set_oneshot_mods(MOD_BIT(KC_LSHIFT));
      }
      shift_time = 0;
    }
  switch (keycode) {
    case SC_SHIFT:
      if (record->event.pressed) {
        set_oneshot_mods(MOD_BIT(KC_LSHIFT));
        reset_oneshot_layer();
        layer_on(UNICODE);
      }
      return true;
    break;
      case KC_COLN:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT("."));
      }
      return false;
    break;
    case KC_DOT:
      if (record->event.pressed) {
        if (shift_pressed()) {
          SEND_STRING(SS_LALT(SS_TAP(X_KP_6) SS_TAP(X_KP_2)));
        }
        else
        {
          SEND_STRING(".");
        }
      }
      return false;
    break;
  }
  if (record->event.pressed) {
    layer_off(UNICODE);
    layer_off(MIRUNI);
  }
  return true;
}
