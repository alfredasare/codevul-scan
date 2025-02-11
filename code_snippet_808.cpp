METHODDEF(JDIMENSION)
get_raw_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo)
{
  ppm_source_ptr source = (ppm_source_ptr)sinfo;
  JDIMENSION buffer_width = sinfo->buffer_width;

  if (buffer_width <= 0) {
    ERREXIT(cinfo, JERR_BAD_BUFFER_WIDTH);
    return 0;
  }

  if (!ReadOK(source->pub.input_file, source->iobuffer, buffer_width))
    ERREXIT(cinfo, JERR_INPUT_EOF);
  return 1;
}