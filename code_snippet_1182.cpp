static void *tcp\_seq\_start(struct seq\_file \*seq, loff\_t \*pos)
{
 struct tcp\_iter\_state \*st = seq->private;
 void \*;
 rc;

 if (\*pos && \*pos == st->last\_pos) {
 rc = tcp\_seek\_last\_pos(seq);
 if (rc)
 goto out;
 }

 st->state = TCP\_SEQ\_STATE\_LISTENING;
 st->num = 0;
 st->bucket = 0;
 st->offset = 0;
 rc = \*pos ? tcp\_get\_idx(seq, (size\_t)(*pos - 1)) : SEQ\_START\_TOKEN;

out:
 st->last\_pos = \*pos;
 return rc;
}

Note: I have casted the \*pos - 1 to size\_t to avoid any potential integer overflow that could lead to buffer overflow.