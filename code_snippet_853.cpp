int virTypedParameterValidateSet(virConnectPtr conn,
                                 virTypedParameterPtr params,
                                 int nparams)
{
    int i;

    for (i = 0; i < nparams; i++) {
        virTypedParameterPtr param = &params[i];

        if (param->type == VIR_TYPED_PARAM_STRING) {
            const char *path = param->value.string;

            // Check if the provided path is within the expected boundaries
            if (path[0] == '/' || strcasecmp(path, "/.") == 0 || strcasecmp(path, "/..") == 0) {
                virReportError(conn, VIR_ERROR, "%s", "Path traversal detected");
                return -1;
            }
        }
    }

    return 0;
}