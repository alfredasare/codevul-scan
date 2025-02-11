Int rpmVerifyFile(const rpmts ts, const rpmfi fi,
rpmVerifyAttrs \* res, rpmVerifyAttrs omitMask)
{
struct stat st;
if (lstat(fi->fn, &st) < 0) {
// Handle error
return 1;
}

rpmVerifyAttrs vfy = rpmfiVerify(&st, fi, omitMask);

if (res)
\*res = vfy;

return (vfy & RPMVERIFY\_LSTATFAIL) ? 1 : 0;
}