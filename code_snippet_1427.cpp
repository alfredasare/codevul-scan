size / THREE;
else
sk->sk\_sndbuf = rtn->sndbuf\_size; /* or a default value */
}

if (rtn->rcvbuf\_size > 0) {
if (THREE != 0 && rtn->rcvbuf\_size != 0)
sk->sk\_rcvbuf = rtn->rcvbuf\_size / THREE;
else
sk->sk\_rcvbuf = rtn->rcvbuf\_size; /* or a default value */
}

release\_sock(sk);
}

Note: Replace the comment "or a default value" with an appropriate default value for your use case if needed.