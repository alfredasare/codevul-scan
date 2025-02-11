Void WaitUntilShown() {
> constexpr int kMaxRetries = 100;
int retries = 0;
while (!is\_visible\_ && retries < kMaxRetries) {
message\_loop\_runner\_ = new MessageLoopRunner;
message\_loop\_runner_->Run();
retries++;
}
}