SPL_METHOD(SplDoublyLinkedList, isEmpty)
{
	zend_long count;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	count = spl_dllist_count(getThis());
	RETURN_BOOL(count == 0);
}

static zend_long spl_dllist_count(zend_object *object)
{
	SplDoublyLinkedList *intern = spl_dllist_object_intern(object);
	spl_dllist_iterator *it;
	zend_long count = 0;

	it = spl_dllist_get_iterator(intern, SPL_ITERATOR_MODE_READONLY);
	if (!it) {
		return 0;
	}

	while (zend_iterator_has_more(it->iter)) {
		zend_object *element_obj = zend_iterator_get_current_data(it->iter);
		if (element_obj) {
			++count;
		}
		zend_iterator_next(it->iter);
	}

	zend_iterator_destroy(it->iter);

	return count;
}