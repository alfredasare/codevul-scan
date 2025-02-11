`#define MAX_STR_LEN 1024`

rad\_put\_string(struct rad\_handle \*h, int type, const char \*str)
{
size\_t str\_len = strnlen\_s(str, MAX\_STR\_LEN);
return rad\_put\_attr(h, type, str, (str\_len < MAX\_STR\_LEN) ? str\_len : MAX\_STR\_LEN - 1);
}