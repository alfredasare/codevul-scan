int __cdecl DebugOnStart::Init() {
  const char* commandLine = GetCommandLine();
  if (commandLine!= nullptr) {
    size_t pos = 0;
    while ((pos = strchr(commandLine, '='))!= nullptr) {
      commandLine[pos] = '\0';
      break;
    }
    const char* switchArg = nullptr;
    if (strchr(commandLine, switches::kDebugOnStart)!= nullptr) {
      switchArg = "debugonstart";
    } else if (strchr(commandLine, switches::kWaitForDebugger)!= nullptr) {
      switchArg = "waitfordebugger";
    }
    if (switchArg!= nullptr) {
      char* sanitizedArg = strdup(switchArg);
      for (char* p = sanitizedArg; *p; ++p) {
        if (!isalnum(*p) && *p!= '-') {
          *p = '\0';
          break;
        }
      }
      if (strcmp(sanitizedArg, "debugonstart") == 0) {
        base::debug::SpawnDebuggerOnProcess(GetCurrentProcessId());
      } else if (strcmp(sanitizedArg, "waitfordebugger") == 0) {
        base::debug::WaitForDebugger(60, true);
      }
      free(sanitizedArg);
    }
  }
  return 0;
}