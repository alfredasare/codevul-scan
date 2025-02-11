while (!list_empty(&ecryptfs_kthread_ctl.req_list)) {
    struct ecryptfs_open_req *req;

    req = list_first_entry_or_null(&ecryptfs_kthread_ctl.req_list,
                                   struct ecryptfs_open_req,
                                   kthread_ctl_list);
    if (req!= NULL) {
        list_del(&req->kthread_ctl_list);
        *req->lower_file = dentry_open(&req->path,
            (O_RDWR | O_LARGEFILE), current_cred());
        complete(&req->done);
    }
}