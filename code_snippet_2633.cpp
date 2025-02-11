static void __exit pf_exit(void)
{
	struct pf_unit *pf;
	int unit;
	const int max_units = PF_UNITS;

	unregister_blkdev(major, name);
	for (pf = units, unit = 0; unit < max_units; pf++, unit++) {
		if (pf->present) {
			del_gendisk(pf->disk);

			blk_cleanup_queue(pf->disk->queue);
			blk_mq_free_tag_set(&pf->tag_set);
			put_disk(pf->disk);

			if (pf->present)
				pi_release(pf->pi);
		}
	}
}