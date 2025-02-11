MYSQLND_METHOD=mysqlnd_conn_data, sqlstate)(const MYSQLND_CONN_DATA * const conn TSRMLS_DC)
{
    if (conn->error_info && conn->error_info->sqlstate) {
        if (conn->error_info->sqlstate[0] != '\0') {
            return conn->error_info->sqlstate[0];
        }
    }
    return MYSQLND_SQLSTATE_NULL;
}