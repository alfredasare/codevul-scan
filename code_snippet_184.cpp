static int bt_seq_open(struct inode *inode, struct file *file)
{
	struct bt_sock_list *sk_list;
	struct bt_seq_state *s;

	if (!inode || !inode->i_private) {
		return -EINVAL;
	}
	sk_list = inode->i_private;

	s = __seq_open_private(file, &bt_seq_ops,
			       sizeof(struct bt_seq_state));
	if (!s)
		return -ENOMEM;

	if (!sk_list) {
		__seq_release(file, s);
		return -EINVAL;
	}

	s->l = sk_list;
	return 0;
}