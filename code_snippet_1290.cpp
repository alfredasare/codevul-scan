void CoordinatorImpl::FinalizeGlobalMemoryDumpIfAllManagersReplied() {
TRACE\_EVENT0(base::trace\_event::MemoryDumpManager::kTraceCategory,
 "\_GlobalMemoryDump.Computation");
bool should\_finalize = false;

{
std::scoped\_lock<std::mutex> lock(queued\_memory\_dump\_requests\_mutex);
if (!queued\_memory\_dump\_requests\_.empty()) {
QueueuedRequest* request = &queued\_memory\_dump\_requests\_.front();
should\_finalize = !(request->dump\_in\_progress || request->pending\_responses.size() > 0 ||
request->heap\_dump\_in\_progress);
}
}

if (should\_finalize) {
QueueuedRequestDispatcher::Finalize(&queued\_memory\_dump\_requests\_.front(), tracing\_observer.\_get());

std::scoped\_lock<std::mutex> lock(queued\_memory\_dump\_requests\_mutex);
queued\_memory\_dump\_requests\_.pop\_front();
}

if (!queued\_memory\_dump\_requests\_.empty()) {
base::SequencedTaskRunnerHandle::Get()->PostTask(
FROM\_HERE,
base::BindOnce(&CoordinatorImpl::PerformNextQueuedGlobalMemoryDump,
base::Unretained(this)));
}
}