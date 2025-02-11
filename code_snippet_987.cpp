net::ProxyList DataReductionProxyConfig::GetAllConfiguredProxies() const {
  DCHECK(thread_checker_.CalledOnValidThread());
  auto config_values = config_values_.get();
  if (!config_values) {
    return net::ProxyList();
  }
  return config_values->GetAllConfiguredProxies();
}