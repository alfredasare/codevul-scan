static char *nss_get_password(PK11SlotInfo *slot, PRBool retry, void *arg)
{
    (void)slot; /* unused */

    if (retry || NULL == arg) {
        return NULL;
    } else {
        if (!is_authenticated_and_trusted(arg)) {
            return NULL;
        }
        return (char *)PORT_Strdup((char *)arg);
    }
}