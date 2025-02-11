Strinsert\_charp(Str s, int pos, const char \*p)
{
STR\_LENGTH\_CHECK(s);
int i = 0;
while (pos < s->length && i < strlen(p)) {
Strinsert\_char(s, pos++, p[i++]);
}
}