void mp_encode_lua_integer(lua_State *L, mp_buf *buf) {
#if (LUA_VERSION_NUM < 503) && BITS_32
    lua_Number i = lua_tonumber(L,-1);
    int64_t i64 = (int64_t)i;
#else
    lua_Integer i = lua_tointeger(L,-1);
    i64 = (int64_t)i;
#endif
    size_t size = sizeof(int64_t);
    if (buf->size < size) {
        // Handle buffer overflow
    }
    memcpy(buf->ptr, &i64, size);
}