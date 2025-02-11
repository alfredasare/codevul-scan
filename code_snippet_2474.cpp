static ssize_t lbs_rdrf_read(struct file *file, char __user *userbuf,
			     size_t count, loff_t *ppos)
{
    struct lbs_private *priv = file->private_data;
    ssize_t pos = 0;
    int ret;
    unsigned long addr = (unsigned long)__get_free_page(GFP_KERNEL);
    char *buf = (char *)addr;
    u32 val;
    int max_output_len = 256; // adjust this value based on the expected output length

    if (!buf)
        return -ENOMEM;

    ret = lbs_get_reg(priv, CMD_RF_REG_ACCESS, priv->rf_offset, &val);
    mdelay(10);
    if (!ret) {
        pos = snprintf(buf, max_output_len, "RF[0x%x] = 0x%08x\n",
                       priv->rf_offset, val);
        ret = simple_read_from_buffer(userbuf, count, ppos, buf, pos);
    }
    free_page(addr);

    return ret;
}