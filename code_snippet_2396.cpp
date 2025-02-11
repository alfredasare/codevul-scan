void PageSerializer::serializeCSSStyleSheet(CSSStyleSheet& styleSheet, const KURL& url)
{
    //...

    String itemText = rule->cssText();
    if (!itemText.isEmpty()) {
        if (!isValidCSSRule(itemText)) {
            continue;
        }

        cssText.append(itemText);
        if (i < styleSheet.length() - 1)
            cssText.appendLiteral("\n\n");
    }

    //...

    bool isValidCSSRule(const String& cssText) {
        static const String allowedProperties[] = {"background-color", "color", "font-size",...};
        static const String allowedValues[] = {"#rrggbb", "rgb(0, 0, 0)",...};

        String::size_type pos = 0;
        while ((pos = cssText.find("{", pos))!= String::npos) {
            String property = cssText.substr(pos + 1, cssText.find(":", pos + 1) - pos - 1);
            String value = cssText.substr(cssText.find(":") + 1);

            bool found = false;
            for (const String& allowedProperty : allowedProperties) {
                if (property == allowedProperty) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }

            for (const String& allowedValue : allowedValues) {
                if (value == allowedValue) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }

            pos = cssText.find("}", pos);
            if (pos != String::npos) {
                pos++;
            } else {
                return false;
            }
        }
        return true;
    }
}