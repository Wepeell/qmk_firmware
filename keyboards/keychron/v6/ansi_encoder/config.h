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

#pragma once

/* Key matrix pins */
#define MATRIX_ROW_PINS { B5, B4, B3, A15, A14, A13 }
#define MATRIX_COL_PINS { A10, A9, A8, B1, B0, A7, A6, A5, A4, A3, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN }

/* Pin connected to DS of 74HC595 */
#define DATA_PIN_74HC595 C15
/* Pin connected to SH_CP of 74HC595 */
#define CLOCK_PIN_74HC595 A1
/* Pin connected to ST_CP of 74HC595 */
#define LATCH_PIN_74HC595 A0
/* Pin used number of 74HC595 */
#define PIN_USED_74HC595 10
/* Pin used index start of 74HC595 */
#define PIN_START_74HC595 10

/* Encoder Configuration */
#define ENCODER_DEFAULT_POS 0x3

/* Enable Caps Lock LED*/
// #define CAPS_LOCK_LED_INDEX 61
#define CAPS_LOCK_LED_INDEX 18

/* Enable Num Lock LED */
// #define NUM_LOCK_LED_INDEX 37
#define NUM_LOCK_LED_INDEX 17

/* Enable Scroll Lock LED */
// #define SCROLL_LOCK_LED_INDEX 14
#define SCROLL_LOCK_LED_INDEX 19

/* Enable Layer LED */
#define LAYER_LED_INDEX 16

/* Toggle indicators together with RM_TOGG */
// #define INDICATORS_TOGGLE_ALL

/* If commented out, when indicators are turned off they will inherit the color of the current RGB mode. 
	If turned on, when indicators are turned off they will always be off */
// #define INDICATORS_OFF_MODE

/* Default RGB Settings */
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_REACTIVE_SIMPLE // Default mode 
#define RGB_MATRIX_DEFAULT_HUE 0 // Default hue
#define RGB_MATRIX_DEFAULT_SAT 0 // Default saturation
#define RGB_MATRIX_DEFAULT_VAL 80 // Default brightness, 16 per step
#define RGB_MATRIX_DEFAULT_SPD 32 // Default effect speed, 16 per step

// Reactive effects respond to key releases (instead of key presses)
#define RGB_MATRIX_KEYRELEASES

/* Force NKRO on by default, can still be turned off with FN + N */
#define NKRO_DEFAULT_ON true
