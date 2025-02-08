static void scsi_write_complete(void * opaque, int ret)
 {
     SCSIDiskReq *r = (SCSIDiskReq *)opaque;
     SCSIDiskState *s = DO_UPCAST(SCSIDiskState, qdev, r->req.dev);
    uint32_t len;
     uint32_t n;
 
     if (r->req.aiocb != NULL) {
        r->req.aiocb = NULL;
        bdrv_acct_done(s->bs, &r->acct);
    }

    if (ret) {
        if (scsi_handle_rw_error(r, -ret, SCSI_REQ_STATUS_RETRY_WRITE)) {
            return;
         }
     }
 
    n = r->iov.iov_len / 512;
     r->sector += n;
     r->sector_count -= n;
     if (r->sector_count == 0) {
         scsi_req_complete(&r->req, GOOD);
     } else {
        len = r->sector_count * 512;
        if (len > SCSI_DMA_BUF_SIZE) {
            len = SCSI_DMA_BUF_SIZE;
        }
        r->iov.iov_len = len;
        DPRINTF("Write complete tag=0x%x more=%d\n", r->req.tag, len);
        scsi_req_data(&r->req, len);
     }
 }
