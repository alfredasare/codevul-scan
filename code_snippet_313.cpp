size_t calculated_offset;
      MagickOffsetType blob_end = image->blob_size - calculated_offset;

      /*
        Mipmapcount includes the main image, so start from one
      */
      for (i = 1; (i < (ssize_t) dds_info->mipmapcount) && w && h; i++)
      {
        calculated_offset = ((w + 3) / 4) * ((h + 3) / 4) * texel_size;
        if (calculated_offset > blob_end) break;

        offset = (MagickOffsetType) calculated_offset;

        if (offset < 0 || offset > image->blob_size)
        {
          /* Handle error case */
        }
        (void) SeekBlob(image, offset, SEEK_CUR);

        w = DIV2(w);
        h = DIV2(h);
      }
    }