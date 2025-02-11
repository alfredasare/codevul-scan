int pdf14_put_devn_params(gx_device *pdev, gs_devn_params *pdevn_params, gs_param_list *plist)
{
    if (!pdev || !pdevn_params || !plist) {
        return ERR_NULL_POINTER;
    }

    int code = put_param_pdf14_spot_names(pdev, &pdevn_params->pdf14_separations, plist);
    return code;
}