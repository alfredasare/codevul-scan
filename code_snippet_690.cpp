int jpc_pchglist_insert(jpc_pchglist_t *pcl, int idx, jpc_pocpchg_t *pchg)
{
    // Ensure the index is not out of bounds
    if (idx < 0 || idx > pcl->size) {
        return JPC_ERR_bad_index;
    }

    // Expand the list if necessary
    if (pcl->size == pcl->allocated) {
        pcl->allocated *= 2;
        pcl->buf = realloc(pcl->buf, pcl->allocated * sizeof(jpc_pocpchg_t));
    }

    // Shift elements to insert the new object
    if (idx < pcl->size) {
        memmove(&pcl->buf[idx + 1], &pcl->buf[idx], (pcl->size - idx) * sizeof(jpc_pocpchg_t));
    }

    // Insert the new object
    pcl->buf[idx] = *pchg;
    pcl->size++;

    return 0;
}