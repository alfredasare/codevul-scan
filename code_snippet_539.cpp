CaptureGroupNameSSLSocketPool::CaptureGroupNameSSLSocketPool(
HostResolver* host_resolver,
CertVerifier* cert_verifier)
: SSLClientSocketPool(
GetMaxSockets(), // max_sockets
GetMaxConnectionsPerServer(), // max_connections_per_server
cert_verifier,
nullptr, // dns_client_settings
nullptr, // resolver_context
nullptr, // ssl_config_service
nullptr, // ssl_session_cache_config
std::string(), // tls_unique_ids_enabled
nullptr, // tls_unique_ids_validator
nullptr, // tls_unique_ids_revoker
nullptr, // tls_unique_ids_cache
nullptr, // tls_session_resume_callback
nullptr, // tls_session_resume_callback_data
nullptr) { // ssl_error_handler
}

Note: The `GetMaxSockets` and `GetMaxConnectionsPerServer` functions should be implemented to return appropriate values based on your specific use case.