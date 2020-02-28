#include QMK_KEYBOARD_H

#define _DEFAULT 0
#define _NAV 1
#define _RESET 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT(
    KC_GESC,  KC_1,   KC_2,    KC_3,    KC_4,     KC_5,                        KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS ,
    KC_LBRC,  KC_Q,   KC_W,    KC_E,    KC_R,     KC_T,                        KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_RBRC ,
    KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,     KC_G,                        KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT ,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,     KC_B,    /* Tumb   Tumb */   KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT ,
    KC_LCTL,  KC_NO,  KC_LALT, KC_GRV,  MO(_NAV), KC_BSPC, KC_DEL,   KC_ENT,   KC_SPC,  KC_NO,  KC_RGUI, KC_EQL,  KC_BSLS, KC_NO
  )
};
