static int appendDynamic(dynamicPtr * dp, const void *src, int size)
{
    int bytesNeeded;
    char *tmp;

    if (!dp->dataGood) {
        return FALSE;
    }

    bytesNeeded = dp->pos + size;

    if (bytesNeeded > dp->realSize) {
        dp->realSize = bytesNeeded;
        if (dp->realSize < dp->realSize) {
            return FALSE; // overflow detected
        }
        if (!gdReallocDynamic(dp, dp->realSize * 2)) {
            dp->dataGood = FALSE;
            return FALSE;
        }
    }

    tmp = (char *)dp->data;
    memcpy((void *)(tmp + (dp->pos)), src, size);
    dp->pos += size;

    if (dp->pos > dp->logicalSize) {
        dp->logicalSize = dp->pos;
    };

    return TRUE;
}