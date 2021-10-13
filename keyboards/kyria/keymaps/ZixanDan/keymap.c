/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include <config.h>

uint16_t copy_paste_timer;

enum layers {
    WORKMAN = 0,
    NUMBERS,
    NAV,
    QWERTY,
    WASD,
    FKEYS
};

enum custom_keycodes {
    KC_CCCV = SAFE_RANGE
};

//Tap Dance Declarations
enum {
    HOME_QWERTY = 0,
    MIN_ESC,
    END_NAV,
    NINE_BRACK,
    ZERO_BRACK,
    PGUP_WASD,
    PGDN_NUMB,
    R_T,
    F_G,
    V_B,
    F1_TD,
    F2_TD,
    F3_TD,
    F4_TD,
    F5_TD,
    F6_TD,
    F7_TD,
    F8_TD,
    F9_TD,
    F10_TD,
    F11_TD,
    F12_TD
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [HOME_QWERTY] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_LBRC),
  [MIN_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_ESC),
  [END_NAV] = ACTION_TAP_DANCE_LAYER_MOVE(KC_END, NAV),
  [NINE_BRACK] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_LBRACKET),
  [ZERO_BRACK] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_RBRACKET),
  [PGUP_WASD] = ACTION_TAP_DANCE_LAYER_MOVE(KC_PGUP, WASD),
  [PGDN_NUMB] = ACTION_TAP_DANCE_LAYER_MOVE(KC_PGDN, NUMBERS),
  [R_T] = ACTION_TAP_DANCE_DOUBLE(KC_R, KC_T),
  [F_G] = ACTION_TAP_DANCE_DOUBLE(KC_F, KC_G),
  [V_B] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_B),
  [F1_TD] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1),
  [F2_TD] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2),
  [F3_TD] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3),
  [F4_TD] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4),
  [F5_TD] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5),
  [F6_TD] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_F6),
  [F7_TD] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_F7),
  [F8_TD] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_F8),
  [F9_TD] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_F9),
  [F10_TD] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_F10),
  [F11_TD] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_F11),
  [F12_TD] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_F12)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * WORKMAN Layer: custom workman layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Home/QWERTY |   Q  |  D   |  R   |  W   |  B   |                              |   J  |   F  |   U  |   P  | ;  : |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | - / Esc     |   A  |  S   |  H   |  T   |  G   |                              |   Y  |   N  |   E  |   O  |   I  |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | End/NAV     |   Z  |  X   |  M   |  C   |  V   | ( [ {| Del  |  | Del  | ) ] }|   K  |   L  | ,  < | . >  | /  ? |  - _   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Win  | Lead | Shift| Tab  |Layers|  | Bspc | Space| Shift| Lead |      |
 *                        |      |      |      |      |      |  |      | Nav  |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [WORKMAN] = LAYOUT(
      TD(HOME_QWERTY),   KC_Q,         KC_D,          KC_R,         KC_W,         KC_B,                                                  KC_J, KC_F,         KC_U,         KC_P,          KC_SCLN,         TD(PGUP_WASD),
      TD(MIN_ESC),       LSFT_T(KC_A), LCTL_T(KC_S),  LWIN_T(KC_H), LALT_T(KC_T), KC_G,                                                  KC_Y, RALT_T(KC_N), RWIN_T(KC_E), RCTL_T(KC_O),  RSFT_T(KC_I),    KC_QUOT,
      TD(END_NAV),       KC_Z,         KC_X,          KC_M,         KC_C,         KC_V, TD(NINE_BRACK), KC_BSLS, KC_DEL, TD(ZERO_BRACK), KC_N, KC_M,         KC_COMM,      KC_DOT,        KC_SLSH,         TD(PGDN_NUMB),
                                                                    MO(NUMBERS),   KC_LEAD,      KC_TAB,       MT(MOD_LSFT, KC_SPC), MT(MOD_LALT, KC_ENT), KC_BSPC, MT(MOD_LSFT, KC_SPC), KC_ENT, KC_LEAD, KC_GRV
    ),
