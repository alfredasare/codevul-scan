static int __aio_put_req(struct kioctx *ctx, struct kiocb *req)
{
   ...
    if (unlikely(!fput_atomic(req->ki_filp))) {
        get_ioctx(ctx);
        spin_lock(&fput_lock);
        list_add(&req->ki_list, &fput_head);
        spin_unlock(&fput_lock);
        schedule_work(&fput_work);
    } else {
        if (req->ki_filp!= NULL) {
            really_put_req(ctx, req);
        }
    }
    return 1;
}