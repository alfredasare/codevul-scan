set_dumper_capsicum_rights(pcap_dumper_t *p, off_t max_size)
{
	int fd = fileno(pcap_dump_file(p));
	cap_rights_t rights;

	cap_rights_init(&rights, CAP_SEEK, CAP_WRITE, CAP_FCNTL);
	if (cap_rights_limit(fd, &rights) < 0 && errno != ENOSYS) {
		error("unable to limit dump descriptor");
	}

	// Limit the amount of data that can be written to the file descriptor
	if (ftruncate(fd, max_size) < 0 && errno != ENOSYS) {
		error("unable to truncate dump descriptor");
	}

	if (cap_fcntls_limit(fd, CAP_FCNTL_GETFL) < 0 && errno != ENOSYS) {
		error("unable to limit dump descriptor fcntls");
	}
}