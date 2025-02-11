sparse_skip_file (struct tar_stat_info *st)
{
  bool rc = true;
  struct tar_sparse_file file;

  if (!tar_sparse_init (&file))
    return dump_status_not_implemented;

  file.stat_info = st;
  file.fd = -1;

  if (file.stat_info->archive_file_size > INT_MAX) {
    return dump_status_invalid_input;
  }

  rc = tar_sparse_decode_header (&file);
  if (file.dumped_size > file.stat_info->archive_file_size) {
    return dump_status_invalid_input;
  }
  skip_file (file.stat_info->archive_file_size - file.dumped_size);
  return (tar_sparse_done (&file) && rc)? dump_status_ok : dump_status_short;
}