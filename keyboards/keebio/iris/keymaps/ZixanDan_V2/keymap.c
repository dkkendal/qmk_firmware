#include QMK_KEYBOARD_H
#include <stdbool.h>

enum layer_names {
   _QWERTY,
   _WORKMAN,
   // _SINGLE4, // These two layers are ordered this way intentionally
   // _SINGLE5, // These two layers are ordered this way intentionally
   // _SINGLE1,
   // _SINGLE2,
   // _SINGLE3,
   _SINGLEQ4, // These two layers are ordered this way intentionally
   _SINGLEQ5, // These two layers are ordered this way intentionally
   _SINGLEQ1,
   _SINGLEQ2,
   _SINGLEQ3,
   _WASD,
   _MOBA,
   _NAVI,
   _NUMBERS_L,
   _LOWER,
   _RAISE,
   _MODS,
   _LOCKED1,
   _LOCKED2,
   _LOCKED3,
   _LOCKED4,
};

bool leading = false;
bool fixed_rgb = false;
// int home_layer = _QWERTY;

#ifdef RGBLIGHT_ENABLE
int rgb_mode = RGBLIGHT_MODE_SNAKE;
#endif


enum custom_keycodes {
   SHIFT = SAFE_RANGE,
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

enum {
   _SP_ENT,
   _GR_ESC,
   _BS_DEL,
   _MIN_EQS,
   _LRBRC,
   _QUOT_SLS,
   _TAB_TALK,
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
   [_SP_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
   [_GR_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_ESC),
   [_BS_DEL] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_DEL),
   [_MIN_EQS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_EQL),
   [_LRBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
   [_QUOT_SLS] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_BSLS),
   [_TAB_TALK] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, C(KC_BSLS)),
};

// const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
//    {{5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
//    {{5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
//    {{5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
//    {{5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
//    {{5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}},
//    {{5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 5}, {0, 5}},
//    {{5, 6}, {4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6}},
//    {{5, 7}, {4, 7}, {3, 7}, {2, 7}, {1, 7}, {0, 7}},
//    {{5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8}},
//    {{5, 9}, {4, 9}, {3, 9}, {2, 9}, {1, 9}, {0, 9}},
// };

#ifdef COMBO
const uint16_t PROGMEM ZXCV_combo[] = {KC_Z, KC_X, KC_C, KC_V, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  COMBO(ZXCV_combo, SH_OS)
};
#endif

// tapdance defines
#define SP_ENT TD(_SP_ENT)
#define GR_ESC TD(_GR_ESC)
#define BS_DEL TD(_BS_DEL)
#define MIN_EQS TD(_MIN_EQS)
#define LRBRC TD(_LRBRC)
#define QUOT_SLS TD(_QUOT_SLS)
#define TAB_TALK TD(_TAB_TALK)

