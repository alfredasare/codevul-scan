static void echo_char_raw(unsigned char c, struct n_tty_data *ldata)
{
	if (c == ECHO_OP_START) {
		add_echo_byte(ECHO_OP_START, ldata);
	} else {
		// Check if adding the character will cause buffer overflow
		if (ldata->echo_buf_ptr < ldata->echo_buf_end) {
			*ldata->echo_buf_ptr++ = c;
		}
	}
}