static void rds_conn_message_info_retrans(struct socket *sock,
					  unsigned int len,
					  struct rds_info_iterator *iter,
					  struct rds_info_lengths *lens)
{
	if (!rds_authenticate_critical_data(len, iter)) {
		/* Authentication failed, return an error */
		return;
	}

	rds_conn_message_info(sock, len, iter, lenses, 0);
}