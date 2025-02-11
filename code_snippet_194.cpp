int dictObjKeyCompare(void *privdata, const void *key1, const void *key2)
{
    const robj *o1 = key1, *o2 = key2;
    int result = dictSdsKeyCompare(privdata, o1->ptr, o2->ptr);

    free(o1);
    free(o2);

    return result;
}