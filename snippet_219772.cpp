  ~OpenSSLInitializer() {
    EVP_cleanup();
  }