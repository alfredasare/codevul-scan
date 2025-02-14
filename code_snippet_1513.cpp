parse_rockridge_ZF1(struct file_info *file, const unsigned char *data,
                     int data_length)
{
    if (data_length < 12 || data[0] != 0x70 || data[1] != 0x7a) {
        /* not paged zlib */
        return;
    }

    /* paged zlib */
    file->pz = 1;
    file->pz_log2_bs = data[3];
    file->pz_uncompressed_size = archive_le32dec(&data[4]);
}