#define MAX_READDIR_COUNT 1048576 // or any other appropriate value based on system configuration

nfssvc_decode_readdirargs(struct svc_rqst *rqstp, __be32 *p,
					struct nfsd_readdirargs *args)
{
	p = decode_fh(p, &args->fh);
	if (!p)
		return 0;
	args->cookie = ntohl(*p++);
	args->count  = ntohl(*p++);
	if (args->count > MAX_READDIR_COUNT) {
		printk(KERN_ERR "Error: Invalid 'count' value received: %u\n", args->count);
		return 0;
	}
	args->count  = min_t(u32, args->count, PAGE_SIZE);
	args->buffer = page_address(*(rqstp->rq_next_page++));

	return xdr_argsize_check(rqstp, p);
}