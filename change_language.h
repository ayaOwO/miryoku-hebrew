#define CHANGE_LANGUAGE

#if defined (MIRYOKU_EXTRA_HEBREW)
  #if !defined (MIRYOKU_ALPHAS_HEBREW)
    #undef CHANGE_LANGUAGE 
    #define CHANGE_LANGUAGE \
        register_code(KC_LALT); \
        register_code(KC_LSFT); \
        unregister_code(KC_LALT); \
        unregister_code(KC_LSFT);
  #endif
#else 
  #if defined (MIRYOKU_ALPHAS_HEBREW)
    #if !defined (MIRYOKU_EXTRA_HEBREW)
      #undef CHANGE_LANGUAGE 
      #define CHANGE_LANGUAGE \
          register_code(KC_LALT); \
          register_code(KC_LSFT); \
          unregister_code(KC_LALT); \
          unregister_code(KC_LSFT);
  #endif
#endif
#endif