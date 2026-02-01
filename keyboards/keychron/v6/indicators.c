#include "custom_functions.h"

// Syntax for setting key color
// RGB_MATRIX_INDICATOR_SET_COLOR(index, red, green, blue);

// Set Caps Lock indicator color
#if defined(CAPS_LOCK_LED_INDEX)
void set_caps_lock_indicator(RGB rgb, uint8_t led_min, uint8_t led_max) {
	if (host_keyboard_led_state().caps_lock) {
		RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, rgb.r, rgb.g, rgb.b);
	} else {
		#if defined(INDICATORS_INHERIT_MODE)
		if (!rgb_matrix_get_flags()) {
			RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, 0, 0, 0);
		}
		#else // INDICATORS_INHERIT_MODE
		RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, 0, 0, 0);
		#endif // INDICATORS_INHERIT_MODE
	}
}
#endif // CAPS_LOCK_LED_INDEX

// Set Num Lock indicator color
#if defined(NUM_LOCK_LED_INDEX)
void set_num_lock_indicator(RGB rgb, uint8_t led_min, uint8_t led_max) {
	if (host_keyboard_led_state().num_lock) {
		RGB_MATRIX_INDICATOR_SET_COLOR(NUM_LOCK_LED_INDEX, rgb.r, rgb.g, rgb.b);
	} else {
		#if defined(INDICATORS_INHERIT_MODE)
		if (!rgb_matrix_get_flags()) {
			RGB_MATRIX_INDICATOR_SET_COLOR(NUM_LOCK_LED_INDEX, 0, 0, 0);
		}
		#else // INDICATORS_INHERIT_MODE
		RGB_MATRIX_INDICATOR_SET_COLOR(NUM_LOCK_LED_INDEX, 0, 0, 0);
		#endif // INDICATORS_INHERIT_MODE
	}
}
#endif // NUM_LOCK_LED_INDEX

// Set Scroll Lock indicator color
#if defined(SCROLL_LOCK_LED_INDEX)
void set_scroll_lock_indicator(RGB rgb, uint8_t led_min, uint8_t led_max) {
	if (host_keyboard_led_state().scroll_lock) {
		RGB_MATRIX_INDICATOR_SET_COLOR(SCROLL_LOCK_LED_INDEX, rgb.r, rgb.g, rgb.b);
	} else {
		#if defined(INDICATORS_INHERIT_MODE)
		if (!rgb_matrix_get_flags()) {
			RGB_MATRIX_INDICATOR_SET_COLOR(SCROLL_LOCK_LED_INDEX, 0, 0, 0);
		}
		#else // INDICATORS_INHERIT_MODE
		RGB_MATRIX_INDICATOR_SET_COLOR(SCROLL_LOCK_LED_INDEX, 0, 0, 0);
		#endif // INDICATORS_INHERIT_MODE
	}
}
#endif // SCROLL_LOCK_LED_INDEX

// Set layer indicator color
#if defined(LAYER_LED_INDEX)
void set_layer_indicator(RGB rgb, uint8_t led_min, uint8_t led_max) {
	RGB_MATRIX_INDICATOR_SET_COLOR(LAYER_LED_INDEX, rgb.r, rgb.g, rgb.b);
}
#endif // LAYER_LED_INDEX

// Turn off indicators when RGB is turned off
#if defined(INDICATORS_TOGGLE_ALL)
void set_indicator_off(uint8_t led_min, uint8_t led_max) {
	if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
		RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, 0, 0, 0);
		RGB_MATRIX_INDICATOR_SET_COLOR(NUM_LOCK_LED_INDEX, 0, 0, 0);
		RGB_MATRIX_INDICATOR_SET_COLOR(SCROLL_LOCK_LED_INDEX, 0, 0, 0);
		RGB_MATRIX_INDICATOR_SET_COLOR(LAYER_LED_INDEX, 0, 0, 0);
	}
}
#endif // INDICATORS_TOGGLE_ALL
