static void mcryptd_opportunistic_flush(void)
{
	struct mcryptd_flush_list *flist;
	struct mcryptd_alg_cstate *cstate;

	flist = per_cpu_ptr(mcryptd_flist, smp_processor_id());
	while (single_task_running()) {
		mutex_lock(&flist->lock);
		cstate = list_first_entry_or_null(&flist->list,
				struct mcryptd_alg_cstate, flush_list);
		if (!cstate || !cstate->flusher_engaged) {
			mutex_unlock(&flist->lock);
			return;
		}
		list_del(&cstate->flush_list);
		cstate->flusher_engaged = false;

		/* Re-acquire the lock before using cstate */
		mutex_lock(&flist->lock);
		cstate->alg_state->flusher(cstate);
		mutex_unlock(&flist->lock);
		mutex_unlock(&flist->lock);
	}
}