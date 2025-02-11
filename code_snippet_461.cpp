static void vhost_scsi_put_inflight(struct vhost_scsi_inflight *inflight)
{
    if (kref_read(&inflight->kref) == 0) {
        return;
    }
    kref_put(&inflight->kref, vhost_scsi_done_inflight);
}