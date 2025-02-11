void RenderThreadImpl::OnNetworkQualityChanged(
    net::EffectiveConnectionType type,
    base::TimeDelta http_rtt,
    base::TimeDelta transport_rtt,
    double downlink_throughput_kbps) {
  UMA_HISTOGRAM_BOOLEAN("NQE.RenderThreadNotified", true);
  WebEffectiveConnectionType webType = EffectiveConnectionTypeToWebEffectiveConnectionTypeSafe(type);
  WebNetworkStateNotifier::SetNetworkQuality(webType, http_rtt, transport_rtt, downlink_throughput_kbps);
}

WebEffectiveConnectionType EffectiveConnectionTypeToWebEffectiveConnectionTypeSafe(net::EffectiveConnectionType type) {
  switch (type) {
    case net::EffectiveConnectionType::TYPE_2G:
      return WebEffectiveConnectionType::WEB_EFFECTIVE_CONNECTION_TYPE_2G;
    case net::EffectiveConnectionType::TYPE_3G:
      return WebEffectiveConnectionType::WEB_EFFECTIVE_CONNECTION_TYPE_3G;
    //...
    default:
      return WebEffectiveConnectionType::WEB_EFFECTIVE_CONNECTION_TYPE_UNKNOWN;
  }
}