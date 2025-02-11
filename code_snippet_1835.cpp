static void __exit exit_misc_binfmt(void)
{
    int err = 0;
    if ((err = unregister_binfmt(&misc_format))!= 0) {
        log_error("Error unregistering binfmt: [MASKED]", err); // Log the error at a lower severity level with masked sensitive information
    }
    if ((err = unregister_filesystem(&bm_fs_type))!= 0) {
        log_error("Error unregistering filesystem: [MASKED]", err); // Log the error at a lower severity level with masked sensitive information
    }
}