/* Copyright 2018 Milton Griffin
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
#include "keymap_fr_ch.h"

// Keyboard Layers
#define _QW 0
#define _UP 1
#define _BE 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | CAP LK | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | RGUI   | RCTRL  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
    KC_ESC,  CH_1,    CH_2,    CH_3,    CH_4,    CH_5,    TG(_BE),  CH_6,    CH_7,    CH_8,    CH_9,    CH_0,    CH_QUOT, KC_EQL,  KC_BSPC, \
    KC_TAB,  CH_Q,    CH_W,    CH_E,    CH_R,    CH_T,    KC_END,   CH_Z,    CH_U,    CH_I,    CH_O,    CH_P,    CH_EGRV, KC_RBRC, KC_ENT,  \
    XXXXXXX, CH_A,    CH_S,    CH_D,    CH_F,    CH_G,    MO(_UP),   CH_H,    CH_J,    CH_K,    CH_L,    CH_EACU, CH_AGRV, KC_NUHS, XXXXXXX,  \
    KC_LSFT, CH_Y,    CH_X,    CH_C,    CH_V,    CH_B,    MO(_UP),   CH_N,    CH_M,    CH_COMM, CH_DOT,  KC_SLSH, XXXXXXX, KC_UP,   KC_RSFT, \
    KC_LCTL, KC_LALT, _______, KC_LGUI, XXXXXXX,  XXXXXXX, KC_SPC ,  XXXXXXX,  KC_SPC,  KC_RGUI, KC_RCTL, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT  \
 ),

 [_UP] = LAYOUT_ortho_5x15( /* FUNCTION */
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,      KC_F10,  KC_F11,  KC_F12,  _______, \
    _______, BL_TOGG, _______, _______, _______, _______, _______, A(CH_5), A(CH_6), _______,    _______, _______, _______, _______, _______, \
    _______, BL_INC,  BL_DEC,  _______, _______, _______, _______, A(CH_8), A(CH_9), _______,    _______, _______, _______, _______, _______, \
    _______, RGB_TOG, RGB_MODE_BREATHE, RGB_MODE_SNAKE, RGB_MODE_PLAIN, _______, _______, KC_NUBS, S(KC_NUBS), A(CH_N), _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______  \
 ),
 [_BE] = LAYOUT_ortho_5x15( /* FUNCTION */
     _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,_______, _______,  \
     _______, CH_B,    CH_W,    CH_P,    CH_O,    A(KC_EQL),  _______, CH_ACUT, CH_V,    CH_D,    CH_L,    CH_J,    _______,_______, _______, \
     _______, CH_A,    CH_U,    CH_I,    CH_E,    S(CH_QUOT), _______, CH_C,    CH_T,    CH_S,    CH_R,    CH_N,    _______,_______, _______, \
     _______, CH_Z,    CH_Y,    CH_X,    CH_DOT,  CH_K,       _______, CH_M,    CH_Q,    CH_G,    CH_C,    _______, _______,_______, _______, \
     _______, _______, _______, _______, _______, _______,    _______, _______, _______, CH_F,    _______, _______, _______,_______, _______ \
  )
};
