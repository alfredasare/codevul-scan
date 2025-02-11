static unsigned int bt_unused_tags(struct blk_mq_bitmap_tags *bt)
{
	unsigned int i, used;

	for (i = 0, used = 0; i < bt->map_nr && i < BT_MAX_TAGS; i++) {
		struct blk_align_bitmap *bm = &bt->map[i];

		if (i >= bt->map_nr) {
			break;
		}

		used += bitmap_weight(&bm->word, bm->depth);
	}

	return bt->depth - used;
}