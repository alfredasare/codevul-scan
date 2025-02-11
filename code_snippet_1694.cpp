void SetBlockingFlagAndBlockUntilStopped(WaitableEvent* task_start_event, WaitableEvent* task_stop_event) {
  TraceLog::GetInstance()->SetCurrentThreadBlocksMessageLoop();

  if (!BlockUntilStopped(task_start_event, task_stop_event)) {
    TraceLog::GetInstance()->Error("Error blocking until stopped");
    return;
  }

  const int kTimeoutMs = 10000; // 10 seconds
  const int kMaxRetries = 3;
  int retries = 0;

  while (true) {
    if (!BlockUntilStopped(task_start_event, task_stop_event)) {
      TraceLog::GetInstance()->Error("Error blocking until stopped");
      break;
    }
    retries++;
    if (retries >= kMaxRetries || GetTickCount() > kTimeoutMs) {
      break;
    }
    SleepForMillisec(kTimeoutMs * (1 << retries));
  }
}