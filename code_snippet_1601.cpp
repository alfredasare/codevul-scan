static bool get_new_nicname(char **dest, char *br, int pid, char **cnic)
{
    char template[IFNAMSIZ];
    snprintf(template, sizeof(template), "vethXXXXXX");
    *dest = lxc_mkifname(template);

    if (pid < 0 || pid > sysconf(_SC_OPEN_MAX) ||!has_permission(pid, CAP_NET_ADMIN)) {
        return false;
    }

    if (!create_nic(*dest, br, pid, cnic)) {
        return false;
    }
    return true;
}