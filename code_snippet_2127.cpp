static int install_session_keyring(struct key *keyring)
{
	struct cred *new;
	int ret;

	if (!keyring)
		return -EINVAL;

	if (keyring->type != KEY_RING_SESSION_KEYRING)
		return -EINVAL;

	new = prepare_creds();
	if (!new)
		return -ENOMEM;

	ret = install_session_keyring_to_cred(new, keyring);
	if (ret < 0) {
		abort_creds(new);
		return ret;
	}

	return commit_creds(new);
}