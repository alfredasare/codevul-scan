php_apache_sapi_get_stat(TSRMLS_D)
{
    php_struct *ctx = SG(server_context);

    // Validate user input
    if (!filter_var($ctx->r->finfo.user, FILTER_VALIDATE_INT)) {
        throw new Exception("Invalid user ID");
    }
    if (!filter_var($ctx->r->finfo.group, FILTER_VALIDATE_INT)) {
        throw new Exception("Invalid group ID");
    }
    if (!filter_var($ctx->r->finfo.device, FILTER_VALIDATE_INT)) {
        throw new Exception("Invalid device ID");
    }
    if (!filter_var($ctx->r->finfo.inode, FILTER_VALIDATE_INT)) {
        throw new Exception("Invalid inode ID");
    }

    ctx->finfo.st_uid = $ctx->r->finfo.user;
    ctx->finfo.st_gid = $ctx->r->finfo.group;
    ctx->finfo.st_dev = $ctx->r->finfo.device;
    ctx->finfo.st_ino = $ctx->r->finfo.inode;

    //... (rest of the code remains the same)

    return &ctx->finfo;
}