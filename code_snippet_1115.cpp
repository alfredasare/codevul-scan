static struct sk_buff *tun\_ring\_recv(struct tun\_file \*tfile, int noblock,
int \*err)
{
DECLARE\_WAITQUEUE(wait, current);
struct sk\_buff \*skb = NULL;
int error = 0;

skb = skb\_array\_consume(&tfile->tx\_array);
if (!skb) { // Fix: Check if skb is NULL
if (noblock) {
error = -EAGAIN;
goto out;
}

add\_wait\_queue(&tfile->wq.wait, &wait);
current->state = TASK\_INTERRUPTIBLE;

while (1) {
skb = skb\_array\_consume(&tfile->tx\_array);
if (skb)
break;
if (signal\_pending(current)) {
error = -ERESTARTSYS;
break;
}
if (tfile->socket.sk->sk\_shutdown & RCV\_SHUTDOWN) {
error = -EFAULT;
break;
}

schedule();
}

current->state = TASK\_RUNNING;
remove\_wait\_queue(&tfile->wq.wait, &wait);
}

out:
\*err = error;
return skb;
}