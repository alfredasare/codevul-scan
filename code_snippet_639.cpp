kex\_send\_kexinit(struct ssh *ssh)
{
 u\_char *cookie;
 struct kex *kex = ssh->kex;
 int r;

 if (kex == NULL)
 return SSH\_ERR\_INTERNAL\_ERROR;
 if (kex->flags & KEX\_INIT\_SENT)
 return 0;
 kex->done = 0;

 /* generate a random cookie using secure random function */
 if (sshbuf\_len(kex->my) < KEX\_COOKIE\_LEN)
 return SSH\_ERR\_INVALID\_FORMAT;
 if ((cookie = sshbuf\_mutable\_ptr(kex->my)) == NULL)
 return SSH\_ERR\_INTERNAL\_ERROR;
 getrandom(cookie, KEX\_COOKIE\_LEN, 0);

 if ((r = sshpkt\_start(ssh, SSH2\_MSG\_KEXINIT)) != 0 ||
 (r = sshpkt\_putb(ssh, kex->my)) != 0 ||
 (r = sshpkt\_send(ssh)) != 0)
 return r;
 debug("SSH2\_MSG\_KEXINIT sent");
 kex->flags |= KEX\_INIT\_SENT;
 return 0;
}