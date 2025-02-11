static __u16 convert\_ace\_to\_cifs\_ace(struct cifs\_posix\_ace *cifs\_ace,
const posix\_acl\_xattr\_entry *local\_ace)
{
__u16 rc = 0; /* 0 = ACL converted ok */

cifs\_ace->cifs\_e\_perm = le16\_to\_cpu(local\_ace->e\_perm);
cifs\_ace->cifs\_e\_tag = le16\_to\_cpu(local\_ace->e\_tag);
/* BB is there a better way to handle the large uid? */
if (local\_ace->e\_id == cpu\_to\_le32(-1)) {
/* Probably no need to le convert -1 on any arch but can not hurt */
cifs\_ace->cifs\_uid = (__u64)cpu\_to\_le32(-1) << 32;
} else
cifs\_ace->cifs\_uid = (__u64)le32\_to\_cpu(local\_ace->e\_id) << 32;
/*cFYI(1, "perm %d tag %d id %d",ace->e\_perm,ace->e\_tag,ace->e\_id);*/
return rc;
}