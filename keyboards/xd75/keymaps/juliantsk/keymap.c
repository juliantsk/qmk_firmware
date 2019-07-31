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
#define _NL 2

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  //QUOTS
  CUPTY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | SELALL | COPY   | PSTE   | DEL    | F5     | F6     | P7     | P8     | P9     | /      | SUPER  | LEFT   | DOWN   | UP     | RIGHT  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | Q      | W      | F      | P      | G      | P.     | P4     | P5     | P6     | P0     | J      | L      | U      | Y      | ;      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | A      | R      | S      | T      | D      | PGUP   | P1     | P2     | P3     | ENTER  | H      | N      | E      | I      | O      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | Z      | X      | C      | V      | B      | PGDN   | PRINT  | PAUSE  | MINUS  | PLUS   | K      | M      | ,      | .      | /      |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | TAB    | CTRL   | SUPER  | BKSPC  | SHIFT  | SS     | ALT    | CTRL   | SHFT   | NL     | SPACE  | ESC    | HOME   | END    | ENTER  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_CO] = LAYOUT_ortho_5x15( /* COLEMAK */
    C(KC_A),TD(CUPTY),C(KC_V), KC_DEL,  KC_F5,    KC_F6,   KC_P7,   KC_P8,   KC_P9,   KC_PSLS, KC_LGUI, KC_LEFT,KC_DOWN, KC_UP,   KC_RIGHT,
    KC_Q,   KC_W,     KC_F,    KC_P,    KC_G,     KC_PDOT, KC_P4,   KC_P5,   KC_P6,   KC_P0,   KC_J,    KC_L,   KC_U,    KC_Y,    KC_SCLN,
    KC_A,   KC_R,     KC_S,    KC_T,    KC_D,     KC_PGUP, KC_P1,   KC_P2,   KC_P3,   KC_ENT,  KC_H,    KC_N,   KC_E,    KC_I,    KC_O,
    KC_Z,   KC_X,     KC_C,    KC_V,    KC_B,     KC_PGDN, KC_PSCR, KC_BRK,  KC_PMNS, KC_PPLS, KC_K,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH,
    KC_TAB, KC_LCTRL, KC_LGUI, KC_BSPC, KC_LSFT,  MO(_SS), KC_LALT, KC_RCTRL,KC_RSFT, MO(_NL), KC_SPC,  KC_GESC,KC_HOME, KC_END,  KC_ENT
  ),

/* SECONDARY & SYMBOL
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | `      | ~      |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | !      | @      | #      | $      | %      |        |        |        |        |        | ^      | &      | *      | (      | )      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | =      | _      | +      | -      | \      |        |        |        |        |        | {      | }      | [      | ]      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        | |      |        |        |        |        |        |        |        | <      | >      | "      |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        | SS     |        |        |        | SLEEP  |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_SS] = LAYOUT_ortho_5x15( /* SECONDARY & SYMBOL */
    KC_GRV, S(KC_GRV), _______, _______, _______,   _______, _______, _______, _______, _______, _______,   _______,   _______,   _______,  _______,
    S(KC_1),S(KC_2),   S(KC_3), S(KC_4), S(KC_5),   _______, _______, _______, _______, _______, S(KC_6),   S(KC_7),   S(KC_8),   S(KC_9),  S(KC_0),
    KC_EQL, S(KC_MINS),KC_PPLS, KC_PMNS, KC_BSLS,   _______, _______, _______, _______, _______, S(KC_LBRC),S(KC_RBRC),KC_LBRC,   KC_RBRC,  KC_QUOT,
    _______,_______,   _______, _______, S(KC_BSLS),_______, _______, _______, _______, _______, _______,   _______,   S(KC_COMM),S(KC_DOT),S(KC_QUOT),
    _______,_______,   _______, _______, _______,   _______, _______, KC_SLEP, _______, _______, _______,   _______,   _______,   _______,  _______
  ),

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | P1     | P2     | P3     | P4     | P5     |        |        |        |        |        | P6     | P7     | P8     | P9     | P0     |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        | LEFT   | DOWN   | UP     | RIGHT  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        | RESET  |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        | SLEEP  |        | NL     |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_NL] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______,
    KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,   _______, _______, _______, _______, _______, KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
    _______, _______, _______, _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_SLEP, _______, _______, _______, _______, _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // switch (keycode) {
  //   case DBLOH:
  //     if (record->event.pressed) {
  //       // when keycode QMKBEST is pressed
  //       SEND_STRING("00");
  //     } else {
  //       // when keycode QMKBEST is released
  //     }
  //     break;
  // }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

enum combos {
  IO_ENT,
  AR_TAB
};

const uint16_t PROGMEM io_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM ar_combo[] = {KC_Z, KC_X, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [IO_ENT] = COMBO(io_combo, KC_ENT),
  [AR_TAB] = COMBO(ar_combo, KC_TAB)
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //[QUOTS]  = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, LSFT(KC_QUOT))
  [CUPTY]  = ACTION_TAP_DANCE_DOUBLE(C(KC_C), C(KC_X))
// Other declarations would go here, separated by commas, if you have them
};