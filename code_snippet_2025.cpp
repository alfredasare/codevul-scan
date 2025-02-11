ZEND_API zval* ZEND_FASTCALL _zend_hash_next_index_insert(HashTable *ht, zval *pData ZEND_FILE_LINE_DC)
{
    zend_ulong key = ht->nNextFreeElement;
    if (key >= ht->arData->nelts) {
        // Handle error condition (e.g., return NULL or throw an exception)
    }
    return _zend_hash_index_add_or_update_i(ht, key, pData, HASH_ADD | HASH_ADD_NEXT ZEND_FILE_LINE_RELAY_CC);
}