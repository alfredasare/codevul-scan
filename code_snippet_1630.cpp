MagickExport void LocaleUpper(char *string)
{
  register char
    *q;

  assert(string!= (char *) NULL);

  // Sanitize the input string using a whitelist approach
  for (q = string; *q!= '\0'; q++) {
    if (allowed_characters(*q)) { 
      *q = (char)LocaleUppercase((int)*q);
    } else {
      *q = '\0'; // Set to null to prevent further processing
    }
  }
}

bool allowed_characters(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c =='';
}