static int qcow2\_change\_backing\_file(BlockDriverState \*bs, const char \*backing\_file, const char \*backing\_fmt)
{
 if (backing\_file && strlen(backing\_file) >= sizeof(bs->backing\_file)) {
 return -1; /* error: backing_file is too long */
 }
 if (backing\_fmt && strlen(backing\_fmt) >= sizeof(bs->backing\_format)) {
 return -1; /* error: backing_fmt is too long */
 }
 strncpy(bs->backing\_file, backing\_file ?: "", sizeof(bs->backing\_file));
 strncpy(bs->backing\_format, backing\_fmt ?: "", sizeof(bs->backing\_format));

 return qcow2\_update\_header(bs);
}