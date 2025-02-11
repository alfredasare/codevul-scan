bool V4L2JpegEncodeAccelerator::EncodedInstance::CreateBuffers(
    gfx::Size coded_size,
    size_t output_buffer_size) {
  DCHECK(parent_->encoder_task_runner_->BelongsToCurrentThread());

  if (coded_size.width > MAX_WIDTH || coded_size.height > MAX_HEIGHT ||
      output_buffer_size > MAX_OUTPUT_BUFFER_SIZE) {
    LOG(ERROR) << "Invalid input parameters";
    return false;
  }

  if (!SetOutputBufferFormat(coded_size, output_buffer_size)) {
    return false;
  }

  if (!SetInputBufferFormat(coded_size)) {
    return false;
  }

  if (!RequestInputBuffers()) {
    return false;
  }

  if (!RequestOutputBuffers()) {
    return false;
  }

  return true;
}