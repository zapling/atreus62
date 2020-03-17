#include QMK_KEYBOARD_H

#define _DEFAULT 0
#define _NAV 1
#define _RESET 2

enum custom_keycaps {
  BACKTIC
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BACKTIC:
      if (record->event.pressed) {
        SEND_STRING("`");
      }
      break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT(
    KC_GESC,  KC_1,   KC_2,     KC_3,   KC_4,     KC_5,                       KC_6,    KC_7,     KC_8,     KC_9,     KC_0,     KC_EQL,
    KC_LBRC,  KC_Q,   KC_W,     KC_E,   KC_R,     KC_T,                       KC_Y,    KC_U,     KC_I,     KC_O,     KC_P,     KC_RBRC,
    KC_TAB,   KC_A,   KC_S,     KC_D,   KC_F,     KC_G,                       KC_H,    KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,     KC_C,   KC_V,     KC_B,                       KC_N,    KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
    KC_LCTL,  KC_NO,  KC_LALT,  MO(1),  KC_LGUI,  KC_BSPC,  KC_DEL,  KC_ENT,  KC_SPC,  KC_RGUI,  KC_MINS,  KC_BSLS,  KC_NO,    KC_RCTL
  ),

  [_NAV] = LAYOUT(
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                        KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_HOME,  KC_PGUP,  KC_UP,    KC_PGDN,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_END,   KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_TRNS,  BACKTIC,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  TO(2),    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [_RESET] = LAYOUT(
    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),
    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),
    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),
    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),
    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  RESET,  RESET,  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0)
  )
};