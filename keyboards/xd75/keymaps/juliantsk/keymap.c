/* Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Layer shorthand
#define _CO 0
#define _SS 1
#define _FN 2

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | Q      | W      | F      | P      | G      | CAP LK | P7     | P8     | P9     | PAUSE  | J      | L      | U      | Y      | ;      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | A      | R      | S      | T      | D      | PRINT  | P4     | P5     | P6     | SCROLL | H      | N      | E      | I      | O      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | Z      | X      | C      | V      | B      | ENTER  | P1     | P2     | P3     | HOME   | K      | M      | ,      | .      | /      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LCTRL  | SUPER  | LALT   | =      | VOLUP  | DELETE | PN     | P0     | P.     | END    | VOLDN  | PGUP   | RALT   | UP     | RCTRL  |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | P*     | COPY   | FN     | -      | SPACE  | SHIFT  | SS     | ESC    | SS     | SHIFT  | SPACE  | PGDN   | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_CO] = LAYOUT_ortho_5x15( /* COLEMAK */
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_CAPS, KC_P7,   KC_P8,   KC_P9,   KC_MPLY, KC_J,     KC_L,      KC_U,    KC_Y,    KC_SCLN,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_PSCR, KC_P4,   KC_P5,   KC_P6,   KC_SLCK, KC_H,     KC_N,      KC_E,    KC_I,    KC_O,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,  KC_P1,   KC_P2,   KC_P3,   KC_HOME, KC_K,     KC_M,      KC_COMM, KC_DOT,  KC_SLSH,
    KC_LCTL, KC_LGUI, KC_LALT, KC_EQL,  KC_VOLU, KC_DEL,  KC_NO,   KC_P0,   KC_PDOT, KC_END,  KC_VOLD,  KC_PGUP,   KC_RALT, KC_UP,   KC_RCTRL,
    KC_PAST, KC_COPY, MO(_FN), KC_MINS, KC_SPC,  KC_LSFT, MO(_SS), KC_GESC, MO(_SS), KC_RSFT, KC_SPC,   KC_PGDOWN, KC_LEFT, KC_DOWN, KC_RIGHT
  ),

/* SECONDARY & SYMBOL
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | 1      | 2      | 3      | 4      | 5      | NUM LK |        |        |        |        | 6      | 7      | 8      | 9      | 0      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | ~      |        |        | (      | {      |        |        |        |        |        | }      | )      | [      | ]      | \      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        | SS     |        | SS     |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_SS] = LAYOUT_ortho_5x15( /* SECONDARY & SYMBOL */
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NLCK, _______, _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_TILD, _______, _______, KC_LPRN, KC_LCBR, _______, _______, _______, _______, _______, KC_RCBR, KC_RPRN, KC_LBRC, KC_RBRC, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, MO(_SS), _______, MO(_SS), _______, _______, _______, _______, _______, _______,
  ),

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F9     | F10    | F11    | F12    |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | F5     | F6     | F7     | F8     |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | F1     | F2     | F3     | F4     |        |        |        |        |        |        |        | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, _______, _______, RESET,   _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, MO(_FN), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
