Struct sock \*ax25\_find\_listener(ax25\_address \*restrict addr, int restrict digi,
struct net\_device \*restrict dev, int restrict type)
{
 ax25\_cb \*s;

 spin\_lock(&ax25\_list\_lock);
 ax25\_for\_each(s, &ax25\_list) {
 if ((s->iamdigi && !digi) || (!s->iamdigi && digi))
 continue;
 if (s->sk && ax25\_valid\_addr(addr) && !ax25cmp(&s->source\_addr, addr) &&
s->sk->sk\_type == type && s->sk->sk\_state == TCP\_LISTEN) {
 /* If device is null we match any device */
if (s->ax25\_dev == NULL || s->ax25\_dev->dev == dev) {
sock\_hold(s->sk);
spin\_unlock(&ax25\_list\_lock);
return s->sk;
}
}
}
spin\_unlock(&ax25\_list\_lock);

return NULL;
}

void ax25\_valid\_addr(const ax25\_address \*addr)
{
if (addr == NULL) {
pr\_err("Invalid ax25 address\n");
abort();
}
// Perform additional validation checks here
}