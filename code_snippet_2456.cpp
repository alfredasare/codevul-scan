XNewModifiermap(int keyspermodifier)
{
    XModifierKeymap *res = Xmalloc(sizeof(XModifierKeymap));
    if (res) {
        res->max_keypermod = keyspermodifier;
        res->modifiermap = (keyspermodifier > 0? 
            malloc(sizeof(KeyCode) * keyspermodifier) : NULL);
        if (res->modifiermap == NULL) {
            free(res);
            return (XModifierKeymap *) NULL;
        }
    }
    return (res);
}