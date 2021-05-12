/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"


enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

#define TG_NUMP TG(_NUMPAD)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BEPO
 * ,-----------------------------------------------------------------------------------.
 * | esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   b  |   é  |   p  |   o  |   è  |   !  |   v  |   d  |   l  |   j  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shift|   A  |   u  |   i  |   e  |   ,  |   c  |   t  |   s  |   r  |   n  |  m   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ^  |  à   |   y  |   x  |   .  |   k  |   ?  |   q  |   g  |   h  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,       KC_5,       KC_6,    KC_7,       KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_B,    KC_SCLN, KC_P,    KC_O,       S(KC_RBRC), KC_EXLM, KC_V,       KC_D,    KC_L,    KC_J,    KC_DEL,
  KC_LSFT, KC_A,    KC_U,    KC_I,    KC_E,       KC_COMM,    KC_C,    KC_T,       KC_S,    KC_R,    KC_N,    KC_M,
  KC_LSFT, KC_EQL,  KC_QUOT, KC_Z,    KC_X,       KC_DOT,     KC_K,    S(KC_MINS), KC_Q,    KC_G,    KC_H,    KC_ENT,
  _______, KC_LCTL, KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,     KC_SPC,  MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   +  |   "  |   *  |   ç  |   %  |   &  |   /  |   (  |   )  |   =  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   #  |  @   |      |      |      |      |   \  |   {  |   }  |   <  |   >  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |   £  | euro |      |   §  |   °  |   [  |   ]  |   $  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   ~  |   -  |   _  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  S(KC_EQL), S(KC_1), S(KC_2),    S(KC_3),    S(KC_4),    S(KC_5), S(KC_6), S(KC_7),    S(KC_8),    S(KC_9),    S(KC_0), KC_BSPC,
  _______,   RALT(KC_3), RALT(KC_G), _______, _______,    _______, _______, LSA(KC_7),  RALT(KC_8), RALT(KC_9), KC_NUBS, S(KC_NUBS),
  _______,   _______, _______,    S(KC_BSLS), RALT(KC_E), _______, KC_GRV,  S(KC_GRV),  RALT(KC_5), RALT(KC_6), KC_BSLS, _______,
  _______,   _______, _______,    _______,    _______,    _______, _______, RALT(KC_N), KC_SLSH,    S(KC_SLSH), _______, _______,
  _______,   _______, _______,    _______,    _______,    _______, _______, _______,    KC_MNXT,    KC_VOLD,    KC_VOLU, KC_MPLY
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  f1  |  f2  |  f3  |  f4  |  f5  |  f6  |      |      |  z   |   w  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  f7  |  f8  |  f9  |  f10 |  f11 | f12  |      |      |      |      |  f   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |cancel| copy |paste |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_Y,    KC_W,    _______,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, KC_F,
  _______, G(KC_Y), G(KC_X), G(KC_C),  G(KC_V), _______, _______, _______, _______,_______, _______, _______,
  _______, KC_LCTL, KC_LALT, KC_LGUI, _______, _______, _______, _______, _______, _______, _______, _______
),
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______,  _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
