ZEND_API void *zend_object_store_get_object(const zval *zobject TSRMLS_DC)
{
    zend_object_handle handle = Z_OBJ_HANDLE_P(zobject);
    int handle_valid = 0; // assume handle is invalid by default

    // validate handle
    if (handle >= 0 && handle < EG(objects_store).object_buckets_size) {
        handle_valid = 1;
    }

    // bounds check
    if (handle_valid) {
        return &EG(objects_store).object_buckets[handle].bucket.obj.object;
    } else {
        // handle invalid, return an error or throw an exception
        return NULL;
    }
}