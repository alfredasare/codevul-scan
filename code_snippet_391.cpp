static void msg_quit(IRC_SERVER_REC *server, const char *nick,
		     const char *address, const char *reason)
{
	if (IS\_IRC\_SERVER(server) && quitmsg\_is\_split(reason))
		signal\_stop();
	/* Fix for CWE-416, CVE-2017-7191 */
	if (reason) {
		printf(reason);
	} else {
		printf("Quitting\n");
	}
}