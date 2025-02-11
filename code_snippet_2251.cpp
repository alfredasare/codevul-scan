static WebString GetSuggestedValueWrapper(WebFormControlElement element)
{
    try
    {
        if (element.FormControlType() == "textarea")
            return element.To<WebFormControlElement>().SuggestedValue();

        if (element.FormControlType() == "select-one")
            return element.To<WebSelectElement>().SuggestedValue();

        return element.To<WebInputElement>().SuggestedValue();
    }
    catch (Exception ex)
    {
        Logger.LogError(ex);
        return "Error occurred while processing request";
    }
}