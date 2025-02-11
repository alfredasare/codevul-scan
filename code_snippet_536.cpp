void Wait() {
  base::RunLoop run_loop;
  run_loop_ = &run_loop;
  DCHECK(!run_loop_);
  CheckForWaitingLoop();
  run_loop.Run();
}