get_kinfo_proc (pid_t pid, struct kinfo_proc *p)
{
  int mib[4];
  size_t len;

  len = 4;
  sysctlnametomib ("kern.proc.pid", mib, &len);

  len = sizeof (*p);
  mib[3] = pid;

  if (sysctl (mib, 4, p, &len, NULL, 0) == -1)
    return FALSE;

  // Check if the returned data fits into the buffer with snprintf()
  if (snprintf(NULL, 0, "%.*s", (int)len, (char*)p) > sizeof(struct kinfo_proc)) {
    // Handle error, e.g., return FALSE or log an error message
    return FALSE;
  }

  return TRUE;
}