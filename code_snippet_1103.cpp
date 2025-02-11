static int override\_release(char __user \*release, size\_t len)
{
 int ret = 0;

 if (current->personality & UNAME26) {
 const char \*rest = UTS\_RELEASE;
 char buf[65] = {0};
 int ndots = 0;
 unsigned v;
 size\_t copy;

 while (\*rest) {
 if (\*rest == '.' && ++ndots >= 3)
 break;
 if (!isdigit(\*rest) && \*rest != '.')
 break;
 rest++;
 }

 v = ((LINUX\_VERSION\_CODE >> 8) & 0xff) + 40;
 copy = clamp\_t(size\_t, len, 1, sizeof(buf) - 1); // Subtract 1 to account for null terminator
 copy = scnprintf(buf, copy, "2.6.%u%s", v, rest);

 // Ensure copy\_to\_user includes the null terminator
 if (copy + 1 > len) {
 ret = -EINVAL;
 goto out;
 }

 ret = copy\_to\_user(release, buf, copy + 1);
 }
out:
 return ret;
}