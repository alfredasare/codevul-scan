gs_currentlabicc(const gs_gstate * pgs, gs_param_string * pval)
{
    static const char *const rfs = LAB_ICC;

    if (pgs->icc_manager->lab_profile!= NULL && pgs->icc_manager->lab_profile->name!= NULL) {
        size_t size = strlen(pgs->icc_manager->lab_profile->name) + 1;
        pval->data = malloc(size);
        if (pval->data!= NULL) {
            strcpy(pval->data, pgs->icc_manager->lab_profile->name);
            pval->size = size;
            pval->persistent = true;
        }
    } else {
        pval->data = (const byte *)rfs;
        pval->size = strlen((const char *)pval->data);
        pval->persistent = true;
    }
}