file\_fmtcheck(struct magic\_set \*ms, const struct magic \*m, const char \*def,
const char \*file, size\_t line)
{
const char **endptr;
if (validate\_format\_string(m->desc)) {
const char \*ptr = fmtcheck(m->desc, def);
if (ptr == def)
file\_magerror(ms,
":lf:%zu: format `%s' does not match with `%s'",
file, line, m->desc, def);
return ptr;
} else {
file\_magerror(ms,
":lf:%zu: invalid format string `%s'.",
file, line, m->desc);
}
exit(1);
}