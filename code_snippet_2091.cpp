set\_interface\_reachtime(const char \*iface, uint32\_t rtime)
{
char resolved\_path[MAX\_PATH];
int ret;

if (privsep\_enabled())
return privsep\_interface\_reachtime(iface, rtime);

if (strnlen(iface, MAX\_PATH) >= MAX\_PATH ||
realpath(iface, resolved\_path) == NULL ||
strstr(resolved\_path, "/../") != NULL ||
strstr(resolved\_path, "./") != NULL)
return -1;

ret = set\_interface\_var(resolved\_path,
PROC\_SYS\_IP6\_BASEREACHTIME\_MS,
NULL,
rtime);
if (ret)
ret = set\_interface\_var(resolved\_path,
PROC\_SYS\_IP6\_BASEREACHTIME,
"BaseReachableTimer",
rtime / 1000); /* sec */
return ret;
}