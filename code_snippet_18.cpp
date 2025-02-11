static __be32 *read_buf(struct nfsd4_compoundargs *argp, u32 nbytes)
{
    unsigned int avail = (char *)argp->end - (char *)argp->p;
    __be32 *p;

    if (nbytes > avail) { // added input validation
        return NULL;
    }

    if (nbytes <= sizeof(argp->tmp)) {
        p = argp->tmp;
    } else {
        kfree(argp->tmpp);
        p = argp->tmpp = kmalloc(nbytes, GFP_KERNEL);
        if (!p)
            return NULL;
    }

    memcpy_safe(p, argp->p, avail); // replaced memcpy with safer alternative
    next_decode_page(argp);
    memcpy_safe(((char*)p)+avail, argp->p, (nbytes - avail)); // replaced memcpy with safer alternative
    argp->p += XDR_QUADLEN(nbytes - avail);
    return p;
}