static int addFillStyle(SWFShape shape, SWFFillStyle fill)
{
    int i;

    assert(STYLE_INCREMENT > 0);

    for (i = 0; i < shape->nFills; ++i)
    {
        if (SWFFillStyle_equals(fill, shape->fills[i]))
            return i;
    }

    if (shape->isEnded)
        return -1;

    size_t new_size = (shape->nFills + STYLE_INCREMENT) * sizeof(SWFFillStyle);
    if (new_size > MAX_FILL_SIZE)
    {
        return -2;
    }

    shape->fills = (SWFFillStyle*)realloc(shape->fills, new_size);
    if (shape->fills == NULL)
    {
        return -3;
    }

    shape->fills[shape->nFills] = fill;
    ++shape->nFills;
    return shape->nFills;
}