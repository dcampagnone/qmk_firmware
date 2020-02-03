#include QMK_KEYBOARD_H
extern bool g_suspend_state;
#define _BASE 0
#define _FUNCTION 1
#define _RGB 2
		/*
    # - Template
    .--------------------------------------------------------------------------------------------------------------------------------------.
    |        |        |        |        |        |        |        |        |        |        |        |        |        |                 |
    |        |        |        |        |        |        |        |        |        |        |        |        |        |                 |
    |--------------------------------------------------------------------------------------------------------------------------------------|
    |            |        |        |        |        |        |        |        |        |        |        |        |        |             |
    |            |        |        |        |        |        |        |        |        |        |        |        |        |             |
    |--------------------------------------------------------------------------------------------------------------------------------------|
    |               |        |        |        |        |        |        |        |        |        |        |        |                   |
    |               |        |        |        |        |        |        |        |        |        |        |        |                   |
    |--------------------------------------------------------------------------------------------------------------------------------------|
    |                   |        |        |        |        |        |        |        |        |        |               |        |        |
    |                   |        |        |        |        |        |        |        |        |        |               |        |        |
    |--------------------------------------------------------------------------------------------------------------------------------------|
    |          |          |          |                                                        |        |        |        |        |        |
    |          |          |          |                                                        |        |        |        |        |        |
    '--------------------------------------------------------------------------------------------------------------------------------------'
  */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
	/*
    0 - Base Layer
    .--------------------------------------------------------------------------------------------------------------------------------------.
    | ~      | !      | @      | #      | $      | %      | ^      | &      | *      | (      | )      | _      | +      |                 |
    | Esc    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | Backspace       |
    |--------------------------------------------------------------------------------------------------------------------------------------|
    |            |        |        |        |        |        |        |        |        |        |        | {      | }      | |           |
    | Tab        | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | [      | ]      | \           |
    |--------------------------------------------------------------------------------------------------------------------------------------|
    |               |        |        |        |        |        |        |        |        |        | :      | "      |                   |
    | L1            | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      | Enter             |
    |--------------------------------------------------------------------------------------------------------------------------------------|
    |                   |        |        |        |        |        |        |        | <      | >      |         ?     |        |  Del   |
    | Shift             | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | Shft    /     | Up     |   L2   |
    |--------------------------------------------------------------------------------------------------------------------------------------|
    |          |          |          |                                                        |        |        |        |        |        |
    | Ctrl     | Win      | Alt      | Space                                                  | Alt    |    L1  | Left   | Down   | Right  |
    '--------------------------------------------------------------------------------------------------------------------------------------'
  */
		KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,\
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,\
		MO(1), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,\
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH), KC_UP, LT(2,KC_DEL),\
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(1), KC_LEFT, KC_DOWN, KC_RGHT),
	[_FUNCTION] = LAYOUT(
		/*
    1 - Function Layer
    .--------------------------------------------------------------------------------------------------------------------------------------.
    |        |        |        |        |        |        |        |        |        |        |        |        |        |                 |
    |        | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | Del             |
    |--------------------------------------------------------------------------------------------------------------------------------------|
    |            |        |        |        |        |        |        |        |        |        |        |        |        |             |
    |            |        | Up     |        |        |        |Calc (y)|        |Ins     |        | Prev   |Vol Up  |Next    | Reset       |
    |--------------------------------------------------------------------------------------------------------------------------------------|
    |               |        |        |        |        |        |        |        |        |        |        |        |                   |
    |               |Left    |Down    |Right   |        |        |        |Prnt Scr|Scrl Lck|Pause   |Mute    |Vol Down|                   |
    |--------------------------------------------------------------------------------------------------------------------------------------|
    |                   |        |        |        |        |        |        |        |        |        |               |        |        |
    |                   |        |        |        |        |        |        |        |        |        |Shift          |Pg Up   |Calc    |
    |--------------------------------------------------------------------------------------------------------------------------------------|
    |          |          |          |                                                        |        |        |        |        |        |
    |          |          |          |                                                        |        |        |Home    |Pg Down |End     |
    '--------------------------------------------------------------------------------------------------------------------------------------'
  */
		KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,\
		KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_CALC, KC_TRNS, KC_INS, KC_TRNS, KC_MPRV, KC_VOLU, KC_MNXT, RESET,\
		KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_MUTE, KC_VOLD, KC_TRNS,\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RSFT, KC_PGUP, KC_CALC,\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END),
	[_RGB] = LAYOUT(
		/*
    2 - RGB Layer
    .--------------------------------------------------------------------------------------------------------------------------------------.
    |        |        |        |        |        |        |        |        |        |        |        |        |        |                 |
    |        | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | Del             |
    |--------------------------------------------------------------------------------------------------------------------------------------|
    |            |RGB     |        |Hue     |Hue     |Sat     |Sat     |Brt     |Brt     |RGB Mode|RGB Mode|        |        |             |
    |            |Tog (q) |        |+ (e)   |- (r)   |+ (t)   |- (y)   |+ (u)   |- (i)   |+ (o)   |- (p)   |        |        | Reset       |
    |--------------------------------------------------------------------------------------------------------------------------------------|
    |               |        |        |        |        |        |        |        |Effect  |Effect  |        |        |                   |
    |               |        |        |        |        |        |        |        |+ (k)   |- (l)   |        |        |                   |
    |--------------------------------------------------------------------------------------------------------------------------------------|
    |                   |        |        |        |        |        |        |        |        |        |               |        |        |
    |                   |        |        |        |        |        |        |        |        |        |               |        |        |
    |--------------------------------------------------------------------------------------------------------------------------------------|
    |          |          |          |                                                        |        |        |        |        |        |
    |          |          |          |                                                        |        |        |        |        |        |
    '--------------------------------------------------------------------------------------------------------------------------------------'
  */
		KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,\
		KC_TRNS, RGB_TOG, KC_TRNS, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_MOD, RGB_RMOD, KC_TRNS, KC_TRNS, RESET,\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_SPI, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS,\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};


