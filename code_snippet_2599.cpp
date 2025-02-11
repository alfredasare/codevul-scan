#define MAX_RETRIES 5
#define RETRY_DELAY_MS 100

static int pf_atapi(struct pf_unit *pf, char *cmd, int dlen, char *buf, char *fun)
{
	int r, retries = 0;

	r = pf_command(pf, cmd, dlen, fun);
	mdelay(1);
	if (!r)
		r = pf_completion(pf, buf, fun);

	while (r && (retries < MAX_RETRIES)) {
		pf_req_sense(pf, !fun);
		mdelay(RETRY_DELAY_MS);
		r = pf_completion(pf, buf, fun);
		retries++;
	}

	if (r)
		PF_ERROR("Error in pf_atapi\n");

	return r;
}