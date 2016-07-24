// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _PLOVER 3
#define _I3 4
#define _ADJUST 16

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  PLOVER,
  LOWER,
  RAISE,
  EXT_PLV
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Caps | GUI  | Alt  |Lower |    Space    |Raise |Leader|      |      |  i3  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_ESC,  KC_CAPS, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEAD, _______, _______, MO(_I3)}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, KC_ENT},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, KC_ENT},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Reset|      |      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Aud on|Audoff|AGnorm|AGswap|Qwerty|Plover| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL},
  {AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  PLOVER,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______},
  {MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* i3 layer
 * ,-----------------------------------------------------------------------------------.
 * |      |                             Go to 1 - 9                             |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |                            Move to 1 - 9                            |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |                             Make 1 - 9                              |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_I3] = {
  {_______, M(1),    M(2),    M(3),    M(4),    M(5),    M(6),    M(7),    M(8),    M(9),    _______, _______},
  {_______, M(11),   M(12),   M(13),   M(14),   M(15),   M(16),   M(17),   M(18),   M(19),   _______, _______},
  {_______, M(21),   M(22),   M(23),   M(24),   M(25),   M(26),   M(27),   _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |TogOut|   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = {
  {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
  {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
  {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
}

};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
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
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_NOTE_ARRAY(tone_plover, false, 0);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_plover_gb, false, 0);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}

const macro_t *action_get_macro (keyrecord_t *record, uint8_t id, uint8_t opt)
{
    /* Yes, I know. Trust me, I don't like this function anymore than you do.
     * It must be the worst function I've written in years (probably since the
     * last time I wrote C). I'll refactor it later after I'm more familiar with
     * this codebase and I've figured out how to translate a uint8_t to a keycode.
     * For now, it works.
     */

    if (!(record->event.pressed)) {
        return MACRO_NONE;
    }
    switch (id) {
        // Go to id
        case 1:
            return MACRO (D(LALT), T(1), U(LALT), END);
        case 2:
            return MACRO (D(LALT), T(2), U(LALT), END);
        case 3:
            return MACRO (D(LALT), T(3), U(LALT), END);
        case 4:
            return MACRO (D(LALT), T(4), U(LALT), END);
        case 5:
            return MACRO (D(LALT), T(5), U(LALT), END);
        case 6:
            return MACRO (D(LALT), T(6), U(LALT), END);
        case 7:
            return MACRO (D(LALT), T(7), U(LALT), END);
        case 8:
            return MACRO (D(LALT), T(8), U(LALT), END);
        case 9:
            return MACRO (D(LALT), T(9), U(LALT), END);

        // Move to id
        case 11:
            return MACRO( D(LALT), D(LSFT), T(1), U(LSFT), U(LALT), END );
        case 12:
            return MACRO( D(LALT), D(LSFT), T(2), U(LSFT), U(LALT), END );
        case 13:
            return MACRO( D(LALT), D(LSFT), T(3), U(LSFT), U(LALT), END );
        case 14:
            return MACRO( D(LALT), D(LSFT), T(4), U(LSFT), U(LALT), END );
        case 15:
            return MACRO( D(LALT), D(LSFT), T(5), U(LSFT), U(LALT), END );
        case 16:
            return MACRO( D(LALT), D(LSFT), T(6), U(LSFT), U(LALT), END );
        case 17:
            return MACRO( D(LALT), D(LSFT), T(7), U(LSFT), U(LALT), END );
        case 18:
            return MACRO( D(LALT), D(LSFT), T(8), U(LSFT), U(LALT), END );
        case 19:
            return MACRO( D(LALT), D(LSFT), T(9), U(LSFT), U(LALT), END );

        // Make current id
        case 21:
            return MACRO(
                W(100), D(LALT),
                // move all current windows to 8
                D(LSFT), T(8), T(8), T(8), T(8), T(8), U(LSFT),
                // Go to target
                T(1),
                // Move all windows to 9
                D(LSFT), T(9), T(9), T(9), T(9), T(9), U(LSFT),
                // Go to 8
                T(8),
                // Move all windows to target
                D(LSFT), T(1), T(1), T(1), T(1), T(1), U(LSFT),
                // Go to target
                T(1),
                // Go to 9
                T(9),
                U(LALT), END
            );
        case 22:
            return MACRO(
                W(100), D(LALT),
                D(LSFT), T(8), T(8), T(8), T(8), T(8), U(LSFT),
                T(2),
                D(LSFT), T(9), T(9), T(9), T(9), T(9), U(LSFT),
                T(8),
                D(LSFT), T(2), T(2), T(2), T(2), T(2), U(LSFT),
                T(2), T(9), U(LALT), END
            );
        case 23:
            return MACRO(
                W(100), D(LALT),
                D(LSFT), T(8), T(8), T(8), T(8), T(8), U(LSFT),
                T(3),
                D(LSFT), T(9), T(9), T(9), T(9), T(9), U(LSFT),
                T(8),
                D(LSFT), T(3), T(3), T(3), T(3), T(3), U(LSFT),
                T(3), T(9), U(LALT), END
            );
        case 24:
            return MACRO(
                W(100), D(LALT),
                D(LSFT), T(8), T(8), T(8), T(8), T(8), U(LSFT),
                T(4),
                D(LSFT), T(9), T(9), T(9), T(9), T(9), U(LSFT),
                T(8),
                D(LSFT), T(4), T(4), T(4), T(4), T(4), U(LSFT),
                T(4), T(9), U(LALT), END
            );
        case 25:
            return MACRO(
                W(100), D(LALT),
                D(LSFT), T(8), T(8), T(8), T(8), T(8), U(LSFT),
                T(5),
                D(LSFT), T(9), T(9), T(9), T(9), T(9), U(LSFT),
                T(8),
                D(LSFT), T(5), T(5), T(5), T(5), T(5), U(LSFT),
                T(5), T(9), U(LALT), END
            );
        case 26:
            return MACRO(
                W(100), D(LALT),
                D(LSFT), T(8), T(8), T(8), T(8), T(8), U(LSFT),
                T(6),
                D(LSFT), T(9), T(9), T(9), T(9), T(9), U(LSFT),
                T(8),
                D(LSFT), T(6), T(6), T(6), T(6), T(6), U(LSFT),
                T(6), T(9), U(LALT), END
            );
        case 27:
            return MACRO(
                W(100), D(LALT),
                D(LSFT), T(8), T(8), T(8), T(8), T(8), U(LSFT),
                T(7),
                D(LSFT), T(9), T(9), T(9), T(9), T(9), U(LSFT),
                T(8),
                D(LSFT), T(7), T(7), T(7), T(7), T(7), U(LSFT),
                T(7), T(9), U(LALT), END
            );
    }
    return MACRO_NONE;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

LEADER_EXTERNS();

void matrix_scan_user (void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F) {
      register_code(KC_S);
      unregister_code(KC_S);
    }
  }
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
