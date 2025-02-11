void LiveSyncTest::EnableNetwork(Profile* profile) {
net::ProxyConfig proxyConfig = net::ProxyConfig::CreateNoProxy();
SetProxyConfig(profile->GetRequestContext(), proxyConfig);
net::NetworkChangeNotifier::NotifyObserversOfIPAddressChangeForTests();
}