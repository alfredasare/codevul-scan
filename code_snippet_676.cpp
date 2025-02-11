void WaitForEvents(size_t numbers_of_events) {
  size_t max_iterations = 100; // adjust this value based on your system's resources
  size_t iterations = 0;

  while (records_.size() < numbers_of_events && iterations < max_iterations) {
    loop_.reset(new base::RunLoop);
    loop_->Run();
    loop_.reset();
    iterations++;
  }

  if (iterations >= max_iterations) {
    // handle the case where the loop exceeded the maximum iterations
  }
}