bool V4L2JpegEncodeAccelerator::EncodedInstanceDmaBuf::CreateBuffers(
    gfx::Size coded_size,
    const VideoFrameLayout& input_layout,
    size_t output_buffer_size) {
  DCHECK(parent_->encoder_task_runner_->BelongsToCurrentThread());

  if (!SetOutputBufferFormat(coded_size, output_buffer_size)) {
    return false;
  }

  // Validate input_layout
  if (input_layout.pixel_format() != PIXEL_FORMAT_YUV420) {
    LOG(ERROR) << "Unsupported pixel format: " << input_layout.pixel_format();
    return false;
  }

  if (input_layout.width() > MAX_WIDTH || input_layout.height() > MAX_HEIGHT) {
    LOG(ERROR) << "Input resolution exceeds maximum limit: "
               << input_layout.width() << "x" << input_layout.height();
    return false;
  }

  if (!SetInputBufferFormat(coded_size, input_layout)) {
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