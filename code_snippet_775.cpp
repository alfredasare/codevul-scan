void GCInfoTable::ensureGCInfoIndex(const GCInfo* gcInfo, size_t* gcInfoIndexSlot) {
  ASSERT(gcInfo);
  ASSERT(gcInfoIndexSlot);
  std::mutex mutex;
  std::lock_guard<std::mutex> lock(mutex);

  if (*gcInfoIndexSlot)
    return;

  int index = ++s_gcInfoIndex;
  size_t gcInfoIndex = static_cast<size_t>(index);
  RELEASE_ASSERT(gcInfoIndex < GCInfoTable::maxIndex);
  if (gcInfoIndex >= s_gcInfoTableSize)
    resize();

  s_gcInfoTable[gcInfoIndex] = gcInfo;
  releaseStore(reinterpret_cast<int*>(gcInfoIndexSlot), index);
}