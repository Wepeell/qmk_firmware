/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

#include "quantum.h"
#include "custom_functions.h"

// Declare variable for DIP switch layer detection
static bool win_mode = false;

#ifdef DIP_SWITCH_ENABLE

bool dip_switch_update_kb(uint8_t index, bool active) {
    if (!dip_switch_update_user(index, active)) {
        return false;
    }
    if (index == 0) {
#    if defined(OS_SWITCH_REVERT)
        default_layer_set(1UL << (!active ? 2 : 0));
#    else
        default_layer_set(1UL << (active ? 2 : 0));
#    endif
    }

	// Detect DIP switch in Mac or Windows mode
	if (index == 0 && active) {
		win_mode = true;
	} else {
		win_mode = false;
	}

    return true;
}

#endif // DIP_SWITCH_ENABLE

#if defined(RGB_MATRIX_ENABLE) && (defined(CAPS_LOCK_LED_INDEX) || defined(NUM_LOCK_LED_INDEX) || defined(SCROLL_LOCK_LED_INDEX) || defined(LAYER_LED_INDEX) || defined(INDICATORS_TOGGLE_ALL))

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case QK_RGB_MATRIX_TOGGLE:
            if (record->event.pressed) {
                switch (rgb_matrix_get_flags()) {
                    case LED_FLAG_ALL: {
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_set_color_all(0, 0, 0);
                    } break;
                    default: {
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                    } break;
                }
            }
            if (!rgb_matrix_is_enabled()) {
                rgb_matrix_set_flags(LED_FLAG_ALL);
                rgb_matrix_enable();
            }
            return false;
    }
    return true;
}

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) {
        return false;
    }

	// Get layer color
	#if defined(CAPS_LOCK_LED_INDEX) || defined(NUM_LOCK_LED_INDEX) || defined(SCROLL_LOCK_LED_INDEX) || defined(LAYER_LED_INDEX) || defined(INDICATORS_TOGGLE_ALL)
	RGB rgb = get_layer_color(win_mode);
	#endif // Get layer color

	// Set Caps Lock indicator color
	#if defined(CAPS_LOCK_LED_INDEX)
	set_caps_lock_indicator(rgb, led_min, led_max);
	#endif // CAPS_LOCK_LED_INDEX

	// Set Num Lock indicator color
	#if defined(NUM_LOCK_LED_INDEX)
	set_num_lock_indicator(rgb, led_min, led_max);
	#endif // NUM_LOCK_LED_INDEX

	// Set Scroll Lock indicator color
	#if defined(SCROLL_LOCK_LED_INDEX)
	set_scroll_lock_indicator(rgb, led_min, led_max);
	#endif // SCROLL_LOCK_LED_INDEX

	// Set layer indicator color
	#if defined(LAYER_LED_INDEX)
	set_layer_indicator(rgb, led_min, led_max);
	#endif // LAYER_LED_INDEX

	// Turn off indicators when RGB is turned off
	#if defined(INDICATORS_TOGGLE_ALL)
	set_indicator_off(led_min, led_max);
	#endif // INDICATORS_TOGGLE_ALL

    return true;
}

#endif // RGB_MATRIX_ENABLE...
