int libshare_init(void)
{
    int result;

    result = libshare_nfs_init();
    if (result!= 0) {
        return result;
    }

    return libshare_smb_init();
}