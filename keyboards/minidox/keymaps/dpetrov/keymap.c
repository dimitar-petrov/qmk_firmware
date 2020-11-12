#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum my_layers {
                _AREN,
                _SYS,
                _NAV,
                _NUM_E,
                _SYM
};

enum my_keycodes {
                  AREN = SAFE_RANGE,
                  SYS,
                  NAV,
                  NUM_E,
                  SYM
};

#define ALT_E LALT_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define CTRL_R LCTL_T(KC_R)
#define CTRL_T LCTL_T(KC_T)
#define GUI_N LGUI_T(KC_N)
#define GUI_S LGUI_T(KC_S)
#define NAV_SP LT(_NAV, KC_SPC)
#define NAV_LK TG(_NAV)
#define NAV_OS OSL(_NAV)
#define NUME_ENT LT(_NUM_E, KC_ENT)
#define NUME OSL(_NUM_E)
#define NUMLK_E TG(_NUM_E)
/* #define SFT_A LSFT_T(KC_A) */
/* #define SFT_O LSFT_T(KC_O) */
#define SFT_SLASH LSFT_T(KC_SLASH)
#define SFT_BS LSFT_T(KC_BSPC)
#define SFT_OS OSM(MOD_LSFT)
/* #define SYM_COMM LT(_SYM, KC_COMMA) */
/* #define SYM_U LT(_SYM, KC_U) */
#define SYM_SPC LT(_SYM, KC_SPC)
#define SYM_OS OSL(_SYM)
#define SYS_Z LT(_SYS, KC_Z)
#define VOL_DN S(LALT(KC__VOLDOWN))
#define VOL_UP S(LALT(KC__VOLUP))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* AREN
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   L  |   ,  |   P  |   \  |           |   -  |   F  |   U  |   D  |   K  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  | CTL/R| ALT/E| GUI/N|   B  |           |   G  | GUI/S| ALT/I| CTL/T|   O  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SYS/Z|   W  |   .  |   H  |   J  |           |   V  |   C  |   Y  |   M  |   X  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  | SFT//|NV/SPC|      |    |      |  SYM |SFT/BS|
 *                  `------+------|NU/ENT|    | ESC  |------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_AREN] = LAYOUT( \
  KC_Q,  KC_L,   KC_COMMA,  KC_P,   KC_BSLS,        KC_MINS, KC_F,   KC_U,   KC_D,   KC_K, \
  KC_A,  CTRL_R, ALT_E,     GUI_N,  KC_B,           KC_G,    GUI_S,  ALT_I,  CTRL_T, KC_O, \
  SYS_Z, KC_W,   KC_DOT,    KC_H,   KC_J,           KC_V,    KC_C,   KC_Y,   KC_M,   KC_X, \
                 SFT_SLASH, NAV_SP, NUME_ENT,       KC_ESC,  SYM_OS, SFT_BS                \
),

/* System, media, and layer lock keys
 *
 * ,----------------------------------.           ,----------------------------------.
 * | RESET|DEBUG |      |      | AREN |           |      | VOL--| VOL++|BRITE-|BRITE+|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SHIFT| CTRL |  ALT |  GUI |NAV LK|           | POWER| VOL- | VOL+ | MUTE | MPLY |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |AU OFF| AU ON|      |           |      |NUM LK| MRWD | MFFD |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |KC_APP|      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_SYS] = LAYOUT( \
  RESET,   DEBUG,   _______, _______, AREN,           _______,  KC_VOLD, KC_VOLU, KC_BRID,  KC_BRIU, \
  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, NAV_LK,        KC_POWER, VOL_DN,  VOL_UP,  KC__MUTE, KC_MPLY, \
  _______, _______, AU_OFF,  AU_ON,   _______,       _______,  NUMLK_E, KC_MRWD, KC_MFFD,  _______, \
                    _______, _______, _______,       KC_APP,  _______, _______                     \
),

/* Navigation + mouse keys
 *
 * ,----------------------------------.           ,----------------------------------.
 * | PSCR |      | WH U | WH D |      |           | BSPC | PGDN | PGUP | HOME |  END |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SHIFT| CTRL |  ALT |  GUI |NAV LK|           | CAPS | LEFT | DOWN |  UP  | RIGHT|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      | ACL0 | ACL1 | ACL2 | BTN2 |           | BTN1 | MS L | MS D | MS U | MS R |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      |      |      |    |      | TAB  |      |
 *                  `------+------|  ESC |    | DEL  |------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_NAV] = LAYOUT( \
  KC_PSCR, _______, KC_WH_U, KC_WH_D, _______,       KC_BSPC, KC_PGDN, KC_PGUP, KC_HOME, KC_END,  \
  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, NAV_LK,        KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, \
  _______, KC_ACL0, KC_ACL1, KC_ACL2, KC_BTN2,       KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, \
                    _______, _______, KC_ESC,        KC_DEL,  KC_TAB,  _______                    \
),

/* Number + function keys (ergonomic number order - default pairing with Arensito)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |  F7  |  F8  |  F9  |  F10 |           |   -  |   7  |   8  |   9  |   +  |
 * |------|------+------+------+------+           |------+------+------+------+------|
 * |      |  F4  |  F5  |  F6  |  F11 |           |   .  |   4  |   5  |   6  |   =  |
 * |------|------+------+------+------+           |------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F12 |           | NMLK |   1  |   2  |   3  |  INS |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      |      |      |    |      |  0   |      |
 *                  `------+------|      |    |      |------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_NUM_E] = LAYOUT( \
  _______, KC_F7, KC_F8, KC_F9, KC_F10,           KC_MINS, KC_7, KC_8, KC_9, KC_PLUS, \
  _______, KC_F4, KC_F5, KC_F6, KC_F11,           KC_DOT,  KC_4, KC_5, KC_6, KC_EQUAL, \
  _______, KC_F1, KC_F2, KC_F3, KC_F12,           NUMLK_E, KC_1, KC_2, KC_3, KC_INS, \
             _______, _______, _______,           _______, KC_0, _______               \
),

/* Symbols
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   ?  |   '  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   +  |   {  |   [  |   (  |   "  |           |   :  |   )  |   ]  |   }  |   =  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   _  |   |  |   -  |   <  |   \  |           |   /  |   >  |   `  |   ~  |   ;  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      |      |      |    |      |      |      |
 *                  `------+------|      |    |      |------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_SYM] = LAYOUT( \
  KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_QUES, KC_QUOT,  \
  KC_PLUS,  KC_LCBR, KC_LBRC, KC_LPRN, KC_DQT,        KC_COLN, KC_RPRN, KC_RBRC, KC_RCBR, KC_EQUAL, \
  KC_UNDS,  KC_PIPE, KC_MINS, KC_LT,   KC_BSLS,       KC_SLSH, KC_GT,   KC_GRV,  KC_TILD, KC_SCLN,  \
                     _______, _______, _______,       _______, _______, _______                     \
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case AREN:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_AREN);
        }
        return false;
    default:
        return true;
    }
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
         case LSFT_T(KC_SLASH):
            return TAPPING_TERM - 25;
        case LSFT_T(KC_BSPC):
            return TAPPING_TERM - 25;
        default:
            return TAPPING_TERM - 25;
    }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
         case LSFT_T(KC_SLASH):
	   return false;
        case LSFT_T(KC_BSPC):
	   return false;
        default:
	   return true;
    }
}
