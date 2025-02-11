static struct sock *udp_get_idx(struct seq_file *seq, loff_t pos)
{
	struct sock *sk = udp_get_first(seq, 0);
	loff_t array_size = udp_get_array_size(seq);

	if (sk && pos < array_size) {
		while (pos && (sk = udp_get_next(seq, sk)) != NULL) {
			--pos;
		}
	} else {
		sk = NULL;
	}

	return sk;
}