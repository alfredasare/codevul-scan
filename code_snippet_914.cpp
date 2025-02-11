png_data_freer(png_structp png_ptr, png_infop info_ptr,
   int freer, png_uint_32 mask)
{
   png_debug(1, "in png_data_freer");

   if (png_ptr == NULL || info_ptr == NULL)
      return;

   // Add bounds checking for the freer parameter
   if (freer < PNG_DESTROY_DATA || freer > PNG_USER_CHUNK_DATA) {
      png_warning(png_ptr, "Invalid freer parameter value in png_data_freer.");
      return;
   }

   if (freer == PNG_DESTROY_WILL_FREE_DATA)
      info_ptr->free_me |= mask;
   else if (freer == PNG_USER_WILL_FREE_DATA)
      info_ptr->free_me &= ~mask;
   else
      png_warning(png_ptr,
         "Unknown freer parameter in png_data_freer.");
}