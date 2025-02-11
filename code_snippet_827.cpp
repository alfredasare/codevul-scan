PHP\_FUNCTION(gethostbyaddr)
{
	char *addr;
	int addr\_len;
	char *hostname;
	int max\_iterations = 10;

	if (zend\_parse\_parameters(ZEND\_NUM\_ARGS() TSRMLS\_CC, "s", &addr, &addr\_len) == FAILURE) {
		return;
	}

	if (!filter\_var(addr, FILTER\_VALIDATE\_IP, FILTER\_FLAG\_IPV4 | FILTER\_FLAG\_IPV6)) {
		php\_error\_docref(NULL TSRMLS\_CC, E\_WARNING, "Invalid address format");
		RETURN\_FALSE;
	}

	hostname = php\_gethostbyaddr\_limited(addr, max\_iterations);

	if (hostname == NULL) {
		php\_error\_docref(NULL TSRMLS\_CC, E\_WARNING, "Address is not a valid IPv4 or IPv6 address");
		RETURN\_FALSE;
	} else {
		RETVAL\_STRING(hostname, 0);
	}
}

/* Helper function to limit the number of iterations */
char\* php\_gethostbyaddr\_limited(char \*addr, int max\_iterations)
{
	struct hostent \*hostent;
	int i;

	for (i = 0; i < max\_iterations; i++) {
#ifdef HAVE\_IPV6
		hostent = gethostbyname2(addr, AF\_INET6);
#else
		hostent = gethostbyname2(addr, AF\_INET);
#endif

		if (hostent != NULL) {
			break;
		}
	}

	return hostent != NULL ? hostent->h\_name : NULL;
}