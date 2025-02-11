static tsize_t TIFFWriteBlob(thandle_t image, tdata_t data, tsize_t size)
{
  const tsize_t max_allowed_size = /* Set the maximum allowed size based on your system */;

  if (size > max_allowed_size) {
    fprintf(stderr, "Error: Size exceeded maximum allowed limit\n");
    return -1;
  }

  tsize_t count = (tsize_t)WriteBlob((Image *)image, (size_t)size, (unsigned char *)data);
  return count;
}