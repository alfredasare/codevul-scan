static int cmd_yank(void *data, const char *input) {
	ut64 n;
	RCore *core = (RCore *)data;
	switch (input[0]) {
	case ' ':
		r_core_yank (core, core->offset, r_num_math (core->num, input + 1));
		break;
	case 'l':
		core->num->value = core->yank_buf->length;
		break;
	case 'y':
		while (input[1] == ' ') {
			input++;
		}
		n = input[1]? r_num_math (core->num, input + 1): core->offset;
		r_core_yank_paste (core, n, 0);
		break;
	case 'x':
		r_core_yank_hexdump (core, r_num_math (core->num, input + 1));
		break;
	case 'z':
		r_core_yank_string (core, core->offset, r_num_math (core->num, input + 1));
		break;
	case 'w':
		switch (input[1]) {
		case ' ':
			r_core_yank_set (core, 0, (const ut8*)input + 2, strlen (input + 2));
			break;
		case 'x':
			if (input[2] == ' ') {
				char *out = strdup (input + 3);
				int len = r_hex_str2bin (input + 3, (ut8*)out);
				if (len> 0) {
					r_core_yank_set (core, 0LL, (const ut8*)out, len);
				} else {
					eprintf ("Invalid length\n");
				}
				free (out);
			} else {
				eprintf ("Usage: ywx [hexpairs]\n");
			}
			break;
		}
		break;
	case 'p':
		r_core_yank_cat (core, r_num_math (core->num, input + 1));
		break;
	case 's':
		r_core_yank_cat_string (core, r_num_math (core->num, input + 1));
		break;
	case 't': // "wt"
		if (input[1] == 'f') { // "wtf"
			const char *file = r_str_chop_ro (input + 2);
			if (!r_file_dump (file, core->yank_buf->buf, core->yank_buf->length, false)) {
				eprintf ("Cannot dump to '%s'\n", file);
			}
		} else {
			r_core_yank_to (core, input + 1);
		}
		break;
	case 'f':
		switch (input[1]) {
		case ' ': // "wf"
			r_core_yank_file_ex (core, input + 1);
			break;
		case 'a': // "wfa"
			r_core_yank_file_all (core, input + 2);
			break;
		}
		break;
	case '\0':
		r_core_yank_dump (core, r_num_math (core->num, ""));
		break;
	default:{
		const char* help_msg[] = {
		"Usage:", "y[ptxy] [len] [[@]addr]", " # See wd? for memcpy, same as 'yf'.",
		"y", "", "show yank buffer information (srcoff len bytes)",
		"y", " 16", "copy 16 bytes into clipboard",
		"y", " 16 0x200", "copy 16 bytes into clipboard from 0x200",
		"y", " 16 @ 0x200", "copy 16 bytes into clipboard from 0x200",
		"yz", "", "copy up to blocksize zero terminated string bytes into clipboard",
		"yz", " 16", "copy up to 16 zero terminated string bytes into clipboard",
		"yz", " @ 0x200", "copy up to blocksize zero terminated string bytes into clipboard from 0x200",
		"yz", " 16 @ 0x200", "copy up to 16 zero terminated string bytes into clipboard from 0x200",
		"yp", "", "print contents of clipboard",
		"yx", "", "print contents of clipboard in hexadecimal",
		"ys", "", "print contents of clipboard as string",
		"yt", " 64 0x200", "copy 64 bytes from current seek to 0x200",
		"ytf", " file", "dump the clipboard to given file",
		"yf", " 64 0x200", "file copy 64 bytes from 0x200 from file (opens w/ io), use -1 for all bytes",
		"yfa", " file copy", "copy all bytes from file (opens w/ io)",
		"yy", " 0x3344", "paste clipboard",
		NULL};
		r_core_cmd_help (core, help_msg);
		}
		break;
	}
	return true;
}
