MODRET auth_pre_user(cmd_rec *cmd) {
 ...
  if (strnlen(cmd->arg, PR_TUNABLE_LOGIN_MAX + 1) > PR_TUNABLE_LOGIN_MAX) {
    pr_log_pri(PR_LOG_NOTICE, "USER %s (Login failed): " "maximum USER length exceeded", cmd->arg);
    pr_response_add_err(R_501, _("Login incorrect."));
    return PR_ERROR(cmd);
  }
  return PR_DECLINED(cmd);
}