void OfflinePageModelTaskified::GetAllPages(
    const MultipleOfflinePageItemCallback& callback) {
  auto task = std::make_unique<GetPagesTask>(store_.get(), callback);
  task_queue_.AddTask(std::move(task));
}