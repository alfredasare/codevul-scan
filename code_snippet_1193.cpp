static gboolean webkit_signal_accumulator_object_handled(GSignalInvocationHint* ihint, GValue* returnAccu, const GValue* handlerReturn, gpointer dummy)
{
    gpointer newWebView = g_value_get_object(handlerReturn);
    g_value_set_object(returnAccu, newWebView);

    gboolean result = !newWebView;
    
    // Check if newWebView is not NULL and free the memory accordingly
    if (newWebView != NULL) {
        g_object_unref(newWebView);
    }

    return result;
}