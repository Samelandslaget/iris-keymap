#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
bool is_ctl_tab_active = false;
uint16_t ctl_tab_timer = 0;

enum custom_keycodes {
	QWERTY = SAFE_RANGE,
	LOWER,
	RAISE,
	ADJUST,
	ALT_TAB,
	CTL_TAB,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT(
			//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
			   KC_INS,  KC_LSFT, KC_RALT, KC_LALT, CTL_TAB, KC_DEL,                             KC_DEL,  ALT_TAB, KC_LALT, KC_RALT, KC_LSFT, KC_PAUS,
			//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
			   KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_QUOT,
			//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
			   KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_BSPC,
			//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
			   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_MUTE,          KC_MPLY, KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
			//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
			                                  KC_LGUI, LOWER,   KC_ENT,                    KC_SPC,  RAISE,   KC_LCTL
			                              // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
			),

	[_LOWER] = LAYOUT(
			//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
			   _______, _______, _______, _______, _______, _______,                            _______, KC_SLSH, KC_ASTR, KC_MINS, _______, _______,
			//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
			   KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
			//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
			   KC_LGUI, KC_APP,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                            _______, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
			//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
			   _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,          _______, _______, KC_1,    KC_2,    KC_3,    KC_DOT,  _______,
			//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
			                                  _______, _______, _______,                   KC_DEL,  _______, CTL_T(KC_0)
			                              // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
			),

	[_RAISE] = LAYOUT(
			//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
			   KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
			//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
			   _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
			//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
			   KC_LCTL, KC_GRV,  _______, KC_LPRN, KC_LBRC, KC_MINS,                            KC_EQL,  KC_RBRC, KC_RPRN, _______, KC_BSLS, _______,
			//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
			   _______, KC_TILD, _______, _______, KC_LCBR, KC_UNDS, _______,          _______, KC_PLUS, KC_RCBR, _______, _______, KC_PIPE, _______,
			//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
			                                  _______, _______, _______,                   _______, _______, _______
			                              // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
			),

	[_ADJUST] = LAYOUT(
			//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
			   _______, _______, _______, KC_VOLU, _______, _______,                            _______, _______, _______, _______, _______, _______,
			//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
			   _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______,                            _______, _______, RGB_M_P, RGB_M_X, RGB_M_T, UG_TOGG, // Plain, Xmas, Test rgb
			//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
			   _______, _______, _______, MS_UP,   _______, MS_WHLU,                            MS_BTN3, MS_BTN1, UG_HUEU, UG_SATU, UG_VALU, UG_NEXT,
			//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
			   _______, _______, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLD, _______,          _______, _______, MS_BTN2, UG_HUED, UG_SATD, UG_VALD, _______,
			//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
			                                  _______, _______, _______,                   _______, _______, _______
			                              // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
			)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case QWERTY:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_QWERTY);
			}
			return false;
			break;
		case LOWER:
			if (record->event.pressed) {
				layer_on(_LOWER);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			} else {
				layer_off(_LOWER);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}
			return false;
			break;
		case RAISE:
			if (record->event.pressed) {
				layer_on(_RAISE);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			} else {
				layer_off(_RAISE);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}
			return false;
			break;
		case ADJUST:
			if (record->event.pressed) {
				layer_on(_ADJUST);
			} else {
				layer_off(_ADJUST);
			}
			return false;
			break;
		case ALT_TAB:
			if (record->event.pressed) {
				if (!is_alt_tab_active) {
					is_alt_tab_active = true;
					register_code(KC_LALT);
				}
				alt_tab_timer = timer_read();
				register_code(KC_TAB);
			} else {
				unregister_code(KC_TAB);
			}
			break;
		case CTL_TAB:
			if (record->event.pressed) {
				if (!is_ctl_tab_active) {
					is_ctl_tab_active = true;
					register_code(KC_LCTL);
				}
				ctl_tab_timer = timer_read();
				register_code(KC_TAB);
			} else {
				unregister_code(KC_TAB);
			}
			break;
	}
	return true;
}

void matrix_scan_user(void) {
	if (is_alt_tab_active) {
		if (timer_elapsed(alt_tab_timer) > 200) {
			unregister_code(KC_LALT);
			is_alt_tab_active = false;
		}
	}
	else if (is_ctl_tab_active) {
		if (timer_elapsed(ctl_tab_timer) > 200) {
			unregister_code(KC_LCTL);
			is_ctl_tab_active = false;
		}
	}
}
