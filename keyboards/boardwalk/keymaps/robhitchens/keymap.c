/*
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

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
bool is_shift_alt_tab_active = false;
uint16_t shift_alt_tab_timer = 0;

// Layer shorthand
enum layer {
  _QWERTY,
  _GAMEMODE,
  _SPACEFN,
  _LEFTARROWFN,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCK,
};

enum boardwalk_keycodes {
  QWERTY = SAFE_RANGE,
  GAMEMODE,
  SPACEFN,
  LEFTARROWFN,
  BACKLIT,
  FUNCK,
  ALT_TAB,
  ALSFH_TAB
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCK MO(_FUNCK)
#define SPACEFN MO(_SPACEFN)
#define TAPSPACE LT(SPACEFN, KC_SPC)
#define GUISPACE LT(SPACEFN, KC_LGUI)
#define SHIFTSPACE LT(KC_RSFT, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_5x14(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PGUP,       KC_PGDN,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LEFT,       KC_RIGHT,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_DOWN,       KC_UP,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MS_WH_DOWN, KC_MS_WH_UP, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, \
  KC_LALT, KC_LGUI, FUNCK,   KC_LALT, LOWER,   TAPSPACE,TAPSPACE,      KC_RSFT,     KC_RSFT, RAISE,   KC_RALT, FUNCK,   KC_RGUI, KC_RALT  \
),
[_GAMEMODE] = LAYOUT_ortho_5x14(
  KC_ESC,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_PGUP,       KC_PGDN,     KC_6,    KC_7,  KC_8,    KC_9,    KC_0,     KC_DEL, \
  KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_LEFT,       KC_RIGHT,    KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,     KC_BSPC, \
  KC_LCTL, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_DOWN,       KC_UP,       KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  \
  KC_LSFT, KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_MS_WH_DOWN, KC_MS_WH_UP, KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT, \
  KC_LALT, GUISPACE, KC_LALT, LOWER,   FUNCK,   KC_SPC,  KC_SPC,        KC_RSFT,     KC_RSFT, RAISE, FUNCK,   KC_RALT, GUISPACE, KC_RALT  \
),
[_SPACEFN] = LAYOUT_ortho_5x14(
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,  KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10, KC_GRV, \
  KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  KC_LCTL, XXXXXXX, KC_GRV,  KC_MINS, KC_EQL,  KC_BSLS, _______, _______, KC_PIPE, KC_LBRC, KC_RBRC, XXXXXXX, KC_COLN, KC_DQUO,  \
  KC_LSFT, XXXXXXX, KC_TILD, KC_UNDS, KC_PLUS, XXXXXXX, _______, _______, KC_LCBR, KC_RCBR, KC_LT,   KC_GT,   KC_QUES, KC_ENT, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),
[_LOWER] = LAYOUT_ortho_5x14(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
  _______, KC_MS_WH_LEFT,   KC_MS_U,KC_MS_WH_RIGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_MS_L,    KC_MS_D,    KC_MS_R, _______, _______, _______, _______, _______, KC_MS_BTN1, KC_MS_BTN2, _______, _______, _______,  \
  _______, KC_MS_WH_DOWN, KC_MS_BTN3, KC_MS_WH_UP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),
[_RAISE] = LAYOUT_ortho_5x14(
  _______, _______,   _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  \
  _______, ALSFH_TAB, KC_UP,   ALT_TAB,  _______, _______, _______, _______, _______, KC_PSCR, KC_INS,  KC_HOME, KC_PGUP,  _______, \
  _______, KC_LEFT,   KC_DOWN, KC_RIGHT, _______, KC_CAPS, _______, _______, KC_ESC,  KC_APP,  _______,  KC_END, KC_PGDN,  _______,  \
  _______, XXXXXXX,   XXXXXXX, XXXXXXX,  _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX,  KC_SLSH, _______, \
  _______, _______,   _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______  \
),
[_ADJUST] = LAYOUT_ortho_5x14(
  _______, QWERTY, GAMEMODE, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  \
  _______,  RESET, DEBUG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD ,_______, _______, _______, \
  _______, _______,   _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  \
  _______, _______,   _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  \
  _______, _______,   _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______  \
),
/*TODO might add funck layer later, or might just delete.*/
[_FUNCK] = LAYOUT_ortho_5x14(
  _______, _______,   _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  \
  _______, KC_MS_WH_UP,_______, KC_MS_WH_DOWN,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  \
  _______, _______,   _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  \
  _______, _______,   _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  \
  _______, _______,   _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______  \
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ALT_TAB:
        if(record->event.pressed){
            if(!is_alt_tab_active){
                is_alt_tab_active = true;
                register_code(KC_LALT);
            }
            alt_tab_timer = timer_read();
            register_code(KC_TAB);
        }else{
            unregister_code(KC_TAB);
        }
        break;
    case ALSFH_TAB:
        if(record->event.pressed){
            if(!is_shift_alt_tab_active){
                is_shift_alt_tab_active = true;
                register_code(KC_LALT);
                register_code(KC_LSHIFT);
            }
            shift_alt_tab_timer = timer_read();
            register_code(KC_TAB);
        }else{
            unregister_code(KC_TAB);
        }
        break;
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case GAMEMODE:
      if(record->event.pressed){
        print("mode just switched to gamemode");
        set_single_persistent_default_layer(_GAMEMODE);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
  }
  return true;
}
void matrix_scan_user(void) {
    if(is_alt_tab_active){
        if(timer_elapsed(alt_tab_timer) > 500){
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
    if(is_shift_alt_tab_active){
        if(timer_elapsed(shift_alt_tab_timer) > 500){
            unregister_code(KC_LALT);
            unregister_code(KC_LSHIFT);
            is_shift_alt_tab_active = false;
        }
    }
}
