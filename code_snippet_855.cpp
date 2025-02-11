static const int kMaxChildProcesses = 10; // Adjust this value based on your requirements
static int numChildProcesses_ = 0;

static bool CreateInitProcessReaper(base::Closure* post_fork_parent_callback) {
  if (numChildProcesses_ >= kMaxChildProcesses) {
    LOG(ERROR) << "Error creating an init process: Maximum number of child processes reached";
    return false;
  }

  const bool init_created =
      sandbox::CreateInitProcessReaper(post_fork_parent_callback);
  if (!init_created) {
    LOG(ERROR) << "Error creating an init process to reap zombies";
    return false;
  }

  ++numChildProcesses_;

  // Add a cleanup function to decrement the numChildProcesses_ variable when the child process exits
  base::ScopedClosureRunner runner(base::Bind(&DecrementChildProcessCount));

  return true;
}

void DecrementChildProcessCount() {
  --numChildProcesses_;
}