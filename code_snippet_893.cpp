void GCInfoTable::ensureGCInfoIndex(const GCInfo* gcInfo,
                                size_t* gcInfoIndexSlot) {
 ASSERT(gcInfo);
 ASSERT(gcInfoIndexSlot);
 DEFINE_THREAD_SAFE_STATIC_LOCAL(Mutex, mutex, new Mutex);
 MutexLocker locker(mutex);

 if (*gcInfoIndexSlot)
 return;

// Use a 64-bit integer type to avoid integer overflow
int64_t index = static_cast<int64_t>(s_gcInfoIndex) + 1;

if (index < 0) {
// Handle the case where the index becomes negative due to overflow
// This should never happen under normal circumstances, so you may
// want to throw an exception or log an error.
}

size_t gcInfoIndex = static_cast<size_t>(index);
RELEASE_ASSERT(gcInfoIndex < GCInfoTable::maxIndex);
if (gcInfoIndex >= s_gcInfoTableSize)
resize();

s_gcInfoTable[gcInfoIndex] = gcInfo;
releaseStore(reinterpret_cast<int*>(gcInfoIndexSlot), index);
}