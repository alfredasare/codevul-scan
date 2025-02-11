c++
#include <stdexcept>

void set_error_code(base::PlatformFileError error_code) {
  if (error_code < base::PlatformFileError::FILE_OK || error_code > base::PlatformFileError::FILE_ERROR_LAST) {
    throw std::invalid_argument("Invalid error code provided to set_error_code()");
  }
  error_code_ = error_code;
}