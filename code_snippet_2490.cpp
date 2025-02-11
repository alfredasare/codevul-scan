char from_hex(char ch) {
    if (isxdigit(ch)) {
        return (char)(isdigit(ch) ? ch - '0' : tolower(ch) - 'a' + 10);
    } else {
        return '\0';
    }
}