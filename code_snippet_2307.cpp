php
PHP_FUNCTION(imagerotate)
{
    //... (rest of the function remains the same until this point)

    im_dst = gdImageRotateInterpolated(im_src, (const float)degrees, color);

    // Use zend_string_* functions to ensure safe memory access
    char* dst_data = (char*)zend_string_get_data(im_dst->image);
    int dst_width = im_dst->width;
    int dst_height = im_dst->height;

    // Rest of the function remains the same
}