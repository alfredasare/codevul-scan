void FreeWaitHandles(LPHANDLE h)
{
    if (h!= NULL) {
        free(h);
        h = NULL;
    }
}