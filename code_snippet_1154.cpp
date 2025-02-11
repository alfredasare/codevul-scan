class DataReductionProxyConfig {
 public:
  DataReductionProxyConfig() : config_values_(std::make_unique<ProxyList>()) {}

  //... other member functions ...

  net::ProxyList GetAllConfiguredProxies() const {
    DCHECK(thread_checker_.CalledOnValidThread());
    if (!config_values_) return net::ProxyList();
    return config_values_->GetAllConfiguredProxies();
  }

 private:
  std::unique_ptr<ProxyList> config_values_;
};