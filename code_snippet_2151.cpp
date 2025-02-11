bool ShouldQuicCloseSessionsOnIpChange(const VariationParameters& quic_trial_params) {
  std::string param_value = GetVariationParam(quic_trial_params, "close_sessions_on_ip_change");
  return std::string("true").compare(std::locale::classic(), 0, param_value, 0, param_value.size()) == 0;
}