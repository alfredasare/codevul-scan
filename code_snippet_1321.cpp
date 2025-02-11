static void re_yy_load_buffer_state(yyscan_t yyscanner) {
    struct yyguts_t *yyg = (struct yyguts_t *)yyscanner;
    if (yyg->yy_input_file) {
        yyg->yy_n_chars = YY_CURRENT_BUFFER_LVALUE->yy_n_chars;
        yyg->yytext_ptr = yyg->yy_c_buf_p = YY_CURRENT_BUFFER_LVALUE->yy_buf_pos;
        yyg->yyin = YY_CURRENT_BUFFER_LVALUE->yy_input_file;
        yyg->yy_hold_char = *yyg->yy_c_buf_p;
    } else {
        fprintf(stderr, "Error: yyin is not valid\n");
    }
}