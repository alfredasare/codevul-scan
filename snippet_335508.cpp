dissect_dnp3_udp_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
  return (udp_dissect_pdus(tvb, pinfo, tree, DNP_HDR_LEN, dnp3_udp_check_header_heur,
                   get_dnp3_message_len, dissect_dnp3_message, data) != 0);

}