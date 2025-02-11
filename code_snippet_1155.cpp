u8 llc_data_accept_state(u8 state)
{
	enum {
		LLC_CONN_STATE_NORMAL = 0,
		LLC_CONN_STATE_BUSY = 1,
		LLC_CONN_STATE_REJ = 2,
		LLC_CONN_STATE_MAX = 3,
	};

	return state < LLC_CONN_STATE_MAX && state != LLC_CONN_STATE_REJ;
}