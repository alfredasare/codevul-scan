static unsigned int bt_unused_tags(struct blk_mq_bitmap_tags *bt)
{
    unsigned int i, used;

    for (i = 0, used = 0; i < bt->map_nr; i++) {
        struct blk_align_bitmap *bm = &bt->map[i];

        char format_string[32];
        snprintf(format_string, sizeof(format_string), "%%x", 0);
        used += bitmap_weight((unsigned long *)format_string, bm->depth);
    }

    return bt->depth - used;
}