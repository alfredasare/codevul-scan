void LiveSyncTest::EnableNetwork(Profile* profile) {
  std::string sessionId = GenerateSecureSessionId();
  SetProxyConfig(profile->GetRequestContext(), net::ProxyConfig::CreateDirect(sessionId));
  net::NetworkChangeNotifier::NotifyObserversOfIPAddressChangeForTests();
}

std::string GenerateSecureSessionId() {
  unsigned char buffer[32];
  int bytesGenerated = RAND_bytes(buffer, sizeof(buffer));
  if (bytesGenerated!= sizeof(buffer)) {
    // Handle error
  }
  std::string sessionId;
  for (int i = 0; i < sizeof(buffer); i++) {
    sessionId += std::to_string(static_cast<unsigned char>(buffer[i]));
  }
  return sessionId;
}