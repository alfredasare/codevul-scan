static struct socket *get_socket(int fd)
{
	struct socket *sock;

	/* special case to disable backend */
	if (fd == -1)
		return NULL;
	sock = get_raw_socket(fd);
	if (IS_ERR(sock)) {
		sock = get_tap_socket(fd);
		if (IS_ERR(sock))
			return ERR_PTR(-EINVAL);
	}
	return sock;
}