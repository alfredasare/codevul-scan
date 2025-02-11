_pango_Is_Emoji_Emoji_Default (gunichar ch)
{
  if (ch < 0 || ch > G_MAXUINT16) {
    return FALSE;
  }
  return _pango_Is_Emoji_Presentation (ch);
}