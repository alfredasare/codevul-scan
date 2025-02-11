free_share(sa_share_impl_t impl_share) {
    sa_fstype_t *fstype;

    if (impl_share == NULL) {
        return;
    }

    fstype = fstypes;
    while (fstype != NULL) {
        if (impl_share->fsinfo && impl_share->fsinfo->resource && impl_share->fsinfo->resource->shareopts && impl_share->fsinfo->resource->shareopts->clear_shareopts) {
            impl_share->fsinfo->resource->shareopts->clear_shareopts(impl_share);
        }

        free(FSINFO(impl_share, fstype)->resource);

        if (FSINFO(impl_share, fstype)->dataset != NULL) {
            free(FSINFO(impl_share, fstype)->dataset);
        }

        fstype = fstype->next;
    }

    if (impl_share->sharepath != NULL) {
        free(impl_share->sharepath);
    }

    if (impl_share->dataset != NULL) {
        free(impl_share->dataset);
    }

    if (impl_share->fsinfo != NULL) {
        free(impl_share->fsinfo);
    }

    free(impl_share);
}