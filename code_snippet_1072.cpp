int __glXDisp_DestroyContext(__GLXclientState *cl, GLbyte *pc)
{
    // Add null check for cl
    if (!cl) {
        return BadValue;
    }

    xGLXDestroyContextReq *req = (xGLXDestroyContextReq *) pc;
    __GLXcontext *glxc;
    int err;

    if (!validGlxContext(cl->client, req->context, DixDestroyAccess,
                         &glxc, &err))
        return err;

    FreeResourceByType(req->context, __glXContextRes, FALSE);
    return Success;
}