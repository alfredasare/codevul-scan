void RestartOnHostShutdown() {
    std::optional<base::TaskRunner*> task_runner = context_->network_task_runner();
    if (!task_runner.has_value()) {
        LOG(ERROR) << "Invalid network task runner";
        return;
    }

    DCHECK(task_runner->BelongsToCurrentThread());

    if (shutting_down_) {
        return;
    }

    restarting_ = false;
    host_ = NULL;
    ResetHost();

    StartHost();
}