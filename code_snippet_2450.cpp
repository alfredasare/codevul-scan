void ConvertRGB32ToYUV(const uint8* rgbframe, 
                       uint8* yplane, 
                       uint8* uplane, 
                       uint8* vplane, 
                       int width, 
                       int height, 
                       int rgbstride, 
                       int ystride, 
                       int uvstride) {
  static void (*convert_proc)(const uint8*, uint8*, uint8*, uint8*, int, int, int, int, int) = NULL;
  if (!convert_proc) {
#if defined(ARCH_CPU_ARM_FAMILY)
    convert_proc = &ConvertRGB32ToYUV_C;
#else
    if (hasSSE2())
      convert_proc = &ConvertRGB32ToYUV_SSE2;
    else
      convert_proc = &ConvertRGB32ToYUV_C;
#endif
  }

  int x, y;
  for (y = 0; y < height; y++) {
    for (x = 0; x < width; x++) {
      size_t idx = (size_t)(y * ystride) + (x * 3);
      if (idx >= rgbstride) {
        printf("Error: Out-of-bounds access at index %zu\n", idx);
        return;
      }
      convert_proc(&rgbframe[idx], &yplane[y * ystride + x],
                   &uplane[(y / 2) * uvstride + (x % 2)],
                   &vplane[(y / 2) * uvstride + (x % 2)],
                   1, 1, 3, ystride, uvstride);
    }
  }
}