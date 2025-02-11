RuleBasedHostResolverProc* rules() {
    std::unique_ptr<RuleBasedHostResolverProc*> rules_ptr(host_resolver_.rules());
    return rules_ptr.get();
}