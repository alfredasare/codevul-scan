HMODULE advapi32 = LoadLibrary(TEXT("ADVAPI32.DLL"));
RTLGENRANDOM_FUNC RtlGenRandom = (RTLGENRANDOM_FUNC)GetProcAddress(advapi32, "SystemFunction036");

if (RtlGenRandom) {
    if (RtlGenRandom((PVOID)target, (ULONG)count) == TRUE) {
        success = 1;
    }
}
FreeLibrary(advapi32);

return success;