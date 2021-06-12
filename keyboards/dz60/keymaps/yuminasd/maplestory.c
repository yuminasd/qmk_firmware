#include QMK_KEYBOARD_H
#define ______ KC_TRNS

static uint16_t key_trigger = 0; //1 = hold repeat NORELOAD 2 = VERTICAL FARM 3 = HORIZONTAL FARM
static uint16_t key_timer = 0;

enum custom_keycodes {
  //MAPLE
  NORELOAD,
  HAMMER,
  SHOTGUN,
  SGPSKATE,
  VERTICALFARM,
  HORIZONTALFARM,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // M-MACROS
        case NORELOAD:
            if (record->event.pressed) {
                key_trigger = 1;
            } else {
                key_trigger = 0;
            }
            break;

        case HAMMER:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_N) SS_DOWN(X_LCTRL) SS_DELAY(100) SS_TAP(X_E) SS_DELAY(400) SS_UP(X_N) SS_DELAY(100) SS_UP(X_LCTRL) SS_DELAY(5) SS_TAP(X_SPC));
            }
            break;

        case SHOTGUN:
            if (record->event.pressed) {
                key_trigger = 2;
            } else {
                key_trigger = 0;
            }
            break;

        case SGPSKATE:
            if (record->event.pressed) {
                                   SEND_STRING(
                    SS_DOWN(X_LCTRL)
                    SS_DELAY(200) SS_TAP(X_Q) SS_DELAY(300) SS_TAP(X_W) SS_DELAY(300)
                    SS_UP(X_LCTRL)
                    SS_DELAY(5)
                    SS_TAP(X_SPC)
                        SS_DELAY(50)
                        SS_DOWN(X_SPC)
                        SS_DELAY(100)
                        SS_DOWN(X_COMM)
                        SS_DELAY(10)
                        SS_UP(X_COMM)
                        SS_UP(X_SPC)

                    );
            } else {
               
            }
            
            break;

        case VERTICALFARM:// on release key starts the farm or stops it
            if (record->event.pressed) {
            } else {
                if(key_trigger !=4) {
                    key_trigger= 4;
                }
                else {
                    key_trigger = 0;
                }
            }
            break;

        case HORIZONTALFARM:
            if (record->event.pressed) {
            } else {
                if(key_trigger !=5) {
                    key_trigger= 5;
                }
                else {
                    key_trigger = 0;
                }
            }
            break;
    }
    return true;
};

