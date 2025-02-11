save_directory_hook()
{
  rl_icppfunc_t *ret;

  if (dircomplete_expand)
    ret = rl_completion_entry_function_dynamic("", rl_filename_completion_function);
  else
    ret = rl_completion_entry_function_dynamic("", rl_filename_rewrite_function);

  return ret;
}