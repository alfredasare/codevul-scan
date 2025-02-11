static int l_hostkey_hash(lua_State *L) {
luaL_Buffer B;
static int hash_option[] = { LIBSSH2_HOSTKEY_HASH_MD5, LIBSSH2_HOSTKEY_HASH_SHA1 };
static int hash_length[] = { 16, 20 };
static const char *hashes[] = { "md5", "sha1", NULL };
int type = luaL\_checkoption(L, 2, "sha1", hashes);
struct ssh\_userdata \*state = NULL;
const unsigned char \*hash = NULL;

state = (struct ssh\_userdata \*) nseU\_checkudata(L, 1, SSH2\_UDATA, "ssh2");
hash = (const unsigned char \*) libssh2\_hostkey\_hash(state->session, hash\_option[type]);

if (hash == NULL)
return nseU\_safeerror(L, "could not get hostkey hash");

luaL\_buffinit(L, &B);
for (int i = 0; i < hash\_length[type]; i++) {
char byte[3]; /* with space for NULL */
int len = snprintf(byte, sizeof(byte), "%02X", (unsigned int)hash[i]);
if (len < 0 || len >= sizeof(byte)) { // Check for errors or truncation
return nseU\_safeerror(L, "failed to convert hash value to hex");
}
if (i)
luaL\_addchar(&B, ':');
luaL\_addlstring(&B, byte, 2);
}
luaL\_pushresult(&B);

return 1;
}