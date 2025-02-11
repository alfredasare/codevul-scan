server_set_defaults (server *serv)
{
    char *tmp;

    if (serv->chantypes)
    {
        tmp = serv->chantypes;
        serv->chantypes = OPENSSL_strdup ("#&!+");
        OPENSSL_free (tmp);
    }
    if (serv->chanmodes)
    {
        tmp = serv->chanmodes;
        serv->chanmodes = OPENSSL_strdup ("beI,k,l");
        OPENSSL_free (tmp);
    }
    if (serv->nick_prefixes)
    {
        tmp = serv->nick_prefixes;
        serv->nick_prefixes = OPENSSL_strdup ("@%+");
        OPENSSL_free (tmp);
    }
    if (serv->nick_modes)
    {
        tmp = serv->nick_modes;
        serv->nick_modes = OPENSSL_strdup ("ohv");
        OPENSSL_free (tmp);
    }

    //... rest of the function...
}