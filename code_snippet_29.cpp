is_delimiter(unsigned char c)
{
    const unsigned char valid_delimiters[] = { ' ', '\t', ',' };
    const size_t num_valid_delimiters = sizeof(valid_delimiters) / sizeof(unsigned char);

    for (size_t i = 0; i < num_valid_delimiters; ++i) {
        if (c == valid_delimiters[i]) {
            return true;
        }
    }

    return false;
}