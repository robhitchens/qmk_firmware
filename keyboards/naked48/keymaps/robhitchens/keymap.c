#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _QWERTY = 0,
  _GAMEMODE,
  _SPACEFN,
  _LEFTARROWFN,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCK
};

enum custom_keycodes {
  RGB_RST = SAFE_RANGE,
  QWERTY,
  GAMEMODE,
  LOWER,
  RAISE,
  ADJUST,
  FUNCK
};

#define SPACEFN MO(_SPACEFN)
#define TAPSPACE LT(SPACEFN, KC_SPC)
#define GUISPACE LT(SPACEFN, KC_LGUI)
#define LEFTARROWFN MO(_LEFTARROWFN)
#define TAPLEFTARROW LT(LEFTARROWFN, KC_LEFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,   KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+-------+--------+--------|
     KC_LCTRL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,   KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+-------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M, KC_COMM, KC_DOT, KC_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------+--------+--------|
                KC_ESC, KC_LGUI, KC_LALT,   FUNCK,   LOWER,TAPSPACE, KC_RSFT,   RAISE, TAPLEFTARROW, KC_DOWN,  KC_UP,KC_RIGHT
          //`------------------------------------------------------------------------------------------------------------'
  ),
  [_GAMEMODE] = LAYOUT(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,   KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+-------+--------+--------|
     KC_LCTRL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,   KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+-------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M, KC_COMM, KC_DOT, KC_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------+--------+--------|
                KC_ESC,GUISPACE, KC_LALT,   FUNCK,   LOWER,  KC_SPC, KC_RSFT,   RAISE, KC_LEFT, KC_DOWN,  KC_UP,KC_RIGHT
          //`------------------------------------------------------------------------------------------------------------'
  ),
  [_SPACEFN] = LAYOUT(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR,KC_LPRN, KC_RPRN,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+-------+--------+--------|
     KC_LCTRL, XXXXXXX,  KC_GRV, KC_MINS,  KC_EQL, KC_BSLS,                   KC_PIPE, KC_LBRC, KC_RBRC,XXXXXXX, KC_COLN, KC_DQUO,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+-------+--------+--------|
      KC_LSFT, XXXXXXX, KC_TILD, KC_UNDS, KC_PLUS, XXXXXXX,                   KC_LCBR, KC_RCBR,   KC_LT,  KC_GT, KC_QUES,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------+--------+--------|
               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, _______
          //`------------------------------------------------------------------------------------------------------------'
  ),
//   [_QWERTY] = LAYOUT(//original default layer layout.
//   //,-----------------------------------------------------|                 |-----------------------------------------------------.
//        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
//   //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
//        KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
//   //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
//       KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
//   //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
//            MO(_ADJUST),KC_LCTRL, KC_LALT, KC_LGUI,MO(_LOWER),KC_SPC,KC_SPC,MO(_RAISE), KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT
//           //`------------------------------------------------------------------------------------------------------------'
//   ),



//   [_LOWER] = LAYOUT(
//   //,-----------------------------------------------------|                 |-----------------------------------------------------.
//       KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                   KC_CIRC, KC_AMPR,  KC_ASTR,KC_LPRN, KC_RPRN,  KC_DEL,
//   //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
//       _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
//   //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
//       _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,                    KC_F12,S(KC_NUHS),S(KC_NUBS),_______,_______,_______,
//   //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
//                _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
//           //`------------------------------------------------------------------------------------------------------------'
//   ),

//     [_FUNCK] = LAYOUT(
//     KC_FN1, KC_FN2,   KC_FN3,  KC_FN4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,  KC_F10, KC_F11, KC_F12,
//     _______, KC_1, KC_2,  KC_3,   KC_4,  KC_5, KC_6, KC_7,  KC_8,  KC_9,  KC_0,  _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
// ),

[_FUNCK] = LAYOUT( /* Base */
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
      KC_PLUS,    KC_1,    KC_2,    KC_3, _______, _______,                   _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
     KC_MINUS,    KC_4,    KC_5,    KC_6, _______, _______,                   _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      KC_ASTR,    KC_7,    KC_8,    KC_9, _______, _______,                   _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                  KC_0,  KC_DOT, KC_SLSH, _______, _______, _______, _______, _______, _______, _______, _______, _______
          //`------------------------------------------------------------------------------------------------------------'
  ),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
