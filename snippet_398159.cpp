static int sctp_sendmsg(struct sock *sk, struct msghdr *msg, size_t msg_len)
{
	struct sctp_endpoint *ep = sctp_sk(sk)->ep;
	struct sctp_transport *transport = NULL;
	struct sctp_sndrcvinfo _sinfo, *sinfo;
	struct sctp_association *asoc, *tmp;
	struct sctp_cmsgs cmsgs;
	union sctp_addr *daddr;
	bool new = false;
	__u16 sflags;
	int err;

	/* Parse and get snd_info */
	err = sctp_sendmsg_parse(sk, &cmsgs, &_sinfo, msg, msg_len);
	if (err)
		goto out;

	sinfo  = &_sinfo;
	sflags = sinfo->sinfo_flags;

	/* Get daddr from msg */
	daddr = sctp_sendmsg_get_daddr(sk, msg, &cmsgs);
	if (IS_ERR(daddr)) {
		err = PTR_ERR(daddr);
		goto out;
	}

	lock_sock(sk);

	/* SCTP_SENDALL process */
	if ((sflags & SCTP_SENDALL) && sctp_style(sk, UDP)) {
		list_for_each_entry_safe(asoc, tmp, &ep->asocs, asocs) {
			err = sctp_sendmsg_check_sflags(asoc, sflags, msg,
							msg_len);
			if (err == 0)
				continue;
			if (err < 0)
				goto out_unlock;

			sctp_sendmsg_update_sinfo(asoc, sinfo, &cmsgs);

			err = sctp_sendmsg_to_asoc(asoc, msg, msg_len,
						   NULL, sinfo);
			if (err < 0)
				goto out_unlock;

			iov_iter_revert(&msg->msg_iter, err);
		}

		goto out_unlock;
	}

	/* Get and check or create asoc */
	if (daddr) {
		asoc = sctp_endpoint_lookup_assoc(ep, daddr, &transport);
		if (asoc) {
			err = sctp_sendmsg_check_sflags(asoc, sflags, msg,
							msg_len);
			if (err <= 0)
				goto out_unlock;
		} else {
			err = sctp_sendmsg_new_asoc(sk, sflags, &cmsgs, daddr,
						    &transport);
			if (err)
				goto out_unlock;

			asoc = transport->asoc;
			new = true;
		}

		if (!sctp_style(sk, TCP) && !(sflags & SCTP_ADDR_OVER))
			transport = NULL;
	} else {
		asoc = sctp_id2assoc(sk, sinfo->sinfo_assoc_id);
		if (!asoc) {
			err = -EPIPE;
			goto out_unlock;
		}

		err = sctp_sendmsg_check_sflags(asoc, sflags, msg, msg_len);
		if (err <= 0)
			goto out_unlock;
	}

	/* Update snd_info with the asoc */
	sctp_sendmsg_update_sinfo(asoc, sinfo, &cmsgs);

	/* Send msg to the asoc */
	err = sctp_sendmsg_to_asoc(asoc, msg, msg_len, transport, sinfo);
	if (err < 0 && err != -ESRCH && new)
		sctp_association_free(asoc);

out_unlock:
	release_sock(sk);
out:
	return sctp_error(sk, msg->msg_flags, err);
}