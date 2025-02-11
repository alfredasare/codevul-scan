XMLRPC_VALUE XMLRPC_CreateValueDateTime(const char* id, time_t time) {
   XMLRPC_VALUE val = XMLRPC_CreateValueEmpty();
   if(val && id && strlen(id) < XMLRPC_VALUE_ID_MAX_LENGTH) {
      XMLRPC_SetValueDateTime(val, time);
      XMLRPC_SetValueID(val, id, 0);
   }
   return val;
}