void matrix_scan_user(void) { 

    switch (key_trigger)
    {
        case 1: {//NORELOAD REPEAT
            if (timer_elapsed(key_timer) > 10) {  // if timer has exceed set amount of time
                SEND_STRING(SS_DOWN(X_LCTRL) SS_DELAY(200) SS_TAP(X_Q) SS_DELAY(300) SS_TAP(X_W) SS_DELAY(300) SS_UP(X_LCTRL) SS_DELAY(5) SS_TAP(X_SPC));
                key_timer = timer_read32();  // reset the timer 
            }
        } break;

        case 2: {//SHOTGUN
            if(timer_elapsed(key_timer)>70) {
                SEND_STRING(
                    SS_DOWN(X_LCTRL)
                    SS_DELAY(200)
                    SS_TAP(X_DOT)
                    SS_DELAY(200)
                    SS_UP(X_LCTRL)
                    SS_DELAY(5)
                    SS_TAP(X_SPC)
                );
                key_timer = timer_read32();  // reset the timer 
            }
           
        }break;

        case 3: {//SPG SKATE
                    if(timer_elapsed(key_timer)>10) {
                    SEND_STRING(
                    SS_DOWN(X_LCTRL)
                    SS_DELAY(200)
                    SS_TAP(X_DOT)
                    SS_DELAY(200)
                    SS_UP(X_LCTRL)
                    SS_DELAY(5)
                    SS_TAP(X_SPC)
                        SS_DELAY(200)
                        SS_TAP(X_SPC)
                        SS_DELAY(200)
                        SS_TAP(X_COMM)

                    );
                    key_timer = timer_read32();  // reset the timer 
                }
        }break; 

        case 4: {//VERTICALFARM
             if (timer_elapsed(key_timer) > 200) {  
                SEND_STRING(
                    SS_DOWN(X_LCTRL) SS_DELAY(200) SS_TAP(X_Q) SS_DELAY(300) SS_TAP(X_W) SS_DELAY(300) SS_UP(X_LCTRL) SS_DELAY(5) SS_TAP(X_SPC)
                    SS_DELAY(400)
                    SS_DOWN(X_LCTRL) SS_DELAY(200) SS_TAP(X_Q) SS_DELAY(300) SS_TAP(X_W) SS_DELAY(300) SS_UP(X_LCTRL) SS_DELAY(5) SS_TAP(X_SPC)
                    SS_DELAY(400)
                     SS_DOWN(X_LCTRL) SS_DELAY(200) SS_TAP(X_Q) SS_DELAY(300) SS_TAP(X_W) SS_DELAY(300) SS_UP(X_LCTRL) SS_DELAY(5) SS_TAP(X_SPC)
                    SS_DELAY(400)
                     SS_DOWN(X_LCTRL) SS_DELAY(200) SS_TAP(X_Q) SS_DELAY(300) SS_TAP(X_W) SS_DELAY(300) SS_UP(X_LCTRL) SS_DELAY(5) SS_TAP(X_SPC)
                    SS_DELAY(400)
                    
                    SS_DOWN(X_N) SS_DOWN(X_LCTRL) SS_DELAY(100) SS_TAP(X_E) SS_DELAY(400) SS_UP(X_N) SS_DELAY(100) SS_UP(X_LCTRL) SS_DELAY(5) SS_TAP(X_SPC)
                    SS_DELAY(1000)
                   
                    SS_DOWN(X_RIGHT)
                    SS_DELAY(480)
                    SS_UP(X_RIGHT)   
                    SS_DELAY(500)
                    SS_DOWN(X_LEFT)
                    SS_DELAY(80)
                    SS_UP(X_LEFT)   

                    SS_DELAY(400)
                    SS_DOWN(X_LCTRL) SS_DELAY(200)SS_TAP(X_DOT)SS_DELAY(200)SS_UP(X_LCTRL)SS_DELAY(5)SS_TAP(X_SPC)
                    SS_DELAY(400)
                    SS_DOWN(X_LCTRL) SS_DELAY(200)SS_TAP(X_DOT)SS_DELAY(200)SS_UP(X_LCTRL)SS_DELAY(5)SS_TAP(X_SPC)
                     SS_DOWN(X_LCTRL) SS_DELAY(200) SS_TAP(X_Q) SS_DELAY(300) SS_TAP(X_W) SS_DELAY(300) SS_UP(X_LCTRL) SS_DELAY(5) SS_TAP(X_SPC)
                    SS_DELAY(400)
                     SS_DOWN(X_LCTRL) SS_DELAY(200) SS_TAP(X_Q) SS_DELAY(300) SS_TAP(X_W) SS_DELAY(300) SS_UP(X_LCTRL) SS_DELAY(5) SS_TAP(X_SPC)
                    SS_DELAY(400)


                   
                );

                key_timer = timer_read32();  // reset the timer to 
            }
        } break;

        case 5: {//HORIZONTAL FARM
            if (timer_elapsed(key_timer) > 1000) {  
                SEND_STRING(
                    //LEFT ONCE
                    SS_DOWN(X_LEFT)
                    SS_DELAY(100)
                    SS_DOWN(X_LCTRL) SS_DELAY(200) SS_TAP(X_Q) SS_DELAY(300) SS_TAP(X_W) SS_DELAY(300) SS_UP(X_LCTRL) SS_DELAY(5) SS_TAP(X_SPC)
                    SS_DELAY(200)
                    SS_DOWN(X_LCTRL)
                    SS_DELAY(500)
                    SS_UP(X_LCTRL)
                    SS_UP(X_LEFT)
                    SS_TAP(X_2)

                    SS_DELAY(300)

                    //LEFT ONCE
                    SS_DOWN(X_LEFT)
                    SS_DELAY(100)
                    SS_DOWN(X_LCTRL) SS_DELAY(200) SS_TAP(X_Q) SS_DELAY(300) SS_TAP(X_W) SS_DELAY(300) SS_UP(X_LCTRL) SS_DELAY(5) SS_TAP(X_SPC)
                    SS_DELAY(200)
                    SS_DOWN(X_LCTRL)
                    SS_DELAY(500)
                    SS_UP(X_LCTRL)
                    SS_UP(X_LEFT)
                    SS_TAP(X_1)

                    SS_DELAY(300)

                    //LEFT ONCE
                    SS_DOWN(X_LEFT)
                    SS_DELAY(100)
                    SS_DOWN(X_LCTRL) SS_DELAY(200) SS_TAP(X_Q) SS_DELAY(300) SS_TAP(X_W) SS_DELAY(300) SS_UP(X_LCTRL) SS_DELAY(5) SS_TAP(X_SPC)
                    SS_DELAY(200)
                    SS_DOWN(X_LCTRL)
                    SS_DELAY(500)
                    SS_UP(X_LCTRL)
                    SS_UP(X_LEFT)


                    SS_DELAY(300)

                    //LEFT ONCE
                    SS_DOWN(X_LEFT)
                    SS_DELAY(100)
                    SS_DOWN(X_LCTRL) SS_DELAY(200) SS_TAP(X_Q) SS_DELAY(300) SS_TAP(X_W) SS_DELAY(300) SS_UP(X_LCTRL) SS_DELAY(5) SS_TAP(X_SPC)
                    SS_DELAY(200)
                    SS_DOWN(X_LCTRL)
                    SS_DELAY(500)
                    SS_UP(X_LCTRL)
                    SS_UP(X_LEFT)
                    SS_TAP(X_1)

                    SS_DELAY(300)

                    //RIGHT ONCE
                    SS_DOWN(X_RIGHT)
                    SS_DELAY(100)
                    SS_DOWN(X_LCTRL) SS_DELAY(200) SS_TAP(X_Q) SS_DELAY(300) SS_TAP(X_W) SS_DELAY(300) SS_UP(X_LCTRL) SS_DELAY(5) SS_TAP(X_SPC)
                    SS_DELAY(200)
                    SS_DOWN(X_LCTRL)
                    SS_DELAY(500)
                    SS_UP(X_LCTRL)
                    SS_UP(X_RIGHT)
                    SS_TAP(X_2)

                    SS_DELAY(300)

                                        //RIGHT ONCE
                    SS_DOWN(X_RIGHT)
                    SS_DELAY(100)
                    SS_DOWN(X_LCTRL) SS_DELAY(200) SS_TAP(X_Q) SS_DELAY(300) SS_TAP(X_W) SS_DELAY(300) SS_UP(X_LCTRL) SS_DELAY(5) SS_TAP(X_SPC)
                    SS_DELAY(200)
                    SS_DOWN(X_LCTRL)
                    SS_DELAY(500)
                    SS_UP(X_LCTRL)
                    SS_UP(X_RIGHT)
                    SS_TAP(X_1)

                    SS_DELAY(300)

                                        //RIGHT ONCE
                    SS_DOWN(X_RIGHT)
                    SS_DELAY(100)
                    SS_DOWN(X_LCTRL) SS_DELAY(200) SS_TAP(X_Q) SS_DELAY(300) SS_TAP(X_W) SS_DELAY(300) SS_UP(X_LCTRL) SS_DELAY(5) SS_TAP(X_SPC)
                    SS_DELAY(200)
                    SS_DOWN(X_LCTRL)
                    SS_DELAY(500)
                    SS_UP(X_LCTRL)
                    SS_UP(X_RIGHT)


                    SS_DELAY(300)

                                        //RIGHT ONCE
                    SS_DOWN(X_RIGHT)
                    SS_DELAY(100)
                    SS_DOWN(X_LCTRL) SS_DELAY(200) SS_TAP(X_Q) SS_DELAY(300) SS_TAP(X_W) SS_DELAY(300) SS_UP(X_LCTRL) SS_DELAY(5) SS_TAP(X_SPC)
                    SS_DELAY(200)
                    SS_DOWN(X_LCTRL)
                    SS_DELAY(500)
                    SS_UP(X_LCTRL)
                    SS_UP(X_RIGHT)
                    SS_TAP(X_1)

                    SS_DELAY(300)
  
                );
                key_timer = timer_read32();  // reset the timer to 
            }
        } break;

    default:
        break;
    }
  
}


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
      KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, P, KC_DEL,
      KC_LCTL, KC_LGUI, KC_LALT, KC_F1, KC_SPC, KC_BSPC, MO(2), KC_RCTL , KC_LEFT, KC_DOWN, KC_RIGHT
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
      KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, TO(0), TO(0),
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
      KC_CAPS, NORELOAD, SHOTGUN, HAMMER, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, SGPSKATE, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_DEL,
      KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_BSPC, HORIZONTALFARM, VERTICALFARM , KC_LEFT, KC_DOWN, KC_RIGHT
      ),

};   