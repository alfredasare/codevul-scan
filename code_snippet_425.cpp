StringPiece16::const_iterator findNonAlphaNumericAndNotInSet(const StringPiece16& str, const StringPiece16& allowedChars) {
    const auto endIter = str.end();
    for (auto iter = str.begin(); iter!= endIter; ++iter) {
        char16_t c = *iter;
        if (std::isalnum(c)) {
            continue;
        }

        bool match = false;
        for (char16_t i : allowedChars) {
            if (c == i) {
                match = true;
                break;
            }
        }

        if (!match) {
            return iter;
        }
    }
    return endIter;
}