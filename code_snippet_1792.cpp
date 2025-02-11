void AppLayerProtoDetectUnittestCtxRestore(void)
{
SCEnter();
if (alpd\_ctx_ut == NULL) {
return;
}
alpd\_ctx = alpd\_ctx\_ut;
memset(&alpd\_ctx\_ut, 0, sizeof(alpd\_ctx\_ut));
SCReturn;
}