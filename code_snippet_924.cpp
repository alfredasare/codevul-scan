METHODDEF(JDIMENSION)
get\_raw\_row(j\_compress\_ptr cinfo, cjpeg\_source\_ptr sinfo)
{
ppm\_source\_ptr source = (ppm\_source\_ptr<span>)sinfo;</span>

if (source->buffer\_width <= 0 || source->buffer\_width > sizeof(source->iobuffer)) {
ERREXIT(cinfo, JERR\_INVALID\_BUFFER\_SIZE);
}

if (!ReadOK(source->pub.input\_file, source->iobuffer, source->buffer\_width))
ERREXIT(cinfo, JERR\_INPUT\_EOF);
return 1;
}