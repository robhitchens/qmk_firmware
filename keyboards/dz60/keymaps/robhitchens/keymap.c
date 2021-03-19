#include QMK_KEYBOARD_H

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
bool is_shift_alt_tab_active = false;
uint16_t shift_alt_tab_timer = 0;
uint16_t macro_max_timer = 750;

enum dz60_layers {
    _BASE,
    _GAMEMODE,
    _SPACEFN,
    _LOWER,
    _RAISE,
    _SHIFTL,
    _ADJUST
};

enum dz60_keycodes {
    BASE = SAFE_RANGE,
    GAMEMODE,
    ALT_TAB,
    ALSFH_TAB
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define SPACEFN MO(_SPACEFN)
#define TAPSPACE LT(SPACEFN, KC_SPC)
#define SHIFTL MO(_SHIFTL)
#define GUISPACE LT(SPACEFN, KC_RGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RGUI,
        KC_LCTL, KC_LALT, LOWER,                   TAPSPACE,  TAPSPACE, TAPSPACE,          RAISE,  KC_RALT,  KC_RALT, KC_RGUI, KC_RCTL
    ),

    [_GAMEMODE] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, GUISPACE,
        KC_LCTL, KC_LALT, LOWER,                     KC_SPC,  KC_SPC,  KC_SPC,           RAISE,  KC_RALT,  KC_RALT, KC_RGUI, KC_RCTL
    ),
    [_SPACEFN] = LAYOUT(
        _______,  KC_F1,   KC_F2,   KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_F11, KC_F12,  _______, _______,
        _______,  KC_EXLM, KC_AT,   KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN, KC_LCBR,KC_RCBR, _______,
        _______,  KC_QUOT, KC_GRV,  KC_MINS,  KC_EQL,   KC_BSLS,  KC_PIPE,  KC_LBRC,  KC_RBRC,  _______,  KC_COLN, KC_DQUO,          _______,
        _______, XXXXXXX, KC_DQUO,  KC_TILD,  KC_UNDS,  KC_PLUS,  _______,  KC_LCBR,  KC_RCBR,  KC_LT,    KC_GT,   KC_QUES, _______, _______,
        _______, _______, _______,                   _______,  _______,  _______,        _______,  _______, _______, _______, _______
    ),
    [_LOWER] = LAYOUT(
        _______,  _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______, _______,_______,  _______, _______,
        _______,  KC_MS_WH_UP, KC_MS_U, KC_MS_WH_DOWN,  _______,  _______,  _______,  _______,  _______,  _______,   _______, _______,_______, _______,
        _______,  KC_MS_L, KC_MS_D, KC_MS_R,  _______,  _______,  _______,   KC_MS_BTN1,  KC_MS_BTN2,  _______,   _______, _______,          _______,
        _______, XXXXXXX,  KC_MS_WH_LEFT, KC_MS_BTN3,  KC_MS_WH_RIGHT,  _______,  _______,  _______,  _______,  _______,_______,  _______, _______, _______,
        _______, _______, _______,                   _______,  _______,  _______,        _______,  _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT(
        _______,  _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______, _______,_______,  _______, _______,
        _______,  ALSFH_TAB, KC_UP, ALT_TAB,  _______,  _______,  KC_DEL,  KC_PSCR,  KC_INS,  KC_HOME,  KC_PGUP, _______,_______, _______,
        _______,  KC_LEFT, KC_DOWN, KC_RIGHT,  _______, KC_CAPS,  KC_ESC,   KC_APP,  _______,  KC_END,   KC_PGDN, _______,          _______,
        _______, XXXXXXX,  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______, _______, _______,
        _______, _______, _______,                   _______,  _______,  _______,        _______,  _______, _______, _______, _______
    ),
    [_SHIFTL] = LAYOUT(
        _______,  _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______, _______,_______,  _______, _______,
        _______,  S(KC_Q), S(KC_W), S(KC_E),  S(KC_R),  S(KC_T),  S(KC_Y),  S(KC_U),  S(KC_I),  S(KC_O),   S(KC_P), _______,_______, _______,
        _______,  S(KC_A), S(KC_S), S(KC_D),  S(KC_F),  S(KC_G),  S(KC_H),  S(KC_J),  S(KC_K),  S(KC_L),   S(KC_SCLN), S(KC_QUOT),          _______,
        _______, XXXXXXX,  S(KC_Z), S(KC_X),  S(KC_C),  S(KC_V),  S(KC_B),  S(KC_N),  S(KC_M),  S(KC_COMM),S(KC_DOT),  S(KC_SLSH), _______, _______,
        _______, _______, _______,                   _______,  _______,  _______,        _______,  _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT(
        _______,  BASE, GAMEMODE, _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______, _______,_______,  _______, _______,
        _______,  RESET, DEBUG, RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,   RGB_VAD, _______,_______, _______,
        _______,  _______, _______, _______,  _______,  _______,  _______,   _______,  _______,  _______,   _______, _______,          _______,
        _______, XXXXXXX,  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,_______,  _______, _______, _______,
        _______, _______, _______,                   _______,  _______,  _______,        _______,  _______, _______, _______, _______
    )
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
    state = update_tri_layer_state(state, _SPACEFN, _RAISE, _SHIFTL);
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
