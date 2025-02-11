TEE_Result syscall_cryp_obj_restrict_usage(unsigned long obj, unsigned long usage)
{
	TEE_Result res;
	struct tee_ta_session *sess;
	struct tee_obj *o;

	if (usage > MAX_ALLOWED_USAGE) {
		return TEE_ERROR_BAD_PARAMETERS;
	}

	res = tee_ta_get_current_session(&sess);
	if (res != TEE_SUCCESS)
		goto exit;

	res = tee_obj_get(to_user_ta_ctx(sess->ctx),
			  tee_svc_uref_to_vaddr(obj), &o);
	if (res != TEE_SUCCESS)
		goto exit;

	if ((o->info.objectUsage & usage) != usage) {
		res = TEE_ERROR_GENERIC;
		goto exit;
	}

	o->info.objectUsage &= usage;

exit:
	return res;
}