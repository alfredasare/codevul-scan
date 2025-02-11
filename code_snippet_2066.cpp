int gcc\_unaligned\_memcmp(const void \*p, const void \*q, size\_t l)
{
#if defined(__x86\_64__) || defined(__i386)
\#if defined(\_\_GNUC\_\_)
const unsigned char \*pa = (const unsigned char \*)p;
const unsigned char \*qa = (const unsigned char \*)q;
unsigned int diff = 0;

for (size\_t i = 0; i + 7 < l; i += 8)
{
\_\_builtin\_expect(\_\_builtin\_expect((uintptr\_t)pa & 7, 0) == 0, 1);
\_\_builtin\_expect(\_\_builtin\_expect((uintptr\_t)qa & 7, 0) == 0, 1);
diff |= \_\_builtin\_bswap32(pa[i] | pa[i + 1] << 8 | pa[i + 2] << 16 | pa[i + 3] << 24) ^
\_\_builtin\_bswap32(qa[i] | qa[i + 1] << 8 | qa[i + 2] << 16 | qa[i + 3] << 24);
}

if (i < l)
{
\_\_builtin\_expect(\_\_builtin\_expect((uintptr\_t)pa & 7, 0) == 0, 1);
\_\_builtin\_expect(\_\_builtin\_expect((uintptr\_t)qa & 7, 0) == 0, 1);
diff |= pa[i] | pa[i + 1] << 8 | pa[i + 2] << 16 | pa[i + 3] << 24 ^
qa[i] | qa[i + 1] << 8 | qa[i + 2] << 16 | qa[i + 3] << 24;
}

return __builtin\_expect(diff != 0, 0) ? (diff < 0 ? -1 : 1) : 0;

#else
return memcmp(p, q, l);
#endif

#else
return memcmp(p, q, l);
#endif
}