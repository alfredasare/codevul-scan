void Wait() {
  base::RunLoop run_loop;
  DCHECK(!run_loop_);
  if (run_loop_ != nullptr) {
    return;
  }
  run_loop_ = &run_loop;
  CheckForWaitingLoop();
  run_loop.Run();
}