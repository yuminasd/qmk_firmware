#include QMK_KEYBOARD_H
#define ______ KC_TRNS


enum custom_keycodes {
  //MAPLE
  DPRIGHT = SAFE_RANGE,
  DPLEFT,
  SUPERRIGHT,
  SUPERLEFT
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case DPRIGHT:
            if (record->event.pressed) {
                SEND_STRING(
                SS_DOWN(X_RIGHT)
                SS_DELAY(20)
                SS_DOWN(X_DOWN)
                 SS_DELAY(20)
                SS_UP(X_RIGHT)
                 SS_DELAY(20)
                SS_DOWN(X_RIGHT)
                SS_DELAY(20)
                SS_UP(X_DOWN)
                 SS_DELAY(20)
                SS_DOWN(X_F)
                SS_DELAY(20)
                SS_UP(X_F)
                SS_UP(X_RIGHT)
                );
            } 
            break;
        
        case DPLEFT:
            if (record->event.pressed) {
                SEND_STRING(
                SS_DOWN(X_LEFT)
                SS_DELAY(20)
                SS_DOWN(X_DOWN)
                 SS_DELAY(20)
                SS_UP(X_LEFT)
                 SS_DELAY(20)
                SS_DOWN(X_LEFT)
                SS_DELAY(20)
                SS_UP(X_DOWN)
                 SS_DELAY(20)
                SS_DOWN(X_F)
                SS_DELAY(20)
                SS_UP(X_F)
                SS_UP(X_LEFT)
                );
            } 
            break;

          case SUPERRIGHT:
            if (record->event.pressed) {
                SEND_STRING(
                SS_DOWN(X_RIGHT)
                SS_DELAY(20)
                SS_DOWN(X_DOWN)
                SS_DELAY(20)
                SS_UP(X_RIGHT)

                SS_DOWN(X_LEFT)
                SS_UP(X_DOWN)
                SS_DELAY(20)

                SS_DOWN(X_RIGHT)
                SS_UP(X_LEFT)
                SS_DELAY(20)
                SS_UP(X_RIGHT)
                SS_DOWN(X_F)
                SS_DELAY(20)
                SS_UP(X_F)
                );
            } 
            break;

              case SUPERLEFT:
            if (record->event.pressed) {
                SEND_STRING(
                SS_DOWN(X_LEFT)
                SS_DELAY(20)
                SS_DOWN(X_DOWN)
                SS_DELAY(20)
                SS_UP(X_LEFT)

                SS_DOWN(X_RIGHT)
                SS_UP(X_DOWN)
                SS_DELAY(20)

                SS_DOWN(X_LEFT)
                SS_UP(X_RIGHT)
                SS_DELAY(20)
                SS_UP(X_LEFT)
                SS_DOWN(X_F)
                SS_DELAY(20)
                SS_UP(X_F)
                );
            } 
            break;
    }
    return true;
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

      /* Base
   * ,-----------------------------------------------------------------------------------------.
   * | ESC |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  +  | LAYER |FN|
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
   * |-----------------------------------------------------------------------------------------+
   * | Caps    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | RSh |  U  | DEL |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl |  Cmd  |  Alt  |      Space      |SPC|   Bkspc     |NUMPAD|Rctrl|  L  |  D  |  R  |
   * `-----------------------------------------------------------------------------------------'
   */
    LAYOUT_directional(
      KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, MO(1), TO(2),
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
      KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT,         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_DEL,
      KC_LCTL, KC_LGUI, KC_LALT, KC_F1, KC_SPC, KC_BSPC, MO(2), KC_RALT , KC_LEFT, KC_DOWN, KC_RIGHT
      ),

  /* FN Layerd
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |      |    |
   * |-----------------------------------------------------------------------------------------+
   * |        |RBB T|RGB M| Hue+| Hue-| Sat+| Sat-| Val+| Val-|     |     |      |      |RESET |
   * |-----------------------------------------------------------------------------------------+
   * |         | BL T| BL M| BL+ | BL- |     |     |     |     |     |     |     |             |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |     |     |     |     |     |     |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |                                   |     |      |     |     |     |
   * `-----------------------------------------------------------------------------------------'
   */

  LAYOUT_directional(
      KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, KC_TRNS,______,
      ______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, ______, ______, ______, ______, RESET,
      ______, BL_TOGG, BL_STEP, BL_INC, BL_DEC, ______, ______, ______, ______, ______, ______, ______,
      ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
      ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______
      ),


            /* MAPLE
   * ,-----------------------------------------------------------------------------------------.
   * | ESC |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  +  | LAYER |FN|
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
   * |-----------------------------------------------------------------------------------------+
   * | Caps  |NORELOAD|  s  |BUNKER|  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter  |
   * |-----------------------------------------------------------------------------------------+
   * | Shift     |  z  |  X  | HAMMER  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | RSh |  U  | DEL  |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl |  Cmd  |  Alt  |      Space      |SPC|   Bkspc     |NUMPAD|Rctrl|  L  |  D  |  R  |
   * `-----------------------------------------------------------------------------------------'
   */
    LAYOUT_directional(
      KC_GESC, KC_1, SUPERRIGHT, SUPERRIGHT, SUPERRIGHT, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, TO(0), TO(0),
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, SUPERLEFT, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
      KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT,         KC_Z, KC_X, DPRIGHT, DPLEFT, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_DEL,
      KC_LCTL, KC_LGUI, KC_LALT, KC_UP, KC_SPC, KC_UP, KC_UP, KC_RALT , KC_LEFT, KC_DOWN, KC_RIGHT
      ),

};   