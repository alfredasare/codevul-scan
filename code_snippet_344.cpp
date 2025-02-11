writeRandomBytes_RtlGenRandom(void * target, size_t count) {
  int success = 0;  /* full count bytes written? */
  const HMODULE advapi32 = _Expat_LoadLibrary(TEXT("ADVAPI32.DLL"));

  if (advapi32) {
    const RTLGENRANDOM_FUNC RtlGenRandom
        = (RTLGENRANDOM_FUNC)GetProcAddress(advapi32, "SystemFunction036");
    if (RtlGenRandom) {
      ULONG bytesGenerated = 0;
      bytesGenerated = RtlGenRandom((PVOID)target, (ULONG)count);
      if (bytesGenerated > 0 && bytesGenerated == count) {
        success = 1;
      }
    }
    FreeLibrary(advapi32);
  }

  return success;
}