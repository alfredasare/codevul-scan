print_anchor(FILE* f, int anchor)
{
  if (!(anchor & (ANCR_BEGIN_BUF | ANCR_BEGIN_LINE | ANCR_BEGIN_POSITION |
                 ANCR_END_BUF | ANCR_SEMI_END_BUF | ANCR_END_LINE |
                 ANCR_ANYCHAR_INF | ANCR_ANYCHAR_INF_ML))) {
    fprintf(f, "[none]");
    return;
  }

  fprintf(f, "[");

  if (anchor & ANCR_BEGIN_BUF) {
    fprintf(f, "begin-buf");
    q = 1;
  }
  // ... Rest of the code ...
}