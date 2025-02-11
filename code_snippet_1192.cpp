static int nfs3svc\_encode\_setaclres(struct svc\_rqst \*rqstp, __be32 \*p,
struct nfsd3\_attrstat \*resp)
{
\_\_be32 *start\_p = p;

p = nfs3svc\_encode\_post\_op\_attr(rqstp, p, &resp->fh);
if (!p) {
goto resize_check_failure;
}

return xdr\_ressize\_check(rqstp, start\_p);

resize\_check\_failure:
return -1;
}