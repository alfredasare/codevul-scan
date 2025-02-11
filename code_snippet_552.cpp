nfssvc_decode_sattrargs(struct svc_rqst *rqstp, __be32 *p,
                         struct nfsd_sattrargs *args)
{
	size_t attrs_size = sizeof(args->attrs);
	p = decode_fh(p, &args->fh);
	if (!p)
		return 0;
	p = decode_sattr(p, &args->attrs);

	if (p - rqstp->rq_arg.sa.data > attrs_size) {
		/* Handle error due to buffer overflow */
		return -EINVAL;
	}

	return xdr_argsize_check(rqstp, p);
}