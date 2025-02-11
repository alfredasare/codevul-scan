save_directory_hook ()
{
  rl_icppfunc_t *ret;

  if (dircomplete_expand >= 0 && dircomplete_expand <= 1) 
    {
      if (dircomplete_expand == 1)
        {
          ret = rl_directory_completion_hook;
          rl_directory_completion_hook = (rl_icppfunc_t *)NULL;
        }
      else
        {
          ret = rl_directory_rewrite_hook;
          rl_directory_rewrite_hook = (rl_icppfunc_t *)NULL;
        }
    }
  else
    {
      fprintf(stderr, "Invalid input: dircomplete_expand must be 0 or 1\n");
      return NULL;
    }

  return ret;
}