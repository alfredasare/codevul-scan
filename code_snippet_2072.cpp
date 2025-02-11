void StyleResolver::matchUARules(ElementRuleCollector& collector, RuleSet* rules)
{
    collector.clearMatchedRules();

    // Check if the matchedProperties size is greater than 0 before accessing its elements
    if (collector.matchedResult().matchedProperties.size() > 0) {
        collector.matchedResult().ranges.lastUARule = collector.matchedResult().matchedProperties.size() - 1;
    } else {
        collector.matchedResult().ranges.lastUARule = -1;
    }

    RuleRange ruleRange = collector.matchedResult().ranges.UARuleRange();
    collector.collectMatchingRules(MatchRequest(rules), ruleRange);

    collector.sortAndTransferMatchedRules();
}