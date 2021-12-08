#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _WORKMAN 1
#define _WASD 2
#define _NAVI 3
#define _NUMBERS_L 4

bool leading = false;

// enum custom_keycodes {
//   QWERTY = SAFE_RANGE,
//   WORKMAN,
//   WASD,
//   LOWER,
//   RAISE,
//   NAVI,
//   NUMBERS_L,
// };

//Tap Dance Declarations
enum {
   DOWN_UP = 0,
   LEFT_HOME,
   RIGHT_END,
   MIN_ESC,
   END_NAV,
   NINE_BRACK,
   ZERO_BRACK,
   PGUP_WASD,
   PGDN_NUMB,
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
   [DOWN_UP] = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_UP),
   [LEFT_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, KC_HOME),
   [RIGHT_END] = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT, KC_END),
   [MIN_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_ESC),
   [END_NAV] = ACTION_TAP_DANCE_LAYER_MOVE(KC_END, _NAVI),
   [NINE_BRACK] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_LBRACKET),
   [ZERO_BRACK] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_RBRACKET),
   [PGUP_WASD] = ACTION_TAP_DANCE_LAYER_MOVE(KC_PGUP, _WASD),
   [PGDN_NUMB] = ACTION_TAP_DANCE_LAYER_MOVE(KC_PGDN, _NUMBERS_L),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MINS,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_EQL,LSFT_T(KC_A),LCTL_T(KC_S),LWIN_T(KC_D),LALT_T(KC_F), KC_G,           KC_H, RALT_T(KC_J), RWIN_T(KC_K), RCTL_T(KC_L), RSFT_T(KC_SCLN), KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LEAD,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,          XXXXXXX,  KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_LEAD,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_TAB, KC_SPC,   KC_ENT,                   TD(LEFT_HOME), TD(DOWN_UP), TD(RIGHT_END)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_WORKMAN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,                               KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
KC_EQL, LSFT_T(KC_A), LCTL_T(KC_S), LWIN_T(KC_H), LALT_T(KC_T), KC_G,               KC_H, RALT_T(KC_N), RWIN_T(KC_E), RCTL_T(KC_O), RSFT_T(KC_I), KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LEAD, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    XXXXXXX,          XXXXXXX, KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_LEAD,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_TAB,  KC_SPC,   KC_ENT,                 TD(LEFT_HOME), TD(DOWN_UP), TD(RIGHT_END)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_WASD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MINS,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_EQL,LSFT_T(KC_A),LCTL_T(KC_S),LWIN_T(KC_D),LALT_T(KC_F), KC_G,           KC_H, RALT_T(KC_J), RWIN_T(KC_K), RCTL_T(KC_L), RSFT_T(KC_SCLN), KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LEAD,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,          XXXXXXX,  KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_LEAD,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_TAB, KC_SPC,   KC_ENT,                  TD(LEFT_HOME), TD(DOWN_UP), TD(RIGHT_END)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NAVI] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, XXXXXXX,          XXXXXXX, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUMBERS_L] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, XXXXXXX,          XXXXXXX, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case QWERTY:
//       if (record->event.pressed) {
//          switch (biton32(layer_state)) {
//             case _QWERTY:
//                layer_move(_WORKMAN);
//                break;
//             default:
//                layer_move(_QWERTY)
//                break;
//          }
//       }
//       return false;
//       break;
//     case LOWER:
//       if (record->event.pressed) {
//         layer_on(_LOWER);
//       } else {
//         layer_off(_LOWER);
//       }
//       return false;
//       break;
//     case RAISE:
//       if (record->event.pressed) {
//         layer_on(_RAISE);
//       } else {
//         layer_off(_RAISE);
//       }
//       return false;
//       break;
//     case NAVI:
//       layer_invert(_NAVI);
//       return false;
//       break;
//   }
  return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
   if (index == 0) {
      switch (biton32(layer_state)) {
         case _NAVI:
            if (clockwise)
               tap_code(KC_VOLU);
            else
               tap_code(KC_VOLD);
            break;
         default:
            if (clockwise)
               tap_code(KC_VOLU);
            else
               tap_code(KC_VOLD);
      }
    }
    else if (index == 1) {
      switch (biton32(layer_state)) {
         case _QWERTY:
         case _WORKMAN:
            if(clockwise)
               tap_code16(C(KC_TAB));
            else
               tap_code16(C(KC_TAB));
            break;
         default:
            if (clockwise) {
              tap_code16(C(KC_TAB));
            } else {
               tap_code16(C(S(KC_TAB)));
            }
            break;
      }
    }
    return true;
}
#endif

#ifdef LEADER_ENABLE
void matrix_scan_user(void) {
   LEADER_DICTIONARY(){
      leading = false;
      leader_end();

      SEQ_ONE_KEY(KC_1){
         tap_code(KC_F1);
      }

      SEQ_ONE_KEY(KC_2){
         tap_code(KC_F2);
      }

      SEQ_ONE_KEY(KC_3){
         tap_code(KC_F3);
      }

      SEQ_ONE_KEY(KC_4){
         tap_code(KC_F4);
      }

      SEQ_ONE_KEY(KC_5){
         tap_code(KC_F5);
      }

      SEQ_ONE_KEY(KC_6){
         tap_code(KC_F6);
      }

      SEQ_ONE_KEY(KC_7){
         tap_code(KC_F7);
      }

      SEQ_ONE_KEY(KC_8){
         tap_code(KC_F8);
      }

      SEQ_ONE_KEY(KC_9){
         tap_code(KC_F9);
      }

      SEQ_TWO_KEYS(KC_1, KC_0){
         tap_code(KC_F10);
      }

      SEQ_TWO_KEYS(KC_1, KC_1){
         tap_code(KC_F11);
      }

      SEQ_TWO_KEYS(KC_1, KC_2){
         tap_code(KC_F12);
      }

      SEQ_THREE_KEYS(KC_W, KC_A, KC_D){
         layer_invert(_WASD);
      }
   }
}
#endif
