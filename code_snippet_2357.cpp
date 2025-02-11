static bool send_client_authreq(PgSocket *client)
{
    size_t saltlen = 0;
    int res;
    int auth = cf_auth_type;
    uint8_t randbuf[16];

    if (auth == AUTH_CRYPT) {
        saltlen = 2;
    } else if (auth == AUTH_MD5) {
        saltlen = 4;
    }

    get_random_bytes(randbuf, saltlen);
    client->tmp_login_salt = malloc(saltlen);
    memcpy(client->tmp_login_salt, randbuf, saltlen);

    SEND_generic(res, client, 'R', "ib", auth, client->tmp_login_salt, saltlen);
    free(client->tmp_login_salt);
    return res;
}