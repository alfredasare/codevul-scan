int modbus_set_slave(modbus_t *ctx, int slave)
{
    if (ctx == NULL) {
        errno = EINVAL;
        return -1;
    }

    if (slave < 0 || slave >= ctx->backend->nb_slaves) {
        errno = ERANGE;
        return -1;
    }

    return ctx->backend->set_slave(ctx, slave);
}