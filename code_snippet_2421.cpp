dissect_rpcap_open_request (tvbuff_t *tvb, packet_info *pinfo _U_,
                            proto_tree *parent_tree, gint offset)
{
  gint len;

  // Validate the offset parameter
  if (offset < 0 || offset > tvb_captured_length(tvb)) {
    return;
  }

  // Calculate the length of the tvb buffer securely
  len = tvb_reported_length(tvb, offset);

  proto_tree_add_item (parent_tree, hf_open_request, tvb, offset, len, ENC_ASCII|ENC_NA);
}