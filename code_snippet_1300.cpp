pr_sgr_end_if (char const *s)
{
  if (color_option && s != NULL)
    pr_sgr_end (s);
}