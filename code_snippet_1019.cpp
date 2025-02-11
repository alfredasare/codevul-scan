static void gdImageVLine(gdImagePtr im, int x, int y1, int y2, int col)
{
	if (im && (x >= 0) && (x < im->sx) && (y1 >= 0) && (y1 < im->sy) && (y2 >= 0) && (y2 < im->sy)) {
		if (im->thick > 1) {
			int thickhalf = im->thick >> 1;
			gdImageFilledRectangle(im, x - thickhalf, y1, x + im->thick - thickhalf - 1, y2, col);
		} else {
			if (y2 < y1) {
				int t = y1;
				y1 = y2;
				y2 = t;
			}

			for (;y1 <= y2; y1++) {
				gdImageSetPixel(im, x, y1, col);
			}
		}
	}
	return;
}