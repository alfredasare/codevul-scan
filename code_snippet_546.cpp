static long vhost_set_vring_endian(struct vhost_virtqueue *vq, int __user *argp)
{
	struct vhost_vring_state s;
	size_t bytes_copied;

	if (vq->private_data)
		return -EBUSY;

	bytes_copied = copy_from_user(&s, argp, sizeof(s));
	if (bytes_copied != sizeof(s))
		return -EFAULT;

	if (s.num != VHOST_VRING_LITTLE_ENDIAN &&
	    s.num != VHOST_VRING_BIG_ENDIAN)
		return -EINVAL;

	vq->user_be = s.num;

	return 0;
}