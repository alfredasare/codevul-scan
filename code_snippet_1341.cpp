INLINE void impeg2d\_bit\_stream\_flush(void\* pv\_ctxt, UWORD32 u4\_no\_of\_bits)
{
stream\_t \*ps\_stream = (stream\_t \*)pv\_ctxt;
if (ps\_stream->u4\_offset + u4\_no\_of\_bits <= ps\_stream->u4\_max\_offset)
{
FLUSH\_BITS(ps\_stream->u4\_offset, ps\_stream->u4\_buf, ps\_stream->u4\_buf\_nxt, u4\_no\_of\_bits, ps\_stream->pu4\_buf\_aligned)
}
return;
}