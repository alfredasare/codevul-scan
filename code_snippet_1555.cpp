static inline void InsertPixelList(const Quantum pixel, PixelList *pixel_list)
{
  size_t
    scaled_index; 

  unsigned short
    index;

  index = ScaleQuantumToShort(pixel); 
  scaled_index = index % (sizeof(pixel_list->skip_list.nodes) / sizeof(pixel_list->skip_list.nodes[0])); 

  index = scaled_index; 
  if (index >= pixel_list->skip_list.count) { 
    AddNodePixelList(pixel_list, index);
  } else {
    pixel_list->skip_list.nodes[index].count++;
  }
}