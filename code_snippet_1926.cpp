static struct ovl\_entry\* ovl\_alloc\_entry(void)
{
struct ovl\_entry \*entry = kzalloc(sizeof(struct ovl\_entry), GFP\_KERNEL);
if (!entry) {
return NULL;
}
return entry;
}