void sctp\_generate\_heartbeat\_event(unsigned long data)
{
 int error = 0;
 struct sctp\_transport \*transport = (struct sctp\_transport \*)data;
 struct sctp\_association \*asoc = transport->asoc;
 struct net \*net = sock\_net(asoc->base.sk);

 bh\_lock\_sock(asoc->base.sk);

 if (sock\_owned\_by\_user(asoc->base.sk)) {
 pr\_debug("%s: sock is busy\n", __func__);
 goto out\_unlock;
 }

 /* Is this structure just waiting around for us to actually
 * get destroyed?
 */
 if (transport->dead)
 goto out\_unlock;

 /* Save the state before checking for ownership */
 bool is\_owned\_by\_user = sock\_owned\_by\_user(asoc->base.sk);

 if (!is\_owned\_by\_user) {
 error = sctp\_do\_sm(net, SCTP\_EVENT\_T\_TIMEOUT,
 SCTP\_ST\_TIMEOUT(SCTP\_EVENT\_TIMEOUT\_HEARTBEAT),
 asoc->state, asoc->ep, asoc,
 transport, GFP\_ATOMIC);

 if (error)
 asoc->base.sk->sk\_err = -error;
 }

out\_unlock:
 bh\_unlock\_sock(asoc->base.sk);
 sctp\_transport\_put(transport);
}