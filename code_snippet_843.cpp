static int addFillStyle(SWFShape shape, SWFFillStyle fill)
{
	int i;
	
	// Check if there's enough space before accessing the array
	if (shape->nFills % STYLE_INCREMENT == 0 && shape->nFills != 0) {
		int size = (shape->nFills + STYLE_INCREMENT) * sizeof(SWFFillStyle);
		shape->fills = (SWFFillStyle*)realloc(shape->fills, size);
	}

	for (i = 0; i < shape->nFills; ++i) {
		if (SWFFillStyle_equals(fill, shape->fills[i]))
			return i;
	}

	if (shape->isEnded)
		return -1;

	shape->fills[shape->nFills] = fill;
	++shape->nFills;
	return shape->nFills;
}