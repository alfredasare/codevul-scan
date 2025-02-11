int btrfs_create_subvol_root(struct btrfs_trans_handle *trans,
			     struct btrfs_root *new_root,
			     struct btrfs_root *parent_root,
			     u64 new_dirid)
{
    //... (rest of the code remains the same)

    err = btrfs_subvol_inherit_props(trans, new_root, parent_root);
    if (err) {
        btrfs_dbg(new_root->fs_info, "error inheriting subvolume properties: %d", err);
        printk(KERN_ERR "btrfs: error inheriting subvolume properties: %d\n", err);
    }

    //... (rest of the code remains the same)
}