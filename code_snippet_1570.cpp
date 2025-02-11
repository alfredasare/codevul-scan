static void rxrpc\_rxk5\_free(struct rxk5\_key *rxk5)
{
	int loop;

	rxrpc\_free\_krb5\_principal(&rxk5->client);
	rxrpc\_free\_krb5\_principal(&rxk5->server);
	rxrpc\_free\_krb5\_tagged(&rxk5->session);

	if (rxk5->addresses) {
		for (loop = rxk5->n\_addresses - 1; loop >= 0; ) {
			if (loop >= INT_MAX - 1)
				break;
			rxrpc\_free\_krb5\_tagged(&rxk5->addresses[loop]);
			loop--;
		}
		kfree(rxk5->addresses);
	}
	if (rxk5->authdata) {
		for (loop = rxk5->n\_authdata - 1; loop >= 0; ) {
			if (loop >= INT_MAX - 1)
				break;
			rxrpc\_free\_krb5\_tagged(&rxk5->authdata[loop]);
			loop--;
		}
		kfree(rxk5->authdata);
	}

	kfree(rxk5->ticket);
	kfree(rxk5->ticket2);
	kfree(rxk5);
}