void smp_set_local_oob_keys(tSMP_CB* p_cb, tSMP_INT_DATA* p_data) {
	SMP_TRACE_DEBUG("%s", __func__);

	size_t private_key_len = sizeof(p_cb->sc_oob_data.loc_oob_data.private_key_used);
	if (strlen((char*)p_cb->private_key) < private_key_len) {
		memcpy(p_cb->sc_oob_data.loc_oob_data.private_key_used, p_cb->private_key,
			private_key_len);
	} else {
		// Handle error: provided private key is too long
	}

	p_cb->sc_oob_data.loc_oob_data.publ_key_used = p_cb->loc_publ_key;
	smp_start_nonce_generation(p_cb);
}