#include <limits>

constexpr auto kMaxWaitTimeMs = std::numeric_limits<decltype(WaitableEvent::Wait(0))>::max();

void SetBlockingFlagAndBlockUntilStopped(WaitableEvent* task_start_event,
                                         WaitableEvent* task_stop_event) {
  TraceLog::GetInstance()->SetCurrentThreadBlocksMessageLoop();
  auto wait_time = kMaxWaitTimeMs; // Set the maximum wait time

  while (wait_time > 0 && !task_stop_event->Wait(wait_time)) {
    wait_time = 100; // Set a reasonable wait time between retries
    // Perform any necessary cleanup or handling here if the event is not signaled
  }
}