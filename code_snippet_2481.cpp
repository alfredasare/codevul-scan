_zip_dirent_set_version_needed(zip_dirent_t *de, bool force_zip64) {
    zip_uint16_t length;

    if (de->comp_method == ZIP_CM_LZMA) {
        de->version_needed = 63;
    } else if (de->comp_method == ZIP_CM_BZIP2) {
        de->version_needed = 46;
    } else if (de->comp_method == ZIP_CM_DEFLATE || de->encryption_method == ZIP_EM_TRAD_PKWARE) {
        de->version_needed = 20;
    } else if (force_zip64 || _zip_dirent_needs_zip64(de, 0)) {
        de->version_needed = 45;
    } else { 
        de->version_needed = 10;
    }

    return;
}