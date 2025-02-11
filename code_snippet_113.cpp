Sure, here's the fixed version of the code that validates the size of the `ResourceTimingInfo` object before passing it to the `AddResourceTiming` method:
++
constexpr size_t MAX_ALLOWED_SIZE = 1024;