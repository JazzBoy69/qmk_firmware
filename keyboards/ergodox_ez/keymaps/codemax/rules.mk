# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
LTO_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
RGBLIGHT_ENABLE = no
WPM_ENABLE = no
KEY_LOCK_ENABLE = no
EXTRAFLAGS += -flto
COMBO_ENABLE = yes