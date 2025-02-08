static int ext2_show_options(struct seq_file *seq, struct dentry *root)
{
	struct super_block *sb = root->d_sb;
	struct ext2_sb_info *sbi = EXT2_SB(sb);
	struct ext2_super_block *es = sbi->s_es;
	unsigned long def_mount_opts;

	spin_lock(&sbi->s_lock);
	def_mount_opts = le32_to_cpu(es->s_default_mount_opts);

	if (sbi->s_sb_block != 1)
		seq_printf(seq, ",sb=%lu", sbi->s_sb_block);
	if (test_opt(sb, MINIX_DF))
		seq_puts(seq, ",minixdf");
	if (test_opt(sb, GRPID))
		seq_puts(seq, ",grpid");
	if (!test_opt(sb, GRPID) && (def_mount_opts & EXT2_DEFM_BSDGROUPS))
		seq_puts(seq, ",nogrpid");
	if (!uid_eq(sbi->s_resuid, make_kuid(&init_user_ns, EXT2_DEF_RESUID)) ||
	    le16_to_cpu(es->s_def_resuid) != EXT2_DEF_RESUID) {
		seq_printf(seq, ",resuid=%u",
				from_kuid_munged(&init_user_ns, sbi->s_resuid));
	}
	if (!gid_eq(sbi->s_resgid, make_kgid(&init_user_ns, EXT2_DEF_RESGID)) ||
	    le16_to_cpu(es->s_def_resgid) != EXT2_DEF_RESGID) {
		seq_printf(seq, ",resgid=%u",
				from_kgid_munged(&init_user_ns, sbi->s_resgid));
	}
	if (test_opt(sb, ERRORS_RO)) {
		int def_errors = le16_to_cpu(es->s_errors);

		if (def_errors == EXT2_ERRORS_PANIC ||
		    def_errors == EXT2_ERRORS_CONTINUE) {
			seq_puts(seq, ",errors=remount-ro");
		}
	}
	if (test_opt(sb, ERRORS_CONT))
		seq_puts(seq, ",errors=continue");
	if (test_opt(sb, ERRORS_PANIC))
		seq_puts(seq, ",errors=panic");
	if (test_opt(sb, NO_UID32))
		seq_puts(seq, ",nouid32");
	if (test_opt(sb, DEBUG))
		seq_puts(seq, ",debug");
	if (test_opt(sb, OLDALLOC))
		seq_puts(seq, ",oldalloc");

#ifdef CONFIG_EXT2_FS_XATTR
	if (test_opt(sb, XATTR_USER))
		seq_puts(seq, ",user_xattr");
	if (!test_opt(sb, XATTR_USER) &&
	    (def_mount_opts & EXT2_DEFM_XATTR_USER)) {
		seq_puts(seq, ",nouser_xattr");
	}
#endif

#ifdef CONFIG_EXT2_FS_POSIX_ACL
	if (test_opt(sb, POSIX_ACL))
		seq_puts(seq, ",acl");
	if (!test_opt(sb, POSIX_ACL) && (def_mount_opts & EXT2_DEFM_ACL))
		seq_puts(seq, ",noacl");
#endif

	if (test_opt(sb, NOBH))
		seq_puts(seq, ",nobh");

#if defined(CONFIG_QUOTA)
	if (sbi->s_mount_opt & EXT2_MOUNT_USRQUOTA)
		seq_puts(seq, ",usrquota");

	if (sbi->s_mount_opt & EXT2_MOUNT_GRPQUOTA)
		seq_puts(seq, ",grpquota");
#endif

#ifdef CONFIG_FS_DAX
	if (sbi->s_mount_opt & EXT2_MOUNT_XIP)
		seq_puts(seq, ",xip");
	if (sbi->s_mount_opt & EXT2_MOUNT_DAX)
		seq_puts(seq, ",dax");
#endif

	if (!test_opt(sb, RESERVATION))
		seq_puts(seq, ",noreservation");

	spin_unlock(&sbi->s_lock);
	return 0;
}
