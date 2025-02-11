void tkhd_del(GF_Box *s)
{
	GF_TrackHeaderBox *ptr = NULL;
	if (s == NULL || (ptr = (GF_TrackHeaderBox *)s) == NULL) return;
	gf_free(ptr);
	return;
}