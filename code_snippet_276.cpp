struct socket *sock;

sock = sockfd_lookup_light(fd, &err, NULL);

if (!sock)
	goto out;

err = __sys_sendmsg(sock, msg, &msg_sys, flags, NULL);

fput_light(sock->file, 1);
out:
	return err;