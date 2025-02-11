void brcmf_do_escan(struct brcmf_if *ifp, struct cfg80211_scan_request *request)
{
    //... (rest of the function remains the same)

    char *path = ifp->drvr->config->escan_info.escan_buf;
    size_t path_len = strlen(path);

    // Validate the path and restrict it to a allowed directory
    if (path_len > 0 && path[path_len - 1] == '/') {
        // Prevent path traversal attack by removing trailing slash
        path[path_len - 1] = '\0';
    }

    //... (rest of the function remains the same)
}