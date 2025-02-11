parse_single_hex_dump_line(char* rec, guint8 *buf, guint byte_offset) {
    if (!rec || strlen(rec) == 0) {
        return FALSE; // invalid input
    }

    for (int i = 0; i < strlen(rec); i++) {
        if (!isxdigit(rec[i]) && rec[i] != ' ' && rec[i] != '\n') {
            return FALSE; // invalid character found
        }
    }

    //...
}