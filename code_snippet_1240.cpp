static void rng\_backend\_prop\_set\_opened(Object *obj, bool value, Error **errp)
{
RngBackend *s = RNG\_BACKEND(obj);
RngBackendClass *k = RNG\_BACKEND\_GET\_CLASS(s);
Error *local\_err = NULL;
bool current\_opened;

if (value == s->opened) {
return;
}

current\_opened = s->opened;
s->opened = value;

if (!value && current\_opened) {
error\_setg(errp, QERR\_PERMISSION\_DENIED);
return;
}

if (k->opened) {
k->opened(s, &local\_err);
if (local\_err) {
error\_propagate(errp, local\_err);
return;
}
}
}