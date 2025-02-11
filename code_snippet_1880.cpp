static UPNP_INLINE void glob_alias_init(void)
{
    struct xml_alias_t *alias = &gAliasDoc;
    int i;

    if (XML_ALIAS_SIZE > 0) {
        for (i = 0; i < XML_ALIAS_SIZE; i++) {
            if (i < sizeof(alias->doc) / sizeof(alias->doc[0])) {
                membuffer_init(&alias->doc[i]);
            }
        }
    }
    alias->ct = NULL;
    alias->last_modified = 0;
}