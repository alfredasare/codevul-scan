PHP_FUNCTION(imagerotate)
{
	zval *SIM;
	gdImagePtr im\_dst, im\_src;
	double degrees;
	long color;
	long ignoretransparent = 0;

	if (zend\_parse\_parameters(ZEND\_NUM\_ARGS() TSRMLS\_CC, "rdl|l", &SIM, &degrees, &color, &ignoretransparent) == FAILURE) {
		RETURN\_FALSE;
	}

	ZEND\_FETCH\_RESOURCE(im\_src, gdImagePtr, &SIM, -1, "Image", le\_gd);

	im\_dst = gdImageRotateInterpolated(im\_src, (const float)degrees, color);

	if (im\_dst != NULL) {
		ZEND\_REGISTER\_RESOURCE(return\_value, im\_dst, le\_gd);
	} else {
		gdFree(im\_src); // Clean up the source image resource to avoid memory leaks
		RETURN\_FALSE;
	}
}