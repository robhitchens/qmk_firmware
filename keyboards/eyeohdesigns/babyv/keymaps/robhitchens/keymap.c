/* Copyright 2020 Eye Oh! Designs
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

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
bool is_shift_alt_tab_active = false;
uint16_t shift_alt_tab_timer = 0;
uint16_t macro_max_timer = 750;

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _GAMEMODE,
    _LOWER,
    _RAISE,
    _SHIFTL,
    _SPACEFN,
    _NUMHOME,
    _ADJUST,
    _FUNCK
};

enum custom_keycodes {
    BASE = SAFE_RANGE,
    GAMEMODE,
    ALT_TAB,
    ALSFH_TAB
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define FUNCK MO(_FUNCK)
#define SPACEFN MO(_SPACEFN)
#define TAPSPACE LT(SPACEFN, KC_SPC)
#define SHIFTL MO(_SHIFTL)
#define GUISPACE LT(SPACEFN, KC_RGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
   [QWERTY] = LAYOUT_2u(
        KC_ESC,  KC_Q,    KC_W,    KC_E,      KC_R,       KC_T,    KC_Y,    KC_U,    KC_I,      KC_O,     KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,      KC_F,       KC_G,    KC_H,    KC_J,    KC_K,      KC_L,     KC_SCLN, KC_ENT, 
        KC_LSFT, KC_Z,    KC_X,    KC_C,      KC_V,       KC_B,    KC_N,    KC_M,    KC_COMM,   KC_DOT,   KC_SLSH, KC_RSFT,
        KC_LCTL,                   KC_LALT,      MO(NUMBRS),            KC_SPC,      MO(FUNCT),                    KC_LGUI
    ),
   [FUNCT] = LAYOUT_2u(
        KC_VOLU, KC_Q,    KC_PGUP, RGB_TOG,    BL_STEP,    KC_T,    KC_Y,    KC_U,       KC_UP,      RGB_MOD,  RGB_RMOD, KC_DEL,
        KC_VOLD, KC_HOME, KC_PGDN, KC_D,       KC_U,       KC_MINS, KC_EQL,  KC_LEFT,    KC_DOWN,    KC_RIGHT, KC_QUOT,  RESET,
        KC_LSFT, RGB_HUI, RGB_HUD, RGB_SAI,    RGB_SAD,    KC_LBRC, KC_RBRC, RGB_VAI,    RGB_VAD,    KC_DOT,   KC_BSLS,  KC_RSFT,
        KC_LCTL,                    KC_TRNS,      KC_TRNS,              KC_SPC,      KC_TRNS,                      RESET
    ),
    [NUMBRS] = LAYOUT_2u(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,     KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,     KC_F10,   KC_F11,  KC_F12,
        KC_MUTE, KC_1,    KC_2,    KC_3,      KC_4,       KC_5,    KC_6,    KC_7,    KC_8,      KC_9,     KC_0,    KC_ENT,
        KC_CAPS, KC_EXLM, KC_AT,   KC_HASH,   KC_DLR,     KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,   KC_LPRN,  KC_RPRN, KC_RSFT,
        KC_LCTL,                   KC_TRNS,       KC_TRNS,               KC_SPC,     KC_TRNS,                      KC_LGUI
    ),
    */
    [_BASE] = LAYOUT_2u(
		KC_TAB,   KC_Q,     KC_W,     KC_E,   KC_R,    KC_T,          KC_Y,    KC_U, KC_I,    KC_O,    KC_P,    KC_BSPC,
		KC_LCTL,  KC_A,     KC_S,     KC_D,   KC_F,    KC_G,          KC_H,    KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT,
		KC_LSFT,  KC_Z,     KC_X,     KC_C,   KC_V,    KC_B,          KC_N,    KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
	    KC_LALT,                      LOWER,  TAPSPACE,	              SHIFTL,        RAISE,                     KC_RALT
    ),
    [_GAMEMODE] = LAYOUT_2u(
		KC_TAB,   KC_Q,     KC_W,     KC_E,   KC_R,    KC_T,          KC_Y,   KC_U, KC_I,    KC_O,    KC_P,    KC_BSPC,
		KC_LCTL,  KC_A,     KC_S,     KC_D,   KC_F,    KC_G,          KC_H,   KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT,
		KC_LSFT,  KC_Z,     KC_X,     KC_C,   KC_V,    KC_B,          KC_N,   KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
		KC_LALT,                      LOWER,           KC_SPC,	      SHIFTL,       RAISE,                     GUISPACE
    ),
    [_SPACEFN] = LAYOUT_2u(
		_______,  KC_EXLM,     KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,          KC_CIRC,   KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN, _______,
		_______,  XXXXXXX,     KC_GRV,    KC_MINS,   KC_EQL,    KC_BSLS,          KC_PIPE,   KC_LBRC, KC_RBRC, XXXXXXX,  KC_COLN, KC_DQUO,
		_______,  XXXXXXX,     KC_TILD,   KC_UNDS,   KC_PLUS,   XXXXXXX,          KC_LCBR,   KC_RCBR, KC_LT,   KC_GT,    KC_QUES, _______,
		_______,                            _______,            _______,	      _______,            _______,                    _______
    ),
    [_SHIFTL] = LAYOUT_2u(
		_______,  S(KC_Q), S(KC_W),     S(KC_E),   S(KC_R),    S(KC_T),          S(KC_Y),   S(KC_U), S(KC_I),    S(KC_O),    S(KC_P),    _______,
		_______,  S(KC_A), S(KC_S),     S(KC_D),   S(KC_F),    S(KC_G),          S(KC_H),   S(KC_J), S(KC_K),    S(KC_L),    S(KC_SCLN), S(KC_QUOT),
		_______,  S(KC_Z), S(KC_X),     S(KC_C),   S(KC_V),    S(KC_B),          S(KC_N),   S(KC_M), S(KC_COMM), S(KC_DOT),  S(KC_SLSH), _______,
		_______,                        _______,               _______,	         _______,   _______,                                     _______
    ),
    [_LOWER] = LAYOUT_2u(
		_______,  KC_MS_WH_UP,   KC_MS_U,     KC_MS_WH_DOWN,    _______,    _______,          _______,   _______,     _______,    _______, _______, _______,
		_______,  KC_MS_L,       KC_MS_D,     KC_MS_R,          _______,    _______,          _______,   KC_MS_BTN1,  KC_MS_BTN2, _______, _______, _______,
		_______,  KC_MS_WH_LEFT, KC_MS_BTN3,  KC_MS_WH_RIGHT,   _______,    _______,          _______,   _______,     _______,    _______, _______, _______,
		_______,                              _______,                      _______,	      _______,                _______,                      _______
    ),
    [_RAISE] = LAYOUT_2u(
		_______,  ALSFH_TAB,   KC_UP,       ALT_TAB,   _______,    _______,          KC_DEL,   KC_PSCR, KC_INS,  KC_HOME, KC_PGUP, _______,
		_______,  KC_LEFT,     KC_DOWN,     KC_RIGHT,  _______,    KC_CAPS,          KC_ESC,   KC_APP,  XXXXXXX, KC_END,  KC_PGDN, _______,
		_______,  XXXXXXX,     XXXXXXX,     XXXXXXX,   _______,    _______,          _______,  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	    _______,                            _______,               _______,	         _______,           _______,                   _______
    ),
    [_NUMHOME] = LAYOUT_2u(
		KC_F11,    KC_F1,     KC_F2,    KC_F3,   KC_F4,   KC_F5,         KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F12,
		_______,   KC_1,      KC_2,     KC_3,    KC_4,    KC_5,          KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    _______,
		_______,   _______,   _______,  _______, _______, _______,       _______, _______,  _______, _______, _______, _______,
		_______,                        _______,          _______,	     _______,           _______,                   _______
    ),
    [_ADJUST] = LAYOUT_2u(
		_______,  RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI,         RGB_HUD,  RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, _______,
		_______,  _______, _______, _______, _______, _______,         _______,  BASE,    GAMEMODE, _______, _______, _______,
		_______,  BL_TOGG, BL_STEP, BL_ON,   BL_OFF,  BL_INC,          BL_DEC,   BL_BRTG, _______,  _______, _______, _______,
		_______,                    _______,          _______,	       _______,           _______,                    _______
    ),
};

void matrix_scan_user(void) {
    if(is_alt_tab_active){
        if(timer_elapsed(alt_tab_timer) > macro_max_timer){
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
    if(is_shift_alt_tab_active){
        if(timer_elapsed(shift_alt_tab_timer) > macro_max_timer){
            unregister_code(KC_LALT);
            unregister_code(KC_LSHIFT);
            is_shift_alt_tab_active = false;
        }
    }
}

layer_state_t layer_state_set_user(layer_state_t state){
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    state = update_tri_layer_state(state, _SPACEFN, _RAISE, _NUMHOME);
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record){
    switch (keycode)
    {
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
        if(record->event.pressed){
            set_single_persistent_default_layer(_BASE);
        }
        return false;
        break;
    case GAMEMODE:
        if(record->event.pressed){
            set_single_persistent_default_layer(_GAMEMODE);
        }
        return false;
        break;
    }
    return true;
}