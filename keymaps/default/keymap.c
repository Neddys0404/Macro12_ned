// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum macro_layers {
     LAYER_BASE = 0,
     LAYER_MAC_ONE,
     LAYER_MAC_TWO,
     LAYER_MAC_THREE,
     LAYER_MAC_FOUR
};

enum custom_keys {
     OPEN_VSC = SAFE_RANGE,
     SCREENSNIP,
     AUTO_IF_P,
     AUTO_FOR_P,
     AUTO_WHILE_P,
     AUTO_CASE_P,
     AUTO_IF_C,
     AUTO_FOR_C,
     AUTO_WHILE_C,
     AUTO_CASE_C,
     SWITCH_TAB,
     OPEN_WS,
     OPEN_STEAM,
     OPEN_YTM,
     OPEN_FOLDER
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     switch (keycode) {
          case AUTO_IF_P:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING("if ():\n" SS_TAP(X_TAB));
               } else {
                    // when keycode QMKURL is released
               }
               return true;

          case AUTO_FOR_P:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING("for i in range(len()):\n" SS_TAP(X_TAB));
               } else {
                    // when keycode QMKURL is released
               }
               return true;
          case AUTO_WHILE_P:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING("while ():\n" SS_TAP(X_TAB));
               } else {
                    // when keycode QMKURL is released
               }
               return true;

          case AUTO_CASE_P:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING("condition = 0\n\nmatch condition:\n" SS_TAP(X_TAB) "case 0:\n" SS_TAP(X_TAB) SS_TAP(X_TAB) "break\n" SS_TAP(X_TAB) "case _:\n" SS_TAP(X_TAB) SS_TAP(X_TAB) "break\n");
               } else {
                    // when keycode QMKURL is released
               }
               return true;

          case AUTO_IF_C:
               if   (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING("if () {\n\n\n\n}\n" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_TAB));
               } else {
                    // when keycode QMKURL is released
               }
               return true;

          case AUTO_FOR_C:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING("for (int i = 0; i < var.length; i++) {\n\n\n\n}\n" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_TAB));
               } else {
                    // when keycode QMKURL is released
               }
               return true;

          case AUTO_WHILE_C:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING("while () {\n\n\n\n}\n" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_TAB));
               } else {
                    // when keycode QMKURL is released
               }
               return true;

          case AUTO_CASE_C:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING("switch () {\n" SS_TAP(X_TAB) "case :\n" SS_TAP(X_TAB) SS_TAP(X_TAB) "break;\n" SS_TAP(X_TAB) "default:\n" SS_TAP(X_TAB) SS_TAP(X_TAB) "break;\n}");
               } else {
                    // when keycode QMKURL is released
               }
               return true;

          case SWITCH_TAB:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_TAB) SS_UP(X_LCTL) SS_UP(X_LSFT));
               } else {
                    // when keycode QMKURL is released
               }
               return true;

          case OPEN_WS:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING(SS_LGUI("4")); //this requires whatsapp to be at forth icon in the task bar 
               } else {
                    // when keycode QMKURL is released
               }
               return true;

          case OPEN_VSC:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING_DELAY(SS_LGUI("r"), 200);
                    SEND_STRING("Code"); 
                    SEND_STRING(SS_TAP(X_ENTER)); 
               } else {
                    // when keycode QMKURL is released
               }
               return true;

          case OPEN_STEAM:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING(SS_LGUI("1")); //this requires steam to be at first icon in the task bar
               } else {
                    // when keycode QMKURL is released
               }
               return true;

          case OPEN_YTM:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING(SS_LGUI("2")); //this requires youtube music to be at second icon in the task bar
               } else {
                    // when keycode QMKURL is released
               }
               return true;

          case OPEN_FOLDER:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING(SS_LGUI("3")); //this requires File Explorer to be at third icon in the task bar
               } else {
                    // when keycode QMKURL is released
               }
               return true;

          case SCREENSNIP:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING_DELAY(SS_LGUI("r"), 200);
                    SEND_STRING("SnippingTool"); 
                    SEND_STRING(SS_TAP(X_ENTER)); 
               } else {
                    // when keycode QMKURL is released
               }
               return true;

          default:
               return true; // Process all other keycodes normally
     }
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [LAYER_MAC_ONE] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),  ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [LAYER_MAC_TWO] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),  ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [LAYER_MAC_THREE] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),  ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [LAYER_MAC_FOUR] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),  ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) }
};
#endif

