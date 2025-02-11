svc_rqst_alloc(struct svc_serv *serv, struct svc_pool *pool, int node)
{
	struct svc_rqst	*rqstp;
	void *tmp_argp, *tmp_resp;

	rqstp = kzalloc_node(sizeof(*rqstp), GFP_KERNEL, node);
	if (!rqstp)
		return rqstp;

	__set_bit(RQ_BUSY, &rqstp->rq_flags);
	spin_lock_init(&rqstp->rq_lock);
	rqstp->rq_server = serv;
	rqstp->rq_pool = pool;

	tmp_argp = kmalloc_node(serv->sv_xdrsize, GFP_KERNEL, node);
	if (!tmp_argp)
		goto out_enomem_rqstp;
	rqstp->rq_argp = tmp_argp;

	tmp_resp = kmalloc_node(serv->sv_xdrsize, GFP_KERNEL, node);
	if (!tmp_resp) {
		kfree(tmp_argp);
		goto out_enomem_rqstp;
	}
	rqstp->rq_resp = tmp_resp;

	if (!svc_init_buffer(rqstp, serv->sv_max_mesg, node)) {
		kfree(tmp_resp);
		goto out_enomem_argp;
	}

	return rqstp;

out_enomem_argp:
	kfree(rqstp->rq_argp);
out_enomem_rqstp:
	kfree(rqstp);
	return NULL;
}