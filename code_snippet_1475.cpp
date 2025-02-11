nfssvc_decode_readdirargs(struct svc_rqst *rqstp, __be32 *p,
                         struct nfsd_readdirargs *args)
{
    p = decode_fh(p, &args->fh);
    if (!p) {
        return 0;
    }

    args->cookie = ntohl(*p++);
    args->count = ntohl(*p++);

    // Ensure proper null-termination of the string
    args->cookie = htonl(args->cookie);
    args->count = htonl(args->count);
    *p = 0; // Set the null-terminator

    // Verify proper initialization of the args structure
    if (!args ||!args->fh) {
        return 0;
    }

    args->buffer = page_address(*(rqstp->rq_next_page++));

    return xdr_argsize_check(rqstp, p);
}