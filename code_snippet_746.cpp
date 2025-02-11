php_mysqlnd_ok_free_mem(void * _packet, zend_bool stack_allocation TSRMLS_DC)
{
    MYSQLND_PACKET_OK *p = (MYSQLND_PACKET_OK *) _packet;
    if (p->message) {
        mnd_efree(p->message);
        p->message = NULL;
    }
    if (!stack_allocation) {
        int result = mnd_pefree(p, p->header.persistent);
        if (result!= 0) {
            error_log("Error freeing memory: ". mysqlnd_strerror(result));
        }
    }
}