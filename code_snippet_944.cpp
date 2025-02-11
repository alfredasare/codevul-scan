void __fuse_get_request(struct fuse_req *req)
{
	mutex_lock(&req->count_mutex);
	refcount_inc(&req->count);
	mutex_unlock(&req->count_mutex);
}