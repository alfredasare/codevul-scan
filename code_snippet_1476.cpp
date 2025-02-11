_gnutls_set_server_random (gnutls_session_t session, const uint8_t *rnd, size_t rnd_len)
{
  size_t len_to_copy = sizeof(session->security_parameters.server_random);
  len_to_copy = len_to_copy < rnd_len ? len_to_copy : rnd_len; // Use min value
  memcpy (session->security_parameters.server_random, rnd, len_to_copy);
}