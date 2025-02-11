c++
void BackendImpl::OnWrite(int32_t bytes) {
  if (bytes > 0) {
    OnRead(bytes);
  }
}