void SparseHistogram::WriteAscii(std::string* output) const {
  std::string protectedOutput = *output;
  WriteAsciiImpl(true, "\n", &protectedOutput);
  *output = protectedOutput;
}