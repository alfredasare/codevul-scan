dissect_PRINTER_INFO_1(tvbuff_t *tvb, int offset,
					  packet_info *pinfo, proto_tree *tree,
					  dcerpc_info *di, guint8 *drep)
{
	guint32 length;
	gboolean err = FALSE;

	offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
								  hf_printer_flags, &length);
	if (offset == -1) {
		err = TRUE;
	}

	if (!err) {
		offset += length;
	}

	err = FALSE;

	offset = tvb_ensure_remaining_length(tvb, offset);
	if (!offset) {
		err = TRUE;
	}

	if (!err) {
		offset = dissect_spoolss_relstr(tvb, offset, pinfo, tree, di, drep,
									   hf_printerdesc, 0, NULL);
		if (offset == -1) {
			err = TRUE;
		}
	}

	if (!err) {
		offset += tvb_get_length(tvb, offset);
	}

	err = FALSE;

	offset = tvb_ensure_remaining_length(tvb, offset);
	if (!offset) {
		err = TRUE;
	}

	if (!err) {
		offset = dissect_spoolss_relstr(tvb, offset, pinfo, tree, di, drep,
									   hf_printername, 0, NULL);
		if (offset == -1) {
			err = TRUE;
		}
	}

	if (!err) {
		offset += tvb_get_length(tvb, offset);
	}

	err = FALSE;

	offset = tvb_ensure_remaining_length(tvb, offset);
	if (!offset) {
		err = TRUE;
	}

	if (!err) {
		offset = dissect_spoolss_relstr(tvb, offset, pinfo, tree, di, drep,
									   hf_printercomment, 0, NULL);
		if (offset == -1) {
			err = TRUE;
		}
	}

	if (err) {
		warning("Error parsing PRINTER_INFO_1");
		return -1;
	}

	return offset;
}