static inline void gen_string_movl_A0_EDI(DisasContext *s)
{
    char buffer[1024]; 
    const char *str = escape_special_chars(s->aflag); 

    if (strlen(str) > sizeof(buffer) - 1) {
        return;
    }

    strncpy(buffer, str, sizeof(buffer) - 1);

    gen_lea_v_seg(s, buffer, R_ES, -1);
}