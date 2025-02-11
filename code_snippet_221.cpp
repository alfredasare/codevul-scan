void bioset_free(struct bio_set *bs)
{
	struct bio_set *tmp_bs;

	tmp_bs = bs;

	if (bs->rescue_workqueue)
		destroy_workqueue(bs->rescue_workqueue);

	bs = NULL; /* Remove the pointer that points to the original 'bs' */

	if (tmp_bs->bio_pool)
		mempool_destroy(tmp_bs->bio_pool);

	if (tmp_bs->bvec_pool)
		mempool_destroy(tmp_bs->bvec_pool);

	bioset_integrity_free(tmp_bs);
	bio_put_slab(tmp_bs);

	kfree(tmp_bs);
}