static int ne2000_buffer_full(NE2000State *s)
{
    int avail, index, boundary;
    uint8_t *index_ptr, *boundary_ptr;

    index_ptr = (uint8_t *) &index;
    *index_ptr++ = s->curpag;
    *index_ptr = 0;

    index <<= 8;
    if (*index_ptr == 0xFF) {
        // Handle the case when shift results in an integer overflow
        return 1;
    }

    boundary_ptr = (uint8_t *) &boundary;
    *boundary_ptr++ = s->boundary;
    *boundary_ptr = 0;

    boundary <<= 8;
    if (*boundary_ptr == 0xFF) {
        // Handle the case when shift results in an integer overflow
        return 1;
    }

    if (index < boundary)
        avail = boundary - index;
    else
        avail = (s->stop - s->start) - (index - boundary);
    if (avail < (MAX_ETH_FRAME_SIZE + 4))
        return 1;
    return 0;
}