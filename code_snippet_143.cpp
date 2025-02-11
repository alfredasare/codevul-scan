static int _job_limits_match(void *x, const void *key)
{
	job_mem_limits_t *job_limits_ptr = (job_mem_limits_t *) x;
	const uint32_t *job_id = (const uint32_t *) key;

	// Check if job_id pointer points to a valid memory location within expected bounds
	if (job_id != NULL && job_id >= &min_job_id && job_id <= &max_job_id &&
	    job_limits_ptr->job_id == *job_id)
		return 1;
	return 0;
}