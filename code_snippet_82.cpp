void ftp_gc(ftpbuf_t *ftp) {
    if (ftp == NULL || ftp->pwd == NULL || ftp->syst == NULL) {
        return;
    }

    if (ftp->pwd!= NULL) {
        free(ftp->pwd);
        ftp->pwd = NULL;
    }

    if (ftp->syst!= NULL) {
        free(ftp->syst);
        ftp->syst = NULL;
    }
}