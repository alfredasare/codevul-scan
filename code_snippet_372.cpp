c++
static WorkerFetchContextHolder* From(WorkerClients& clients) {
  auto supplement = Supplement<WorkerClients>::From(clients, SupplementName());
  if (supplement == nullptr) {
    throw std::runtime_error("Supplement is null");
  }
  return static_cast<WorkerFetchContextHolder*>(supplement);
}