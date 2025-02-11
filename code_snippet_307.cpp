ClientDiscardableSharedMemoryManager::CreateMemoryAllocatorDump(
    DiscardableSharedMemoryHeap::Span* span,
    const char* name,
    base::trace_event::ProcessMemoryDump* pmd) const {
  base::AutoLock lock(lock_);
  if (!span ||!span->IsValid() || span->GetBase() + span->GetSize() > heap_->GetCapacity()) {
    // Handle invalid or null pointer or out-of-bounds access
    return;
  }

  // Copy the memory region pointed to by span into pmd
  size_t size = span->GetSize();
  char* buffer = new char[size];
  memcpy(buffer, span->GetBase(), size);
  pmd->AddMemoryRegion(name, buffer, size);
  delete[] buffer;

  return heap_->CreateMemoryAllocatorDump(span, name, pmd);
}