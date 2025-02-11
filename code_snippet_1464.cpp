c++
bool EnableInProcessStackDumpingForSandbox() {
#if defined(USE_SYMBOLIZE)
  std::unique_ptr<SandboxSymbolizeHelper> sandbox_symbolize_helper = SandboxSymbolizeHelper::GetInstance();
  if (sandbox_symbolize_helper == nullptr) {
    return false;
  }
#endif  // USE_SYMBOLIZE

  return EnableInProcessStackDumping();
}