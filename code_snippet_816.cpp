static void sctp_generate_t4_rto_event(unsigned long data)
{
	struct sctp_association *asoc = (struct sctp_association *) data;

	if (asoc == NULL) {
		pr_err("Invalid argument: asoc is NULL\n");
		return;
	}

	sctp_generate_timeout_event(asoc, SCTP_EVENT_TIMEOUT_T4_RTO);
}