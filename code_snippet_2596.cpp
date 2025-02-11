dissect_rpcap_open_request (tvbuff_t *tvb, packet_info *pinfo _U_,
                            proto_tree *parent_tree, gint offset)
{
  gint len;
  guint16 max_len = 4096; // Set a maximum length limit

  len = tvb_captured_length_remaining (tvb, offset);
  if (len > max_len) { // Validate input length
    len = max_len;
  }

  proto_tree_add_item (parent_tree, hf_open_request, tvb, offset, len, ENC_ASCII|ENC_NA);
}