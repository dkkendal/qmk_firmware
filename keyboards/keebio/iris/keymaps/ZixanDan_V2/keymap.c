#include QMK_KEYBOARD_H

enum layer_names {
   _QWERTY,
   _WORKMAN,
   _CHORDS,
   _WASD,
   _MOBA,
   _NAVI,
   _NUMBERS_L,
   _LOWER,
   _RAISE,
   _NORTH,
   _SOUTH,
   _EAST,
   _WEST,
   _MODS,
   _LOCKED1,
   _LOCKED2,
   _LOCKED3,
   _LOCKED4,
};

bool leading = false;
int home_layer = _QWERTY;

enum custom_keycodes {
   QWERTY = SAFE_RANGE,
   WORKMAN,
   WASD,
   LOWER,
   RAISE,
   NAVI,
   NUMBERS_L,
   SHIFT,
   SAY_BOOM,
   SAY_GG,
   SAY_GGS,
   SAY_WP,
   SAY_NS,
   SAY_GTG,
   SAY_OOPS,
   SAY_LOL,
   SAY_XD,
   SAY_EH,
   SAY_BRB,
   SAY_OH,
   SAY_DARN,
   SAY_YEET,
   SAY_TY,
};

#ifdef TAP_DANCE
typedef enum {
   TD_NONE,
   TD_UNKNOWN,
   TD_SINGLE_TAP,
   TD_SINGLE_HOLD,
   TD_DOUBLE_TAP,
   TD_DOUBLE_HOLD,
   TD_DOUBLE_SINGLE_TAP, // Send two single taps
   TD_TRIPLE_TAP,
   TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
   bool is_press_action;
   td_state_t state;
} td_tap_t;

td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the lock tap dance. Put it here so it can be used in any keymap
void lock_finished(qk_tap_dance_state_t *state, void *user_data);
void lock_reset(qk_tap_dance_state_t *state, void *user_data);

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
   [W_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_HOME),
   [O_END] = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_END),
   [E_UP] = ACTION_TAP_DANCE_DOUBLE(KC_E, KC_UP),
   [R_DOWN] = ACTION_TAP_DANCE_DOUBLE(KC_R, KC_DOWN),
   [U_LEFT] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_LEFT),
   [I_RIGHT] = ACTION_TAP_DANCE_DOUBLE(KC_I, KC_RIGHT),
   [D_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_D, KC_HOME),
   [P_END] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_END),
   [R_UP] = ACTION_TAP_DANCE_DOUBLE(KC_R, KC_UP),
   [W_DOWN] = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_DOWN),
   [F_LEFT] = ACTION_TAP_DANCE_DOUBLE(KC_F, KC_LEFT),
   [U_RIGHT] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_RIGHT),
};
#endif

