void BackendIO::WriteSparseData(EntryImpl* entry,
                                 int64_t offset,
                                 net::IOBuffer* buf,
                                 int buf_len) {
  if (!entry || offset < 0 ||!buf || buf_len <= 0) {
    return;
  }

  operation_ = OP_WRITE_SPARSE;
  entry_ = entry;
  offset64_ = offset;
  buf_ = buf;
  buf_len_ = buf_len;
}