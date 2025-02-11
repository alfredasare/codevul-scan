void smp_proc_compare(tSMP_CB* p_cb, tSMP_INT_DATA* p_data) {
  SMP_TRACE_DEBUG("%s", __func__);
  if (p_data->key.p_data && strlen(p_data->key.p_data) == BT_OCTET16_LEN) {
    if (p_cb->rconfirm && strlen(p_cb->rconfirm) == BT_OCTET16_LEN) {
      if (!memcmp(p_cb->rconfirm, p_data->key.p_data, BT_OCTET16_LEN)) {
        //...
      } else {
        // Handle invalid input
      }
    } else {
      // Handle invalid input
    }
  } else {
    // Handle invalid input
  }
}