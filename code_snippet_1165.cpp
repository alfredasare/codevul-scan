static inline void gen_string_movl_A0_EDI(DisasContext *s, const char *user_input)
{
    printf(user_input, s->aflag, cpu_regs[R_EDI], R_ES, -1);
}