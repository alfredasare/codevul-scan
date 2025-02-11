static int __check_block_validity(struct inode *inode, const char *func,
				unsigned int line,
				struct ext4_map_blocks *map)
{
    char error_msg[1024];
    const char *format_str = "lblock %lu mapped to illegal pblock (length %d)";
    const char *safe_format_str = "lblock %lu mapped to illegal pblock";

    if (strchr(format_str, '%')!= NULL) {
        format_str = safe_format_str;
    }

    snprintf(error_msg, sizeof(error_msg), format_str, (unsigned long) map->m_lblk, map->m_len);

    ext4_error_inode(inode, func, line, map->m_pblk, error_msg);

    return 0;
}