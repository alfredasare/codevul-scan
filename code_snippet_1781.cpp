void SparseHistogram::WriteAscii(std::string* output) const {
    if (output == nullptr) {
        throw std::invalid_argument("Output pointer is NULL");
    }
    WriteAsciiImpl(true, "\n", output);
}