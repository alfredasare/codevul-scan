static int bochs\_read(BlockDriverState \*bs, int64\_t sector\_num,
uint8\_t \*buf, int nb\_sectors)
{
int ret;

while (nb\_sectors > 0) {
int64\_t block\_offset = seek\_to\_sector(bs, sector\_num);
if (block\_offset >= 0) {
ret = bdrv\_pread(bs->file, block\_offset, buf, 512);
if (ret < 0) {
return -1;
} else if (ret != 512) {
memset(buf + ret, 0, 512 - ret);
}
} else {
memset(buf, 0, 512);
}
nb\_sectors--;
sector\_num++;
buf += 512;
}
return 0;
}