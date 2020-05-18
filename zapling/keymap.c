#include QMK_KEYBOARD_H

// Layers
#define _DEFAULT 0
#define _NAV 1
#define _RESET 2

// Custom bindable keys
enum custom_keys {
  KC_A_DIACRITIC = SAFE_RANGE,
  KC_A_DIAERESIS,
  KC_O_DIAERESIS,
  KEY_EUR
};

// Custom unicode characters
const char LOWER_A_DIACRITIC[] = "0x00e5"; // å
const char UPPER_A_DIACRITIC[] = "0x00c5"; // Å

const char LOWER_A_DIAERESIS[] = "0x00e4"; // ä
const char UPPER_A_DIAERESIS[] = "0x00c4"; // Ä

const char LOWER_O_DIAERESIS[] = "0x00f6"; // ö
const char UPPER_O_DIAERESIS[] = "0x00d6"; // Ö

const char EURO_SIGN[] = "0x20ac"; // €

/**
* Return true if the shift modifier pressed
*/
bool is_shift_pressed(void) {
  if (keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT)) {
    return true;
  }
  return false;
}

/**
* Print a custom unicode character
* Uses the linux unicode input mode in order to convert the unicode to a real character.
* This might not always work, depending on the application.
*
* Uses the function 'send_string' in lowercase that allows for a char param.
*/
void print_unicode_char(const char* chars) {
  SEND_STRING(
    SS_DOWN(X_LCTL)
    SS_DOWN(X_LSFT)
    "u"
    SS_UP(X_LCTL)
    SS_UP(X_LSFT)
  );
  send_string(chars);
  SEND_STRING(SS_TAP(X_ENT));
}

/**
* Process the key press and handle the logic for custom keys.
*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_A_DIACRITIC: // å key
      if (record->event.pressed) {
        is_shift_pressed() ? print_unicode_char(UPPER_A_DIACRITIC) : print_unicode_char(LOWER_A_DIACRITIC);
      }
      break;

    case KC_A_DIAERESIS: // ä key
      if (record->event.pressed) {
        is_shift_pressed() ? print_unicode_char(UPPER_A_DIAERESIS) : print_unicode_char(LOWER_A_DIAERESIS);
      }
      break;

    case KC_O_DIAERESIS: // ö key
      if (record->event.pressed) {
        is_shift_pressed() ? print_unicode_char(UPPER_O_DIAERESIS) : print_unicode_char(LOWER_O_DIAERESIS);
      }
      break;

    case KEY_EUR: // €
      if (record->event.pressed) {
        print_unicode_char(EURO_SIGN);
      }
  }
  return true;
};

/**
* Custom keyboard layout
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT(
    KC_GESC,  KC_1,   KC_2,     KC_3,   KC_4,     KC_5,                       KC_6,    KC_7,     KC_8,     KC_9,     KC_0,     KC_EQL,
    KC_LBRC,  KC_Q,   KC_W,     KC_E,   KC_R,     KC_T,                       KC_Y,    KC_U,     KC_I,     KC_O,     KC_P,     KC_RBRC,
    KC_TAB,   KC_A,   KC_S,     KC_D,   KC_F,     KC_G,                       KC_H,    KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,     KC_C,   KC_V,     KC_B,                       KC_N,    KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
    KC_LCTL,  KC_NO,  KC_LALT,  MO(1),  KC_LGUI,  KC_BSPC,  KC_DEL,  KC_ENT,  KC_SPC,  KC_RGUI,  KC_MINS,  KC_BSLS,  KC_GRV,   KC_RCTL
  ),

  [_NAV] = LAYOUT(
    KC_F1,            KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                        KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,           KC_F12,
    KC_A_DIACRITIC,   KC_TRNS,  KC_TRNS,  KEY_EUR,  KC_TRNS,  KC_TRNS,                      KC_HOME,  KC_PGUP,  KC_UP,    KC_PGDN,  KC_TRNS,          KC_TRNS,
    KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_END,   KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_O_DIAERESIS,   KC_A_DIAERESIS,
    KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,          KC_TRNS,
    KC_TRNS,          TO(2),    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,          KC_TRNS
  ),

  [_RESET] = LAYOUT(
    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),
    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),
    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),
    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),
    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  RESET,  RESET,  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0)
  )
};