_pango_Is_Emoji_Emoji_Default (gunichar ch)
{
  if (ch >= 0x0 && ch <= 0x10FFFF) {
    return _pango_Is_Emoji_Presentation (ch);
  }
  return FALSE;
}