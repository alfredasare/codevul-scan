tt_name_entry_ascii_from_other( TT_NameEntry  entry,
                                   FT_Memory     memory )
  {
    FT_String*  string = NULL;
    FT_UInt     len, code, n;
    FT_Byte*    read   = (FT_Byte*)entry->string;
    FT_Error    error;


    len = (FT_UInt)entry->stringLength;

    if ( FT_NEW_ARRAY( string, len + 1 ) )
      return NULL;

    for ( n = 0; n < len; n++ )
    {
      code = *read++;

      if ( code == 0 )
        break;

      // Restrict code to the ASCII range
      if ( code < 0 || code > 127 )
        code = '?';

      // Check for buffer overflow before writing to the string
      if (n >= len)
      {
          FT_FREE(string);
          return NULL;
      }

      string[n] = (char)code;
    }

    string[n] = 0;

    return string;
  }