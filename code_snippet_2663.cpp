static ssize_t lbs\_rdrf\_read(struct file \*file, char __user \*userbuf,
size\_t count, loff\_t \*ppos)
{
struct lbs\_private \*priv = file->private\_data;
ssize\_t pos = 0;
int ret;
unsigned long addr = get\_zeroed\_page(GFP\_KERNEL);
char \*buf = (char \*)addr;
u32 val;

if (!buf)
return -ENOMEM;

ret = lbs\_get\_reg(priv, CMD\_RF\_REG\_ACCESS, priv->rf\_offset, &val);
mdelay(10);
if (!ret) {
pos = snprintf(buf, PAGE\_SIZE, "RF[0x%x] = 0x%08x\n",
priv->rf\_offset, val);
ret = simple\_read\_from\_buffer(userbuf, count, ppos, buf, pos < count ? pos : count);
}
free\_page(addr);

return ret;
}