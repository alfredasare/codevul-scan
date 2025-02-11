static int segment_bits_seq_show(struct seq_file *seq, void *offset)
{
    struct super_block *sb = seq->private;
    struct f2fs_sb_info *sbi = F2FS_SB(sb);
    unsigned int total_segs = le32_to_cpu(sbi->raw_super->segment_count_main);
    int i;

    seq_puts(seq, "format: segment_type|valid_blocks|bitmaps\n"
            "segment_type(0:HD, 1:WD, 2:CD, 3:HN, 4:WN, 5:CN)\n");

    for (i = 0; i < total_segs; i++) {
        if (i >= 0 && i < total_segs) {
            struct seg_entry *se = get_seg_entry(sbi, i);

            seq_printf(seq, "%-10d", i);
            seq_printf(seq, "%d|%-3u|", se->type,
                        get_valid_blocks(sbi, i, false));
            for (int j = 0; j < SIT_VBLOCK_MAP_SIZE; j++)
                seq_printf(seq, " %.2x", se->cur_valid_map[j]);
            seq_putc(seq, '\n');
        } else {
            seq_printf(seq, "Invalid segment index %d\n", i);
        }
    }
    return 0;
}