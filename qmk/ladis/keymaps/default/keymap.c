//#include "ladis.h"
#include QMK_KEYBOARD_H

#define _BL 0
#define _FL 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BL] = LAYOUT(
		KC_WWW_BACK, KC_UP, KC_WWW_FORWARD, \
		KC_LEFT, KC_DOWN, KC_RIGHT, \
		MO(_FL), KC_WWW_REFRESH, KC_F16, \
		LCTL(KC_LGUI), KC_MUTE),

[_FL] = LAYOUT(
		KC_F17, KC_F18, KC_F19, \
		KC_F20, KC_F21, KC_F22, \
		KC_NO, KC_F23, KC_F24, \
		KC_SYSTEM_SLEEP, KC_MUTE),

};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise & layer_state_is(_BL)) {
            tap_code(KC_RIGHT);
        } else if (clockwise & layer_state_is(_FL)){
			tap_code(KC_MS_WH_DOWN);
        } 
		else if (!clockwise & layer_state_is(_BL)){
            tap_code(KC_LEFT);
        }
		 else if (!clockwise & layer_state_is(_FL)) {
            tap_code(KC_MS_WH_UP);
		}
    } else if (index == 1) { /* Second encoder */
        if (clockwise & layer_state_is(_BL)) {
            tap_code(KC_AUDIO_VOL_UP);
        } else if (clockwise & layer_state_is(_FL)){
			tap_code(KC_MS_WH_RIGHT);
        } 
		
		else if (!clockwise & layer_state_is(_BL)){
            tap_code(KC_AUDIO_VOL_DOWN);
        }
		else if (!clockwise & layer_state_is(_FL)) {
            tap_code(KC_MS_WH_LEFT);
		}
    }
    return false;
}

static void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 31,127,255,255,255,255,255, 31, 15,  7,  7,  7,  3,  3,  3,  3,  3,  7,  7,  7, 15, 63,255,255,255,255,255,255,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,224,240,112,112,240,240,224,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,240,240,192,  0,  0,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,127,255,255,255,255,254,252,252,252,252,124, 56,124,252,252,252,254,254,254,255,255,255,255, 63,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  7,  1,192,248,255,255, 15,  1,128,192,224,224,240,112,176, 32,  0,  0,  0,128,192,224,240,112, 48, 32,224,252,255,127,  7,192,240,231,  7,  7,224,224,240, 48, 48,240,224, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,255,255,255,255,255,223,135,135,191,248,112,112,187,135,  7,135,143,255,255,255,255,251,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,192,224,252,255,191,135,  0, 16,254,255,199,227,112, 60,254,255, 63,  6,  0,126,255,255,195,240, 56,124,255,255, 31,  3, 32,252,255, 63,  7,112,240,225,199,207,255,252,120,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,248,255,255,255,255,255,255,255,255,255,253,253,253,252,252,253,255,255,255,255,255,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  3,  7,  7, 15, 14, 30, 30, 28, 28, 14,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}


void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to put your image on the master side, put your function call here:
    render_logo();
  } else {
    // And if you want to put your image on the slave side, put it here instead:
    render_logo();
  }
}