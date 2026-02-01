#pragma once

#include "quantum.h"

// Public functions
void set_caps_lock_indicator(RGB rgb, uint8_t led_min, uint8_t led_max);
void set_num_lock_indicator(RGB rgb, uint8_t led_min, uint8_t led_max);
void set_scroll_lock_indicator(RGB rgb, uint8_t led_min, uint8_t led_max);
void set_layer_indicator(RGB rgb, uint8_t led_min, uint8_t led_max);
void set_indicator_off(uint8_t led_min, uint8_t led_max);
RGB get_layer_color(bool win_mode);
