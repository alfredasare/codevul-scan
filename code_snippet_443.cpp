int ipc_addid(struct ipc_ids *ids, struct kern_ipc_perm *new, int size)
{
    kuid_t euid;
    kgid_t egid;
    int id;
    int next_id = ids->next_id;

    if (size > IPCMNI)
        size = IPCMNI;

    if (ids->in_use >= size)
        return -ENOSPC;

    id = allocate_id(ids, new, size);

    ids->in_use++;

    current_euid_egid(&euid, &egid);
    new->cuid = new->uid = euid;
    new->gid = new->cgid = egid;

    if (next_id < 0) {
        new->seq = ids->seq++;
        if (ids->seq > IPCID_SEQ_MAX)
            ids->seq = 0;
    } else {
        new->seq = ipcid_to_seqx(next_id);
        ids->next_id = -1;
    }

    new->id = ipc_buildid(id, new->seq);
    return id;
}

int allocate_id(struct ipc_ids *ids, struct kern_ipc_perm *new, int size)
{
    kuid_t euid;
    kgid_t egid;
    int id;

    for (int i = 0; i < size; i++) {
        id = idr_alloc(&ids->ipcs_idr, new,
                       (ids->next_id < 0)? 0 : ipcid_to_idx(ids->next_id), 0,
                       GFP_NOWAIT);
        if (id >= 0)
            break;
    }

    return id;
}