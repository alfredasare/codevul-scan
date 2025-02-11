if (pending == NULL) {
		return false;
	}

	pending[num_pending] = req;
	conn->pending = pending;
	tevent_req_set_cleanup_fn(req, smbXcli_req_cleanup);
	tevent_req_set_cancel_fn(req, smbXcli_req_cancel);

	if (!smbXcli_conn_receive_next(conn)) {
		/*
		 * the caller should notify the current request
		 *
		 * And all other pending requests get notified
		 * by smbXcli_conn_disconnect().
		 */
		smbXcli_req_unset_pending(req);
		smbXcli_conn_disconnect(conn, NT_STATUS_NO_MEMORY);
		return false;
	}

	return true;