php_image_filter_selective_blur(gdImagePtr im, int /*arg1*/ /* = 0 */,
                                int /*arg2*/ /* = 0 */, int /*arg3*/ /* = 0 */,
                                int /*arg4*/ /* = 0 */) {
  return gdImageSelectiveBlur(im) == 1;
}