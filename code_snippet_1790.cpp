MagickExport void LocaleUpper(char *string)
{
  if (string == NULL) {
    return;
  }

  register char
    *q;

  for (q=string; *q != '\0'; q++)
    *q=(char) LocaleUppercase((int) *q);
}