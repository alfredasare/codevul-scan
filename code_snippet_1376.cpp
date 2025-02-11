static void cwd_globals_dtor(virtual_cwd_globals *cwd_g TSRMLS_DC) /* {{{ */
{
	if (cwd_g->cwd != NULL) {
		CWD_STATE_FREE(&cwd_g->cwd);
	}
	realpath_cache_clean(TSRMLS_C);
}
/* }}} */