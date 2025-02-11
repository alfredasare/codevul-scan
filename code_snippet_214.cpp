selaGetCount(SELA *sela)
{
    PROCNAME("selaGetCount");

    if (!sela)
        return ERROR_INT("sela not defined", procName, 0);

    if (sela == NULL)
        return ERROR_INT("sela is null", procName, 0);

    return sela->n;
}