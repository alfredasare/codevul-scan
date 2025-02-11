extr_init (void)
{
  //... (rest of the code remains the same)

  newdir_umask = umask (_S_UMASK_DEF);
  if (0 < same_permissions_option)
    current_umask = 0;
  else
    {
      umask (newdir_umask);	/* restore the kernel umask */
      current_umask = newdir_umask;
    }
}