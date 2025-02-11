int jas\_image\_copycmpt(jas\_image\_t *dstimage, int dstcmptno,
jas\_image\_t *srcimage, int srccmptno)
{
jas\_image\_cmpt\_t \*newcmpt;
int num\_elements = dstimage->numcmpts\_ - dstcmptno;
int total\_size = (num\_elements + 1) \* sizeof(jas\_image\_cmpt\_t \*);

if (dstimage->numcmpts\_ >= dstimage->maxcmpts\_) {
if (jas\_image\_growcmpts(dstimage, dstimage->maxcmpts\_ + 128)) {
return -1;
}
}

if (dstcmptno + 1 > dstimage->numcmpts\_) {
dstimage->numcmpts\_ = dstcmptno + 1;
}

if (!(newcmpt = jas\_image\_cmpt\_copy(srcimage->cmpts\_{\[srccmptno\]}}))) {
return -1;
}

// Check if there is enough space before copying
if (total\_size > dstimage->maxcmpts\_ \* sizeof(jas\_image\_cmpt\_t \*)) {
return -1;
}

if (dstcmptno < dstimage->numcmpts\_) {
memmove(&dstimage->cmpts\_{[dstcmptno + 1], dstimage->cmpts\_{[dstcmptno], num\_elements \* sizeof(jas\_image\_cmpt\_t \*)});
}

dstimage->cmpts\_{[dstcmptno] = newcmpt;
++dstimage->numcmpts\_;

jas\_image\_setbbox(dstimage);
return 0;
}