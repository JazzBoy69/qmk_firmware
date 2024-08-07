/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY

#define RETRO_TAPPING
#define RETRO_TAPPING_PER_KEY

#define ONESHOT_TAP_TOGGLE 2

#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 2000

#define USB_SUSPEND_WAKEUP_DELAY 0

#define MOUSEKEY_WHEEL_MAX_SPEED 24
#define MOUSEKEY_WHEEL_INTERVAL 20
