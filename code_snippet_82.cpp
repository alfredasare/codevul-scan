ftp_gc(ftpbuf_t *ftp)
{
	if (ftp == NULL) {
		return;
	}
	int pwd_freed = 0;
	int syst_freed = 0;
	if (ftp->pwd) {
		efree(ftp->pwd);
		ftp->pwd = NULL;
		pwd_freed = 1;
	}
	if (ftp->syst) {
		efree(ftp->syst);
		ftp->syst = NULL;
		syst_freed = 1;
	}
	if (pwd_freed) {
		ftp->pwd = ecalloc(1, sizeof(char));
	}
	if (syst_freed) {
		ftp->syst = ecalloc(1, sizeof(char));
	}
}