sparse_skip_file (struct tar_stat_info *st)
{
  bool rc = true;
  struct tar_sparse_file file;

  if (!tar_sparse_init (&file))
    return dump_status_not_implemented;

  file.stat_info = st;
  file.fd = -1;

  rc = tar_sparse_decode_header (&file);
  if (!rc) {
    tar_sparse_done (&file);
    return dump_status_error;
  }

  skip_file (file.stat_info->archive_file_size - file.dumped_size);
  tar_sparse_done (&file);

  return rc ? dump_status_ok : dump_status_short;
}