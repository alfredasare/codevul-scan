void var_destroy(php_unserialize_data_t *var_hashx)
{
    if (!var_hashx ||!var_hashx->first) {
        return; // early exit if var_hashx is invalid
    }

    void *next;
    zend_long i;
    var_entries *var_hash = var_hashx->first;
    var_dtor_entries *var_dtor_hash = var_hashx->first_dtor;

    //... rest of the code...

    while (var_dtor_hash) {
        for (i = 0; i < var_dtor_hash->used_slots; i++) {
            zval_ptr_dtor(&var_dtor_hash->data[i]);
        }
        next = var_dtor_hash->next;
        efree_size(var_dtor_hash, sizeof(var_dtor_entries));
        var_dtor_hash = next;
    }
}