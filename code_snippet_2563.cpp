bool address\_space\_access\_valid(AddressSpace \*as, hwaddr addr, int len, bool is\_write)
{
if (len <= 0) {
return true;
}
MemoryRegion \*mr;
hwaddr l, xlat;

while (len > 0) {
l = MIN(l, len);
mr = address\_space\_translate(as, addr, &xlat, &l, is\_write);
if (!memory\_access\_is\_direct(mr, is\_write)) {
l = MIN(l, memory\_access\_size(mr, l, addr));
if (!memory\_region\_access\_valid(mr, xlat, l, is\_write)) {
return false;
}
}

len -= l;
addr += l;
}
return true;
}