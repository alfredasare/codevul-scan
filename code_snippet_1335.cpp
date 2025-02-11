sctp_style(sk, TCP))
return -EOPNOTSUPP;
if (optlen < sizeof(int))
return -EINVAL;
if (optlen > sizeof(int)) {
pr\_warn("sctp\_setsockopt\_autoclose: truncating input\n");
optlen = sizeof(int);
}
if (copy\_from\_user(&sp->autoclose, optval, optlen))
return -EFAULT;

if (sp->autoclose > net->sctp.max_autoclose)
sp->autoclose = net->sctp.max_autoclose;
else if (sp->autoclose < 0)
sp->autoclose = 0;

return 0;
}