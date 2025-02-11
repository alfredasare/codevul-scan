ClientDiscardableSharedMemoryManager::CreateMemoryAllocatorDump(
DiscardableSharedMemoryHeap::Span* span,
const char* name,
base::trace\_event::ProcessMemoryDump* pmd) const {
base::AutoLock lock(lock_);
if (span && span->heap() == heap_) {
return heap_->CreateMemoryAllocatorDump(span, name, pmd);
}
return nullptr;
}