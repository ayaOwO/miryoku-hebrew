// custom keycodes used for changing language
// alt + shift, changes base layer 
enum custom_keycodes {
    changeToDvorak = SAFE_RANGE,
    changeToHebrew,
    changeToQwerty,
    changeToSteno
};

// custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    //set_keylog(keycode, record);
    switch (keycode) {
      case changeToDvorak:
      {
        // change language
        if (layer_state_is(HEB))
        {
          register_code(KC_LALT);
          register_code(KC_LSFT);
          unregister_code(KC_LALT);
          unregister_code(KC_LSFT);
        }
          layer_move(BASE);
          return false;

        break;
      }
      case changeToHebrew:
      {
        // change language
          register_code(KC_LALT);
          register_code(KC_LSFT);
          unregister_code(KC_LALT);
          unregister_code(KC_LSFT);
          layer_move(HEB);
          return false;
        break;
      }
      case changeToQwerty:
      {
        // change language
        if (layer_state_is(HEB)){
          register_code(KC_LALT);
          register_code(KC_LSFT);
          unregister_code(KC_LALT);
          unregister_code(KC_LSFT);
        }
        layer_move(GAME);
        return false;
        break;
      }
      case changeToSteno:
      {
        // change language
        if (layer_state_is(HEB)){
          register_code(KC_LALT);
          register_code(KC_LSFT);
          unregister_code(KC_LALT);
          unregister_code(KC_LSFT);
        }
        layer_move(STENO);
        return false;
        break;
      }
    }
  }
  return true;
}
