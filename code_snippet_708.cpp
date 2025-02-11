guint16 dissect_spoolss_relstr(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep, guint16 hf_index, gint max_length, gchar **string) {
 if (max_length < 0 || tvb_reported_length_remaining(tvb, offset) > max_length) {
 return -1;
 }

 len = dissect_ndr_small_unsigned_string(tvb, offset, pinfo, tree, di, drep, hf_index, max_length, string);
 offset += len;

 return offset;
}

dissect_PRINTER_INFO_1(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep) {
 offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_printer_flags, NULL);

 const gint max_length = 256; // Set a reasonable maximum length
 gchar *str = NULL;

 offset = dissect_spoolss_relstr(tvb, offset, pinfo, tree, di, drep, hf_printerdesc, max_length, &str);
 if (offset < 0) {
 return offset;
 }

 offset = dissect_spoolss_relstr(tvb, offset, pinfo, tree, di, drep, hf_printername, max_length, &str);
 if (offset < 0) {
 return offset;
 }

 offset = dissect_spoolss_relstr(tvb, offset, pinfo, tree, di, drep, hf_printercomment, max_length, &str);
 if (offset < 0) {
 return offset;
 }

 return offset;
}