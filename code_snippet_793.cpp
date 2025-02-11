struct btrfs_dir_item *btrfs_lookup_dir_item(struct btrfs_trans_handle *trans,
					     struct btrfs_root *root,
					     struct btrfs_path *path, u64 dir,
					     const char *name, int name_len,
					     int mod)
{
	int ret;
	struct btrfs_key key;
	int ins_len = mod < 0 ? -1 : 0;
	int cow = mod != 0;
	struct btrfs_dir_item *item;

	key.objectid = dir;
	btrfs_set_key_type(&key, BTRFS_DIR_ITEM_KEY);

	key.offset = btrfs_name_hash(name, name_len);

	ret = btrfs_search_slot(trans, root, &key, path, ins_len, cow);
	if (ret < 0)
		return ERR_PTR(ret);

	if (ret == 0) {
		item = btrfs_match_dir_item_name(root, path, name, name_len);
		if (!item)
			ret = -ENOMEM;
		else
			ret = 0;
	}

	if (ret < 0)
		return ERR_PTR(ret);

	return item;
}