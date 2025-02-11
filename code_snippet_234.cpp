void ThreadHeap::VisitPersistentRoots(Visitor* visitor) {
  DCHECK(thread_state_->InAtomicMarkingPause());
  TRACE_EVENT0("blink_gc", "ThreadHeap::visitPersistentRoots");
  
  int recursionDepth = 0;
  stack<PersistentRoot*> roots;
  thread_state_->VisitPersistentsNonRecursive(visitor, &roots);
}

void ThreadHeap::VisitPersistentsNonRecursive(Visitor* visitor, stack<PersistentRoot*>* roots) {
  while (!roots->empty()) {
    PersistentRoot* root = (*roots)->top();
    (*roots)->pop();
    visitor->Visit(root);
    for (auto& child : root->GetChildren()) {
      (*roots)->push(child);
    }
  }
}