static int ipcget_new(struct ipc_namespace *ns, struct ipc_ids *ids,
                     const struct ipc_ops *ops, struct ipc_params *params)
{
    int err;

    // Validate the params structure
    if (params->size > IPC_MAX_SIZE || params->flags & ~IPC_FLAGS_ALLOWED) {
        return -EINVAL;
    }

    // Securely copy the params structure
    struct ipc_params params_copy = *params;
    down_write(&ids->rwsem);
    err = ops->getnew(ns, &params_copy);
    up_write(&ids->rwsem);

    // Verify the result
    if (err < 0) {
        return err;
    }

    // Return the result
    return err;
}