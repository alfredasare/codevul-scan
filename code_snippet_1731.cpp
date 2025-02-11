static int ne2000_buffer_full(NE2000State *s)
{
    unsigned int avail, index, boundary;

    index = (unsigned int)(s->curpag << 8);
    boundary = (unsigned int)(s->boundary << 8);
    if (index < boundary)
        avail = boundary - index;
    else
        avail = (s->stop - s->start) - (index - boundary);
    if (avail < (UINT_MAX - (unsigned int)sizeof(struct ethernet_frame)))
        return 1;
    return 0;
}