void __imlib_FreeUpdates(ImlibUpdate *u)
{
   ImlibUpdate *uu;

   while (u) {
      if (u->size!= sizeof(ImlibUpdate)) {
         // Handle invalid size error
      }
      uu = u;
      u = u->next;
      free(uu);
   }
}