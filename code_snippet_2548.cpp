ZEND_EXTERN_MODULE_GLOBALS(mbstring)

struct _zend_mb_regex_globals {
	OnigEncoding default_mbctype;
	OnigEncoding current_mbctype;
	HashTable ht_rc;
	zval *search_str;
	zval *search_str_val;
	unsigned int search_pos;
	php_mb_regex_t *search_re;
	OnigRegion *search_regs;
	OnigOptionType regex_default_options;
	OnigSyntaxType *regex_default_syntax;
};

/* Validate and sanitize input before using it in onig_new() */
#define MAX_REGEX_LENGTH 1024
if (Z_TYPE_P(search_str) == IS_STRING && Z_STRLEN_P(search_str) < MAX_REGEX_LENGTH && onig_check_syntax(Z_STRVAL_P(search_str), Z_STRLEN_P(search_str), ONIG_SYNTAX_PERL, &error_info) >= 0) {
    search_re = onig_new(Z_STRVAL_P(search_str), Z_STRLEN_P(search_str), ONIG_OPTION_NONE, &error_info);
} else {
    /* Handle error cases */
}