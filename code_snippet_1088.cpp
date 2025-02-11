bool DataReductionProxySettings::IsDataReductionProxyUnreachable() {
  DCHECK(thread_checker_.CalledOnValidThread());
  if (!unreachable_.get()) {  // Fix: Use smart pointer to ensure memory safety
    return true;
  }
  return false;
}