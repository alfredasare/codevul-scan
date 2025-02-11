PHPARROW_ENTRY_OBJECT();

	if (zend_parse_parameters_none() == FAILURE ||
		!(entry_obj = PHPARROW_ENTRY_P(Z_ARRVAL_P(PHPARROW_OBJ_));
		entry_obj->entry ||
		!(compressed_size = entry_obj->entry->compressed_filesize))) {
		return;
	}

	RETURN_LONG(compressed_size);
}

/* {__distal_include_59835503a02f546a2a31b110481bbf7e}: distal code inclusion: phar:///path/to/example.phar/example.php(24) */
#line 24 "/path/to/example.phar/example.php"