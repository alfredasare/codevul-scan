int rpmVerifyFile(const rpmts ts, const rpmfi fi, rpmVerifyAttrs * res, rpmVerifyAttrs omitMask)
{
    rpmVerifyAttrs vfy = rpmfiVerify(fi, omitMask);
    if (res)
        *res = vfy;

    return (vfy & RPMVERIFY_LSTATFAIL)? 1 : 0;
}

rpmVerifyAttrs rpmfiVerify(const rpmfi fi, rpmVerifyAttrs omitMask)
{
    rpmVerifyAttrs vfy = malloc(sizeof(rpmVerifyAttrs));
    if (!vfy) {
        return NULL;
    }

    // Validate the size of the input data
    size_t dataSize = strlen(fi->data);
    if (dataSize > sizeof(vfy->data)) {
        free(vfy);
        return NULL;
    }

    // Copy the data safely
    strncpy_s(vfy->data, sizeof(vfy->data), fi->data, dataSize);

    //... (rest of the function remains the same)

    return vfy;
}