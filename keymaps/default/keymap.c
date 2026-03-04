// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum macro_layers {
     LAYER_BASE = 0,
     LAYER_MAC_ONE,
     LAYER_MAC_TWO,
};

enum custom_keys {
     AUTO_IF_P = SAFE_RANGE,
     AUTO_FOR_P,
     AUTO_WHILE_P,
     AUTO_CASE_P,
     AUTO_IF_C,
     AUTO_FOR_C,
     AUTO_WHILE_C,
     AUTO_CASE_C,
     SWITCH_TAB,
     OPEN_CHROME,
     OPEN_WS,
     OPEN_VSC,
     OPEN_PUTTY,
     OPEN_STEAM,
     OPEN_YTM,
     OPEN_FOLDER,
     SCREENSNIP,
};

bool encoder_update_user(uint8_t index, bool clockwise) {
     
     if (index == 0) {
          switch (get_highest_layer(layer_state)) {
               case LAYER_BASE:
                    if (clockwise) {
                         tap_code(KC_VOLU);
                    } else {
                         tap_code(KC_VOLD);
                    }
                    break;
     
               case LAYER_MAC_ONE:
                    if (clockwise) {
                         tap_code(KC_PGDN);
                    } else {
                         tap_code(KC_PGUP);
                    }
                    break;
     
               case LAYER_MAC_TWO:
                    if (clockwise) {
                         tap_code(KC_RIGHT);
                    } else {
                         tap_code(KC_LEFT);
                    }
                    break;
          }
     }
     else if (index == 1) {
          switch (get_highest_layer(layer_state)) {
               case LAYER_BASE:
                    if (clockwise) {
                         tap_code(KC_VOLU);
                    } else {
                         tap_code(KC_VOLD);
                    }
                    break;
     
               case LAYER_MAC_ONE:
                    if (clockwise) {
                         tap_code(KC_PGDN);
                    } else {
                         tap_code(KC_PGUP);
                    }
                    break;
     
               case LAYER_MAC_TWO:
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

#define QUOTE MO(LAYER_QUOTE)
#define NUM MO(LAYER_NUM)
#define MACRO MO(LAYER_MACRO)

#define MAC_ONE_SS LT(LAYER_MAC_ONE,SCREENSNIP)
#define MAC_TWO_VSC  LT(LAYER_MAC_TWO,OPEN_VSC)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     switch (keycode) {
          case AUTO_IF_P:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING("if ():\n" SS_TAP(X_TAB));
               } else {
                    // when keycode QMKURL is released
               }
               break;
          case AUTO_FOR_P:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING("for i in range(len()):\n" SS_TAP(X_TAB));
               } else {
                    // when keycode QMKURL is released
               }
               break;
          case AUTO_WHILE_P:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING("while ():\n" SS_TAP(X_TAB));
               } else {
                    // when keycode QMKURL is released
               }
               break;
          case AUTO_IF_C:
               if   (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING("if () {\n\n\n\n}\n" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_TAB));
               } else {
                    // when keycode QMKURL is released
               }
               break;
          case AUTO_FOR_C:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING("for (int i = 0; i < var.length; i++) {\n\n\n\n}\n" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_TAB));
               } else {
                    // when keycode QMKURL is released
               }
               break;
          case AUTO_WHILE_C:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING("while () {\n\n\n\n}\n" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_TAB));
               } else {
                    // when keycode QMKURL is released
               }
               break;

          case SWITCH_TAB:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_TAB) SS_UP(X_LCTL) SS_UP(X_LSFT));
               } else {
                    // when keycode QMKURL is released
               }
               break;

          case OPEN_CHROME:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING_DELAY(SS_LGUI("r"), 200);
                    SEND_STRING("chrome "); 
                    SEND_STRING("https://www.youtube.com"); 
                    SEND_STRING(SS_TAP(X_ENTER)); 
               } else {
                    // when keycode QMKURL is released
               }
               break;

          case OPEN_WS:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING(SS_LGUI("4")); //this requires whatsapp to be at forth icon in the task bar 
               } else {
                    // when keycode QMKURL is released
               }
               break;

          case OPEN_VSC:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING_DELAY(SS_LGUI("r"), 200);
                    SEND_STRING("Code"); 
                    SEND_STRING(SS_TAP(X_ENTER)); 
               } else {
                    // when keycode QMKURL is released
               }
               break;

          case OPEN_PUTTY:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING_DELAY(SS_LGUI("r"), 200); 
                    SEND_STRING("PUTTY"); 
                    SEND_STRING(SS_TAP(X_ENTER)); 
               } else {
                    // when keycode QMKURL is released
               }
               break;

          case OPEN_STEAM:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING(SS_LGUI("1")); //this requires steam to be at first icon in the task bar
               } else {
                    // when keycode QMKURL is released
               }
               break;

          case OPEN_YTM:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING(SS_LGUI("2")); //this requires youtube music to be at second icon in the task bar
               } else {
                    // when keycode QMKURL is released
               }
               break;

          case OPEN_FOLDER:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING(SS_LGUI("3")); //this requires File Explorer to be at third icon in the task bar
               } else {
                    // when keycode QMKURL is released
               }
               break;

          case SCREENSNIP:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING_DELAY(SS_LGUI("r"), 200);
                    SEND_STRING("SnippingTool"); 
                    SEND_STRING(SS_TAP(X_ENTER)); 
               } else {
                    // when keycode QMKURL is released
               }
               break;
     }
     return true;
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────────────────────╮
          AUTO_IF_P,    AUTO_FOR_P,    AUTO_WHILE_P,    AUTO_CASE_P,    OPEN_WS,
  // ├────────────────────────────────────────────────────────────────────────────────┤
          AUTO_IF_C,    AUTO_FOR_C,    AUTO_WHILE_C,    AUTO_CASE_C,    
  // ├────────────────────────────────────────────────────────────────────────────────┤
          OPEN_STEAM,   OPEN_YTM,      OPEN_FOLDER,     OPEN_WS,        MAC_ONE_SS
  // ╰────────────────────────────────────────────────────────────────────────────────╯
  ),

  [LAYER_MAC_ONE] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────────────────────╮
          AUTO_IF_P,    AUTO_FOR_P,    AUTO_WHILE_P,    AUTO_CASE_P,    OPEN_WS,
  // ├────────────────────────────────────────────────────────────────────────────────┤
          AUTO_IF_C,    AUTO_FOR_C,    AUTO_WHILE_C,    AUTO_CASE_C,    
  // ├────────────────────────────────────────────────────────────────────────────────┤
          OPEN_STEAM,   OPEN_FOLDER,   OPEN_WS,         OPEN_VSC,       KC_B
  // ╰────────────────────────────────────────────────────────────────────────────────╯
  ),

  [LAYER_MAC_TWO] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────────────────────╮
          AUTO_IF_P,    AUTO_FOR_P,    AUTO_WHILE_P,    AUTO_CASE_P,    OPEN_WS,
  // ├────────────────────────────────────────────────────────────────────────────────┤
          AUTO_IF_C,    AUTO_FOR_C,    AUTO_WHILE_C,    AUTO_CASE_C,    
  // ├────────────────────────────────────────────────────────────────────────────────┤
          OPEN_STEAM,   OPEN_FOLDER,   OPEN_WS,         OPEN_VSC,       KC_B
  // ╰────────────────────────────────────────────────────────────────────────────────╯
  )

};
// clang-format on
