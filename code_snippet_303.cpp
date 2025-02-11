static StyleSheetCSSRuleList* Create(CSSStyleSheet* sheet) {
    if (sheet == nullptr) {
        return nullptr;
    }
    return new StyleSheetCSSRuleList(sheet);
}