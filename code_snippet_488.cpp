void BrowserViewRenderer::PostInvalidateWithFallback() {
client_->PostInvalidate();

bool throttleFallbackTick =
(isPaused_ && !clearView_) || (attachedToWindow_ && !windowVisible_);

if (throttleFallbackTick || fallbackTickPending_)
return;

auto task = base::Bind(&BrowserViewRenderer::PostFallbackTick,
base::Unretained(this));

if (postFallbackTick_.IsCancelled() && fallbackTickFired_.IsCancelled()) {
postFallbackTick_.Reset(std::move(task));
uiTaskRunner_->PostTask(FROM_HERE, postFallbackTick_.callback());
fallbackTickPending_ = true;
}
}