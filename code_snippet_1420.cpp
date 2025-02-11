static void rds_conn_message_info_retrans(struct socket *sock,
					  unsigned int len,
					  struct rds_info_iterator *iter,
					  struct rds_info_lengths *lens)
{
	mutex_lock(&sock->struct_mutex);
	rds_conn_message_info(sock, len, iter, lens, 0);
	mutex_unlock(&sock->struct_mutex);
}

struct socket {
	/* other socket fields */
	struct mutex struct_mutex;
};