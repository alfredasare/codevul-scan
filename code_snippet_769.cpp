TIFFVStripSize(TIFF* tif, uint32 nrows)
{
	static const char module[] = "TIFFVStripSize";
	uint64_t m;
	tmsize_t n;
	m = TIFFVStripSize64(tif, nrows);

	if (m > INT32_MAX || m < INT32_MIN)
	{
		TIFFErrorExt(tif->tif_clientdata, module, "Arithmetic overflow");
		n = 0;
	}
	else
	{
		n = (tmsize_t)m;

		if ((uint64_t)n != m)
		{
			TIFFErrorExt(tif->tif_clientdata, module, "Integer overflow");
			n = 0;
		}
	}

	return n;
}