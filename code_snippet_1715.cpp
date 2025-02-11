PHPAPI void var\_destroy(php\_unserialize\_data\_t \*var\_hashx)
{
if (!var\_hashx || !var\_hashx->first || !var\_hashx->first\_dtor) {
return;
}

while (var\_hash) {
next = var\_hash->next;
efree\_size(var\_hash, sizeof(var\_entries));
var\_hash = next;
}

while (var\_dtor\_hash) {
for (i = 0; i < var\_dtor\_hash->used\_slots; i++) {
if (var\_dtor\_hash->data[i] != NULL) {
#if VAR\_ENTRIES\_DBG
fprintf(stderr, "var\_destroy dtor(%p, %ld)\n", var\_dtor\_hash->data[i], Z\_REFCOUNT\_P(var\_dtor\_hash->data[i]));
#endif
zval\_ptr\_dtor(&var\_dtor\_hash->data[i]);
}
}
next = var\_dtor\_hash->next;
efree\_size(var\_dtor\_hash, sizeof(var\_dtor\_entries));
var\_dtor\_hash = next;
}
}