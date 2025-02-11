static void re_yy_load_buffer_state(yyscan_t yyscanner) {
    struct yyguts_t *yyg = (struct yyguts_t *)yyscanner;
    int n_chars = YY_CURRENT_BUFFER_LVALUE->yy_n_chars;
    char *text_ptr = YY_CURRENT_BUFFER_LVALUE->yy_buf_pos;
    FILE *input_file = YY_CURRENT_BUFFER_LVALUE->yy_input_file;
    char hold_char = *text_ptr;

    yyg->yy_n_chars = n_chars;
    yyg->yytext_ptr = text_ptr;
    yyg->yy_c_buf_p = text_ptr;
    yyin = input_file;
    yyg->yy_hold_char = hold_char;
}