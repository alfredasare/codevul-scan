static inline void InsertPixelList(const Quantum pixel, PixelList *pixel_list)
{
  size_t
    signature;

  unsigned short
    index;

  index = ScaleQuantumToShort(pixel);

  // Check if the index is within bounds
  if (index >= pixel_list->skip_list.num_nodes)
  {
    // Clamp the value to the last index as an example of a graceful error handling mechanism
    index = pixel_list->skip_list.num_nodes - 1;
  }

  signature = pixel_list->skip_list.nodes[index].signature;
  if (signature == pixel_list->signature)
  {
    pixel_list->skip_list.nodes[index].count++;
    return;
  }
  AddNodePixelList(pixel_list, index);
}