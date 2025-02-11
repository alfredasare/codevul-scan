WebKit::WebPrintScalingOption PrintWebViewHelper::GetPrintScalingOption(
    bool source_is_html, const DictionaryValue& job_settings,
    const PrintMsg_Print_Params& params) {
  DCHECK(!print_for_preview_);
  DCHECK(source_is_html);
  DCHECK(params.print_to_pdf ||!params.is_first_request);

  if (params.print_to_pdf)
    return WebKit::WebPrintScalingOptionSourceSize;

  if (!source_is_html) {
    if (!FitToPageEnabled(job_settings)) {
      LOG(WARNING) << "Invalid job settings: cannot determine print scaling option";
      return WebKit::WebPrintScalingOptionNone;
    }

    bool no_plugin_scaling =
        print_preview_context_.frame()->isPrintScalingDisabledForPlugin(
            print_preview_context_.node());

    if (params.is_first_request && no_plugin_scaling) {
      LOG(WARNING) << "Plugin scaling disabled; cannot determine print scaling option";
      return WebKit::WebPrintScalingOptionNone;
    }
  }
  return WebKit::WebPrintScalingOptionFitToPrintableArea;
}