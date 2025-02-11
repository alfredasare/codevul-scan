static void s\_wrpkt(Ssh ssh, struct Packet \*pkt)
{
int len, backlog, offset;
len = s\_wrpkt\_prepare(ssh, pkt, &offset);

// Fixed: Add boundary check for 'len' before using it in the write operation.
if (len > 0 && len <= SSH\_BUF\_SIZE - offset) {
backlog = s\_write(ssh, pkt->data + offset, len);
}

if (backlog > SSH\_MAX\_BACKLOG)
ssh\_throttle\_all(ssh, 1, backlog);
ssh\_free\_packet(pkt);
}