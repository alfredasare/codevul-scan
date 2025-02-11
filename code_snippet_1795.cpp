void nsc\_encode(NSC\_CONTEXT\* context, const BYTE\* bmpdata, UINT32 rowstride)
{
	// Validate input to prevent buffer overflow
	if (rowstride < context->ImageWidth \* 4)
	{
		printf("Invalid row stride\n");
		return;
	}

	nsc\_encode\_argb\_to\_aycocg(context, bmpdata, rowstride);

	if (context->ChromaSubsamplingLevel)
	{
		nsc\_encode\_subsampling(context);
	}
}