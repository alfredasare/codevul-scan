static int param_get_audit(char *buffer, struct kernel_param *kp)
{
	size_t buffer_len = kp->maxlen - 1;
	if (!capable(CAP_MAC_ADMIN))
		return -EPERM;

	if (!apparmor_enabled)
		return -EINVAL;

	if (buffer_len < strnlen_user(audit_mode_names[aa_g_audit], buffer_len))
		return -ERANGE;

	return strncpy_from_user(buffer, audit_mode_names[aa_g_audit], buffer_len + 1);
}