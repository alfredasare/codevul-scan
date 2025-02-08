TEE_Result tee_obj_attr_copy_from(struct tee_obj *o, const struct tee_obj *src)
{
	TEE_Result res;
	const struct tee_cryp_obj_type_props *tp;
	const struct tee_cryp_obj_type_attrs *ta;
	size_t n;
	uint32_t have_attrs = 0;
	void *attr;
	void *src_attr;

	if (o->info.objectType == TEE_TYPE_DATA)
		return TEE_SUCCESS; /* pure data object */
	if (!o->attr)
		return TEE_ERROR_BAD_STATE;
	tp = tee_svc_find_type_props(o->info.objectType);
	if (!tp)
		return TEE_ERROR_BAD_STATE;

	if (o->info.objectType == src->info.objectType) {
		have_attrs = src->have_attrs;
		for (n = 0; n < tp->num_type_attrs; n++) {
			ta = tp->type_attrs + n;
			attr = (uint8_t *)o->attr + ta->raw_offs;
			src_attr = (uint8_t *)src->attr + ta->raw_offs;
			res = attr_ops[ta->ops_index].from_obj(attr, src_attr);
			if (res != TEE_SUCCESS)
				return res;
		}
	} else {
		const struct tee_cryp_obj_type_props *tp_src;
		int idx;

		if (o->info.objectType == TEE_TYPE_RSA_PUBLIC_KEY) {
			if (src->info.objectType != TEE_TYPE_RSA_KEYPAIR)
				return TEE_ERROR_BAD_PARAMETERS;
		} else if (o->info.objectType == TEE_TYPE_DSA_PUBLIC_KEY) {
			if (src->info.objectType != TEE_TYPE_DSA_KEYPAIR)
				return TEE_ERROR_BAD_PARAMETERS;
		} else if (o->info.objectType == TEE_TYPE_ECDSA_PUBLIC_KEY) {
			if (src->info.objectType != TEE_TYPE_ECDSA_KEYPAIR)
				return TEE_ERROR_BAD_PARAMETERS;
		} else if (o->info.objectType == TEE_TYPE_ECDH_PUBLIC_KEY) {
			if (src->info.objectType != TEE_TYPE_ECDH_KEYPAIR)
				return TEE_ERROR_BAD_PARAMETERS;
		} else {
			return TEE_ERROR_BAD_PARAMETERS;
		}

		tp_src = tee_svc_find_type_props(src->info.objectType);
		if (!tp_src)
			return TEE_ERROR_BAD_STATE;

		have_attrs = BIT32(tp->num_type_attrs) - 1;
		for (n = 0; n < tp->num_type_attrs; n++) {
			ta = tp->type_attrs + n;

			idx = tee_svc_cryp_obj_find_type_attr_idx(ta->attr_id,
								  tp_src);
			if (idx < 0)
				return TEE_ERROR_BAD_STATE;

			attr = (uint8_t *)o->attr + ta->raw_offs;
			src_attr = (uint8_t *)src->attr +
				   tp_src->type_attrs[idx].raw_offs;
			res = attr_ops[ta->ops_index].from_obj(attr, src_attr);
			if (res != TEE_SUCCESS)
				return res;
		}
	}

	o->have_attrs = have_attrs;
	return TEE_SUCCESS;
}
