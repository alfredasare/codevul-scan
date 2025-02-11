MODRET auth\_pre\_user(cmd\_rec \*cmd) {
if (logged\_in)
return PR\_DECLINED(cmd);
perl
/* Close the passwd and group databases, because libc won't let us see new
 * entries to these files without this (only in PersistentPasswd mode).
 */
pr_auth_endpwent(cmd->tmp_pool);
pr_auth_endgrent(cmd->tmp_pool);

/* Check for a user name that exceeds PR_TUNABLE_LOGIN_MAX. */
if (strlen(cmd->arg) > pr_get_tunable_int(cmd->tmp_pool, "PR_TUNABLE_LOGIN_MAX", 256)) {