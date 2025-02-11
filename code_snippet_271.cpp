static char \*exif\_get\_tagname(int tag\_num, char \*ret, int len, tag\_table\_type tag\_table TSRMLS\_DC)
{
int i, t;
char tmp[32];

for (i = 0; (t = tag\_table[i].Tag) != TAG\_END\_OF\_LIST; i++) {
if (t == tag\_num) {
if (ret && len > 0) { // Check for overflow
if (sizeof(tag\_table[i].Desc) > len) {
strlcpy(ret, tag\_table[i].Desc, len);
if (len < 0) {
memset(ret + strlen(ret), ' ', -len - strlen(ret) - 1);
ret[-len - 1] = '\0';
}
return ret;
}
}
return tag\_table[i].Desc;
}
}

if (ret && len > 0) { // Check for overflow
if (sizeof(tmp) > len) {
snprintf(tmp, sizeof(tmp), "UndefinedTag:0x%04X", tag\_num);
strlcpy(ret, tmp, len);
if (len < 0) {
memset(ret + strlen(ret), ' ', -len - strlen(ret) - 1);
ret[-len - 1] = '\0';
}
}
}

return "";
}