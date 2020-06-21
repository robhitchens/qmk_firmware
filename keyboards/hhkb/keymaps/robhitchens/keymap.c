/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include QMK_KEYBOARD_H

//#define BASE 0
//#define HHKB 1

enum hhkb_layers {
    _BASE,
    _GAMEMODE,
    _SPACEFN,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FUNCK
};

enum hhkb_keycodes {
    BASE = SAFE_RANGE,
    GAMEMODE,
    SPACEFN,
    RAISE,
    LOWER,
    FUNCK
};

//#define LOWER MO(_LOWER)
//#define RAISE MO(_RAISE)
//#define FUNCK MO(_FUNCK)
#define SPACEFN MO(_SPACEFN)
#define TAPSPACE LT(SPACEFN, KC_SPC)
#define GUISPACE LT(SPACEFN, KC_RGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BASE Level: Default Layer
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Esc   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | \     | ` |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Tab   | Q | W | E | R | T | Y | U | I | O | P | [     | ]   | Backs |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Cont  | A | S | D | F | G | H | J | K | L | ; | '     | Ent |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Shift | Z | X | C | V | B | N | M | , | . | / | Shift | Fn0 |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|

            |------+------+-----------------------+------+------|
            | LAlt | LGUI | ******* Space ******* | RGUI | RAlt |
            |------+------+-----------------------+------+------|
    */

    [_BASE] = LAYOUT( //  default layer
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_RGUI,
        KC_LALT, LOWER, /*        */ TAPSPACE, RAISE, KC_RALT
    ),
    [_GAMEMODE] = LAYOUT( //  default layer
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, GUISPACE,
        KC_LALT, LOWER, /*        */ KC_SPC, RAISE, KC_RALT
    ),
    [_SPACEFN] = LAYOUT(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PIPE, KC_GRV,
        KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_DEL,
        KC_LCTL, XXXXXXX, KC_GRV, KC_MINS, KC_EQL, KC_BSLS, KC_PIPE, KC_LBRC, KC_RBRC, XXXXXXX, KC_COLN, KC_DQUO, KC_ENT,
        KC_LSFT, XXXXXXX, KC_TILD, KC_UNDS, KC_PLUS, XXXXXXX, KC_LCBR, KC_RCBR, KC_LT, KC_GT, KC_QUES, KC_RSFT, KC_RGUI,
        _______, _______, /*        */ _______, _______, _______
    ),
    [_LOWER] = LAYOUT( //  default layer
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_MS_WH_LEFT, KC_MS_U, KC_MS_WH_RIGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, KC_MS_BTN1, KC_MS_BTN2, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, /*        */ _______, _______, _______
    ),
    [_RAISE] = LAYOUT( //  default layer
        _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX,   KC_UP,  XXXXXXX, _______, _______, _______, KC_PSCR,  KC_INS, KC_HOME, KC_PGUP, XXXXXXX, _______, KC_DEL,
        _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, KC_CAPS,  KC_ESC,  KC_APP, XXXXXXX,  KC_END, KC_PGDN, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX,  XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_RGUI,
        _______, _______, /*        */ _______, _______, _______
    ),
    [_ADJUST] = LAYOUT( //  default layer
        _______,    BASE, GAMEMODE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,   RESET,    DEBUG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, /*        */ _______, _______, _______
    ),
    /* Layer HHKB: HHKB mode (HHKB Fn)
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Pwr  | F1  | F2  | F3  | F4 | F5 | F6 | F7 | F8  | F9  | F10 | F11 | F12   | Ins   | Del |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Caps |     |     |     |    |    |    |    | Psc | Slk | Pus | Up  |       | Backs |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | VoD | VoU | Mut |    |    | *  | /  | Hom | PgU | Lef | Rig | Enter |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    | +  | -  | End | PgD | Dow |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******************** | **** | **** |
                 |------+------+----------------------+------+------+

     */

    // [HHKB] = LAYOUT(
    //     KC_PWR, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,
    //     KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP, KC_TRNS, KC_BSPC,
    //     KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_PENT,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PPLS, KC_PMNS, KC_END, KC_PGDN, KC_DOWN, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record){
    switch (keycode)
    {
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
    case LOWER:
        if(record->event.pressed){
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }else{
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        break;
    case RAISE:
        if(record->event.pressed){
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }else{
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
    }
    return true;
}
