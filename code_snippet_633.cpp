lexer_hex_to_character (parser_context_t *context_p, /**< context */
                        const uint8_t *source_p, /**< current source position */
                        int length) /**< source length */
{
  uint32_t result = 0;

  do
  {
    uint32_t byte = *source_p++;

    if (result >= (UINT32_MAX / 16)) {
      parser_raise_error(context_p, PARSER_ERR_INTEGER_OVERFLOW);
      return (ecma_char_t) 0; // or some other error handling
    }

    result = (result << 4) | byte;
    if (byte >= LIT_CHAR_0 && byte <= LIT_CHAR_9)
    {
      result -= LIT_CHAR_0;
    }
    else
    {
      byte = LEXER_TO_ASCII_LOWERCASE(byte);
      if (byte >= LIT_CHAR_LOWERCASE_A && byte <= LIT_CHAR_LOWERCASE_F)
      {
        result -= (LIT_CHAR_LOWERCASE_A - 10);
      }
      else
      {
        parser_raise_error(context_p, PARSER_ERR_INVALID_ESCAPE_SEQUENCE);
      }
    }
  }
  while (--length > 0);

  return (ecma_char_t) result;
} /* lexer_hex_to_character */