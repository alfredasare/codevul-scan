static bool __stratum_send(struct pool *pool, char *s, ssize_t len)
{
    SOCKETTYPE sock = pool->sock;
    ssize_t ssent = 0;

    char buffer[1024]; 
    sprintf(buffer, "%s\n", s); 
    len = strlen(buffer);

    //...
}