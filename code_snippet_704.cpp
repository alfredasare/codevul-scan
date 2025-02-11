static bool cmd_write_pio(IDEState *s, uint8_t cmd)
{
bool lba48 = (cmd == WIN_WRITE_EXT);

if (!s->blk) {
ide\_abort\_command(s);
return true;
}

ide\_cmd\_lba48\_transform(s, lba48);

s->req\_nb\_sectors = 1;
s->status = SEEK\_STAT | READY\_STAT;
int rc = ide\_transfer\_start(s, s->io\_buffer, 512, ide\_sector\_write);

s->media\_changed = 1;

if (rc != 0) {
ide\_abort\_command(s);
return true;
}

return false;
}