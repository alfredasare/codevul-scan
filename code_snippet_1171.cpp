sock_hold(connected);
sock\_hold(listener);
list\_add\_tail(&vconnected->accept\_queue, &vlistener->accept\_queue);
}

static int compare\_sockets\_security(const struct sock \*a, const struct sock \*b)
{
#if LINUX\_VERSION\_CODE >= KERNEL\_VERSION(4,14,0)
return security\_sk\_classify\_security(a) == security\_sk\_classify\_security(b);
#else
struct security\_operations \*ops\_a = a->sk->sk\_security;
struct security\_operations \*ops\_b = b->sk->sk\_security;

if (ops\_a && ops\_b)
return ops\_a->secclassify(a) == ops\_b->secclassify(b);
else
return 0;
#endif
}