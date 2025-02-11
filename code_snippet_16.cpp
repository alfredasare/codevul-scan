VOID ParaNdis\_FinalizeCleanup(PARANDIS\_ADAPTER *pContext)
{
if (pContext != NULL && pContext->InterruptHandle != NULL)
{
NdisMDeregisterInterruptEx(pContext->InterruptHandle);
pContext->InterruptHandle = NULL;
}
if (pContext != NULL && pContext->BufferListsPool != NULL)
{
NdisFreeNetBufferListPool(pContext->BufferListsPool);
pContext->BufferListsPool = NULL;
}
if (pContext != NULL && pContext->DmaHandle != NULL)
{
NdisMDeregisterScatterGatherDma(pContext->DmaHandle);
pContext->DmaHandle = NULL;
}
}