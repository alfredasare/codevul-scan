static int param_get_audit(char *buffer, struct kernel_param *kp)
{
    if (!capable(CAP_MAC_ADMIN)) {
        return -EPERM;
    }

    if (!apparmor_enabled) {
        return -EINVAL;
    }

    if (snprintf(buffer, sizeof(buffer), "%s", audit_mode_names[aa_g_audit]) < 0) {
        return -EFAULT;
    }

    return 0;
}