const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
   {{5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
   {{5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
   {{5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
   {{5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
   {{5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}},
   {{5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 5}, {0, 5}},
   {{5, 6}, {4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6}},
   {{5, 7}, {4, 7}, {3, 7}, {2, 7}, {1, 7}, {0, 7}},
   {{5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8}},
   {{5, 9}, {4, 9}, {3, 9}, {2, 9}, {1, 9}, {0, 9}},
};

#ifdef COMBO
const uint16_t PROGMEM ZXCV_combo[] = {KC_Z, KC_X, KC_C, KC_V, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  COMBO(ZXCV_combo, SH_OS)
};
#endif

#define TD_WH TD(W_HOME)
#define TD_OE TD(O_END)
#define TD_EU TD(E_UP)
#define TD_RD TD(R_DOWN)
#define TD_UL TD(U_LEFT)
#define TD_IR TD(I_RIGHT)
#define RD_DH TD(D_HOME)
#define TD_RU TD(R_UP)
#define TD_WD TD(W_DOWN)
#define RD_FL TD(F_LEFT)
#define TD_UR TD(U_RIGHT)
#define TD_PE TD(P_END)
#define SFT_A LSFT_T(KC_A)
#define CTL_S LCTL_T(KC_S)
#define WIN_D LWIN_T(KC_D)
#define ALT_F LALT_T(KC_F)
#define ALT_J RALT_T(KC_J)
#define WIN_K RWIN_T(KC_K)
#define CTL_L RCTL_T(KC_L)
#define SFT_SCLN RSFT_T(KC_SCLN)
#define CTL_I LCTL_T(KC_I)
#define WIN_H LWIN_T(KC_H)
#define TALT_T LALT_T(KC_T)
#define ALT_N RALT_T(KC_N)
#define WIN_E RWIN_T(KC_E)
#define CTL_O RCTL_T(KC_O)
#define SFT_I RSFT_T(KC_I)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   WORKMAN,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_MINS,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_EQL,   KC_A,    KC_S,    KC_D,    KC_F,   KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,   SFT_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LBRC,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  XXXXXXX,          XXXXXXX,  KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   MO(_LOWER), KC_SPC, KC_TAB,                   KC_BSPC, KC_ENT, MO(_RAISE)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_WORKMAN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    QWERTY,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MINS,  KC_Q,    KC_D,    KC_R ,   KC_W,   KC_BSLS,                             KC_J,    KC_F,    KC_U,    KC_P,   KC_SCLN, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_EQL,  KC_A,    KC_I,    KC_H,    KC_T,    KC_G,                               KC_H,    KC_N,    KC_E,    KC_O,   SFT_I,   KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LBRC, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,   XXXXXXX,          XXXXXXX,  KC_K,    KC_L,   KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   MO(_LOWER), KC_SPC, KC_TAB,                   KC_BSPC, KC_ENT, MO(_RAISE)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_CHORDS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  TG(_CHORDS),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_MINS, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______,  KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_EQL,  _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______,  KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LBRC, _______, _______, _______, _______, _______, XXXXXXX,         XXXXXXX, _______, _______, _______, _______, _______,  KC_RBRC,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   MO(_LOWER), KC_SPC, KC_TAB,                   KC_BSPC, KC_ENT, MO(_RAISE)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_WASD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_ESC, XXXXXXX,  KC_1,     KC_2,    KC_3,    KC_4,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX,  KC_Q,     KC_W,    KC_E,    KC_R,                            SAY_YEET, SAY_BOOM, SAY_NS, SAY_OOPS, SAY_EH, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX,  KC_A,     KC_S,    KC_D,    KC_F,                             SAY_TY,  SAY_GG,  SAY_WP, SAY_LOL,  SAY_GTG, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX,  KC_Z,     KC_X,    KC_C,    KC_V,  XXXXXXX,          XXXXXXX, XXXXXXX, SAY_GGS,  SAY_OH, SAY_XD,   SAY_BRB, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LCTL,  KC_SPC,  KC_TAB,                  KC_LSFT, TG(_WASD), XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MOBA] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_Y,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LALT,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                              XXXXXXX, SAY_GG,  SAY_WP,  SAY_LOL, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LCTL,  KC_SPC,  KC_TAB,                   KC_LSFT, TG(_MOBA), XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NAVI] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   TG(_NAVI), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_LSFT, KC_LCTL, KC_LWIN, KC_LALT, XXXXXXX,                            KC_BTN3, KC_MS_U, KC_MS_D, KC_MS_L, KC_MS_R, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    MO(_LOWER), KC_SPC, KC_TAB,                  KC_BTN2, KC_BTN1, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUMBERS_L] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
TG(_NUMBERS_L),XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,  KC_PEQL, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,   KC_7,   KC_8,    KC_9,    KC_PPLS, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,   KC_4,   KC_5,    KC_6,    KC_PENT, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,   KC_0,   KC_1,   KC_2,    KC_3,    KC_PDOT, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    MO(_LOWER), KC_SPC, KC_TAB,                  KC_BSPC, KC_ENT, MO(_RAISE)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOCKED1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RGB_M_SW, RGB_M_SN, RGB_M_SW, RGB_M_SN, RGB_M_SW, RGB_M_SN,                      RGB_M_SN, RGB_M_SW, RGB_M_SN, RGB_M_SW, RGB_M_SN, RGB_M_SW,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    RGB_M_SW, RGB_M_SN, RGB_M_SW, RGB_M_SN,MO(_LOCKED2),RGB_M_SN,                     RGB_M_SN, RGB_M_SW, RGB_M_SN, RGB_M_SW, RGB_M_SN, RGB_M_SW,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_M_SW, RGB_M_SN, RGB_M_SW, RGB_M_SN, RGB_M_SW, RGB_M_SN,                      RGB_M_SN, RGB_M_SW, RGB_M_SN, RGB_M_SW, RGB_M_SN, RGB_M_SW,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_M_SW, RGB_M_SN, RGB_M_SW, RGB_M_SN, RGB_M_SW, RGB_M_SN, XXXXXXX,    XXXXXXX, RGB_M_SN, RGB_M_SW, RGB_M_SN, RGB_M_SW, RGB_M_SN, RGB_M_SW,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    RGB_M_K, RGB_M_SN, RGB_M_SW,                 RGB_M_SW, RGB_M_SN, RGB_M_K
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOCKED2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, MO(_LOCKED3), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOCKED3] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, MO(_LOCKED4),              XXXXXXX, XXXXXXX, XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOCKED4] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, XXXXXXX,               TO(_QWERTY),TO(_WORKMAN),XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
XXXXXXX,OSM(KC_LSFT),OSM(MOD_LCTL),OSM(MOD_LGUI),OSM(MOD_LALT),XXXXXXX,               XXXXXXX, XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     SHIFT,   KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_MPLY,                            KC_MPLY, KC_HOME,  KC_PGDN, KC_END, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX,  SH_TG,  SH_TG,   KC_MEH,  KC_HYPR, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                 TG(_LOWER),TT(_NORTH),TT(_SOUTH),               KC_BSPC, XXXXXXX, MO(_MODS)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
 
  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  XXXXXXX,                      XXXXXXX,OSM(MOD_RALT),OSM(MOD_RGUI),OSM(MOD_RCTL),OSM(MOD_RSFT), XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS,  KC_F5,   KC_F6,   KC_F7,   KC_F8,  XXXXXXX,                            KC_MPLY, KC_RALT, KC_RGUI, KC_RCTL, KC_RSFT, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX,  KC_F9,   KC_F10,  KC_F11,  KC_F12, XXXXXXX,  XXXXXXX,         XXXXXXX, XXXXXXX, KC_HYPR, KC_MEH,  SH_TG,   SH_TG, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   MO(_MODS), KC_LCTL, KC_LALT,                TT(_EAST),TT(_WEST),TG(_RAISE)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NORTH] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX,TG(_NORTH), XXXXXXX,                 XXXXXXX, XXXXXXX, XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SOUTH] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX,TG(_SOUTH),                 XXXXXXX, XXXXXXX, XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_EAST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, XXXXXXX,                  TG(_EAST), XXXXXXX, XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_WEST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,TG(_WEST), XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MODS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   TO(_LOCKED1),XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
XXXXXXX,TO(_QWERTY),TO(_WORKMAN),XXXXXXX, RGB_TOG, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  XXXXXXX,TO(_NAVI),TO(_NUMBERS_L),TO(_WASD),TO(_MOBA),XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   if(record->event.pressed){
      switch (keycode) {
         case QWERTY:
            home_layer = _QWERTY;
            layer_move(_QWERTY);
            return false;
            break;
         case WORKMAN:
            home_layer = WORKMAN;
            layer_move(_WORKMAN);
            return false;
            break;
         case SHIFT:
            if(get_mods() & MOD_MASK_SHIFT){
               del_mods(MOD_MASK_SHIFT);
            }
            else {
               add_mods(MOD_MASK_SHIFT);
            }
            return false;
            break;
         case SAY_BOOM:
            tap_code(KC_ENT);
            SEND_STRING("boom");
            tap_code(KC_ENT);
            return false;
            break;
         case SAY_GG:
            tap_code(KC_ENT);
            unregister_code(KC_LSFT);
            SEND_STRING("gg");
            tap_code(KC_ENT);
            return false;
            break;
         case SAY_GGS:
            tap_code(KC_ENT);
            unregister_code(KC_LSFT);
            SEND_STRING("ggs");
            tap_code(KC_ENT);
            return false;
            break;
         case SAY_WP:
            tap_code(KC_ENT);
            SEND_STRING("wp");
            tap_code(KC_ENT);
            return false;
            break;
         case SAY_NS:
            tap_code(KC_ENT);
            SEND_STRING("ns");
            tap_code(KC_ENT);
            return false;
            break;
         case SAY_GTG:
            tap_code(KC_ENT);
            SEND_STRING("gtg");
            tap_code(KC_ENT);
            return false;
            break;
         case SAY_OOPS:
            tap_code(KC_ENT);
            unregister_code(KC_LSFT);
            SEND_STRING("oops");
            tap_code(KC_ENT);
            return false;
            break;
         case SAY_LOL:
            tap_code(KC_ENT);
            SEND_STRING("lol");
            tap_code(KC_ENT);
            return false;
            break;
         case SAY_BRB:
            tap_code(KC_ENT);
            SEND_STRING("brb");
            tap_code(KC_ENT);
            return false;
            break;
         case SAY_OH:
            tap_code(KC_ENT);
            SEND_STRING(":O");
            tap_code(KC_ENT);
            return false;
            break;
         case SAY_EH:
            tap_code(KC_ENT);
            unregister_code(KC_LSFT);
            SEND_STRING(":/");
            tap_code(KC_ENT);
            return false;
            break;
         case SAY_XD:
            tap_code(KC_ENT);
            unregister_code(KC_LSFT);
            SEND_STRING("xD");
            tap_code(KC_ENT);
            return false;
            break;
         case SAY_YEET:
            tap_code(KC_ENT);
            SEND_STRING("yeet");
            tap_code(KC_ENT);
            return false;
            break;
         case SAY_TY:
            tap_code(KC_ENT);
            SEND_STRING("ty");
            tap_code(KC_ENT);
            return false;
            break;
      }
   }
   return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
   if (index == 0) {
      // Left encoder
      switch (biton32(layer_state)) {
         case _LOCKED1:
         case _LOCKED2:
         case _LOCKED3:
         case _LOCKED4:
            if (clockwise)
               rgblight_step_noeeprom();
            else
               rgblight_step_reverse_noeeprom();
            break;
         case _NAVI:
            if (clockwise)
               tap_code(KC_WH_L);
            else
               tap_code(KC_WH_R);
            break;
         case _QWERTY:
         case _WORKMAN:
         case _CHORDS:
         case _WASD:
         case _MOBA:
         case _NUMBERS_L:
         case _LOWER:
         case _RAISE:
         case _MODS:
            if (clockwise) {
               tap_code(KC_DOWN);
            } else {
               tap_code(KC_UP);
            }
            break;
      }
    }
    else if (index == 1) {
      // Right encoder
      switch (biton32(layer_state)) {
         case _LOCKED1:
         case _LOCKED2:
         case _LOCKED3:
         case _LOCKED4:
            if (clockwise)
               rgblight_increase_hue_noeeprom();
            else
               rgblight_decrease_hue_noeeprom();
            break;
         case _NAVI:
            if (clockwise)
               tap_code(KC_WH_D);
            else
               tap_code(KC_WH_U);
            break;
         case _QWERTY:
         case _WORKMAN:
         case _CHORDS:
         case _WASD:
         case _MOBA:
         case _NUMBERS_L:
         case _LOWER:
         case _RAISE:
         case _MODS:
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

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _CHORDS:
        combo_enable();
        break;
    default: //  for any other layers, or the default layer
        combo_disable();
        break;
    }
  return state;
}
