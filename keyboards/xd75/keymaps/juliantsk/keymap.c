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
  DBLOH = SAFE_RANGE,
  COPY,
  PASTE,
  SLALL,
  SS_FN,
  PRNS,
  CBRS,
  BRCS,
  QUOTS,
  BLSL_PP,
  MINSS,
  EQLS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | SELALL | COPY   | PSTE   | DEL    | F5     | F6     | P7     | P8     | P9     | /      | SUPER  | LEFT   | DOWN   | UP     | RIGHT  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | Q      | W      | F      | P      | G      | P.     | P4     | P5     | P6     | P0     | J      | L      | U      | Y      | ;      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | A      | R      | S      | T      | D      | ENTER  | P1     | P2     | P3     | HOME   | H      | N      | E      | I      | O      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | Z      | X      | C      | V      | B      | MINUS  | SCROLL | PAUSE  | PGUP   | PLUS   | K      | M      | ,      | .      | /      |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | SHIFT  | CTRL   | ALT    | ESC    | SPACE  | NL     | PRINT  | FN     | PGDN   | SS     | SPACE  | TAB    | HOME   | END    | ENTER  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_CO] = LAYOUT_ortho_5x15( /* COLEMAK */
    KC_SEL,  KC_W,    KC_F,    KC_P,    KC_G,    KC_MINS, KC_P7,   KC_P8,   KC_P9,   KC_EQL,  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_CAPS, KC_P4,   KC_P5,   KC_P6,   KC_MPLY, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_PSCR, KC_P1,   KC_P2,   KC_P3,   KC_HOME, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SLCK, KC_NO,   KC_P0,   KC_PDOT, KC_END,  KC_PGUP, KC_PGDN, KC_TAB,  KC_UP,   KC_ENT,
    KC_NO,   KC_COPY, MO(_FN), KC_LSFT, KC_SPC,  MO(_SS), KC_ENT, KC_GESC,  KC_BSPC, MO(_SS), KC_SPC,  KC_RSFT, KC_LEFT, KC_DOWN, KC_RIGHT
  ),

/* SECONDARY & SYMBOL
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | !      | @      | #      | $      | %      |        |        |        |        |        | ^      | &      | *      | -   _  | =   +  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | ~      |        |        | (   )  | ENTER  | NUM LK |        |        |        |        | BSPC   | {   }  | [   ]  |        | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        | \      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        | SS     |        | SS     |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_SS] = LAYOUT_ortho_5x15( /* SECONDARY & SYMBOL */
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, _______, _______, KC_6,    KC_7,    KC_8,    TD(MINSS),TD(EQLS),
    KC_TAB,  _______, _______, TD(PRNS),KC_ENT,  KC_NLCK, _______, _______, _______, _______, KC_BSPC, TD(CBRS),TD(BRCS),_______,  TD(QUOTS),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  TD(BSLS_PP),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
    _______, _______, _______, _______, _______, _______, MO(_SS), KC_TILD, MO(_SS), _______, _______, _______, _______, _______,  _______
  ),

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F9     | F10    | F11    | F12    |        |        |        |        |        |        |        | 7      | 8      | 9      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | F5     | F6     | F7     | F8     |        |        |        |        |        |        |        | 4      | 5      | 6      | 0      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | F1     | F2     | F3     | F4     |        |        |        |        |        |        |        | 1      | 2      | 3      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        | VOLUP  |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        | SLEEP  |        |        |        | VOLDN  |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    _______,
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    KC_0,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, K_VOLU,  _______, _______, _______,
    _______, _______, MO(_FN), _______, _______, _______, _______, KC_SLEP, _______, _______, _______, K_VOLD,  _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DBLOH:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("00");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case COPY:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
          case PASTE:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
    case SLALL:
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

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [SS_FN]  = ACTION_TAP_DANCE_DOUBLE(MO(_SS), MO(_SS))
// Other declarations would go here, separated by commas, if you have them
};