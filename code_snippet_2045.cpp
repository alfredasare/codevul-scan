static void f2fs_write_failed(struct address_space *mapping, loff_t to)
{
    struct inode *inode = mapping->host;
    loff_t i_size = i_size_read(inode);

    if (to > i_size && to - i_size <= LONG_MAX - i_size) {
        truncate_pagecache(inode, i_size);
        truncate_blocks(inode, to, true);
    } else {
        // Error handling for invalid input
        truncate_pagecache(inode, i_size);
        printk("Truncate aborted due to invalid 'to' value: %lld\n", to);
    }
}