#define QWERTY TO(_QWERTY)
#define WORKMAN TO(_WORKMAN)
#define WASD TO(_WASD)
#define MOBA TO(_MOBA)
#define LOWER TO(_LOWER)
#define RAISE TO(_RAISE)
#define NAVI TO(_NAVI)
#define NUMBERS_L TO(_NUMBERS_L)
#define SFT_SCLN RSFT_T(KC_SCLN)
#define SFT_I RSFT_T(KC_I)
#define SHIFTY OSM(MOD_LSFT)
#define CTLY OSM(MOD_LCTL)
#define ALTY OSM(MOD_LALT)
#define WINY OSM(MOD_LGUI)
// #define SING1_CTL LM(_SINGLE1, MOD_LCTL)
// #define SING1_ALT LM(_SINGLE1, MOD_LALT)
// #define SING1_GUI LM(_SINGLE1, MOD_LGUI)
// #define SING2_CTL LM(_SINGLE2, MOD_LCTL)
// #define SING2_ALT LM(_SINGLE2, MOD_LALT)
// #define SING2_GUI LM(_SINGLE2, MOD_LGUI)
// #define SINGLE1 TO(_SINGLE1)
// #define SINGLE2 TO(_SINGLE2)
// #define SINGLE3 TO(_SINGLE3)
// #define SINGLE4 TO(_SINGLE4)
// #define SINGLE5 TO(_SINGLE5)
#define SINGQ1_CTL LM(_SINGLEQ1, MOD_LCTL)
#define SINGQ1_ALT LM(_SINGLEQ1, MOD_LALT)
#define SINGQ1_GUI LM(_SINGLEQ1, MOD_LGUI)
#define SINGQ2_CTL LM(_SINGLEQ2, MOD_LCTL)
#define SINGQ2_ALT LM(_SINGLEQ2, MOD_LALT)
#define SINGQ2_GUI LM(_SINGLEQ2, MOD_LGUI)
#define SINGLEQ1 TO(_SINGLEQ1)
#define SINGLEQ2 TO(_SINGLEQ2)
#define SINGLEQ3 TO(_SINGLEQ3)
#define SINGLEQ4 TO(_SINGLEQ4)
#define SINGLEQ5 TO(_SINGLEQ5)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  
      KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   WORKMAN,
  
      KC_MINS,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  
      KC_EQL,   KC_A,    KC_S,    KC_D,    KC_F,   KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,   SFT_SCLN, KC_QUOT,
  
      KC_LBRC,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  XXXXXXX,          XXXXXXX,  KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC,
  
                                   MO(_LOWER), KC_SPC, KC_TAB,                   KC_BSPC, KC_ENT, MO(_RAISE)
                                
  ),

  [_WORKMAN] = LAYOUT(
  
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    QWERTY,
  
     KC_MINS,  KC_Q,    KC_D,    KC_R ,   KC_W,   KC_BSLS,                             KC_J,    KC_F,    KC_U,    KC_P,   KC_SCLN, KC_BSLS,
  
      KC_EQL,  KC_A,    KC_I,    KC_H,    KC_T,    KC_G,                               KC_H,    KC_N,    KC_E,    KC_O,   SFT_I,   KC_QUOT,
  
      KC_LBRC, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,   XXXXXXX,          XXXXXXX,  KC_K,    KC_L,   KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC,
  
                                   MO(_LOWER), KC_SPC, KC_TAB,                   KC_BSPC, KC_ENT, MO(_RAISE)
                                
  ),

//    // base layer for one-handed typing
//   [_SINGLE1] = LAYOUT(
  
//       GR_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    GR_ESC,
  
//       MIN_EQS,  KC_T,    KC_H,    KC_E,    KC_R,    KC_S,                              KC_S,    KC_R,    KC_E,    KC_H,    KC_T,    MIN_EQS,
  
//       SHIFTY,   KC_U,    KC_A,    KC_I,    KC_O,    KC_N,                              KC_N,    KC_O,    KC_I,    KC_A,    KC_U,    SHIFTY,
  
//       BS_DEL,   KC_L,    KC_D,    KC_C,    KC_M,    KC_F,  XXXXXXX,          XXXXXXX,  KC_F,    KC_M,    KC_C,    KC_D,    KC_L,    BS_DEL,
  
//                                  TO(_SINGLE2),SP_ENT,TO(_SINGLE4),             TO(_SINGLE4),SP_ENT,TO(_SINGLE2)
                                
//   ),

//    // secondary layer for one-handed typing
//   [_SINGLE2] = LAYOUT(
  
//       KC_ESC,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ESC,
  
//      QUOT_SLS,  KC_P,    KC_X,    KC_E,    KC_V,    KC_Y,                              KC_Y,    KC_V,    KC_Q,    KC_X,    KC_P,   QUOT_SLS,
  
//       SHIFTY,   KC_K,    KC_W,    KC_Q,    KC_J,    KC_G,                              KC_G,    KC_J,    KC_E,    KC_W,    KC_K,    SHIFTY,
  
//       LRBRC,    KC_Z,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_B,  XXXXXXX,          XXXXXXX,  KC_B,   KC_SLSH,  KC_DOT, KC_COMM,  KC_Z,    LRBRC,
  
