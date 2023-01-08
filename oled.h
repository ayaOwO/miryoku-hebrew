// enables oled support
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    switch (get_highest_layer(layer_state)) {
        case U_NAV:
        {
            oled_write_ln_P(PSTR("NAV"), false);
            break;
        }
        case U_EXTRA:
        {
            oled_write_ln_P(PSTR("EXTRA"), false);
            break;
        }
        case U_TAP:
        {
            oled_write_ln_P(PSTR("TAP"), false);
            break;
        }
        case U_MEDIA:
        {
            oled_write_ln_P(PSTR("MEDIA"), false);
            break;
        }
        case U_NUM:
        {
            oled_write_ln_P(PSTR("NUM"), false);
            break;
        }
        case U_MOUSE:
        {
            oled_write_ln_P(PSTR("MOUSE"), false);
            break;
        }
        case U_SYM:
        {
            oled_write_ln_P(PSTR("SYM"), false);
            break;
        }
        case U_FUN:
        {
            oled_write_ln_P(PSTR("FUN"), false);
            break;
        }
        case U_BASE:
        {
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        }
        default:
        {
            oled_write_ln_P(PSTR("NO CLUE"), false);
            break;
        }
    }
    return false;
}

#endif