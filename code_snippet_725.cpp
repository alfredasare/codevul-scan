int compat_sock_common_setsockopt(struct socket *sock, int level, int optname,
				  char __user *optval, unsigned int optlen)
{
	struct sock *sk = sock->sk;

	if (sk->sk_prot->compat_setsockopt!= NULL)
		return sk->sk_prot->compat_setsockopt(sk, level, optname,
						      optval, optlen);

	// Validate optlen and optval length
	if (optlen > PAGE_SIZE) {
		return -EMSGSIZE;
	}

	// Check if optval is within the user-space address range
	if ((unsigned long)optval < (unsigned long)__user_magic ||
	    (unsigned long)optval > (unsigned long)(__user_magic + PAGE_SIZE)) {
		return -EFAULT;
	}

	// Copy data into a safe buffer
	char safe_buf[PAGE_SIZE];
	memcpy(safe_buf, optval, optlen);

	return sk->sk_prot->setsockopt(sk, level, optname, safe_buf, optlen);
}