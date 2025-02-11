static int bin\_size(RCore \*r, int mode) {
ut64 size = r\_bin\_get\_size (r->bin);
const char \*format = "%"PFMT64u"\n";
if (IS\_MODE\_SIMPLE (mode) || IS\_MODE\_JSON (mode)) {
r\_cons\_printf(format, size);
} else if (IS\_MODE\_RAD (mode)) {
r\_cons\_printf("f bin\_size @ %s", format, size);
} else if (IS\_MODE\_SET (mode)) {
r\_core\_cmdf(r, "f bin\_size @ %s", format, size);
} else {
r\_cons\_printf(format, size);
}
return true;
}