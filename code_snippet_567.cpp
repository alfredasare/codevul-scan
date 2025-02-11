Here's the fixed version of the vulnerable code based on the provided context:


int ZEXPORT inflateGetHeader(z_streamp strm, gz_headerp head)
{
    struct inflate_state FAR *state;

    /* check state */
    if (strm == NULL || strm->state == NULL) return Z_STREAM_ERROR;
    state = (struct inflate_state FAR *)strm->state;
    if ((state->wrap & 2) == 0) return Z_STREAM_ERROR;

    /* check head */