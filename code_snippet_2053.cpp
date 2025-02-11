bool ShouldQuicMigrateSessionsOnNetworkChangeV2(
    const VariationParameters* quic_trial_params) {
  if (!quic_trial_params || !quic_trial_params->GetVariationParam) {
    return false;
  }

  std::string param_value = quic_trial_params->GetVariationParam("migrate_sessions_on_network_change_v2");
  if (param_value.empty()) {
    return false;
  }

  return boost::algorithm::iequals(param_value, "true");
}