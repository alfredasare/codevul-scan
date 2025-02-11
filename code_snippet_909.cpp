bool lodepng_is_valid_color_type(unsigned char colortype) {
  return (colortype == 1 || colortype == 2 || colortype == 3 || colortype == 4 || colortype == 6);
}

unsigned lodepng_is_alpha_type(const LodePNGColorMode* info)
{
  if (!lodepng_is_valid_color_type(info->colortype)) {
    return 0;
  }

  return (info->colortype & 4) != 0; /*4 or 6*/
}