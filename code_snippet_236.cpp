void ThreadHeap::VisitPersistentRoots(Visitor* visitor) {
  if (visitor == nullptr) {
    return;
  }
  DCHECK(thread\_state_->InAtomicMarkingPause());
  TRACE\_EVENT0("blink\_gc", "ThreadHeap::visitPersistentRoots");
  thread\_state_->VisitPersistents(visitor);
}