static boolean parse_identifier( const char **pcur, char *ret, size_t len )
{
   const char *cur = *pcur;
   int i = 0;
   if (is_alpha_underscore( cur )) {
      ret[i++] = *cur++;
      while (i < len && (is_alpha_underscore( cur ) || is_digit( cur ))) {
         ret[i++] = *cur++;
      }
      ret[i] = '\0'; // ensure null-termination within buffer bounds
      *pcur = cur;
      return TRUE;
   }
   return FALSE;
}