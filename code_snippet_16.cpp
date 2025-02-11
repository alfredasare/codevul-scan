VOID ParaNdis_FinalizeCleanup(PARANDIS_ADAPTER *pContext)
{
    if (pContext!= NULL)
    {
        if (pContext->InterruptHandle && pContext->InterruptHandle!= INVALID_HANDLE)
        {
            NdisMDeregisterInterruptEx(pContext->InterruptHandle);
            pContext->InterruptHandle = NULL;
        }
        if (pContext->BufferListsPool && pContext->BufferListsPool!= NULL)
        {
            NdisFreeNetBufferListPool(pContext->BufferListsPool);
            pContext->BufferListsPool = NULL;
        }
        if (pContext->DmaHandle && pContext->DmaHandle!= INVALID_HANDLE)
        {
            NdisMDeregisterScatterGatherDma(pContext->DmaHandle);
            pContext->DmaHandle = NULL;
        }
    }
}