R_API int r_core_cmd_command(RCore *core, const char *command) {
	int ret, len;
	char *buf = NULL;
	char *rcmd = NULL;
	char *ptr = NULL;
	char *cmd = r_core_sysenv_begin (core, command);

	if (!cmd) return -1;

	len = r_sys_cmd_str (cmd,