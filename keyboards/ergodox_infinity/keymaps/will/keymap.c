#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define LBASE 0 // default layer
#define LWIND 1
#define LSYMB 2
#define LMDIA 3
#define LGAME 4

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LBASE] = LAYOUT_ergodox(  // layer 0 : default
/*
 * left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |   =   |  0  |  2  |  3  |  4  |  5  |⌘ ⇧ [|
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |  TAB  |  Q  |  W  |  E  |  R  |  T  |LCK-1|
 *    +-------+-----+-----+-----+-----+-----+     |
 *    | Ctrl  |  A  |  S  |  D  |  F  |  G  +-----+
 *    +-------+-----+-----+-----+-----+-----+ f1  |
 *    | LSHFT |  Z  |  X  |  C  |  V  |  B  | <TK>    |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |LALT |  `  |  \  |LEFT |RIGHT|
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        | ESC | lead|
 *                                  +-----+-----+-----+
 *                                  |     |     | HOME|
 *                                  |BKSPC| LGui+-----+
 *                                  |     |     | END |
 *                                  +-----+-----+-----+
 */
         KC_EQL,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5, LGUI(LSFT(KC_LBRC)),
         KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T, TG(LSYMB),
         KC_LCTL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,
         KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, MO(LSYMB),
         KC_LALT, KC_GRV, KC_BSLS, KC_LEFT, KC_RGHT,
                                                      KC_ESC, KC_LEAD,
                                                              KC_HOME,
                                            KC_BSPC, KC_LGUI, KC_END,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |⌘ ⇧ ]|  6  |  7  |  8  |  9  |  0  |   -   |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        | lck |  Y  |  U  |  I  |  O  |  P  |   \   |
 *        |  1  +-----+-----+-----+-----+-----+-------+
 *        +-----+  H  |  J  |  K  |  L  |;/MDA|   '   |
 *        | f1  +-----+-----+-----+-----+-----+-------+
 *        |     |  N  |  M  |  ,  |  .  |  /  | LSYMB |
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    | UP  |DOWN |     |     | RALT|
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    | DEL |RCTRL|
 *    +-----+-----+-----+
 *    | PGUP|     |     |
 *    +-----+ ENT | SPC |
 *    | PGDN|     |     |
 *    +-----+-----+-----+
 */
 LGUI(LSFT(KC_RBRC)), KC_6,   KC_7,    KC_8,    KC_9,   KC_0,             KC_MINS,
             TG(1),   KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,             KC_BSLS,
                      KC_H,   KC_J,    KC_K,    KC_L,   LT(LMDIA, KC_SCLN),  KC_QUOT,
          MO(LSYMB),  KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH,          MO(LSYMB),
                              KC_UP,   KC_DOWN, KC_UP,  MO(LWIND),        KC_RALT,
             KC_DELETE, KC_RCTL,
             KC_PGUP,
             KC_PGDN, KC_ENT, KC_SPC
    ),

[LWIND] = LAYOUT_ergodox( // layer 1 : windows
    //  left hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       KC_LGUI, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, KC_LCTL, _______,

    // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
    ),


