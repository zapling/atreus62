#include QMK_KEYBOARD_H

#define _DEFAULT 0
#define _NAV 1
#define _RESET 2

enum custom_keys {
  AR,
  AD,
  OD,
  U_AR,
  U_AD,
  U_OD,
};

const uint32_t PROGMEM unicode_map[] = {
  [AR]   = 0x00E5, // å
  [U_AR] = 0x00C5, // Å

  [AD]   = 0x00E4, // ä
  [U_AD] = 0x00C4, // Ä

  [OD]   = 0x00F6, // ö
  [U_OD] = 0x00D6, // Ö
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT(
    KC_GESC,  KC_1,   KC_2,     KC_3,   KC_4,     KC_5,                       KC_6,    KC_7,     KC_8,     KC_9,     KC_0,     KC_EQL,
    KC_LBRC,  KC_Q,   KC_W,     KC_E,   KC_R,     KC_T,                       KC_Y,    KC_U,     KC_I,     KC_O,     KC_P,     KC_RBRC,
    KC_TAB,   KC_A,   KC_S,     KC_D,   KC_F,     KC_G,                       KC_H,    KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,     KC_C,   KC_V,     KC_B,                       KC_N,    KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
    KC_LCTL,  KC_NO,  KC_LALT,  MO(1),  KC_LGUI,  KC_BSPC,  KC_DEL,  KC_ENT,  KC_SPC,  KC_RGUI,  KC_MINS,  KC_BSLS,  KC_GRV,   KC_RCTL
  ),

  [_NAV] = LAYOUT(
    KC_F1,         KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                        KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,        KC_F12,
    XP(AR, U_AR),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_HOME,  KC_PGUP,  KC_UP,    KC_PGDN,  KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_END,   KC_LEFT,  KC_DOWN,  KC_RGHT,  XP(OD, U_OD),  XP(AD, U_AD),
    KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,
    KC_TRNS,       TO(2),    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS
  ),

  [_RESET] = LAYOUT(
    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),
    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),
    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),
    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),
    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  RESET,  RESET,  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0)
  )
};