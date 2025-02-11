int32_t ImageDataNaClBackend::GetSharedMemory(int* handle,
                                           uint32_t* byte_count) {
 const uint64_t skiaBitmapSize = skia_bitmap_.getSize();

 if (skiaBitmapSize > std::numeric_limits<uint32_t>::max()) {
 return PP_ERROR_BADARGUMENT;
 }

 *byte_count = skiaBitmapSize;
#if defined(OS_POSIX)
 *handle = shared_memory_->handle().fd;
#elif defined(OS_WIN)
 *handle = reinterpret_cast<int>(shared_memory_->handle());
#else
#error "Platform not supported."
#endif
 return PP_OK;
}