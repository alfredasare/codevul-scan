static long mem_seek(jas_stream_obj_t *obj, long offset, int origin)
{
	jas_stream_memobj_t *m = (jas_stream_memobj_t *)obj;
	long newpos;

	JAS_DBGLOG(1