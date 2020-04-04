#include QMK_KEYBOARD_H

#define _DEFAULT 0
#define _NAV 1
#define _RESET 2

const char L_AR[] = "0x00e5"; // å
const char U_AR[] = "0x00c5"; // Å

const char L_AD[] = "0x00e4"; // ä
const char U_AD[] = "0x00c4"; // Ä

const char L_OD[] = "0x00f6"; // ö
const char U_OD[] = "0x00d6"; // Ö

const char EURO_SIGN[] = "0x20ac"; // €

enum custom_keys {
  KEY_AR = SAFE_RANGE,
  KEY_AD,
  KEY_OD,
  KEY_EUR
};

bool shift_pressed(void) {
  if (keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT)) {
    return true;
  }
  return false;
}

void send_unicode_char(const char* chars) {
  SEND_STRING(
    SS_DOWN(X_LCTL)
    SS_DOWN(X_LSFT)
    "u"
    SS_UP(X_LCTL)
    SS_UP(X_LSFT)
  );
  send_string(chars); // lowercase in order to send 'char' as param
  SEND_STRING(SS_TAP(X_ENT));
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KEY_AR: // å key
      if (record->event.pressed) {
        shift_pressed() ? send_unicode_char(U_AR) : send_unicode_char(L_AR);
      }
      break;

    case KEY_AD: // ä key
      if (record->event.pressed) {
        shift_pressed() ? send_unicode_char(U_AD) : send_unicode_char(L_AD);
      }
      break;

    case KEY_OD: // ö key
      if (record->event.pressed) {
        shift_pressed() ? send_unicode_char(U_OD) : send_unicode_char(L_OD);
      }
      break;

    case KEY_EUR: // €
      if (record->event.pressed) {
        send_unicode_char(EURO_SIGN);
      }
  }
  return true;
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
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                        KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
    KEY_AR,   KC_TRNS,  KC_TRNS,  KEY_EUR,  KC_TRNS,  KC_TRNS,                      KC_HOME,  KC_PGUP,  KC_UP,    KC_PGDN,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_END,   KC_LEFT,  KC_DOWN,  KC_RGHT,  KEY_OD,   KEY_AD,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  TO(2),    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [_RESET] = LAYOUT(
    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),
    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),
    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),
    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),
    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  RESET,  RESET,  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0)
  )
};