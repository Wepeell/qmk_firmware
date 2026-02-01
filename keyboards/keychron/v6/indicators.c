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

// Get layer color
#if defined(CAPS_LOCK_LED_INDEX) || defined(NUM_LOCK_LED_INDEX) || defined(SCROLL_LOCK_LED_INDEX) || defined(LAYER_LED_INDEX) || defined(INDICATORS_TOGGLE_ALL)
RGB get_layer_color(bool win_mode) {
	// Declare color variables
	HSV hsv;
	RGB rgb;

	// Set the different layer colors
	HSV mac_base_hsv = {85, 255, 255};	// Layer 0 MAC Green
	HSV mac_fn_hsv = {0, 255, 255};		// Layer 1 MAC Function Red
	HSV win_base_hsv = {170, 255, 255};	// Layer 2 Windows Blue
	HSV win_fn_hsv = {234, 255, 255};	// Layer 3 Windows Function Pink

	// Set layer name to index
	#define MAC_BASE 0
	#define MAC_FN   1
	#define WIN_BASE 2
	#define WIN_FN   3

	// Set HSV color per layer
	uint8_t current_layer = get_highest_layer(layer_state);
	switch (current_layer) {
		case MAC_BASE:
			if (!win_mode) {
				hsv = mac_base_hsv; // Layer 0
				break;
			} else {
				// Fall to next case
			}
		case MAC_FN:
			hsv = mac_fn_hsv; // Layer 1
			break;
		case WIN_BASE:
			hsv = win_base_hsv; // Layer 2
			break;
		case WIN_FN:
			hsv = win_fn_hsv; // Layer 3
			break;
		default:
			break;
	}

	// Set HSV brightness
	if (hsv.v != rgb_matrix_get_val()) {
		hsv.v = rgb_matrix_get_val();
	}

	// Convert to RGB
	rgb = hsv_to_rgb(hsv);

	// Return RGB
	return rgb;
}
#endif // Get layer color
