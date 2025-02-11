SPL_METHOD(DirectoryIterator, current)
{
    if (!($this instanceof DirectoryIterator)) {
        throw new Exception("Invalid object type");
    }
    RETURN_ZVAL(getThis(), 1, 0);
}