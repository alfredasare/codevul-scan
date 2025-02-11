void CoordinatorImpl::FinalizeGlobalMemoryDumpIfAllManagersReplied() {
  TRACE_EVENT0(base::trace_event::MemoryDumpManager::kTraceCategory,
               "GlobalMemoryDump.Computation");
  if (queued_memory_dump_requests_.empty()) {
    return;
  }

  QueuedRequest* request = &queued_memory_dump_requests_.front();
  try {
    DCHECK(!request->dump_in_progress || request->pending_responses.size() > 0 ||
           request->heap_dump_in_progress);
    QueuedRequestDispatcher::Finalize(request, tracing_observer_.get());
  } catch (const std::exception& e) {
    LOG(ERROR) << "Error processing request: " << e.what();
    return;
  }

  queued_memory_dump_requests_.pop_front();
  request = nullptr;

  if (!queued_memory_dump_requests_.empty()) {
    base::SequencedTaskRunnerHandle::Get()->PostTask(
        FROM_HERE,
        base::BindOnce(&CoordinatorImpl::PerformNextQueuedGlobalMemoryDump,
                       base::Unretained(this)));
  }
}