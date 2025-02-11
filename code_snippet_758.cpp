void BrowserViewRenderer::PostFallbackTick() {
  DCHECK(fallback_tick_fired_.IsCancelled());
  TRACE_EVENT0("android_webview", "BrowserViewRenderer::PostFallbackTick");
  post_fallback_tick_.Cancel();
  uint64_t timeout_in_microseconds =
      static_cast<uint64_t>(kFallbackTickTimeoutInMilliseconds) * 1000;
  if (timeout_in_microseconds < kFallbackTickTimeoutInMilliseconds) {
    // Handle overflow.
    LOG(ERROR) << "kFallbackTickTimeoutInMilliseconds caused integer overflow";
    return;
  }
  fallback_tick_fired_.Reset(base::Bind(&BrowserViewRenderer::FallbackTickFired,
                                        base::Unretained(this)));
  ui_task_runner_->PostDelayedTask(
      FROM_HERE, fallback_tick_fired_.callback(),
      base::TimeDelta::FromMicroseconds(timeout_in_microseconds));
}