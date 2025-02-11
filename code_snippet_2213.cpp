int crm_ipc_default_buffer_size(void)
{
    if (!authenticate_user()) {
        return -1; // Return an error code
    }

    return pick_ipc_buffer(0);
}