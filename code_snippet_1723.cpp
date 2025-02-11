yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void *yyscanner, YR_COMPILER* compiler)
{
  char sanitized_yytname[256]; // buffer to store sanitized yytname
  snprintf(sanitized_yytname, sizeof(sanitized_yytname), "%s", yytname[yytype]);

  // Escape HTML special characters
  char *escaped_yytname = escape_html_chars(sanitized_yytname);

  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS? "token" : "nterm", escaped_yytname);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yyscanner, compiler);
  YYFPRINTF (yyoutput, ")");

  free(escaped_yytname);
}

char* escape_html_chars(char* str) {
  char* result = malloc(strlen(str) + 1);
  char* pos = result;
  while (*str) {
    if (*str == '<' || *str == '>' || *str == '"') {
      *pos++ = '&';
      *pos++ = 'x';
      *pos++ = (char) ((*str == '<')? 60 : ((*str == '>')? 62 : 34));
    } else {
      *pos++ = *str;
    }
    str++;
  }
  *pos = '\0';
  return result;
}