static int http\_upgrade\_v09\_to\_v10(struct http\_txn *txn)
{
	int delta;
	char *cur\_end;
	struct http\_msg *msg = &txn->req;

	if (msg->sl.rq.v\_l != 0)
		return 1;

	/* RFC 1945 allows only GET for HTTP/0.9 requests */
	if (txn->meth != HTTP\_METH\_GET)
		return 0;

	cur\_end = msg->chn->buf->p + msg->sl.rq.l;

	if (msg->sl.rq.u\_l == 0) {
		/* HTTP/0.9 requests *must* have a request URI, per RFC 1945 */
		return 0;
	}

	/* Validate input to prevent buffer overflow */
	if (cur\_end - msg->chn->buf->p > INT\_MAX - 11 ||
	    msg->chn->buf->size - (cur\_end - msg->chn->buf->p) < 11) {
		return 0;
	}

	/* add HTTP version */
	delta = buffer\_replace2(msg->chn->buf, cur\_end, cur\_end, " HTTP/1.0\r\n", 11);
	http\_msg\_move\_end(msg, delta);
	cur\_end += delta;
	cur\_end = (char *)http\_parse\_reqline(msg,
					     HTTP\_MSG\_RQMETH,
					     msg->chn->buf->p, cur\_end + 1,
					     NULL, NULL);
	if (unlikely(!cur\_end))
		return 0;

	/* we have a full HTTP/1.0 request now and we know that
	 * we have either a CR or an LF at <ptr>.
	 */
	hdr\_idx\_set\_start(&txn->hdr\_idx, msg->sl.rq.l, *cur\_end == '\r');
	return 1;
}