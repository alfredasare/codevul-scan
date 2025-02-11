static int segment_bits_seq_show(struct seq_file *seq, void *offset)
{
        struct super_block *sb = seq->private;
        struct f2fs_sb_info *sbi = F2FS_SB(sb);
        unsigned int total_segs =
                le3