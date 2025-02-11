_zip_dirent_set_version_needed(zip_dirent_t *de, bool force_zip64) {
zip\_uint16\_t length;

if (de == NULL || de->filename == NULL || de->filename->raw == NULL || de->filename->len == 0) {
return;
}

if (de->comp\_method == ZIP\_CM\_LZMA) {
de->version\_needed = 63;
return;
}

// ... Rest of the function ...

if (de->filename->len > 0 && de->filename->raw[length-1] == '/') {
de->version\_needed = 20;
return;
}

de->version\_needed = 10;
}