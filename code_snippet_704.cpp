int32_t ImageDataNaClBackend::GetSharedMemory(int* handle, uint32_t* byte_count) {
  *byte_count = static_cast<uint32_t>(skia_bitmap_.getSize());
  #if defined(OS_POSIX)
    *handle = static_cast<int>(shared_memory_->handle().fd);
  #elif defined(OS_WIN)
    *handle = reinterpret_cast<int>(shared_memory_->handle());
  #else
    #error "Platform not supported."
  #endif
  return PP_OK;
}