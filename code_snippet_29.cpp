#include <cctype>

bool is_delimiter(unsigned char c) {
    return isblank(c) || c == ',';
}