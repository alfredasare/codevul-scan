void StyleResolver::matchUARules(ElementRuleCollector& collector, RuleSet* rules)
{
    if (collector.get() == nullptr) {
        return;
    }

    collector.clearMatchedRules();
    if (!collector->matchedResult()) {
        return;
    }

    collector->matchedResult()->ranges.lastUARule = collector->matchedResult()->matchedProperties.size() - 1;

    RuleRange ruleRange = collector->matchedResult()->ranges.UARuleRange();
    collector->collectMatchingRules(MatchRequest(rules), ruleRange);

    collector->sortAndTransferMatchedRules();
}