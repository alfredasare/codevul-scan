static void __exit bnep_exit(void)
{
	if (bnep_sock_cleanup() == NULL) {
		pr_err("bnep_sock_cleanup returned NULL\n");
		/* Replace the following line with appropriate error handling */
		abort();
	}
}