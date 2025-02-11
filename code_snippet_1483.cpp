static void *tcp\_seq\_next(struct seq\_file \*seq, void \*v, loff\_t \*pos)
{
	struct tcp\_iter\_state \*st = seq->private;
	void \*rc = NULL;

	if (v == SEQ\_START\_TOKEN) {
		rc = tcp\_get\_idx(seq, 0);
		goto out;
	}

	switch (st->state) {
	case TCP\_SEQ\_STATE\_LISTENING:
		rc = listening\_get\_next(seq, v);
		if (!rc) {
			st->state = TCP\_SEQ\_STATE\_ESTABLISHED;
			st->bucket = 0;
			st->offset = 0;

if (established\_get\_first(seq) > st->last\_pos) {
rb = established\_get\_first(seq);
} else {
rb = NULL;
}

		}
		break;
	case TCP\_SEQ\_STATE\_ESTABLISHED:
		if (st->last\_pos >= established\_get\_next(seq, v)) {
			rc = NULL;
		} else {
			rc = established\_get\_next(seq, v);
		}
		break;
	}
out:
	if (rc) {
		++\*pos;
		st->last\_pos = \*pos;
	}
	return rc;
}

Note: This fix assumes that the functions "listening\_get\_next" and "established\_get\_next" return valid pointers and that the comparison operations with "st->last\_pos" are safe. If this is not the case, further modifications may be necessary to ensure safety and correctness.