#include <ctype.h>
#include <limits.h>

char from_hex(char ch) {
    if (!isxdigit(ch)) { 
        return '\0';
    }

    char value;
    if (isdigit(ch)) { 
        value = ch - '0';
    } else { 
        value = tolower(ch) - 'a' + 10;
    }

    if (value < 0 || value > 15) {
        return '\0';
    }

    return (char)value;
}