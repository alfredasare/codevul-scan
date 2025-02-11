static int _job_limits_match(void *x, void *key)
{
    job_mem_limits_t *job_limits_ptr = (job_mem_limits_t *) x;
    uint32_t *job_id = (uint32_t *) key;

    if (*job_id < 0 || *job_id >= job_limits_ptr->limits_size)
        return 0;

    if (job_limits_ptr->job_id == *job_id)
        return 1;
    return 0;
}