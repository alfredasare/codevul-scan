cifs\_parse\_devname(const char \*devname, struct smb\_vol \*vol)
{
const char \*delims = "/\\";

if (strlen(devname) >= PATH\_MAX) {
return -EINVAL;
}

/* make sure we have a valid UNC double delimiter prefix */
if (strnspn(devname, delims, 2) != 2)
return -EINVAL;

/* find delimiter between host and sharename */
const char \*pos = strpbrk(devname + 2, delims);
if (!pos)
return -EINVAL;

/* skip past delimiter */
++pos;

/* now go until next delimiter or end of string */
size\_t len = strcspn(pos, delims);

/* move "pos" up to delimiter or NULL */
pos += len;

vol->UNC = kstrndup(devname, pos - devname, GFP\_KERNEL);
if (!vol->UNC)
return -ENOMEM;

convert\_delimiter(vol->UNC, '\\');

/* If pos is NULL, or is a bogus trailing delimiter then no prepath */
if (!*pos++ || !*pos)
return 0;

vol->prepath = kstrdup(pos, GFP\_KERNEL);
if (!vol->prepath) {
kfree(vol->UNC);
return -ENOMEM;
}

return 0;
}