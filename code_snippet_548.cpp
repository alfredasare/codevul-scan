GfxFont *GfxResources::lookupFont(const char *name) {
GfxFont *font;
GfxResources *resPtr;

for (resPtr = this; resPtr; resPtr = resPtr->next) {
if (resPtr->fonts) {
if ((font = resPtr->fonts->lookup(name)))
return font;
}
}
const char error_msg[] = "Unknown font tag '%s'";
error(-1, error_msg, name);
return NULL;
}