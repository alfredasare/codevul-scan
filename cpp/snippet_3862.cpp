 static int udf_char_to_ustr(struct ustr *dest, const uint8_t *src, int strlen)
 {
	if ((!dest) || (!src) || (!strlen) || (strlen > UDF_NAME_LEN - 2))
		return 0;

	memset(dest, 0, sizeof(struct ustr));
	memcpy(dest->u_name, src, strlen);
	dest->u_cmpID = 0x08;
	dest->u_len = strlen;

	return strlen;
}
