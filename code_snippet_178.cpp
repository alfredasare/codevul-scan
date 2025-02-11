XMLRPC_VALUE XMLRPC_CreateValueDateTime(const char* id, time_t time) {
    XMLRPC_VALUE val = XMLRPC_CreateValueEmpty();
    if(val) {
        XMLRPC_SetValueDateTime(val, time);
        if(id) {
            char buffer[256]; // Buffer to store sanitized id
            int len = snprintf(buffer, sizeof(buffer), "%s", id);
            buffer[len] = '\0';
            XMLRPC_SetValueID(val, buffer, 0);
        }
    }
    return val;
}