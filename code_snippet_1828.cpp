Ewk_Frame_Load_Error error;

DBG("ewkFrame=%p, error=%s (%d, cancellation=%hhu) \"%s\", url=%s",
    ewkFrame, errorDomain, errorCode, isCancellation,
    errorDescription, failingUrl);

error.code = errorCode;
error.is_cancellation = isCancellation;
error.domain = errorDomain;
error.description = errorDescription ? errorDescription : "";
error.failing_url = failingUrl ? failingUrl : "";
error.resource_identifier = 0;
error.frame = ewkFrame;
evas_object_smart_callback_call(ewkFrame, "load,error", &error);
EWK_FRAME_SD_GET_OR_RETURN(ewkFrame, smartData);
ewk_view_load_error(smartData->view, &error);