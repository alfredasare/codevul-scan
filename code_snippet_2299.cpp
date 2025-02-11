__imlib_FreeUpdates(ImlibUpdate * u)
{
   ImlibUpdate        *uu;

   uu = u;
   while (uu)
     {
        u = uu;
        uu = uu->next;
        free(u);
        u = NULL; // Add this line to prevent double free vulnerability
     }
}