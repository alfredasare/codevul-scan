ELFOBJ* Elf_(r\_bin\_elf\_new)(const char\* file, bool verbose) {
ut8 \*buf;
int size;
ELFOBJ \*bin = R\_NEW0 (ELFOBJ);
if (!bin) {
return NULL;
}
memset (bin, 0, sizeof (ELFOBJ));
bin->file = file;
if (!(buf = (ut8\*)r\_file\_slurp (file, &size)) || size <= 0) {
free(buf);
return Elf_(r\_bin\_elf\_free) (bin);
}
bin->size = size;
bin->verbose = verbose;
bin->b = r\_buf\_new ();
if (!r\_buf\_set\_bytes (bin->b, buf, bin->size)) {
free (buf);
return Elf_(r\_bin\_elf\_free) (bin);
}
if (!elf\_init (bin)) {
free (buf);
return Elf_(r\_bin\_elf\_free) (bin);
}
free (buf);
return bin;
}