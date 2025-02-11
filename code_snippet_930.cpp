Int rds\_get\_mr(struct rds\_sock \*rs, char __user \*optval, int optlen)
{
	struct rds\_get\_mr\_args args;
	int copied\_size;

	if (optlen < sizeof(struct rds\_get\_mr\_args))
		return -EINVAL;

	copied\_size = copy\_from\_user(&args, (struct rds\_get\_mr\_args \_\_user \*)optval,
			   sizeof(struct rds\_get\_mr\_args));

	if (copied\_size < 0)
		return -EFAULT;

	if (copied\_size != sizeof(struct rds\_get\_mr\_args))
		return -EINVAL;

	return __rds\_rdma\_map(rs, &args, NULL, NULL);
}