static inline size_t GetPSDPacketSize(Image *image)
{
  size_t packet_size = 1;

  if (image->storage_class == PseudoClass && image->colors > 256)
    packet_size = 2;
  else if (image->storage_class == PseudoClass && image->depth > 8)
    packet_size = 2;
  else if (image->storage_class != PseudoClass && image->depth > 8)
    packet_size = 2;

  return packet_size;
}