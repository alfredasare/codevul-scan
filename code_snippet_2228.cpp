TEE_Result tee_svc_copy_from_user(void *kaddr, const void *uaddr, size_t len)
{
    TEE_Result res;
    struct tee_ta_session *s;
    const char *allowed_paths[] = {"/trusted/directory", "/another/trusted/directory"};
    size_t allowed_paths_len = sizeof(allowed_paths) / sizeof(const char *);

    res = tee_ta_get_current_session(&s);
    if (res != TEE_SUCCESS)
        return res;

    res = tee_mmu_check_access_rights(to_user_ta_ctx(s->ctx),
                                     TEE_MEMORY_ACCESS_READ | TEE_MEMORY_ACCESS_ANY_OWNER,
                                     (uaddr_t)uaddr, len);
    if (res != TEE_SUCCESS)
        return res;

    if (is_allowed_path(uaddr, allowed_paths, allowed_paths_len))
        copy_from_user(kaddr, uaddr, len);
    else
        return TEE_ERROR_ACCESS_DENIED;

    return TEE_SUCCESS;
}