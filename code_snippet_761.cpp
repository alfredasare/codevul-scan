tt_name_entry_ascii_from_other( TT_NameEntry  entry,
                               FT_Memory     memory )
{
    FT_String*  string = NULL;
    FT_UInt     len, code, n;
    FT_Byte*    read   = (FT_Byte*)entry->string;
    FT_Error    error;

    const char* allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-. ";
    bool valid_char = false;

    len = (FT_UInt)entry->stringLength;

    if ( FT_NEW_ARRAY( string, len + 1 ) )
        return NULL;

    for ( n = 0; n < len; n++ )
    {
        code = *read++;

        if ( code == 0 )
            break;

        for ( int i = 0; i < strlen(allowed_chars); i++ )
        {
            if ( code == (FT_Byte)allowed_chars[i] )
            {
                valid_char = true;
                break;
            }
        }

        if (!valid_char )
            code = '?';

        string[n] = (char)code;
    }

    string[n] = 0;

    return string;
}