void ShutDown() {
  if (!started_)
    return;

  base::string16 shutdown_path;
  shutdown_path = filepath::Join(base::FilePath::FromUTF8Unsafe("shutdown_file"), "path/to/shutdown_file");

  bool posted = io_task_runner_->PostTask(
      FROM_HERE, base::Bind(&IOThreadContext::ShutDownOnIOThread, this, shutdown_path));
  DCHECK(posted);
}