#define LONE_SS LT(LAYER_MAC_ONE,KC_PSCR)
#define LTWO_PLYPSE LT(LAYER_MAC_TWO,KC_MEDIA_PLAY_PAUSE)
#define LTHREE_PRVTRACK LT(LAYER_MAC_THREE,KC_MEDIA_PREV_TRACK)
#define LFOUR_NXTTRACK LT(LAYER_MAC_FOUR,KC_MEDIA_NEXT_TRACK)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────────────────────╮
            LONE_SS,   LTWO_PLYPSE, LTHREE_PRVTRACK,    LFOUR_NXTTRACK, KC_AUDIO_MUTE,
  // ├────────────────────────────────────────────────────────────────────────────────┤
          AUTO_IF_P,    AUTO_FOR_P,    AUTO_WHILE_P,       AUTO_CASE_P,    
  // ├────────────────────────────────────────────────────────────────────────────────┤
          AUTO_IF_C,    AUTO_FOR_C,    AUTO_WHILE_C,       AUTO_CASE_C,    SWITCH_TAB
  // ╰────────────────────────────────────────────────────────────────────────────────╯
  ),

  [LAYER_MAC_ONE] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────────────────────╮
            _______,       XXXXXXX,         XXXXXXX,           XXXXXXX, KC_AUDIO_MUTE,
  // ├────────────────────────────────────────────────────────────────────────────────┤
          SWITCH_TAB,    AUTO_FOR_P,    AUTO_WHILE_P,       AUTO_CASE_P,    
  // ├────────────────────────────────────────────────────────────────────────────────┤
          AUTO_IF_C,    AUTO_FOR_C,    AUTO_WHILE_C,       AUTO_CASE_C,    SWITCH_TAB
  // ╰────────────────────────────────────────────────────────────────────────────────╯
  ),

  [LAYER_MAC_TWO] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────────────────────╮
            XXXXXXX,       _______,         XXXXXXX,           XXXXXXX, KC_AUDIO_MUTE,
  // ├────────────────────────────────────────────────────────────────────────────────┤
        OPEN_FOLDER,    AUTO_FOR_P,    AUTO_WHILE_P,       AUTO_CASE_P,    
  // ├────────────────────────────────────────────────────────────────────────────────┤
          AUTO_IF_C,    AUTO_FOR_C,    AUTO_WHILE_C,       AUTO_CASE_C,    SWITCH_TAB
  // ╰────────────────────────────────────────────────────────────────────────────────╯
  ),

  [LAYER_MAC_THREE] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────────────────────╮
            XXXXXXX,       XXXXXXX,         _______,           XXXXXXX, KC_AUDIO_MUTE,
  // ├────────────────────────────────────────────────────────────────────────────────┤
            OPEN_WS,    AUTO_FOR_P,    AUTO_WHILE_P,       AUTO_CASE_P,    
  // ├────────────────────────────────────────────────────────────────────────────────┤
          AUTO_IF_C,    AUTO_FOR_C,    AUTO_WHILE_C,       AUTO_CASE_C,    SWITCH_TAB
  // ╰────────────────────────────────────────────────────────────────────────────────╯
  ),

  [LAYER_MAC_FOUR] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────────────────────╮
            XXXXXXX,       XXXXXXX,         XXXXXXX,           _______, KC_AUDIO_MUTE,
  // ├────────────────────────────────────────────────────────────────────────────────┤
           OPEN_YTM,    AUTO_FOR_P,    AUTO_WHILE_P,       AUTO_CASE_P,    
  // ├────────────────────────────────────────────────────────────────────────────────┤
          AUTO_IF_C,    AUTO_FOR_C,    AUTO_WHILE_C,       AUTO_CASE_C,    SWITCH_TAB
  // ╰────────────────────────────────────────────────────────────────────────────────╯
  )

};
// clang-format on
