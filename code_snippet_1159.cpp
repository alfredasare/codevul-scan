kadm5_create_principal(void *server_handle,
                        kadm5_principal_ent_t entry, long mask,
                       char *password)
{
    // Validate password length
    if (strlen(password) > MAX_PASSWORD_LENGTH) {
        return KADM5_ERROR_INVALID_PASSWORD;
    }

    // Allocate a safe buffer
    char *buf = malloc(MAX_PASSWORD_LENGTH + 1);
    if (!buf) {
        return KADM5_ERROR_OUT_OF_MEMORY;
    }

    // Copy password data safely
    memcpy(buf, password, strlen(password));
    buf[MAX_PASSWORD_LENGTH] = '\0';

    // Call the original function with the safe buffer
    return kadm5_create_principal_3(server_handle, entry, mask, 0, NULL, buf);
}