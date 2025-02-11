static void echo_char_raw(unsigned char c, struct n_tty_data *ldata)
{
    if (c >= 0 && c <= 0xFF) { 
        if (ldata->echo_buffer_size > 0 && ldata->echo_buffer_pos < ldata->echo_buffer_size) {
            ldata->echo_buffer[ldata->echo_buffer_pos++] = c; 
        }
    } else {
        // handle invalid input character
    }
}