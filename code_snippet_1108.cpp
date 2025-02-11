static int l_hostkey_hash(lua_State *L) {
    //...
    luaL_Buffer B;
    //...

    state = (struct ssh_userdata *) nseU_checkudata(L, 1, SSH2_UDATA, "ssh2");
    hash = (const unsigned char *) libssh2_hostkey_hash(state->session, hash_option[type]);

    if (hash == NULL)
        return nseU_safeerror(L, "could not get hostkey hash");

    luaL_buffinit(L, &B);
    for (int i = 0; i < hash_length[type]; i++) {
        char byte[4]; /* with space for NULL and possible escaped characters */
        snprintf(byte, sizeof(byte), "&#x%02X;", (unsigned int)hash[i]);
        if (i)
            luaL_addchar(&B, ':');
        luaL_addstring(&B, byte);
    }
    luaL_pushresult(&B);

    return 1;
}