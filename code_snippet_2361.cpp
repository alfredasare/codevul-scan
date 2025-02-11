void php_mb_regex_globals_free(struct _zend_mb_regex_globals *globals) {
    // Clear any references to the structure
    globals->search_str = NULL;
    globals->search_str_val = NULL;
    globals->search_re = NULL;
    globals->search_regs = NULL;
    globals->regex_default_options = 0;
    globals->regex_default_syntax = NULL;

    // Free the structure
    free(globals);
}