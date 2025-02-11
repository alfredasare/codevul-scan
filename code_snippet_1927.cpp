static int cqspi\_erase(struct spi\_nor \*nor, loff\_t offs)
{
int ret;
size\_t max\_offs = nor->chip\_size - nor->sector\_size;

ret = cqspi\_set\_protocol(nor, 0);
if (ret)
return ret;

if (offs < 0 || offs >= max\_offs)
return -EINVAL;

/* Send write enable, then erase commands. */
ret = nor->write\_reg(nor, SPINOR\_OP\_WREN, NULL, 0);
if (ret)
return ret;

/* Set up command buffer. */
ret = cqspi\_command\_write\_addr(nor, nor->erase\_opcode, offs % nor->sector\_size);
if (ret)
return ret;

return 0;
}