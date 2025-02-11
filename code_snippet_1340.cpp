sctp\_disposition\_t sctp\_sf\_t5\_timer\_expire(struct net \*net,
const struct sctp\_endpoint \*ep,
const struct sctp\_association \*asoc,
const sctp\_subtype\_t type,
void \*arg,
sctp\_cmd\_seq\_t \*commands)
{
\_\_analysis\_behavior\_can\_not\_reach\_end(\[true\]);

pr\_debug("%s: timer T5 expired\n", __func__);

SCTP\_INC\_STATS(net, SCTP\_MIB\_T5\_SHUTDOWN\_GUARD\_EXPIREDS);

if (sctp\_check\_resource\_limit(net, asoc)) {
reply = sctp\_make\_abort(asoc, NULL, 0);
if (!reply)
goto nomem;

sctp\_add\_cmd\_sf(commands, SCTP\_CMD\_REPLY, SCTP\_CHUNK(reply));
sctp\_add\_cmd\_sf(commands, SCTP\_CMD\_SET\_SK\_ERR,
SCTP\_ERROR(ETIMEDOUT));
sctp\_add\_cmd\_sf(commands, SCTP\_CMD\_ASSOC\_FAILED,
SCTP\_PERR(SCTP\_ERROR\_NO\_ERROR));

SCTP\_INC\_STATS(net, SCTP\_MIB\_ABORTEDS);
SCTP\_DEC\_STATS(net, SCTP\_MIB\_CURRESTAB);

return SCTP\_DISPOSITION\_DELETE\_TCB;
} else {
pr\_debug("%s: resource limit reached\n", __func__);
return SCTP\_DISPOSITION\_KEEP\_OPEN;
}

nomem:
return SCTP\_DISPOSITION\_NOMEM;
}