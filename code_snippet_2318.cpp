connection_edge_end_errno(edge_connection_t *conn)
{
  uint8_t reason;
  int sock_errno;

  tor_assert(conn);

  sock_errno = tor_socket_errno(conn->base_.s);
  if (sock_errno == -1) {
    log_error("Error occurred on socket: %s", strerror(sock_errno));
    return -1;
  }

  reason = errno_to_stream_end_reason(sock_errno);
  return connection_edge_end(conn, reason);
}