//                                  TO(_SINGLE1), KC_SPC, KC_TAB,                    KC_TAB, KC_SPC, TO(_SINGLE1)
                                
//   ),

//    // macro layer for one-handed typing
//   [_SINGLE3] = LAYOUT(
  
//      SINGLE1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SINGLE1,
  
//      XXXXXXX, C(KC_P),  C(KC_W), C(KC_O), C(KC_R), C(KC_Y),                           C(KC_Y), C(KC_R), C(KC_O), C(KC_W), C(KC_P), XXXXXXX,
  
//      XXXXXXX, C(KC_A),  C(KC_S), C(KC_D), C(KC_F), C(KC_H),                           C(KC_H), C(KC_F), C(KC_D), C(KC_S), C(KC_A), XXXXXXX,
  
//      XXXXXXX, C(KC_Z),  C(KC_X), C(KC_C), C(KC_V), C(KC_N), XXXXXXX,         XXXXXXX, C(KC_N), C(KC_V), C(KC_C), C(KC_X), C(KC_Z), XXXXXXX,
  
//                                      ALTY,    SHIFTY,   CTLY,                      CTLY,   SHIFTY,   ALTY
                                
//   ),

//    // nav layer for one-handed typing
//   [_SINGLE4] = LAYOUT(
  
//      XXXXXXX, SINGLE1, SINGLE2, SINGLE3, SINGLE5,  XXXXXXX,                           XXXXXXX, SINGLE5, SINGLE3, SINGLE2, SINGLE1, XXXXXXX,
  
//     SING1_CTL, XXXXXXX, KC_END, KC_PGUP, KC_RIGHT, XXXXXXX,                           XXXXXXX, KC_RIGHT, KC_PGUP, KC_END, XXXXXXX, SING1_CTL,
  
//     SING1_GUI, XXXXXXX, KC_HOME, KC_PGDN, KC_END, XXXXXXX,                            XXXXXXX,  KC_END, KC_PGDN, KC_HOME, XXXXXXX, SING1_GUI,
  
//     SING1_ALT, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,  KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, SING1_ALT,
  
//                                      ALTY,    SHIFTY,   CTLY,                     CTLY,    SHIFTY,   ALTY
                                
//   ),

//    // modifiers layer for one-handed typing
//   [_SINGLE5] = LAYOUT(
  
//    TG(_SINGLE5), KC_1,  KC_2,    KC_3,    KC_4,    KC_5,                               KC_1,    KC_2,    KC_3,    KC_4,    KC_5, TG(_SINGLE5),
  
//     SING2_CTL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   WINY,                              WINY,    KC_F4,   KC_F3,   KC_F2,   KC_F1,  SING2_CTL,
  
//     SING2_GUI,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  SHIFTY,                             SHIFTY,  KC_F4,   KC_F3,   KC_F2,   KC_F1,  SING2_GUI,
  
//     SING2_ALT,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   CTLY,  XXXXXXX,          XXXXXXX,  CTLY,    KC_F4,   KC_F3,   KC_F2,   KC_F1,  SING2_ALT,
  
//                                    ALTY,  MO(_MODS), TO(_SINGLE1),           TO(_SINGLE1), MO(_MODS), ALTY
                                
