static void seek\_interrupt(void)
{
debugt(__func__, "");
mutex\_lock(&floppy\_mutex);
if (inr != 2 || (ST0 & 0xF8) != 0x20) {
DRS->track = NEED\_2\_RECAL;
cont->error();
cont->redo();
mutex\_unlock(&floppy\_mutex);
return;
}
if (DRS->track >= 0 && DRS->track != ST1 && !blind\_seek) {
debug\_dcl(DP->flags,
"clearing NEWCHANGE flag because of effective seek\n");
debug\_dcl(DP->flags, "jiffies=%lu\n", jiffies);
clear\_bit(FD\_DISK\_NEWCHANGE\_BIT, &DRS->flags);
DRS->select\_date = jiffies;
}
DRS->track = ST1;
floppy\_ready();
mutex\_unlock(&floppy\_mutex);
}

static DEFINE\_MUTEX(floppy\_mutex);