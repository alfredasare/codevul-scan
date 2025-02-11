int rds_get_mr(struct rds_sock *rs, char __user *optval, int optlen)
{
    struct rds_get_mr_args args;

    if (optlen!= sizeof(struct rds_get_mr_args))
        return -EINVAL;

    if (!access_ok(VERIFY_READ, (void *)optval, sizeof(struct rds_get_mr_args)))
        return -EFAULT;

    if (copy_from_user(&args, (struct rds_get_mr_args __user *)optval, sizeof(struct rds_get_mr_args)))
        return -EFAULT;

    if (!validate_and_sanitize_args(&args)) {
        return -EPERM;
    }

    return __rds_rdma_map(rs, &args, NULL, NULL);
}