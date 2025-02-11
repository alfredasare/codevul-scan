TEE_Result tee_svc_copy_from_user(void *kaddr, const void *uaddr, size_t len)
{
	TEE_Result res;
	struct tee_ta_session *s;
	size_t kaddr_size;

	res = tee_ta_get_current_session(&s);
	if (res != TEE_SUCCESS)
		return res;

	kaddr_size = s->ctx->ksize - s->ctx->offset;

	if (len > kaddr_size) {
		return TEE_ERROR_SHORT_BUFFER;
	}

	res = tee_mmu_check_access_rights(to_user_ta_ctx(s->ctx),
					TEE_MEMORY_ACCESS_READ,
					(uaddr_t)uaddr, len);
	if (res != TEE_SUCCESS)
		return res;

	memcpy(kaddr, uaddr, len);
	return TEE_SUCCESS;
}