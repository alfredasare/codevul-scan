static int __check_block_validity(struct inode *inode, const char *func, unsigned int line, struct ext4_map_blocks *map)
{
	if (map->m_pblk == NULL || map->m_len > (int)(map->m_pgalloc - map->m_pblk)) {
		ext4_error_inode(inode, func, line, map->m_pblk,
				 "Buffer underflow or overflow detected");
		return -EFSCORRUPTED;
	}

	if (!ext4_data_block_valid(EXT4_SB(inode->i_sb), map->m_pblk,
				   min(map->m_len, (int)(map->m_pgalloc - map->m_pblk)))) {
		ext4_error_inode(inode, func, line, map->m_pblk,
				 "lblock %lu mapped to illegal pblock "
				 "(length %d)", (unsigned long) map->m_lblk,
				 map->m_len);
		return -EFSCORRUPTED;
	}
	return 0;
}