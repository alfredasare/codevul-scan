FLAC__StreamDecoderReadStatus file\_read\_callback_(const FLAC\_\_StreamDecoder \*decoder, FLAC\_\_byte buffer[], size\_t \*bytes, void \*client\_data)
{
 (void)client\_data;

 if(\*bytes > 0) {
 size\_t bytes\_read = fread(buffer, sizeof(FLAC\_\_byte), \*bytes, decoder->private\_->file);
 if(ferror(decoder->private\_->file))
 return FLAC\_\_STREAM\_DECODER\_READ\_STATUS\_ABORT;
 else if(bytes\_read != \*bytes)
 return FLAC\_\_STREAM\_DECODER\_READ\_STATUS\_ABORT; /* abort on error */
 else if(bytes\_read == 0)
 return FLAC\_\_STREAM\_DECODER\_READ\_STATUS\_END\_OF\_STREAM;
 else {
 *bytes = bytes\_read;
 return FLAC\_\_STREAM\_DECODER\_READ\_STATUS\_CONTINUE;
 }
 }
 else
 return FLAC\_\_STREAM\_DECODER\_READ\_STATUS\_ABORT; /* abort to avoid a deadlock */
}