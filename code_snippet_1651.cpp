static void add\_server\_options(struct dhcp\_packet \*packet)
{
 struct option\_set \*curr = server\_config.options;

 while (curr) {
 if (curr->data[OPT\_CODE] != DHCP\_LEASE\_TIME)
 udhcp\_add\_binary\_option(packet, curr->data);
 curr = curr->next;
 }

 packet->siaddr\_nip = server\_config.siaddr\_nip;

 if (server\_config.sname)
 strlcpy((char\*)packet->sname, server\_config.sname, sizeof(packet->sname));
if (server\_config.boot\_file)
strlcpy((char\*)packet->file, server\_config.boot\_file, sizeof(packet->file));
}

Or, if strlcpy is not available, use the following implementation of strlcpy:

size\_t my\_strlcpy(char \* restrict dst, const char \* restrict src, size\_t size)
{
size\_t len = strlen(src);
if (len < size)
memcpy(dst, src, len + 1);
else if (size != 0)
memcpy(dst, src, size - 1), dst[size - 1] = '\0';
return len;
}

And then use my\_strlcpy instead of strlcpy:

if (server\_config.sname)
my\_strlcpy((char\*)packet->sname, server\_config.sname, sizeof(packet->sname));
if (server\_config.boot\_file)
my\_strlcpy((char\*)packet->file, server\_config.boot\_file, sizeof(packet->file));