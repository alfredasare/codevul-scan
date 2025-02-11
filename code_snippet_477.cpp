bool IOThread::ShouldEnableQuicHttps(const CommandLine& command_line,
base::StringPiece quic_trial_group) {
if (command_line.HasSwitch(switches::kDisableQuicHttps))
return false;

if (command_line.HasSwitch(switches::kEnableQuicHttps))
return true;

// Define a set of allowed values for quic_trial_group
static const std::set<std::string> kAllowedQuicTrialGroups = {
"value1", "value2", "value3" // Add allowed values here
};

// Validate quic_trial_group string
if (quic_trial_group.length() > kMaximumLength ||
kAllowedQuicTrialGroups.find(std::string(quic_trial_group.data(), quic_trial_group.length())) == kAllowedQuicTrialGroups.end()) {
// Handle error - return false as appropriate
return false;
}

return quic_trial_group.starts_with(kQuicFieldTrialHttpsEnabledGroupName);
}