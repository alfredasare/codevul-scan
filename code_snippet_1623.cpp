static void free_gauss(void) {
    int ret;

    ret = _WM_Lock(&gauss_lock);
    if (ret != 0) {
        /* Handle error */
        if (gauss_table != NULL) {
            free(gauss_table);
            gauss_table = NULL;
        }

        _WM_Unlock(&gauss_lock);
        return;
    }

    free(gauss_table);
    gauss_table = NULL;

    _WM_Unlock(&gauss_lock);
}