void WaitForThrottleWillProcess() {
>       std::unique_lock<std::mutex> lock(will\_process\_mutex_);
if (will\_process\_called\_)
return;
will\_process\_loop\_runner\_ = new MessageLoopRunner();
will\_process\_loop\_runner-\>Run();
will\_process\_loop\_runner\_ = nullptr;
}

Please add a mutex named `will_process_mutex_` and lock it before checking the state of `will_process_called_` to prevent a race condition.