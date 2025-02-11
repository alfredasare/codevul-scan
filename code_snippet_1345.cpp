static int r_bin_dwarf_init_abbrev_decl(RBinDwarfAbbrevDecl *ad) {
	if (!ad) {
		return -EINVAL;
	}
	ad->specs = calloc (sizeof( RBinDwarfAttrSpec), ABBREV_DECL_CAP);

	if (!ad->specs) {
		return -ENOMEM;
	}

	ad->capacity = ABBREV_DECL_CAP;
	ad->length = 0;

	// Only access elements of the 'specs' array if the length is within bounds
	if (ad->length < ad->capacity) {
		ad->specs[ad->length].attr = R_BIN_DWARF_ATTR_DW_AT_name;
		ad->length++;
	}

	return (ad->length < ad->capacity) ? 0 : -EOVERFLOW;
}