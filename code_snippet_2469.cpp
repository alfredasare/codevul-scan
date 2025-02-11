static WebString GetSuggestedValueWrapper(WebFormControlElement element) {
    // Add input validation
    if (element == null) {
        throw new ArgumentNullException(nameof(element), "The element cannot be null");
    }

    if (!element.GetType().IsAssignableFrom(typeof(WebFormControlElement))) {
        throw new ArgumentException("The element must be a WebFormControlElement or its subtype", nameof(element));
    }

    if (element.FormControlType() == "textarea") {
        return element.To<WebFormControlElement>().SuggestedValue();
    }

    if (element.FormControlType() == "select-one") {
        return element.To<WebSelectElement>().SuggestedValue();
    }

    return element.To<WebInputElement>().SuggestedValue();
}