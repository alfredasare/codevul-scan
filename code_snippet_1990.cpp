static void charstring_start(void)
{
  int i;

  if (!charstring_buf) {
    int bufsize = sizeof(byte) * lenIV;
    if (!(charstring_buf = (byte *) malloc(bufsize)))
      fatal_error("out of memory");
  }

  charstring_bp = charstring_buf;
  cr = 4330;
  for (i = 0; i < lenIV; i++)
    *charstring_bp++ = cencrypt((byte) 0);
}