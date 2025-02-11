int sshkey_perm_ok(const char *filename)
{
    struct stat st;
    if (stat(filename, &st) < 0) {
        return 0; // error
    }
    return (st.st_mode & S_IRWXG) == 0 && (st.st_mode & S_IRWXO) == 0;
}

sshkey_load_private_type(int type, const char *filename, const char *passphrase,
    struct sshkey **keyp, char **commentp, int *perm_ok)
{
    int fd, r;

    if (keyp!= NULL)
        *keyp = NULL;
    if (commentp!= NULL)
        *commentp = NULL;

    if ((fd = open(filename, O_RDONLY)) < 0) {
        if (perm_ok!= NULL)
            *perm_ok = 0;
        return SSH_ERR_SYSTEM_ERROR;
    }

    if (perm_ok!= NULL)
        *perm_ok = sshkey_perm_ok(filename);

    r = sshkey_load_private_type_fd(fd, type, passphrase, keyp, commentp);
    close(fd);
    return r;
}