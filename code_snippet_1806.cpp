yydestruct(const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  char sanitized_msg[256]; // adjust buffer size as needed
  if (yymsg && strlen(yymsg) > 0) {
    const char *allowed_formats[] = {"Deleting", "Error"};
    bool valid_format = false;
    for (const char **format in allowed_formats) {
      if (strcmp(yymsg, *format) == 0) {
        valid_format = true;
        break;
      }
    }
    if (!valid_format) {
      yymsg = "Invalid format";
    }
  }

  YY_SYMBOL_PRINT(yymsg, yytype, yyvaluep, yylocationp);
}