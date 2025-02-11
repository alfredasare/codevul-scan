// Provide a safe interface for retrieving individual rules
RuleBasedHostResolverProc* GetRule(int index) {
  return host_resolver_.GetRule(index);
}

// Or provide a safe interface for retrieving a range of rules
std::vector<RuleBasedHostResolverProc*> GetRules(int start_index, int num_rules) {
  return host_resolver_.GetRules(start_index, num_rules);
}