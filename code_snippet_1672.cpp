void ewk_frame_load_error(Evas_Object* ewkFrame, const char* errorDomain, int errorCode, bool isCancellation, const char* errorDescription, const char* failingUrl)
{
    Ewk_Frame_Load_Error error;

    DBG("ewkFrame=%p, error=%s (%d, cancellation=%hhu) \"%s\", url=%s",
        ewkFrame, errorDomain?(errorDomain?"": "null") : "null", errorCode, isCancellation,
        errorDescription, failingUrl);

    if (errorDomain == NULL) {
        // Handle the null pointer exception
        DBG("Error: errorDomain is null");
        // Return an error code or provide a meaningful error message
        return;
    }

    error.code = errorCode;
    error.is_cancellation = isCancellation;
    error.domain = errorDomain;
    error.description = errorDescription;
    error.failing_url = failingUrl;
    error.resource_identifier = 0;
    error.frame = ewkFrame;
    evas_object_smart_callback_call(ewkFrame, "load,error", &error);
    EWK_FRAME_SD_GET_OR_RETURN(ewkFrame, smartData);
    ewk_view_load_error(smartData->view, &error);
}