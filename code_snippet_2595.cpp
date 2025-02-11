static PHP_GSHUTDOWN_FUNCTION(pcre) /* {{{ */
{
	zend_hash_clean(&pcre_globals->pcre_cache);
}
/* }}} */