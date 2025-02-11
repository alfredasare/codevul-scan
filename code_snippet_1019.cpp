static int nfs3svc_encode_setaclres(struct svc_rqst *rqstp, __be32 *p,
                                  struct nfsd3_attrstat *resp)
{
    pthread_mutex_lock(&lock); // Add a lock to protect the shared resource
    p = nfs3svc_encode_post_op_attr(rqstp, p, &resp->fh);
    pthread_mutex_unlock(&lock); // Release the lock

    return xdr_ressize_check(rqstp, p);
}