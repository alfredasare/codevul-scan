void WaitForPageScaleUpdate() {
  static const int kMaxIterations = 1000;
  int iterations = 0;

  if (!got_page_scale_update_) {
    base::RunLoop run_loop;
    on_page_scale_update_ = run_loop.QuitClosure();

    while (!got_page_scale_update_ && iterations < kMaxIterations) {
      run_loop.RunFor(base::TimeDelta::FromMilliseconds(100));
      iterations++;
    }
  }

  got_page_scale_update_ = false;
}