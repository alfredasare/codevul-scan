print_anchor(FILE* f, int anchor)
{
  int32_t q = 0;

  fprintf(f, "[");

  if (anchor & ANCR_BEGIN_BUF) {
    fprintf(f, "begin-buf");
    q = 1;
  } else if (q!= 0) {
    fprintf(f, ", ");
    q = 1;
  }
  if (anchor & ANCR_BEGIN_LINE) {
    if (q!= 0) {
      q = 1;
      fprintf(f, "begin-line");
    }
  }
  if (anchor & ANCR_BEGIN_POSITION) {
    if (q!= 0) {
      q = 1;
      fprintf(f, "begin-pos");
    }
  }
  if (anchor & ANCR_END_BUF) {
    if (q!= 0) {
      q = 1;
      fprintf(f, "end-buf");
    }
  }
  if (anchor & ANCR_SEMI_END_BUF) {
    if (q!= 0) {
      q = 1;
      fprintf(f, "semi-end-buf");
    }
  }
  if (anchor & ANCR_END_LINE) {
    if (q!= 0) {
      q = 1;
      fprintf(f, "end-line");
    }
  }
  if (anchor & ANCR_ANYCHAR_INF) {
    if (q!= 0) {
      q = 1;
      fprintf(f, "anychar-inf");
    }
  }
  if (anchor & ANCR_ANYCHAR_INF_ML) {
    fprintf(f, "anychar-inf-ml");
  }

  fprintf(f, "]");
}