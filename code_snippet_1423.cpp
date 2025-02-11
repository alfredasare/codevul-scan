void free_share(sa_share_impl_t impl_share) {
    sa_fstype_t *fstype;
    char *temp;

    if (impl_share == NULL) {
        return;
    }

    for (fstype = fstypes; fstype!= NULL; fstype = fstype->next) {
        temp = strdup(FSINFO(impl_share, fstype)->resource);
        memset(temp, 0, strlen(temp));
        free(temp);
        FSINFO(impl_share, fstype)->resource = NULL;
    }

    free(impl_share->sharepath);
    free(impl_share->dataset);
    free(impl_share->fsinfo);
    free(impl_share);
}