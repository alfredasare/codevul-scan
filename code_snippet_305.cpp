c++
#include <vector>

class StyleSheetCSSRuleList {
public:
    // ...
    std::vector<CSSRule*> rules;
    // ...
};

StyleSheetCSSRuleList Create(CSSStyleSheet* sheet) {
    StyleSheetCSSRuleList list(sheet);
    list.rules.emplace_back(new CSSRule(/*...*/));
    list.rules.emplace_back(new CSSRule(/*...*/));
    // ... add more rules ...
    return list;
}