static void hash_split(ps_mm *data)
{
	php_uint32 nmax;
	ps_sd **nhash;
	ps_sd **ohash, **ehash;
	ps_sd *ps, *next;

	nmax = ((data->hash_max + 1) << 1) -