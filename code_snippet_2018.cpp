static int install_session_keyring(struct key *keyring)
{
    struct cred *new = NULL;
    int ret;

    new = prepare_creds();
    if (!new) {
        kfree(new);
        return -ENOMEM;
    }

    ret = install_session_keyring_to_cred(new, keyring);
    if (ret < 0) {
        abort_creds(new);
        return ret;
    }

    return commit_creds(new);
}