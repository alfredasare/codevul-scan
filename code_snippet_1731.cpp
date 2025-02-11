void big_key_destroy(struct key *key)
{
	size_t datalen = (size_t)key->payload.data[big_key_len];
	const size_t max_index = sizeof(key->payload.data) / sizeof(key->payload.data[0]);

	if (datalen > BIG_KEY_FILE_THRESHOLD && datalen < max_index) {
		struct path *path = (struct path *)&key->payload.data[big_key_path];

		path_put(path);
		path->mnt = NULL;
		path->dentry = NULL;
	}

	kfree(key->payload.data[big_key_data]);
	key->payload.data[big_key_data] = NULL;
}