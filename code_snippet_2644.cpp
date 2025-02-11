pch_mode (size_t index)
{
  // Validate input
  if (index >= sizeof(p_mode)/sizeof(p_mode[0])) {
    // Handle error or return default value
    return 0;
  }
  
  return p_mode[index];
}