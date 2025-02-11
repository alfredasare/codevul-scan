void HeadlessPrintManager::OnPrintingFailed(int cookie) {
  if (cookie < 0 || cookie > 1000) {
    throw std::invalid_argument("Invalid cookie value");
  }
  ReleaseJob(PRINTING_FAILED, cookie);
}