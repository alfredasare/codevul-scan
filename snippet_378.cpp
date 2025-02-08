bt_status_t btif_transfer_context (tBTIF_CBACK *p_cback, UINT16 event, char* p_params, int param_len, tBTIF_COPY_CBACK *p_copy_cback)
{
    tBTIF_CONTEXT_SWITCH_CBACK *p_msg;

    BTIF_TRACE_VERBOSE("btif_transfer_context event %d, len %d", event, param_len);

 /* allocate and send message that will be executed in btif context */
 if ((p_msg = (tBTIF_CONTEXT_SWITCH_CBACK *) GKI_getbuf(sizeof(tBTIF_CONTEXT_SWITCH_CBACK) + param_len)) != NULL)
 {
        p_msg->hdr.event = BT_EVT_CONTEXT_SWITCH_EVT; /* internal event */
        p_msg->p_cb = p_cback;

        p_msg->event = event; /* callback event */

 /* check if caller has provided a copy callback to do the deep copy */
 if (p_copy_cback)
 {
            p_copy_cback(event, p_msg->p_param, p_params);
 }
 else if (p_params)
 {
            memcpy(p_msg->p_param, p_params, param_len); /* callback parameter data */
 }

        btif_sendmsg(p_msg);
 return BT_STATUS_SUCCESS;
 }
 else
 {
 /* let caller deal with a failed allocation */
 return BT_STATUS_NOMEM;
 }
}
