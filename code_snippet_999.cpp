void mp_encode_lua_integer(lua_State *L, mp_buf *buf) {
#if (LUA_VERSION_NUM < 503) && BITS_32
lua_Number i = lua_tonumber(L,-1);
if (i > INT64_MAX || i < INT64_MIN) {
// Handle error case
return;
}
mp_encode_int(L, buf, (int64_t)i);
#else
lua_Integer i = lua_tointeger(L,-1);
mp_encode_int(L, buf, (int64_t)i);
#endif
}