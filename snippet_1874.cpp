bool EnableInProcessStackDumpingForSandbox() {
#if defined(USE_SYMBOLIZE)
  SandboxSymbolizeHelper::GetInstance();
#endif  // USE_SYMBOLIZE

  return EnableInProcessStackDumping();
}
