#include QMK_KEYBOARD_H

enum layer_names {
   _QWERTY,
   _LOWER,
   _RAISE,
   _MODS,
};

bool leading = false;
int target = -1;

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};

const uint16_t PROGMEM zxcv_combo[] = {KC_Z, KC_X, KC_C, KC_V, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  COMBO(zxcv_combo, KC_MPLY)
};

const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
   {{5, 9}, {4, 9}, {3, 9}, {2, 9}, {1, 9}, {0, 9}},
   {{5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8}},
   {{5, 7}, {4, 7}, {3, 7}, {2, 7}, {1, 7}, {0, 7}},
   {{5, 6}, {4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6}},
   {{5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 5}, {0, 5}},
   {{5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}},
   {{5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
   {{5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
   {{5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
   {{5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_MINS,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_EQL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,    KC_J,    KC_K,   KC_L, RSFT_T(KC_SCLN), KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LBRC,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   XXXXXXX,         XXXXXXX,  KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   MO(_LOWER), KC_SPC, KC_TAB,                   KC_BSPC, KC_ENT, MO(_RAISE)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX,                            XXXXXXX, XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_MPLY,                            KC_MPLY, KC_HOME,  KC_PGDN, KC_END, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, SH_TG,   SH_TG,   KC_MEH,  KC_HYPR, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
 
  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  XXXXXXX,                            XXXXXXX, KC_RALT, KC_RGUI, KC_RCTL, KC_RSFT, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS,  KC_F5,   KC_F6,   KC_F7,   KC_F8,  XXXXXXX,                            KC_MPLY, KC_RALT, KC_RGUI, KC_RCTL, KC_RSFT, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX,  KC_F9,   KC_F10,  KC_F11,  KC_F12, XXXXXXX,  XXXXXXX,         XXXXXXX, XXXXXXX, KC_HYPR, KC_MEH,  SH_TG,   SH_TG, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, KC_LCTL, KC_LALT,                   XXXXXXX, XXXXXXX, XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
   if (index == 0) {
      // Left encoder
      switch (biton32(layer_state)) {
         default:
            if (clockwise) {
               tap_code(KC_DOWN);
            } else {
               tap_code(KC_UP);
            }
      }
    }
    else if (index == 1) {
      // Right encoder
      switch (biton32(layer_state)) {
         default:
            if (clockwise) {
               tap_code(KC_RIGHT);
            } else {
               tap_code(KC_LEFT);
            }
            break;
      }
    }
    return true;
}
#endif
