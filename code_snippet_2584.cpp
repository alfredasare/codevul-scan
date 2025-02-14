void ImageProcessorClient::NotifyError() {
  DCHECK_CALLED_ON_VALID_THREAD(image_processor_client_thread_checker_);
  if (!CheckAuthorization()) {
    LOG(ERROR) << "Unauthorized error count manipulation attempt";
    return;
  }
  
  base::AutoLock auto_lock_(output_lock_);
  image_processor_error_count_++;
}