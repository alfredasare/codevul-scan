R\_API void \*r\_bin\_free(RBin *bin) {
if (!bin) {
return NULL;
}
if (bin->io\_owned) {
r\_io\_free (bin->iob.io);
}
bin->file = NULL;
free(bin->force);
free(bin->srcdir);
r\_list\_free(bin->binfiles);
r\_list\_free(bin->binxtrs);
r\_list\_free(bin->plugins);
sdb\_free(bin->sdb);
r\_id\_pool\_free(bin->file\_ids);
memset(bin, 0, sizeof(RBin));
free(bin);
return NULL;
}