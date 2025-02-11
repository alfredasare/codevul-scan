php_mysqlnd_ok_free_mem(void * _packet, zend_bool stack_allocation TSRMLS_DC)
{
	MYSQLND_PACKET_OK *p= (MYSQLND_PACKET_OK *) _packet;
	if (p->message) {
		mnd_efree(p->message);
		p->message = NULL;
	}
	if (!stack_allocation && p->header.packet_size > 0 && p->header.persistent < p->header.packet_size) {
		mnd_pefree(p, p->header.persistent);
	}
}