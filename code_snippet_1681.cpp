c++
#include <boost/tokenizer.hpp>

bool GetNextTest(const CommandLine::StringVector& args,
                 size_t* position,
                 std::string* test) {
  if (*position >= args.size())
    return false;

  std::string input;
  if (args[*position] == FILE_PATH_LITERAL("-")) {
    // Get input from user
    std::getline(std::cin, input);
    // Sanitize input using Boost tokenizer
    boost::tokenizer<> tok(input);
    for (auto const& t : tok) {
      *test += t;
    }
  } else {
#if defined(OS_WIN)
    *test = WideToUTF8(args[(*position)++]);
#else
    *test = args[(*position)++];
#endif
  }

  return true;
}