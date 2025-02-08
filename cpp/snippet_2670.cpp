 static int ceph_x_build_authorizer(struct ceph_auth_client *ac,
				   struct ceph_x_ticket_handler *th,
				   struct ceph_x_authorizer *au)
{
	int maxlen;
	struct ceph_x_authorize_a *msg_a;
	struct ceph_x_authorize_b msg_b;
	void *p, *end;
	int ret;
	int ticket_blob_len =
		(th->ticket_blob ? th->ticket_blob->vec.iov_len : 0);

	dout("build_authorizer for %s %p\n",
	     ceph_entity_type_name(th->service), au);

	maxlen = sizeof(*msg_a) + sizeof(msg_b) +
		ceph_x_encrypt_buflen(ticket_blob_len);
	dout("  need len %d\n", maxlen);
	if (au->buf && au->buf->alloc_len < maxlen) {
		ceph_buffer_put(au->buf);
		au->buf = NULL;
	}
	if (!au->buf) {
		au->buf = ceph_buffer_new(maxlen, GFP_NOFS);
		if (!au->buf)
			return -ENOMEM;
	}
	au->service = th->service;
	au->secret_id = th->secret_id;

	msg_a = au->buf->vec.iov_base;
	msg_a->struct_v = 1;
	msg_a->global_id = cpu_to_le64(ac->global_id);
	msg_a->service_id = cpu_to_le32(th->service);
	msg_a->ticket_blob.struct_v = 1;
	msg_a->ticket_blob.secret_id = cpu_to_le64(th->secret_id);
	msg_a->ticket_blob.blob_len = cpu_to_le32(ticket_blob_len);
	if (ticket_blob_len) {
		memcpy(msg_a->ticket_blob.blob, th->ticket_blob->vec.iov_base,
		       th->ticket_blob->vec.iov_len);
	}
	dout(" th %p secret_id %lld %lld\n", th, th->secret_id,
	     le64_to_cpu(msg_a->ticket_blob.secret_id));

	p = msg_a + 1;
	p += ticket_blob_len;
	end = au->buf->vec.iov_base + au->buf->vec.iov_len;

	get_random_bytes(&au->nonce, sizeof(au->nonce));
	msg_b.struct_v = 1;
	msg_b.nonce = cpu_to_le64(au->nonce);
	ret = ceph_x_encrypt(&th->session_key, &msg_b, sizeof(msg_b),
			     p, end - p);
	if (ret < 0)
		goto out_buf;
	p += ret;
	au->buf->vec.iov_len = p - au->buf->vec.iov_base;
	dout(" built authorizer nonce %llx len %d\n", au->nonce,
	     (int)au->buf->vec.iov_len);
	BUG_ON(au->buf->vec.iov_len > maxlen);
	return 0;

out_buf:
	ceph_buffer_put(au->buf);
	au->buf = NULL;
	return ret;
}
