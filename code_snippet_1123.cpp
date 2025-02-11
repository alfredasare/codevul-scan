pr_sgr_end_if (char const *s)
{
  unsigned int color_option = /* get the value of color_option */;
  if (color_option < PR_SGR_MAX_COLOR_OPTION) {
    pr_sgr_end (s);
  }
}