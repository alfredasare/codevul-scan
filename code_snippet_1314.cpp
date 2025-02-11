static bool __stratum_send(struct pool *pool, char *s, ssize_t len)
{
	SOCKETTYPE sock = pool->sock;
	ssize_t ssent = 0;
	size_t dest_len = strlen(s) + len + 2; // +2 for '\n' and null terminator

	if (dest_len > sizeof(pool->buffer)) {
		applog(LOG_ERR, "Buffer overflow in stratum_send");
		return false;
	}

	if (opt_protocol)
		applog(LOG_DEBUG, "SEND: %s", s);

	strlcpy(pool->buffer, s, sizeof(pool->buffer));
	strlcat(pool->buffer, "\n", sizeof(pool->buffer));
	len++;

	while (len > 0 ) {
		struct timeval timeout = {0, 0};
		ssize_t sent;
		fd_set wd;

		FD_ZERO(&wd);
		FD_SET(sock, &wd);
		if (select(sock + 1, NULL, &wd, NULL, &timeout) < 1) {
			applog(LOG_DEBUG, "Write select failed on pool %d sock", pool->pool_no);
			return false;
		}
		sent = send(pool->sock, pool->buffer + ssent, len, 0);
		if (sent < 0) {
			if (errno != EAGAIN && errno != EWOULDBLOCK) {
				applog(LOG_DEBUG, "Failed to curl_easy_send in stratum_send");
				return false;