[LSYMB] = LAYOUT_ergodox( // layer 2 : function and symbol layers
/* left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    | reset | f1  | f2  | f3  | f4  | f5  | f11 |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |  !  |  @  |  [  |  ]  |  ~  |     |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |  #  |  $  |  (  |  )  |  `  +-----+
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |  =  |  |  |  {  |  }  |  ^  |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |     |     |  %  |  <  |  >  |
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |     |     |
 *                                  +-----+-----+-----+
 *                                  |     |     | home|
 *                                  |     |     +-----+
 *                                  |     |     | end |
 *                                  +-----+-----+-----+
 */
       RESET  ,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F11,
       _______,KC_EXLM,KC_AT,  KC_LBRC,KC_RBRC,KC_TILD,_______,
       _______,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       _______,KC_EQL, KC_PIPE,KC_LCBR,KC_RCBR,KC_CIRC,_______,
       _______,_______,KC_PERC,KC_LABK,KC_RABK,
                                       _______,_______,
                                               KC_HOME,
                               _______,_______,KC_END,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        | f12 | f6  | f7  | f8  | f9  | f10 | reset |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     | P7  | P8  | P9  | P-  |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+     | P4  | P5  | P6  | P+  |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        |     |     | P1  | P2  | P3  |  =  |       |
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |     |     | P.  |PENT |     |
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |     |     |
 *    +-----+-----+-----+
 *    |     |     |     |
 *    +-----+     | P0  |
 *    |     |     |     |
 *    +-----+-----+-----+
 */
       KC_F12,   KC_F6,   KC_F7,      KC_F8,       KC_F9,          KC_F10,      RESET,
       _______,  _______, KC_KP_7,    KC_KP_8,     KC_KP_9,        KC_KP_MINUS, _______,
                 _______, KC_KP_4,    KC_KP_5,     KC_KP_6,        KC_KP_PLUS,  _______,
       _______,  _______, KC_KP_1,    KC_KP_2,     KC_KP_3,        KC_KP_EQUAL, _______,
                          _______,    _______,     KC_KP_DOT,      KC_KP_ENTER, _______,
       _______, _______,
       _______,
       _______, _______, KC_KP_0
),
[LMDIA] = LAYOUT_ergodox(
/* Left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    | reset |     |     |     |     |     |     |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |     |LClk |MsUp |RtClk|     |Lock |
 *    +-------+-----+-----+-----+-----+-----+  2  |
 *    |       |     |MsLft|MsDwn|MsRgt|     +-----+
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     |BLTOG|BLINC|BLDEC|     |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |     |     |     |     |     |
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |     |     |
 *                                  +-----+-----+-----+
 *                                  |     |     |     |
 *                                  |     |     +-----+
 *                                  |     |     |     |
 *                                  +-----+-----+-----+
 */
       RESET,   _______, _______, _______, _______, _______, _______,
       _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, TG(LSYMB),
       _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
       _______, _______, BL_TOGG, BL_INC,  BL_DEC,  _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     | reset |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+  :  |play |prev |next |     |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        |     |     |mute |volUp|volDn|     |       |
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |     |     |     |     |     |
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |     |     |
 *    +-----+-----+-----+
 *    |     |     |     |
 *    +-----+     |     |
 *    |     |     |     |
 *    +-----+-----+-----+
 */
       _______, _______,  _______, _______, _______, _______, RESET,
    TG(LSYMB),  _______,  _______, _______, _______, _______, _______,
                KC_COLON, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______,
       _______, _______,  KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),

[LGAME] = LAYOUT_ergodox( // layer 3 : games
/*
 * left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |  ESC  |  1  |  2  |  3  |  4  |  5  |  6  |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |  TAB  |  I  |  Q  |  W  |  E  |  R  |  T  |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    | Ctrl  |  T  |  A  |  S  |  D  |  F  +-----+
 *    +-------+-----+-----+-----+-----+-----+  G  |
 *    | LSHFT |  Z  |  X  |  C  |  V  |  B  |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |LGUI |  J  |  U  |  Y  |  O  |
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        | P   | tog |
 *                                  +-----+-----+-----+
 *                                  |     |     |  K  |
 *                                  |SPACE| Ctrl+-----+
 *                                  |     |     |SHIFT|
 *                                  +-----+-----+-----+
 */
    KC_EQL,  KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,
    KC_TAB,  KC_I, KC_Q, KC_W, KC_E, KC_R, KC_T,
    KC_LCTL, KC_T, KC_A, KC_S, KC_D, KC_F,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_G,
    KC_LGUI, KC_J, KC_U, KC_Y, KC_O,
                                                KC_P, TG(LGAME),
                                                      KC_K,
                                     KC_SPC, KC_LCTL, KC_LSFT,

    // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
    ),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

LEADER_EXTERNS();

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    SEQ_ONE_KEY(KC_F) {
      SEND_STRING("QMK is awesome!");
    }

    SEQ_ONE_KEY(KC_W) {
      layer_invert(LWIND);
    }

    SEQ_ONE_KEY(KC_G) {
      layer_invert(LGAME);
    }

  }


    //uint8_t layer = biton32(layer_state);

  /**
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
    */

};
