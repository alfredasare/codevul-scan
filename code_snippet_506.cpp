php
PHP_METHOD(PharFileInfo, getCompressedSize)
{
    PHAR_ENTRY_OBJECT();

    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    if (!isset($entry_obj->entry) ||!isset($entry_obj->entry->compressed_filesize) ||!is_int($entry_obj->entry->compressed_filesize)) {
        warning("Invalid entry object");
        RETURN_FALSE;
    }

    RETURN_LONG((int)$entry_obj->entry->compressed_filesize);
}