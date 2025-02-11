static void udf_find_vat_block(struct super_block *sb, int p_index,
			       int type1_index, sector_t start_block)
{
    struct udf_sb_info *sbi = UDF_SB(sb);
    struct udf_part_map *map = &sbi->s_partmaps[p_index];
    sector_t vat_block;
    struct kernel_lb_addr ino;

    //... (rest of the code remains the same)

    if (sbi->s_vat_inode!= NULL) {
        ino.partitionReferenceNum = type1_index;
        for (vat_block = start_block;
             vat_block >= map->s_partition_root &&
             vat_block >= start_block - 3 &&
            !sbi->s_vat_inode; vat_block--) {
            ino.logicalBlockNum = vat_block - map->s_partition_root;
            sbi->s_vat_inode = udf_iget(sb, &ino);
        }
    } else {
        printk(KERN_ERR "udf_find_vat_block: sbi->s_vat_inode is null\n");
    }
}