void rgb_matrix_layer_helper (uint8_t red, uint8_t green, uint8_t blue, bool default_layer) {
  rgb_led led;
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    led = g_rgb_leds[i];
    if (led.matrix_co.raw < 0xFF) {
      if (led.modifier) {
          rgb_matrix_set_color( i, red, green, blue );
      }
    }
  }
}

void rgb_matrix_indicators_user(void) {
	  uint8_t this_led = host_keyboard_leds();
	  if (!g_suspend_state) {
	    switch (biton32(layer_state)) {
	      case _BASE:
		    break;
	      case _FUNCTION:
	        break;
	      case _RGB:
	        rgb_matrix_layer_helper(0xFF, 0xFF, 0x00, false); break;
	    							  }
	                        }
	  if ( this_led & (1<<USB_LED_CAPS_LOCK)) {
	        rgb_matrix_set_color(40, 0xFF, 0xFF, 0xFF);
	  }

	  switch (biton32(layer_state)) {
	      case _RGB:
	      	  if ( this_led & (1<<USB_LED_NUM_LOCK))
	      	  {
	    	 	  rgb_matrix_set_color(13, 0xFF, 0x00, 0x00);
	      	  }
	    	  else
	    	  {
	    		  rgb_matrix_set_color(13, 0x00, 0x00, 0x00);
	    	  }
	  	    rgb_matrix_set_color(0, 0x00, 0xFF, 0x00);
		    rgb_matrix_set_color(1, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(1, 0x00, 0xFF, 0x00);
	        rgb_matrix_set_color(2, 0x00, 0xFF, 0x00);
	        rgb_matrix_set_color(3, 0x00, 0xFF, 0x00);
	        rgb_matrix_set_color(4, 0x00, 0xFF, 0x00);
	        rgb_matrix_set_color(5, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(6, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(7, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(8, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(9, 0xFF, 0xFF, 0x00);
	        rgb_matrix_set_color(10, 0xFF, 0xFF, 0x00);
	        rgb_matrix_set_color(11, 0xFF, 0xFF, 0x00);
	        rgb_matrix_set_color(12, 0xFF, 0xFF, 0x00);
	        rgb_matrix_set_color(14, 0x00, 0x00, 0xFF);
	        rgb_matrix_set_color(15, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(16, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(17, 0x00, 0xFF, 0x00);
	       	rgb_matrix_set_color(18, 0x00, 0xFF, 0x00);
	       	rgb_matrix_set_color(19, 0x00, 0xFF, 0x00);
	        rgb_matrix_set_color(20, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(21, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(22, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(23, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(24, 0xFF, 0xFF, 0x00);
	        rgb_matrix_set_color(25, 0xFF, 0xFF, 0x00);
	        rgb_matrix_set_color(26, 0xFF, 0xFF, 0x00);
	        rgb_matrix_set_color(27, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(28, 0x00, 0xFF, 0x00);
	        rgb_matrix_set_color(29, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(30, 0x00, 0xFF, 0x00);
	        rgb_matrix_set_color(31, 0x00, 0xFF, 0x00);
	        rgb_matrix_set_color(32, 0x00, 0xFF, 0x00);
	        rgb_matrix_set_color(33, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(34, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(35, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(36, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(37, 0xFF, 0xFF, 0x00);
	        rgb_matrix_set_color(38, 0xFF, 0xFF, 0x00);
	        rgb_matrix_set_color(39, 0xFF, 0xFF, 0x00);
	        rgb_matrix_set_color(40, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(41, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(42, 0x00, 0x00, 0x00);
	       	rgb_matrix_set_color(43, 0x00, 0xFF, 0x00);
	       	rgb_matrix_set_color(44, 0x00, 0xFF, 0x00);
	       	rgb_matrix_set_color(45, 0x00, 0xFF, 0x00);
	        rgb_matrix_set_color(46, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(47, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(48, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(49, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(50, 0xFF, 0xFF, 0x00);
	        rgb_matrix_set_color(51, 0xFF, 0xFF, 0x00);
	        rgb_matrix_set_color(52, 0xFF, 0xFF, 0x00);
	        rgb_matrix_set_color(53, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(54, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(55, 0x00, 0x00, 0x00);
	        rgb_matrix_set_color(56, 0x00, 0x00, 0x00);
	       	rgb_matrix_set_color(57, 0x00, 0xFF, 0x00);
	       	rgb_matrix_set_color(58, 0x00, 0xFF, 0x00);
	        rgb_matrix_set_color(59, 0xFF, 0x00, 0x00);
	        rgb_matrix_set_color(60, 0xFF, 0xFF, 0x00);
	        rgb_matrix_set_color(61, 0xFF, 0xFF, 0x00);
	        rgb_matrix_set_color(62, 0x00, 0x00, 0x00);
	        break;
	    }
}

void matrix_init_user(void) {
  //user initialization
}

void matrix_scan_user(void) {
  //user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}
