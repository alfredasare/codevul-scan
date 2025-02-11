static int read_mii_word(pegasus_t *pegasus, __u8 phy, __u8 indx, __u16 *regd)
{
	if (regd == NULL || sizeof(__u16) != sizeof(*regd)) {
		return -EINVAL;
	}

	return __mii_op(pegasus, phy, indx, regd, PHY_READ);
}