// enables oled support
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void render_logo(void){
    static const char PROGMEM luna[] = {
    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0x04, 0x7e, 0x78, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xe0, 0xf8, 0xfc, 0xfe, 0xfe, 0xfe, 0x1f, 0xef, 0x17, 0x67, 0x77, 0x37, 0x3e, 
    0x3e, 0xfe, 0xfe, 0xfc, 0xf8, 0xf4, 0x8c, 0x36, 0xf6, 0xfa, 0x3a, 0x0a, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0xe0, 0xfc, 0x9f, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xbd, 0xfb, 0xfa, 0xfa, 0xf8, 0x3c, 
    0x3e, 0x3f, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x00, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x87, 0xef, 0xef, 0xfd, 0xfe, 0xfd, 0xff, 0xff, 0xef, 0xef, 
    0xef, 0xef, 0x07, 0x07, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0xf0, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xfc, 0xe0, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x60, 0x60, 0x60, 0x40, 0x00, 
    0x00, 0x00, 0x00, 0x7f, 0xff, 0xc7, 0x3f, 0xff, 0xff, 0x3f, 0xc0, 0xff, 0xff, 0xff, 0xff, 0x1f, 
    0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 
    0x01, 0x01, 0x01, 0x01, 0x01, 
    };
    oled_write_raw_P(luna, sizeof(luna));
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case U_NAV:
            {
                oled_write_ln_P(PSTR("NAV"), false);
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
            case U_BUTTON:
            {
                oled_write_ln_P(PSTR("BUTTON"), false);
                break;
            }
            case U_BASE:
            {
                oled_write_ln_P(PSTR("BASE"), false);
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
            default:
            {
                oled_write_ln_P(PSTR("NO CLUE"), false);
                break;
            }
        }
    }
    else
    {
        render_logo();
    }
    
    return false;
}

#endif