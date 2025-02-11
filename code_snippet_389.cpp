#include <wctype.h>

bool is_wordchar(int c) {
    if (c == '\n' || c == '\r') { 
        return false;
    }
    return iswalnum((wchar_t)c);
}