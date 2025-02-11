PHP_MINIT_FUNCTION(exif)
{
    REGISTER_INI_ENTRIES();
    if (zend_hash_exists(&module_registry, "mbstring", sizeof("mbstring"))) {
        $module_value = zend_hash_get(&module_registry, "mbstring");
        if ($module_value && is_string($module_value)) {
            REGISTER_LONG_CONSTANT("EXIF_USE_MBSTRING", 1, CONST_CS | CONST_PERSISTENT);
        } else {
            error_log("Invalid module registry value for'mbstring'");
        }
    } else {
        REGISTER_LONG_CONSTANT("EXIF_USE_MBSTRING", 0, CONST_CS | CONST_PERSISTENT);
    }
    return SUCCESS;
}