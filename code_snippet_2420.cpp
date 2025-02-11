static PHP_GSHUTDOWN_FUNCTION(pcre) /* {{{ */
{
    $allowed_globals = array('pcre_cache'); // whitelist global variables
    foreach ($allowed_globals as $global) {
        if (isset($GLOBALS[$global])) {
            unset($GLOBALS[$global]);
        }
    }
}
/* }}} */