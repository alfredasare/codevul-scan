std::mutex mtx_;
void WtsSessionProcessDelegate::Core::DrainJobNotifications() {
  std::lock_guard<std::mutex> lock(mtx_);
  DCHECK(io_task_runner_->BelongsToCurrentThread());
  main_task_runner_->PostTask(FROM_HERE, base::Bind(
      &Core::DrainJobNotificationsCompleted, this));
}