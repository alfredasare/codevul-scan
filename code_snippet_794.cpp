unsigned lodepng_is_alpha_type(const LodePNGColorMode* info)
{
    if (!info) {
        return 0; 
    }
    return (info->colortype == 4 || info->colortype == 6); 
}