void smp_proc_compare(tSMP_CB* p_cb, tSMP_INT_DATA* p_data) {
 SMP_TRACE_DEBUG("%s", __func__);
 // Check if the lengths match to prevent buffer over-read
 if (p_cb->rconfirm_len != p_data->key.p_data_len) {
 // Handle the mismatch appropriately, e.g., return an error
 tSMP_INT_DATA smp_int_data;
 smp_int_data.status = SMP_LENGTH_ERR;
 p_cb->failure = SMP_LENGTH_ERR;
 smp_sm_event(p_cb, SMP_AUTH_CMPL_EVT, &smp_int_data);
 return;
 }

 if (!memcmp(p_cb->rconfirm, p_data->key.p_data, p_cb->rconfirm_len)) {
 /* compare the max encryption key size, and save the smaller one for the
 * link */
 if (p_cb->peer_enc_size < p_cb->loc_enc_size)
 p_cb->loc_enc_size = p_cb->peer_enc_size;

 if (p_cb->role == HCI_ROLE_SLAVE)
 smp_sm_event(p_cb, SMP_RAND_EVT, NULL);
 else {
 /* master device always use received i/r key as keys to distribute */
 p_cb->local_i_key = p_cb->peer_i_key;
 p_cb->local_r_key = p_cb->peer_r_key;

 smp_sm_event(p_cb, SMP_ENC_REQ_EVT, NULL);
 }

 } else {
 tSMP_INT_DATA smp_int_data;
 smp_int_data.status = SMP_CONFIRM_VALUE_ERR;
 p_cb->failure = SMP_CONFIRM_VALUE_ERR;
 smp_sm_event(p_cb, SMP_AUTH_CMPL_EVT, &smp_int_data);
 }
}