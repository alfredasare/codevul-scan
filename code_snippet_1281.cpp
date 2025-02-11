INST_HANDLER (adc) {	// ADC Rd, Rr
    if ((buf[0] < 0xf && buf[1] < 2) || buf[0] == 0xf && buf[1] == 0) {
        int d = ((buf[0] >> 4) & 0xf) | ((buf[1] & 1) << 4);
        int r = (buf[0] & 0xf) | ((buf[1] & 2) << 3);
        ESIL_A ("r%d,cf,+,r%d,+,", r, d);	// Rd + Rr + C
        __generic_add_update_flags_rr(op, d, r);	// FLAGS
        ESIL_A ("r%d,=,", d);				// Rd = result
    } else {
        // Handle invalid input error
        //...
    }
}