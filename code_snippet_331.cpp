GF_Err mdia\_Write(GF\_Box *s, GF\_BitStream *bs)
{
GF\_Err e;
GF\_MediaBox *ptr = (GF\_MediaBox *)s;
e = gf\_isom\_box\_write\_header(s, bs);
if (e) return e;
if (ptr->mediaHeader) {
// Add null check
if (ptr->mediaHeader->data != NULL && ptr->mediaHeader->size != 0) {
e = gf\_isom\_box\_write((GF\_Box *) ptr->mediaHeader, bs);
if (e) return e;
}
}
if (ptr->handler) {
// Add null check
if (ptr->handler->data != NULL && ptr->handler->size != 0) {
e = gf\_isom\_box\_write((GF\_Box *) ptr->handler, bs);
if (e) return e;
}
}
if (ptr->information) {
// Add null check
if (ptr->information->data != NULL && ptr->information->size != 0) {
e = gf\_isom\_box\_write((GF\_Box *) ptr->information, bs);
if (e) return e;
}
}
return GF\_OK;
}