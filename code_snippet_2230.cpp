int nfsd_get_nrthreads(int n, int *nthreads, struct net *net)
{
	if (n <= 0 || n >= NFS_MAX_SERVERS) {
		return -EINVAL;
	}

	struct nfsd_net *nn = net_generic(net, nfsd_net_id);

	if (nn->nfsd_serv != NULL) {
		for (int i = 0; i < n && i < nn->nfsd_serv->sv_nrpools; i++)
			nthreads[i] = nn->nfsd_serv->sv_pools[i].sp_nrthreads;
	}

	return 0;
}