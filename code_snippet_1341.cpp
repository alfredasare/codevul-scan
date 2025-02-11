void _gnutls_set_server_random(gnutls_session_t session, uint8_t * rnd)
{
    if (strlen((char*)rnd)!= TLS_RANDOM_SIZE) {
        // Handle invalid input
        return;
    }

    // Use a safe memory copy function
    strcpy_s(session->security_parameters.server_random, TLS_RANDOM_SIZE, (char*)rnd);
}