void ef_debug(u_char level, const char *message)
{ 
   if (EF_GBL_OPTIONS->debug < level)
      return;

   fprintf (stderr, "%s\n", message);
   fflush(stderr);
}