/*
 * FKeys Layer: FKEYS -- move to other layers
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | Lead |      |      |      |  |      |      |      | Lead |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [FKEYS] = LAYOUT(
      _______, KC_F1, KC_F2,         KC_F3,         KC_F4,         _______,                                     _______, KC_F13,         KC_F14,         KC_F15,         KC_F16, _______,
      _______, KC_F5, LCTL_T(KC_F6), LWIN_T(KC_F7), LALT_T(KC_F8), _______,                                     _______, LALT_T(KC_F17), LWIN_T(KC_F18), LCTL_T(KC_F19), KC_F20, _______,
      _______, KC_F9, KC_F10,        KC_F11,        KC_F12,        _______, _______, _______, _______, _______, _______, KC_F21,         KC_F22,         KC_F23,         KC_F24, _______,
                            _______, KC_LEAD, _______, _______, _______, _______, _______, _______, KC_LEAD, _______
    ),
/*
 * Number Layer: Numpad, Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      | VolUp|      |      |                              | / ?  | 7 &  | 8 *  | 9 (  | - _  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | Prev | Play | Next |      |                              | *    | 4 $  | 5 %  | 6 ^  | , <  | +      |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      | VolDn| Mute |      |      |      |  |      |      | 0 )  | 1 !  | 2 @  | 3 #  | = +  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |Ctrl/Spc|    |  |      |      |      |      |      |
 *                        |      |      | Lower|      |      |  |      | Nav  | Raise|      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [NUMBERS] = LAYOUT(
      _______, _______, _______, KC_UP,   _______, _______,                                     KC_SLSH, KC_7,    KC_8,    KC_9, KC_MINS, _______,
      _______, _______, KC_LEFT, KC_DOWN, KC_LEFT, _______,                                     KC_ASTR, KC_4,    KC_5,    KC_6, KC_PLUS, KC_COMMA,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3, KC_EQL,  _______,
                                 _______, KC_LEAD, _______, _______, _______, _______, KC_LCTL, _______, KC_LEAD, _______
    ),
/*
 * Nav Layer: Arrows, mouse and other navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  |   |                              |      |  _   |  €   |      |      |  \     |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |                              |   +  |  -   |  /   |  *   |  %   |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |  ~   |      |      |  |      |      |   &  |  =   |  ,   |  .   |  / ? | - _    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      | Lower|      |      |  |      | Nav  | Raise|      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [NAV] = LAYOUT(
      _______, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                     KC_NO, KC_WH_R, KC_MS_U, KC_WH_U, KC_NO, _______,
      _______, KC_NO, KC_ACL0, KC_ACL1, KC_ACL2, KC_NO,                                     KC_NO, KC_MS_L, KC_BTN3, KC_MS_R, KC_NO, _______,
      _______, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _______, _______, _______, _______, KC_NO, KC_WH_L, KC_MS_D, KC_WH_D, KC_NO, _______,
                                 _______, KC_LEAD, KC_BTN1, KC_BTN2, _______, _______, _______, _______, KC_LEAD, _______
    ),
/*
 * QWERTY Layer: custom workman layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | ESC    |   Q  |  D   |  R   |  W   |  B   |                              |   J  |   F  |   U  |   P  | ;  : |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LSFT   |   A  |  S   |  H   |  T   |  G   |                              |   Y  |   N  |   E  |   O  |   I  |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCTL   |   Z  |  X   |  M   |  C   |  V   | ( [ {| Del  |  | Del  | ) ] }|   K  |   L  | ,  < | . >  | /  ? |  - _   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | Lead | Shift| Tab  |Layers|  | Bspc | Space| Shift| Lead |      |
 *                        |      |      |      |      |      |  |      | Nav  |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [QWERTY] = LAYOUT(
      _______, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
      _______, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
      _______, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B, _______, _______, _______, _______,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
              _______, KC_LEAD, _______, _______, _______, _______, _______, _______, KC_LEAD, _______
    ),
/*
 * WASD Layer: Shifted QWERTY layout for WASD controlled games
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | ESC    |   Q  |  D   |  R   |  W   |  B   |                              |   J  |   F  |   U  |   P  | ;  : |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LSFT   |   A  |  S   |  H   |  T   |  G   |                              |   Y  |   N  |   E  |   O  |   I  |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCTL   |   Z  |  X   |  M   |  C   |  V   | ( [ {| Del  |  | Del  | ) ] }|   K  |   L  | ,  < | . >  | /  ? |  - _   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | Lead | Shift| Tab  |Layers|  | Bspc | Space| Shift| Lead |      |
 *                        |      |      |      |      |      |  |      | Nav  |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [WASD] = LAYOUT(
      _______, KC_ESC,  KC_Q, KC_W, KC_E, TD(R_T),                                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_PIPE,
      _______, KC_LSFT, KC_A, KC_S, KC_D, TD(F_G),                                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      _______, KC_LCTL, KC_Z, KC_X, KC_C, TD(V_B), _______, _______, _______, _______,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
              _______, KC_LEAD, _______, _______, _______, _______, _______, _______, KC_LEAD, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};



#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("       Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case NAV:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)    ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)   ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (biton32(layer_state)) {
            case QWERTY:
                // History scrubbing. For Adobe products, hold shift while moving
                // backward to go forward instead.
                if (clockwise) {
                    tap_code16(C(KC_Z));
                } else {
                    tap_code16(C(KC_Y));
                }
                break;
            default:
                // Switch between windows on Windows with alt tab.
                if (clockwise) {
                    if (!is_alt_tab_active) {
                        is_alt_tab_active = true;
                        register_code(KC_LALT);
                    }
                    alt_tab_timer = timer_read();
                    tap_code16(KC_TAB);
                } else {
                    tap_code16(S(KC_TAB));
                }
                break;
        }
    } else if (index == 1) {
        switch (biton32(layer_state)) {
            case QWERTY:
                // Scrolling with PageUp and PgDn.
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            default:
                // Volume control.
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
        }
    }
    return true;
}
#endif
