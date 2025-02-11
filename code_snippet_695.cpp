void RenderThreadImpl::OnNetworkQualityChanged(
net::EffectiveConnectionType type,
base::TimeDelta http_rtt,
base::TimeDelta transport_rtt,
double downlink_throughput_kbps) {
// Validate the input parameters
if (type < net::EffectiveConnectionType::CONNECTION_2G ||
type > net::EffectiveConnectionType::CONNECTION_TYPE_MAX) {
LOG(ERROR) << "Invalid EffectiveConnectionType: " << type;
return;
}

if (http_rtt < base::TimeDelta() || http_rtt > base::TimeDelta::Max()) {
LOG(ERROR) << "Invalid http_rtt: " << http_rtt;
return;
}

if (transport_rtt < base::TimeDelta() || transport_rtt > base::TimeDelta::Max()) {
LOG(ERROR) << "Invalid transport_rtt: " << transport_rtt;
return;
}

if (downlink_throughput_kbps < 0.0 || downlink_throughput_kbps > 10000.0) {
LOG(ERROR) << "Invalid downlink_throughput_kbps: " << downlink_throughput_kbps;
return;
}

UMA_HISTOGRAM_BOOLEAN("NQE.RenderThreadNotified", true);
WebNetworkStateNotifier::SetNetworkQuality(
EffectiveConnectionTypeToWebEffectiveConnectionType(type), http_rtt,
transport_rtt, downlink_throughput_kbps);
}