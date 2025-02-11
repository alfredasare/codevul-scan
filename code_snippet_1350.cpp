ProcNoOperation(ClientPtr client)
{
    REQUEST_AT_LEAST_SIZE(xReq);

    if (xReq == NULL || xReq < 0 || xReq >= sizeof(xReq) / sizeof(xReq[0])) {
        return Error;
    }

    /* noop -- don't do anything */
    return Success;
}