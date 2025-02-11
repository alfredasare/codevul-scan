INLINE void impeg2d_bit_stream_flush(void* pv_ctxt, UWORD32 u4_no_of_bits)
{
    stream_t *ps_stream = (stream_t *)pv_ctxt;

    if (u4_no_of_bits > ps_stream->u4_max_offset || u4_no_of_bits < 0)
    {
        return;
    }

    if (ps_stream->u4_offset >= ps_stream->u4_max_offset)
    {
        return;
    }

    FLUSH_BITS(ps_stream->u4_offset, ps_stream->u4_buf, ps_stream->u4_buf_nxt, u4_no_of_bits, ps_stream->pu4_buf_aligned);

    ps_stream->u4_offset += u4_no_of_bits;

    return;
}