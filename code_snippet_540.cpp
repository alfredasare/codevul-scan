csharp
DefaultWebClientState GetDefaultBrowser() {
  string chromeDefaultState = ShellUtil::GetChromeDefaultState();
  if (!Regex.IsMatch(chromeDefaultState, @"^[a-zA-Z0-9_]+$")) {
    throw new Exception("Invalid input");
  }
  chromeDefaultState = SanitizeInput(chromeDefaultState);
  if (chromeDefaultState.Length > 255) {
    chromeDefaultState = chromeDefaultState.Substring(0, 255);
  }
  return GetDefaultWebClientStateFromShellUtilDefaultState(chromeDefaultState);
}

string SanitizeInput(string input) {
  return Regex.Replace(input, @"[^a-zA-Z0-9_]+", "");
}