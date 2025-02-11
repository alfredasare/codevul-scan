static __u16 convert_ace_to_cifs_ace(struct cifs_posix_ace *cifs_ace,
				     const posix_acl_xattr_entry *local_ace)
{
	__u16 rc = 0; /* 0 = ACL converted ok */

	cifs_ace->cifs_e_perm = le16_to_cpu(local_ace->e_perm);
	cifs_ace->cifs_e_tag =  le16_to_cpu(local_ace->e_tag);

	if (local_ace->e_id == cpu_to_le32(-1)) {
		/* Set default value for cifs_uid */
		cifs_ace->cifs_uid = cpu_to_le64(-1);
	} else if (local_ace->e_id < 0 || local_ace->e_id > U32_MAX) {
		/* Return error or set default value if e_id is out of range */
		return EINVAL;
	} else {
		cifs_ace->cifs_uid = uto64_to_le64(le32_to_cpu(local_ace->e_id));
	}

	return rc;
}