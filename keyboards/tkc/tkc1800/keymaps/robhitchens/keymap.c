/* Copyright 2017 Mathias Andersson <wraul@dbox.se>
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

//Layers

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
bool is_shift_alt_tab_active = false;
uint16_t shift_alt_tab_timer = 0;

enum layers {
  _BASE,
  _GAMEMODE,
  _SPACEFN,
  _LOWER,
  _RAISE,
  _SHIFTL,
  _PLOVER,
  _ADJUST,
  _FUNCK,
  _SPECL
};

/*enum {
  BASE = 0,
  FUNCTION,
};*/

enum keycodes {
  BASE = 0,
  GAMEMODE,
  SPACEFN,
  LEFTARROWFN,
  PLOVER,
  BACKLIT,
  EXT_PLV,
  FUNCK,
  ALT_TAB,
  ALSFH_TAB
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCK MO(_FUNCK)
#define SPECL MO(_SPECL)
#define SPACEFN MO(_SPACEFN)
//#define TAPLEFTARROW LT(LEFTARROWFN, KC_LEFT)
#define TAPSPACE LT(SPACEFN, KC_SPC)
#define GUISPACE LT(SPACEFN, KC_LGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap BASE: (Base Layer) Default Layer
   * ,-------------------------------------------------------.     ,-------------------.
   * |Esc| F1| F2| F3| F4| | F5| F6| F7| F8| | F9|F10|F11|F12|     |Ins |Home|PgUp|PrSc|
   * `-------------------------------------------------------'     |-------------------|
   *                                                               |Del |End |PgDn|ScrL|
   * ,-----------------------------------------------------------. |-------------------|
   * | ~ | 1 |  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp | |NumL| /  | *  |Paus|
   * |-----------------------------------------------------------| |-------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | | 7  | 8  | 9  | -  |
   * |-----------------------------------------------------------| |-------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return | | 4  | 5  | 6  | +  |
   * |-----------------------------------------------------------' |-------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift  | Up | 1  | 2  | 3  | Ent|
   * |--------------------------------------------------------'----`--------------|    |
   * |Ctrl|Gui |Alt |      Space           |Alt |Fn |Ctr|Left |Down|Rght| 0  | .  |    |
   * `---------------------------------------------------------------------------------'
   */
  [_BASE] = LAYOUT(
    KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                    KC_INS,  KC_HOME, KC_PGUP, KC_PSCR, \
                                                                                                                                            KC_DEL,  KC_END,  KC_PGDN, KC_SLCK, \
    KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, XXXXXXX, KC_NLCK, KC_PSLS, KC_PAST, KC_PAUS, \
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_P7,   KC_P8,   KC_P9,   KC_PMNS, \
    KC_LCTRL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, KC_ENT,           KC_P4,   KC_P5,   KC_P6,   KC_PPLS, \
    KC_LSFT,  XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,      KC_UP,       KC_P1,   KC_P2,   KC_P3,   XXXXXXX, \
    KC_LGUI,  KC_LALT, LOWER,                   TAPSPACE,                               XXXXXXX, RAISE, KC_RALT,      KC_LEFT, KC_DOWN, KC_RGHT,     KC_P0,   KC_PDOT, KC_PENT  \
  ),
  [_SPACEFN] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                    _______,  _______, _______, _______, \
                                                                                                                                            _______,  _______, _______, _______, \
    KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PIPE, XXXXXXX, _______,  _______, _______, _______, \
    _______,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, _______,          _______,  _______, _______, _______, \
    _______,  XXXXXXX, KC_GRV,  KC_MINS, KC_EQL,  KC_BSLS, KC_PIPE, KC_LBRC, KC_RCBR, XXXXXXX, KC_COLN, KC_DQUO, XXXXXXX, _______,          _______,  _______, _______, _______, \
    _______,  XXXXXXX, XXXXXXX, KC_TILD, KC_UNDS, KC_PLUS, XXXXXXX, KC_LCBR, KC_RCBR, KC_LT,   KC_GT,   KC_QUES, _______,         KC_UP,    _______,  _______, _______, XXXXXXX, \
    _______,  _______, _______,                   _______,                               XXXXXXX, _______, _______,      KC_LEFT, KC_DOWN, KC_RGHT,      _______, _______, _______  \
  ),
  [_LOWER] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                    _______,  _______, _______, _______, \
                                                                                                                                            _______,  _______, _______, _______, \
    _______,  _______,       _______,  _______,  _______,   _______,  _______,  _______,  _______, _______,  _______, _______,  _______,  _______, XXXXXXX, _______,  _______, _______, _______, \
    _______,  KC_MS_WH_LEFT, KC_MS_U,  KC_MS_WH_RIGHT, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, \
    _______,  KC_MS_L,       KC_MS_D,  KC_MS_R, _______,  _______, _______, KC_MS_BTN1, KC_MS_BTN2, _______, _______, _______, XXXXXXX, _______,          _______,  _______, _______, _______, \
    _______,  XXXXXXX, KC_MS_WH_DOWN,  KC_MS_BTN3, KC_MS_WH_UP, _______, _______, _______, _______, _______, _______, _______, _______,         KC_UP,    _______,  _______, _______, XXXXXXX, \
    _______,  _______, _______,                   _______,                               XXXXXXX, _______, _______,      KC_LEFT, KC_DOWN, KC_RGHT,      _______, _______, _______  \
  ),
  [_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                    _______,  _______, _______, _______, \
                                                                                                                                            _______,  _______, _______, _______, \
    _______,  _______,       _______,  _______,  _______,   _______,  _______,  _______,  _______, _______,  _______, _______,  _______,  _______, XXXXXXX, _______,  _______, _______, _______, \
    _______,  ALSFH_TAB, KC_UP,  ALT_TAB, _______,  _______, _______, KC_PSCR, KC_INS, KC_HOME, KC_PGUP, _______, _______, _______,          _______,  _______, _______, _______, \
    _______,  KC_LEFT,   KC_DOWN,KC_RIGHT, _______,  KC_CAPS, KC_ESC, KC_APP, _______, KC_END, KC_PGDN, _______, XXXXXXX, _______,          _______,  _______, _______, _______, \
    _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______,   _______,   _______, _______,         KC_UP,    _______,  _______, _______, XXXXXXX, \
    _______,  _______, _______,                   _______,                               XXXXXXX, _______, _______,      KC_LEFT, KC_DOWN, KC_RGHT,      _______, _______, _______  \
  ),
  [_SHIFTL] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                    _______,  _______, _______, _______, \
                                                                                                                                            _______,  _______, _______, _______, \
    _______,  _______,       _______,  _______,  _______,   _______,  _______,  _______,  _______, _______,  _______, _______,  _______,  _______, XXXXXXX, _______,  _______, _______, _______, \
    _______,  S(KC_Q), S(KC_W),  S(KC_E),   S(KC_R),    S(KC_T),    S(KC_Y),    S(KC_U),    S(KC_I),    S(KC_O),    S(KC_P),    S(KC_LBRC), S(KC_RBRC), _______,         _______,  _______,  _______, _______, \
    _______,  S(KC_A), S(KC_S),  S(KC_D),   S(KC_F),    S(KC_G),    S(KC_H),    S(KC_J),    S(KC_K),    S(KC_L),    S(KC_SCLN), S(KC_QUOT), XXXXXXX, _______,          _______,  _______,  _______, _______, \
    _______,  XXXXXXX, S(KC_Z),  S(KC_X),   S(KC_C),    S(KC_V),    S(KC_B),    S(KC_N),    S(KC_M),    S(KC_COMM), S(KC_DOT),  S(KC_SLSH), _______,      KC_UP,      _______,   _______,  _______,   XXXXXXX, \
    _______,  _______, _______,                   _______,                               XXXXXXX, _______, _______,      KC_LEFT, KC_DOWN, KC_RGHT,      _______, _______, _______  \
  ),
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                    _______,  _______, _______, _______, \
                                                                                                                                            _______,  _______, _______, _______, \
    _______,  _______,       _______,  _______,  _______,   _______,  _______,  _______,  _______, _______,  _______, _______,  _______,  _______, XXXXXXX, _______,  _______, _______, _______, \
    _______,  RESET, DEBUG,  _______,   _______,    _______,    _______,    _______,  _______, _______,  _______, _______, _______, _______,         _______,  _______,  _______, _______, \
    _______,  BL_TOGG, BL_STEP,  BL_ON,  BL_OFF, BL_INC, BL_DEC, BL_BRTG,  _______,  _______, _______, _______, XXXXXXX, _______,          _______,  _______,  _______, _______, \
    _______,  XXXXXXX, _______,  _______,   _______,    _______,    _______,    _______,    _______,    _______, _______,  _______, _______,      KC_UP,      _______,   _______,  _______,   XXXXXXX, \
    _______,  _______, _______,                   _______,                               XXXXXXX, _______, _______,      KC_LEFT, KC_DOWN, KC_RGHT,      _______, _______, _______  \
  ),
  /* Keymap FUNCTION: (Function Layer)
   * ,-------------------------------------------------------.     ,-------------------.
   * |   |   |   |   |   | |   |   |   |   | |   |   |   |   |     |    |    |    |    |
   * `-------------------------------------------------------'     |-------------------|
   *                                                               |    |    |    |    |
   * ,-----------------------------------------------------------. |-------------------|
   * |   |   |   |   |   |   |   |   |   |   |   |   |   | RESET | |    |    |    |    |
   * |-----------------------------------------------------------| |-------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     | |    |    |    |    |
   * |-----------------------------------------------------------| |-------------------|
   * |       |   |   |   |   |   |   |   |   |   |   |   |       | |    |    |    |    |
   * |-----------------------------------------------------------' |-------------------|
   * |        |Tog|Mod|Hu+|Hu-|Sa+|Sa-|Va+|Va-|Stp|   |       |    |    |    |    |    |
   * |--------------------------------------------------------'----`--------------|    |
   * |    |    |    |                      |    |   |   |     |    |    |    | .  |    |
   * `---------------------------------------------------------------------------------'
   */
};


layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  state = update_tri_layer_state(state, _SPACEFN, _LOWER, _SHIFTL);
  return state;
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
    case BASE:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_BASE);
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
      /*
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
      break;*/
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


#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    oled_write_P(PSTR("TKC1800\n"),false);
	// Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        /*case FUNCTION:
            oled_write_P(PSTR("Function\n"), false);
            break;*/
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif
