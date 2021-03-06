#include QMK_KEYBOARD_H
#include "mimkorn.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _PESKY 1
#define _SYMB 2
#define _NUMPAD 3
#define _NAV 4 
#define _MOUSE 5
#define _MEDIA 6
#define _ADJUST 7
#define _EMPTY 8

enum custom_keycodes { QWERTY = SAFE_RANGE, SYMB, NAV, ADJUST, D_ACNT, d_ACNT, R_LONG, R_ACNT, O_LONG, L_LONG, KC_UO, KC_AE, n_ACNT, N_ACNT, QMKURL, MY_OTHER_MACRO, CLECODE, ENDHASH };

//Tap Dance Declarations
enum {
  TD_RSFT_CAPS = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_RSFT_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_CAPS)
// Other declarations would go here, separated by commas, if you have them
};

// enum unicode_names {
//     V_D_O,
//     M_D_O,
//     V_UO,
//     M_UO,
//     M_M_D,
//     V_M_D,
//     M_S_A,
//     V_S_A,
//     M_M_N,
//     V_M_N
// };

// const uint32_t PROGMEM unicode_map[] = {
//     [V_D_O] = 0x00D4, 
//     [M_D_O] = 0x00D4,
//     [V_UO] = 0x00D4,
//     [M_UO] = 0x00F4,
//     [M_M_D] = 0x00F4,
//     [V_M_D] = 0x00F4,
//     [M_S_A] = 0x00F4,
//     [M_M_N] = 0x00F4,
//     [V_S_A] = 0x00F4,
//     [V_M_N] = 0x00F4
// };

// Shortcut to make keymap more readable
#define SYM_L MO(_SYMB)
#define NUM_L MO(_NUMPAD)
#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAV1 LT(_NAV, KC_1)
#define KC_NDLZN LT(_NAV, KC_EQL)  // actually ˇ' in SVK
#define KC_MDLZN LT(_MEDIA, KC_EQL)  // actually ˇ' in SVK

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

#define MY_LGZ S(KC_RBRC)
#define MY_PGZ S(KC_BSLS)



void tap_caps(void){
   SEND_STRING(SS_DOWN(X_CAPS) SS_DELAY(120) SS_UP(X_CAPS));
}

void dlzen_pocas_lsft(void){
   SEND_STRING(SS_UP(X_LSFT) SS_TAP(X_EQL) SS_DOWN(X_LSFT));
}

void dlzen_pocas_rsft(void){
   SEND_STRING(SS_UP(X_RSFT) SS_TAP(X_EQL) SS_DOWN(X_RSFT));
}

void pridaj_tag_na_spod_suboru(void){
   SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_DOWN) SS_UP(X_LGUI) SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_TAP(X_ENTER) SS_TAP(X_ENTER) SS_LALT("3")
               SS_TAP(X_ENTER) SS_TAP(X_UP) SS_TAP(X_RIGHT));
}

//#define KC_UO XP(M_UO, V_UO)
#define PESKY OSL(_PESKY)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool isShifted;
    isShifted = get_mods() & MOD_MASK_SHIFT;
   
    //äóďôĺ
    switch (keycode) {
        case KC_UO:
            if (record->event.pressed) {
                if (isShifted) {
                    tap_caps();
                    SEND_STRING(SS_UP(X_LSFT) SS_TAP(X_SCLN) SS_DOWN(X_LSFT));
                    tap_caps();
                } else {
                    SEND_STRING(SS_TAP(X_SCLN));
                }
            }
            break;
        case D_ACNT:
            if (record->event.pressed) {
                if (isShifted) {
                    SEND_STRING(SS_TAP(X_EQL) SS_TAP(X_D));
                } else {
                    SEND_STRING(SS_LSFT(SS_TAP(X_EQL)) SS_TAP(X_D));
                }
            }
            break;
        case O_LONG:
            if (record->event.pressed) {
                if (isShifted) {
                    dlzen_pocas_lsft();
                    SEND_STRING(SS_TAP(X_O));
                } else {
                    SEND_STRING(SS_TAP(X_EQL) SS_TAP(X_O));
                }
            }
            break;
        case L_LONG:
            if (record->event.pressed) {
                if (isShifted) {
                    dlzen_pocas_lsft();
                    SEND_STRING(SS_TAP(X_L));
                } else {
                    SEND_STRING(SS_TAP(X_EQL) SS_TAP(X_L));
                }
            }
            break;
            case R_LONG:
            if (record->event.pressed) {
                if (isShifted) {
                    dlzen_pocas_lsft();
                    SEND_STRING(SS_TAP(X_R));
                } else {
                    SEND_STRING(SS_TAP(X_EQL) SS_TAP(X_R));
                }
            }
            break;
            case R_ACNT:
            if (record->event.pressed) {
                if (isShifted) {
                    SEND_STRING(SS_TAP(X_EQL) SS_TAP(X_R));
                } else {
                    SEND_STRING(SS_LSFT(SS_TAP(X_EQL)) SS_TAP(X_R));
                }
            }
            break;
            case N_ACNT:
            if (record->event.pressed) {
                if (isShifted) {
                    SEND_STRING(SS_TAP(X_EQL) SS_TAP(X_N));
                } else {
                    SEND_STRING(SS_LSFT(SS_TAP(X_EQL)) SS_TAP(X_N));
                }
            }
            break;
        case KC_AE:
            if (record->event.pressed) {
                if (isShifted) {
                    tap_caps();
                    SEND_STRING(SS_UP(X_LSFT) SS_TAP(X_RBRC) SS_DOWN(X_LSFT));
                    tap_caps();
                } else {
                    SEND_STRING(SS_TAP(X_RBRC));
                }
            }
            break;
         case ENDHASH:
            if (record->event.pressed) {
               pridaj_tag_na_spod_suboru();
            }
            break;
         case CLECODE:
            if (record->event.pressed) {
               pridaj_tag_na_spod_suboru();
               SEND_STRING("clean=code");
            }
            break;
    }

    return true;
};

// void eeconfig_init_user(void) {
//     set_unicode_input_mode(UC_MAC);
// }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_6    ,                                            KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,KC_MDLZN,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,A(KC_SCLN),                        SYM_L   ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_LBRC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,NUM_L   ,                          NUM_L   ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,PESKY   ,MO(_MOUSE),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_PGUP ,KC_PGDN ,        KC_HOME ,KC_END  ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,TD(TD_RSFT_CAPS),
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_HYPR ,KC_CAPS ,KC_LALT ,     KC_LGUI ,    KC_BSPC ,KC_DEL  ,        KC_ENT  ,KC_SPC  ,    MO(_NAV),     SYM_L   ,KC_DOWN ,KC_HYPR ,KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_PESKY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     MO(_NAV),KC_2    ,KC_3    ,KC_4    ,R_ACNT  ,KC_6    ,                                            KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_GRV  ,KC_NDLZN,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,A(KC_R) ,A(KC_2), A(KC_7) ,R_LONG  ,A(KC_5) ,KC_F6   ,                          SYM_L   ,KC_Y    ,KC_U    ,S(KC_SCLN),O_LONG,KC_SCLN ,KC_LBRC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,KC_AE   ,A(KC_SCLN),D_ACNT,KC_F    ,KC_G    ,SYM_L   ,                          A(KC_QUOT),KC_H,S(KC_QUOT),A(KC_QUOT),L_LONG,KC_UO   ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_ADPU ,KC_PGDN ,        KC_HOME ,KC_ADEN ,N_ACNT    ,KC_M    ,S(KC_QUOT),KC_DOT,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_PPLS ,KC_PMNS ,KC_LALT ,     KC_LGUI ,    KC_BSPC ,KC_DEL  ,        KC_ENT  ,KC_SPC  ,    KC_RALT ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F8   ,KC_F9   ,KC_F10  ,KC_F11,  KC_F12  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_EXLM ,KC_AT   ,A(KC_7) ,A(KC_R) ,A(KC_5) ,KC_F6   ,                          KC_F7   ,KC_PSLS ,KC_P7 	,KC_P8 	,KC_P9   ,KC_PMNS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______,S(KC_RBRC),A(KC_LBRC),A(KC_COMM),A(KC_9),KC_GRV,_______,                        _______,A(KC_3),A(KC_0),A(KC_DOT),A(KC_RBRC),S(KC_BSLS),XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_PERC ,A(KC_6) ,KC_LPRN ,KC_RPRN ,KC_GRV  ,_______ ,_______ ,        _______ ,_______ ,XXXXXXX ,KC_P1 	,S(KC_QUOT),KC_P3 ,KC_PENT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    A(KC_BSPC),A(KC_DEL),     _______ ,_______ ,    KC_P0   ,     KC_P0   ,KC_PDOT ,KC_PENT ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

    [_NUMPAD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F8   ,KC_F9   ,KC_F10  ,KC_F11,  KC_F12  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_F6   ,                          KC_F7   ,KC_PSLS ,KC_P7 	,KC_P8 	,KC_P9   ,KC_PMNS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,KC_PAST ,KC_P4 	,KC_P5   ,KC_P6   ,KC_PPLS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,        _______ ,_______ ,XXXXXXX ,KC_P1 	,KC_P2   ,KC_P3   ,KC_PENT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    KC_P0   ,     KC_P0   ,KC_PDOT ,KC_PENT ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,KC_PGUP ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,KC_WH_U ,_______ ,                          _______ ,G(KC_Y), KC_HOME, KC_UP   ,KC_END  ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,KC_WH_D ,_______ ,                          _______ ,XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_RIGHT,KC_SCLN ,KC_ENT  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,G(KC_LBRC),G(KC_RBRC),    _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_PGDN ,XXXXXXX ,XXXXXXX ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    G(KC_BSPC),G(KC_DEL),     _______ ,_______ ,    XXXXXXX ,     KC_RGUI ,KC_RALT ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

   [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_D ,XXXXXXX ,                          _______ ,_______ ,KC_WH_U ,KC_WH_D ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_LSFT ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_U ,XXXXXXX ,                          _______ ,_______ ,KC_LCTL ,KC_LALT ,KC_LGUI ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_BTN3 ,KC_WBAK ,KC_WFWD ,        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,_______ ,     _______ ,    KC_BTN1 ,KC_BTN2 ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

   [_MEDIA] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,RESET   ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,KC_MPRV ,KC_MNXT ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_SLCK ,KC_PAUS, KC__VOLDOWN,KC__VOLUP,KC__MUTE,_______ ,                      _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______,C(S(KC_POWER)),_______,_______,_______,_______,       _______ ,_______ ,ENDHASH ,CLECODE ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    KC_MPLY ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,RESET   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX ,        XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

   [_EMPTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
   )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _QWERTY:
            set_led_off;
            break;
        case _SYMB:
            set_led_green;
            break;
        case _NAV:
            set_led_blue;
            break;
        case _ADJUST:
            set_led_red;
            break;
        default:
            break;
    }
  return state;
}


