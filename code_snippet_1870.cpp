yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void *yyscanner, YR_COMPILER* compiler)
{
  if (yytype >= 1 && yytype < YYNTOKENS) {
    YYFPRINTF (yyoutput, "%s %s (",
               "token", yytname[yytype - 1]);

    yy_symbol_value_print (yyoutput, yytype, yyvaluep, yyscanner, compiler);
    YYFPRINTF (yyoutput, ")");
  } else {
    YYFPRINTF (yyoutput, "<unknown token>");
  }
}