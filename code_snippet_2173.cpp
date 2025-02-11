PHP_FUNCTION(snmp_set_enum_print)
{
    long a1;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &a1) == FAILURE) {
        RETURN_FALSE;
    }

    // Validate and sanitize input data
    if (!is_long(a1)) {
        RETURN_FALSE;
    }

    // Use a safe alternative to store and retrieve data from SNMP library
    $buffer = str_pad('', 1024, '\0'); // Custom buffer with a fixed size
    vsprintf($buffer, '%ld', array($a1));
    netsnmp_ds_set_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_PRINT_NUMERIC_ENUM, (int) $buffer);

    RETURN_TRUE;
}