//   ),

   // base layer for one-handed typing
  [_SINGLEQ1] = LAYOUT(
  
      GR_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    GR_ESC,
  
      MIN_EQS,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    MIN_EQS,
  
      SHIFTY,   KC_A,    KC_S,    KC_D,    KC_F,   KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,   SFT_SCLN, SHIFTY,
  
      BS_DEL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  XXXXXXX,          XXXXXXX,  KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH,    BS_DEL,
  
                                 TO(_SINGLEQ2),SP_ENT,TO(_SINGLEQ4),             TO(_SINGLEQ4),SP_ENT,TO(_SINGLEQ2)
                                
  ),

   // secondary layer for one-handed typing
  [_SINGLEQ2] = LAYOUT(
  
      KC_ESC,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_ESC,
  
     QUOT_SLS,  KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,                              KC_T,    KC_R,    KC_E,    KC_W,    KC_Q,   QUOT_SLS,
  
      SHIFTY, SFT_SCLN,  KC_L,    KC_K,    KC_J,    KC_H,                              KC_G,    KC_F,    KC_D,    KC_S,    KC_A,   SHIFTY,
  
      LRBRC,   KC_SLSH,  KC_DOT,  KC_COMM, KC_M,    KC_N,  XXXXXXX,          XXXXXXX,  KC_B,    KC_V,    KC_C,    KC_X,    KC_Z,   LRBRC,
  
                                 TO(_SINGLEQ1), KC_SPC, KC_TAB,                  KC_TAB, KC_SPC, TO(_SINGLEQ1)
                                
  ),

   // macro layer for one-handed typing
  [_SINGLEQ3] = LAYOUT(
  
     SINGLEQ1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SINGLEQ1,
  
     XXXXXXX, C(KC_P),  C(KC_W), C(KC_O), C(KC_R), C(KC_Y),                           C(KC_Y), C(KC_R), C(KC_O), C(KC_W), C(KC_P), XXXXXXX,
  
     XXXXXXX, C(KC_A),  C(KC_S), C(KC_D), C(KC_F), C(KC_H),                           C(KC_H), C(KC_F), C(KC_D), C(KC_S), C(KC_A), XXXXXXX,
  
     XXXXXXX, C(KC_Z),  C(KC_X), C(KC_C), C(KC_V), C(KC_N), XXXXXXX,         XXXXXXX, C(KC_N), C(KC_V), C(KC_C), C(KC_X), C(KC_Z), XXXXXXX,
  
                                     ALTY,    SHIFTY,   CTLY,                      CTLY,   SHIFTY,   ALTY
                                
  ),

   // nav layer for one-handed typing
  [_SINGLEQ4] = LAYOUT(
  
     XXXXXXX, SINGLEQ1,SINGLEQ2,SINGLEQ3,SINGLEQ5,XXXXXXX,                           XXXXXXX, SINGLEQ5,SINGLEQ3,SINGLEQ2,SINGLEQ1, XXXXXXX,
  
   SINGQ1_CTL, XXXXXXX, KC_END, KC_PGUP, KC_RIGHT, XXXXXXX,                           XXXXXXX, KC_RIGHT, KC_PGUP, KC_END, XXXXXXX, SINGQ1_CTL,
  
   SINGQ1_GUI, XXXXXXX, KC_HOME, KC_PGDN, KC_END, XXXXXXX,                            XXXXXXX,  KC_END, KC_PGDN, KC_HOME, XXXXXXX, SINGQ1_GUI,
  
   SINGQ1_ALT, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,  KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, SINGQ1_ALT,
  
                                     ALTY,    SHIFTY,   CTLY,                     CTLY,    SHIFTY,   ALTY
                                
  ),

   // modifiers layer for one-handed typing
  [_SINGLEQ5] = LAYOUT(
  
   TG(_SINGLEQ5), KC_1,  KC_2,    KC_3,    KC_4,    KC_5,                               KC_1,    KC_2,    KC_3,    KC_4,    KC_5, TG(_SINGLEQ5),
  
   SINGQ2_CTL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   WINY,                              WINY,    KC_F4,   KC_F3,   KC_F2,   KC_F1,  SINGQ2_CTL,
  
   SINGQ2_GUI,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  SHIFTY,                             SHIFTY,  KC_F4,   KC_F3,   KC_F2,   KC_F1,  SINGQ2_GUI,
  
   SINGQ2_ALT,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   CTLY,  XXXXXXX,          XXXXXXX,  CTLY,    KC_F4,   KC_F3,   KC_F2,   KC_F1,  SINGQ2_ALT,
  
                                  ALTY,  MO(_MODS), TO(_SINGLEQ1),          TO(_SINGLEQ1), MO(_MODS), ALTY
                                
  ),

  [_WASD] = LAYOUT(
  
      KC_ESC, XXXXXXX,  KC_1,     KC_2,    KC_3,    KC_4,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
     XXXXXXX, XXXXXXX,  KC_Q,     KC_W,    KC_E,    KC_R,                            SAY_YEET, SAY_BOOM, SAY_NS, SAY_OOPS, SAY_EH, XXXXXXX,
  
     XXXXXXX, XXXXXXX,  KC_A,     KC_S,    KC_D,    KC_F,                             SAY_TY,  SAY_GG,  SAY_WP, SAY_LOL,  SAY_GTG, XXXXXXX,
  
     XXXXXXX, XXXXXXX,  KC_Z,     KC_X,    KC_C,    KC_V,  XXXXXXX,          XXXXXXX, XXXXXXX, SAY_GGS,  SAY_OH, SAY_XD,   SAY_BRB, XXXXXXX,
  
                                    KC_LCTL,  KC_SPC, TAB_TALK,                  KC_LSFT, TG(_WASD), XXXXXXX
                                
  ),

  [_MOBA] = LAYOUT(
  
     KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
      KC_Y,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                              XXXXXXX, SAY_GG,  SAY_WP,  SAY_LOL, XXXXXXX, XXXXXXX,
  
     KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
                                    KC_LCTL,  KC_SPC, KC_LALT,                   KC_LSFT, TG(_MOBA), XXXXXXX
                                
  ),

  [_NAVI] = LAYOUT(
  
   TG(_NAVI), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX,
  
     XXXXXXX, KC_LSFT, KC_LCTL, KC_LWIN, KC_LALT, XXXXXXX,                            KC_BTN3, KC_MS_U, KC_MS_D, KC_MS_L, KC_MS_R, XXXXXXX,
  
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  XXXXXXX,
  
                                    MO(_LOWER), KC_SPC, KC_TAB,                  KC_BTN2, KC_BTN1, _______
                                
  ),

  [_NUMBERS_L] = LAYOUT(
  
TG(_NUMBERS_L),XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,  KC_PEQL, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX,
  
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,   KC_7,   KC_8,    KC_9,    KC_PPLS, XXXXXXX,
  
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,   KC_4,   KC_5,    KC_6,    KC_PENT, XXXXXXX,
  
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,   KC_0,   KC_1,   KC_2,    KC_3,    KC_PDOT, XXXXXXX,
  
                                    MO(_LOWER), KC_SPC, KC_TAB,                  KC_BSPC, KC_ENT, MO(_RAISE)
                                
  ),

  [_LOCKED1] = LAYOUT(
  
     RGB_HUI, RGB_HUD, RGB_HUI, RGB_HUD, RGB_HUI, RGB_HUD,                      RGB_HUD, RGB_HUI, RGB_HUD, RGB_HUI, RGB_HUD, RGB_HUI,
  
    RGB_HUI, RGB_HUD, RGB_HUI, RGB_HUD,MO(_LOCKED2),RGB_HUD,                     RGB_HUD, RGB_HUI, RGB_HUD, RGB_HUI, RGB_HUD, RGB_HUI,
  
     RGB_HUI, RGB_HUD, RGB_HUI, RGB_HUD, RGB_HUI, RGB_HUD,                      RGB_HUD, RGB_HUI, RGB_HUD, RGB_HUI, RGB_HUD, RGB_HUI,
  
     RGB_HUI, RGB_HUD, RGB_HUI, RGB_HUD, RGB_HUI, RGB_HUD, XXXXXXX,    XXXXXXX, RGB_HUD, RGB_HUI, RGB_HUD, RGB_HUI, RGB_HUD, RGB_HUI,
  
                                    RGB_M_K, RGB_HUD, RGB_HUI,                 RGB_HUI, RGB_HUD, RGB_M_K
                                
  ),

  [_LOCKED2] = LAYOUT(
  
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, MO(_LOCKED3), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
                                    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
                                
  ),

  [_LOCKED3] = LAYOUT(
  
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
                                    XXXXXXX, XXXXXXX, MO(_LOCKED4),              XXXXXXX, XXXXXXX, XXXXXXX
                                
  ),

  [_LOCKED4] = LAYOUT(
  
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
                                    XXXXXXX, XXXXXXX, XXXXXXX,               TO(_QWERTY),TO(_WORKMAN),XXXXXXX
                                
  ),

  [_LOWER] = LAYOUT(
  
     KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
     KC_GRV,  SHIFTY,  CTLY,    WINY,     ALTY,  XXXXXXX,                            XXXXXXX, XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX,
  
     SHIFT,   KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_MPLY,                            KC_MPLY, KC_HOME,  KC_PGDN, KC_END, XXXXXXX, XXXXXXX,
  
     XXXXXXX,  SH_TG,  SH_TG,   KC_MEH,  KC_HYPR, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
                                   TG(_LOWER), XXXXXXX, XXXXXXX,                 KC_BSPC, XXXXXXX, MO(_MODS)
                                
  ),
 
  [_RAISE] = LAYOUT(
  
     KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
     KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  XXXXXXX,                       XXXXXXX,OSM(MOD_RALT),OSM(MOD_RGUI),OSM(MOD_RCTL),OSM(MOD_RSFT), XXXXXXX,
  
     KC_CAPS,  KC_F5,   KC_F6,   KC_F7,   KC_F8,  XXXXXXX,                            KC_MPLY, KC_RALT, KC_RGUI, KC_RCTL, KC_RSFT, XXXXXXX,
  
     XXXXXXX,  KC_F9,   KC_F10,  KC_F11,  KC_F12, XXXXXXX,  XXXXXXX,         XXXXXXX, XXXXXXX, KC_HYPR, KC_MEH,  SH_TG,   SH_TG, XXXXXXX,
  
                                   MO(_MODS), KC_LCTL, KC_LALT,                  XXXXXXX, XXXXXXX, TG(_RAISE)
                                
  ),

  [_MODS] = LAYOUT(
  
   TO(_LOCKED1),XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
     XXXXXXX,  QWERTY, WORKMAN, SINGLEQ1,  RGB_TOG, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
     XXXXXXX,  NAVI,  NUMBERS_L, WASD,    MOBA,    XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  
                                    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
                                
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   if(record->event.pressed){
      switch (keycode) {
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
         #ifdef RGBLIGHT_ENABLE
         case _LOCKED1:
         case _LOCKED2:
         case _LOCKED3:
         case _LOCKED4:
            if (clockwise)
               rgblight_increase_hue_noeeprom();
            else
               rgblight_decrease_hue_noeeprom();
            break;
         #endif
         case _NAVI:
            if (clockwise)
               tap_code(KC_WH_L);
            else
               tap_code(KC_WH_R);
            break;
         case _QWERTY:
         case _WORKMAN:
         case _WASD:
         case _MOBA:
         case _NUMBERS_L:
         case _LOWER:
         case _RAISE:
         case _MODS:
         default:
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
         #ifdef RGBLIGHT_ENABLE
         case _LOCKED1:
         case _LOCKED2:
         case _LOCKED3:
         case _LOCKED4:
            if (clockwise)
               rgblight_increase_val_noeeprom();
            else
               rgblight_decrease_val_noeeprom();
            break;
         #endif
         case _NAVI:
            if (clockwise)
               tap_code(KC_WH_D);
            else
               tap_code(KC_WH_U);
            break;
         case _QWERTY:
         case _WORKMAN:
         case _WASD:
         case _MOBA:
         case _NUMBERS_L:
         case _LOWER:
         case _RAISE:
         case _MODS:
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

#ifdef RGBLIGHT_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
   if (!fixed_rgb)
      rgb_mode = rgblight_get_mode();
   
   fixed_rgb = true;

   switch (get_highest_layer(state)) {
      case _WASD:
      case _MOBA:
         rgblight_sethsv_noeeprom(HSV_RED);
         break;
      case _NUMBERS_L:
         rgblight_sethsv_noeeprom(HSV_MAGENTA);
         break;
      default: //  for any other layers, or the default layer
         if (fixed_rgb){
            fixed_rgb = false;
            rgblight_mode_noeeprom(rgb_mode);
         }
         break;
    }
  return state;
}
#endif