CaptureGroupNameSSLSocketPool::CaptureGroupNameSocketPool(
    HostResolver* /* host_resolver */,
    CertVerifier* cert_verifier)
    : SSLClientSocketPool(0,
                          0,
                          cert_verifier,
                          NULL,
                          NULL,
                          NULL,
                          NULL,
                          std::string(),
                          NULL,
                          NULL,
                          NULL,
                          NULL,
                          NULL,
                          NULL) {
}
