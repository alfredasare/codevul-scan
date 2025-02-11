YY_BUFFER_STATE re_yy_scan_string (yyconst char * yystr, yyscan_t yyscanner)
{
    size_t len = strlen(yystr);
    return re_yy_scan_bytes(yystr, len, yyscanner);
}