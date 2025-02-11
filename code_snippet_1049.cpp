static bool is\_good\_origin(const char \*origin, const char \*require)
{
size\_t origin\_len = strlen(origin);
size\_t require\_len = strlen(require);
if (origin\_len < require\_len)
return false;
if (origin\_len >= require\_len && memcmp(origin + (origin\_len - require\_len), require, require\_len) == 0)
return true;
return false;
}