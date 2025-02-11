c++
#include <cstring>
#include <stdexcept>

static int CallStat(const char *path, stat_wrapper_t *sb) {
  base::ThreadRestrictions::AssertIOAllowed();

  // Check if the path contains any ".." or "/" characters
  if (strchr(path, '/') || strchr(path, '.')) {
    throw std::runtime_error("Invalid path");
  }

  return stat(path, sb);
}