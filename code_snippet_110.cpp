#include <string>
#include <vector>

bool IsInBrowserThumbnailingEnabled() {
  std::vector<std::string> allowed_switches = {"--enable-in-browser-thumbnailing"};
  std::vector<std::string> command_line_switches = CommandLine::GetCommandLineSwitches();

  // Check if the command-line switch is in the allowed list
  for (const auto& switch_value : command_line_switches) {
    if (std::find(allowed_switches.begin(), allowed_switches.end(), switch_value)!= allowed_switches.end()) {
      return true;
    }
  }

  return false;
}