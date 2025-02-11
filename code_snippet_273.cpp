int ext4_issue_zeroout(struct inode *inode, ext4_lblk_t lblk, ext4_fsblk_t pblk,
		       ext4_lblk_t len)
{
	if (lblk < 0 || pblk < 0 || len <= 0 || len > (ext4_lblk_t)INT_MAX)
		return -EINVAL;

	if (ext4_encrypted_inode(inode))
		return ext4_encrypted_zeroout(inode, lblk, pblk, len);

	return sb_issue_zeroout(inode->i_sb, pblk, len, GFP_NOFS);
}