static inline size_t GetPSDPacketSize(Image *image)
{
  size_t packet_size = 1;

  if (image->storage_class == PseudoClass)
  {
    if (image->colors > 0 && image->colors <= 256)
    {
      if (image->depth > 0 && image->depth <= 8)
        packet_size = 1;
      else if (image->depth > 8)
        packet_size = 2;
    }
  }
  else
  {
    if (image->depth > 0 && image->depth <= 8)
      packet_size = 1;
    else if (image->depth > 8)
      packet_size = 2;
  }

  return packet_size;
}