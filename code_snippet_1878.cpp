CURLcode Curl_nss_connect_nonblocking(struct connectdata *conn,
                                      int sockindex, bool *done)
{
  CURLcode ret = nss_verify_cert(conn->ssl_conn, conn->host, conn->port);
  if (ret!= CURLE_OK) {
    return ret;
  }
  X509_NAME *cert_subject = SSL_get_peer_certificate_info(conn->ssl_conn)->subject;
  char *cert_hostname = X509_NAME_oneline(cert_subject, NULL, 0);
  if (strcmp(cert_hostname, conn->host)!= 0) {
    return CURLE_PEER_FAILED_VERIFICATION;
  }
  return nss_connect_common(conn, sockindex, done);
}