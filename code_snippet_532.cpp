static ZIPARCHIVE_METHOD(getCommentIndex)
{
    struct zip *intern;
    zval *self = getThis();
    zend_long index, flags = 0;
    const char * comment;
    size_t comment_len = 0; 
    struct zip_stat sb;

    if (!self) {
        RETURN_FALSE;
    }

    ZIP_FROM_OBJECT(intern, self);

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "l|l",
            &index, &flags) == FAILURE) {
        return;
    }

    PHP_ZIP_STAT_INDEX(intern, index, 0, sb);
    comment = zip_get_file_comment(intern, index, (size_t*)&comment_len, (int)flags);
    if (comment && comment_len > 0) {
        RETURN_STRINGL((char *)comment, (size_t)comment_len);
    } else {
        RETURN_FALSE;
    }
}