//   [_LOWER] = LAYOUT(
//   KC_TILD, KC_MS_WH_LEFT, KC_MS_U,   KC_MS_WH_RIGHT, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
//   _______,  KC_MS_L,   KC_MS_D,   KC_MS_R,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
//   _______, KC_MS_WH_DOWN,   KC_MS_BTN3,   KC_MS_WH_UP,   KC_F10,  KC_F11,  KC_F12,_______,KC_LEFT_ANGLE_BRACKET,KC_RIGHT_ANGLE_BRACKET, KC_BSLASH, _______,
//   _______, _______, _______, _______, _______, KC_MS_BTN1, KC_MS_BTN2, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
// ),//TODO come back to this.
[_LEFTARROWFN] = LAYOUT_planck_mit(
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[_LOWER] = LAYOUT(
  //,------------------------------------------------------------------|                       |-----------------------------------------------------.
      _______, KC_MS_WH_LEFT, KC_MS_U, KC_MS_WH_RIGHT, _______, _______,                         _______, _______, _______, _______, _______, _______,
  //|--------+--------------+--------+---------------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
      _______,       KC_MS_L, KC_MS_D,        KC_MS_R, _______, _______,                         _______,KC_MS_BTN1,KC_MS_BTN2, _______, _______, _______,
  //|--------+--------------+--------+---------------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
      _______, KC_MS_WH_DOWN, KC_MS_BTN3, KC_MS_WH_UP, _______, _______,                         _______, _______, _______, _______, _______, _______,
  //|--------+--------------+--------+---------------+--------+--------+----------+-----------+---------+--------+--------+--------+--------+--------|
                     _______, _______,        _______, _______, _______,   _______,    _______,  _______, _______, _______, _______, _______
          //`------------------------------------------------------------------------------------------------------------'
  ),
//   [_RAISE] = LAYOUT(
//   //,-----------------------------------------------------|                 |-----------------------------------------------------.
//       KC_TILD,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
//   //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
//       _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
//   //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
//       _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,                    KC_F12, KC_NUHS, KC_NUBS, _______, _______, _______,
//   //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
//                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//           //`------------------------------------------------------------------------------------------------------------'
//   ),

[_RAISE] = LAYOUT( /* Base */
  //,-----------------------------------------------------|                 |-------------------------------------------------------.
      _______, XXXXXXX,   KC_UP, XXXXXXX, _______, _______,                     _______,KC_PSCR,  KC_INS, KC_HOME, KC_PGUP, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                 |----------+-------+--------+--------+--------+--------|
      _______, KC_LEFT, KC_DOWN,KC_RIGHT, _______, KC_CAPS,                      KC_ESC, KC_APP, _______,  KC_END, KC_PGDN, _______,
  //|--------+--------+--------+--------+--------+--------|                 |----------+-------+--------+--------+----------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,                     _______,_______, XXXXXXX, XXXXXXX, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+----------+-----------+--------+--------+----------+--------|
               _______, _______, _______, _______, _______, _______, _______,   _______,_______, KC_VOLD, KC_VOLU, KC_MPLY
          //`------------------------------------------------------------------------------------------------------------'
  ),

  [_ADJUST] = LAYOUT( /* Base */
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   RGB_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX,  QWERTY,GAMEMODE,                   RGB_TOG, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 RESET,   DEBUG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
          //`------------------------------------------------------------------------------------------------------------'
  )
};

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool result = false;
  switch (keycode) {//todo add handling of keycodes here.
    #ifdef RGBLIGHT_ENABLE
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGB_RST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif
    case QWERTY:
        if(record->event.pressed){
            set_single_persistent_default_layer(_QWERTY);
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
        break;
    case FUNCK:
      if(record->event.pressed){
        layer_on(_FUNCK);
      }else{
        layer_off(_FUNCK);
      }
      break;
    default:
      result = true;
      break;
  }

  return result;
}

void matrix_init_user(void) {

}
