static void SkipDXTMipmaps(Image *image, DDSInfo *dds_info, int texel_size)
{
  register ssize_t
    i;

  MagickOffsetType
    offset;

  size_t
    h,
    w;

  //... (rest of the code remains the same)

  for (i = 1; (i < (ssize_t) dds_info->mipmapcount) && w && h; i++)
  {
    offset = (MagickOffsetType) ((w + 3) / 4) * ((h + 3) / 4) * texel_size;
    if (offset >= image->size) {
      break;
    }
    (void) SeekBlob(image, offset, SEEK_CUR);

    w = DIV2(w);
    h = DIV2(h);
  }
}