check_options()
{
	int saved_logfile_fd = logfile_fd;
	if (saved_logfile_fd >= 0 && saved_logfile_fd != log_to_fd) {
		close(saved_logfile_fd);
		logfile_fd = -1;
	}
}