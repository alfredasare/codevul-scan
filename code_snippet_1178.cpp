static int phar_update_cached_entry(zval *data, void *argument) {
    phar_entry_info *entry = (phar_entry_info *)Z_PTR_P(data);

    entry->phar = (phar_archive_data *)argument;

    if (entry->link) {
        entry->link = estrdup(entry->link);
    }

    if (entry->tmp) {
        entry->tmp = estrdup(entry->tmp);
    }

    entry->metadata_str.s = NULL;
    entry->filename = estrndup(entry->filename, entry->filename_len);
    entry->is_persistent = 0;

    if (Z_TYPE(entry->metadata)!= IS_UNDEF) {
        if (entry->metadata_len > 0) {
            size_t metadata_size = entry->metadata_len + 1; // +1 for null-termination
            char *buf = malloc(metadata_size);
            if (buf == NULL) {
                return ZEND_HASH_APPLY_KEEP;
            }
            memcpy(buf, Z_PTR(entry->metadata), metadata_size);
            buf[metadata_size - 1] = '\0';
            phar_parse_metadata_safe((char **) &buf, &entry->metadata, metadata_size);
            free(buf);
        } else {
            zval_copy_ctor(&entry->metadata);
            entry->metadata_str.s = NULL;
        }
    }
    return ZEND_HASH_APPLY_KEEP;
}