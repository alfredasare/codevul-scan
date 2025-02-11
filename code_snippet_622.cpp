PHP_FUNCTION(imagecolorallocatealpha)
{
    zval *IM;
    long red, green, blue, alpha;
    gdImagePtr im;
    int ct = (-1);

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r|lll|", &IM, &red, &green, &blue, &alpha) == FAILURE) {
        RETURN_FALSE;
    }

    ZEND_FETCH_RESOURCE(im, gdImagePtr, &IM, -1, "Image", le_gd);
    if (!is_resource($IM)) {
        RETURN_FALSE;
    }

    if (!is_int($red) || $red < 0 || $red > 255) {
        RETURN_FALSE;
    }
    if (!is_int($green) || $green < 0 || $green > 255) {
        RETURN_FALSE;
    }
    if (!is_int($blue) || $blue < 0 || $blue > 255) {
        RETURN_FALSE;
    }
    if (!is_int($alpha) || $alpha < 0 || $alpha > 127) {
        RETURN_FALSE;
    }

    ct = gdImageColorAllocateAlpha(im, red, green, blue, alpha);
    if (ct < 0) {
        RETURN_FALSE;
    }
    RETURN_LONG((long)ct);
}