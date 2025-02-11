_pango_get_emoji_type (gunichar codepoint)
{
  g_return_val_if_fail (g_unichar_is_valid (codepoint), PANGO_EMOJI_TYPE_TEXT);

  if (_pango_Is_Emoji_Keycap_Base (codepoint) ||
      _pango_Is_Regional_Indicator (codepoint))
    return PANGO_EMOJI_TYPE_TEXT;

  if (codepoint == kCombiningEnclosingKeycapCharacter)
    return PANGO_EMOJI_TYPE_EMOJI_EMOJI;

  if (_pango_Is_Emoji_Emoji_Default (codepoint) ||
      _pango_Is_Emoji_Modifier_Base (codepoint) ||
      _pango_Is_Emoji_Modifier (codepoint))
    return PANGO_EMOJI_TYPE_EMOJI_EMOJI;

  if (_pango_Is_Emoji_Text_Default (codepoint))
    return PANGO_EMOJI_TYPE_EMOJI_TEXT;

  return PANGO_EMOJI_TYPE_TEXT;
}