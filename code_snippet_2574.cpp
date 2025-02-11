uncompressed_buffer = (uint8_t*) malloc(zip->uncompressed_buffer_size);
if (zip->uncompressed_buffer == NULL) {
archive\_set\_error(&a->archive, ENOMEM,
"No memory for xz decompression");
return (ARCHIVE\_FATAL);
}

zip->decompress\_init = 1;
return (ARCHIVE\_OK);
}