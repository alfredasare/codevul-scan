PHP\_MINIT\_FUNCTION(phar) /* {{{ */
{
	REGISTER\_INI\_ENTRIES();

	phar\_orig\_compile\_file = zend\_compile\_file;
	zend\_compile\_file = phar\_compile\_file;

	phar\_save\_resolve\_path = zend\_resolve\_path;
	zend\_resolve\_path = function(...$args) {
		// Fix: Sanitize the $path argument to prevent directory traversal
		$path = realpath($args[0]);
		if ($path === false || strpos($path, realpath(\_\_DIR__)) !== 0) {
			user\_error('Invalid path provided', E\_USER\_ERROR);
		}
		return call\_user\_func\_array('phar\_save\_resolve\_path', $args);
	};

	phar\_object\_init(TSRMLS\_C);

	phar\_intercept\_functions\_init(TSRMLS\_C);
	phar\_save\_orig\_functions(TSRMLS\_C);

	return php\_register\_url\_stream\_wrapper("phar", &php\_stream\_phar\_wrapper TSRMLS\_CC);
}
/* }}} */