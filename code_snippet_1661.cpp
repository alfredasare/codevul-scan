static void net_enque(struct priv_net *pn, void *buf, int len)
{
	struct queue *q;

	q = queue_get_slot(pn);
	if (!q)
		return;

	if (len < 0 || len >= (int) sizeof(q->q_buf)) {
		/* Handle error */
		return;
	}

	q->q_len = len;
	memcpy(q->q_buf, buf, q->q_len);
	queue_add(&pn->pn_queue, q);
}