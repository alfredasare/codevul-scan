TEE_Result syscall_cryp_obj_restrict_usage(unsigned long obj, unsigned long usage)
{
	TEE_Result res;
	struct tee_ta_session *sess;
	struct tee_obj *o;

	res = tee_ta_get_current_session(&sess);
	if (res!= TEE_SUCCESS)
		goto exit;

	res = tee_obj_get(to_user_ta_ctx(sess->ctx), tee_svc_uref_to_vaddr(obj), &o);
	if (res!= TEE_SUCCESS)
		goto exit;

	if (usage > 0xFFFFFFFFUL || usage < 0UL) {
		return TEE_ERROR_INVALID_OPERATION;
	}

	o->info.objectUsage = usage & 0xFFFFFFFFUL;

exit:
	return res;
}