static void put\_reserved\_req(struct fuse\_conn *fc, struct fuse\_req *req)
{
 struct file *file = req->stolen\_file;
 struct fuse\_file *ff = file->private\_data;
 struct fuse\_req *old\_req;

 spin\_lock(&fc->lock);
 fuse\_request\_init(req);
 old\_req = ff->reserved\_req;
 if (old\_req) {
 ff->reserved\_req = NULL;
 wake\_up\_all(&fc->reserved\_req\_waitq);
 }
 BUG\_ON(ff->reserved\_req != NULL);
 ff->reserved\_req = req;
 spin\_unlock(&fc->lock);
 fput(file);
}