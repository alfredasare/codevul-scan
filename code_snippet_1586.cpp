bool V4L2JpegEncodeAccelerator::EncodedInstanceDmaBuf::CreateBuffers(
    gfx::Size coded_size,
    const VideoFrameLayout& input_layout,
    size_t output_buffer_size) {
  DCHECK(parent_->encoder_task_runner_->BelongsToCurrentThread());

  if (!ValidateInputParameters(coded_size, output_buffer_size, input_layout)) {
    return false;
  }

  if (!SetOutputBufferFormat(coded_size, output_buffer_size)) {
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

bool V4L2JpegEncodeAccelerator::EncodedInstanceDmaBuf::ValidateInputParameters(
    gfx::Size coded_size,
    size_t output_buffer_size,
    const VideoFrameLayout& input_layout) {
  if (coded_size.width <= 0 || coded_size.height <= 0) {
    return false;
  }
  if (coded_size.width > MAX_WIDTH || coded_size.height > MAX_HEIGHT) {
    return false;
  }
  if (output_buffer_size <= 0 || output_buffer_size > MAX_BUFFER_SIZE) {
    return false;
  }
  if (input_layout.plane_count < 1 || input_layout.plane_count > MAX_PLANES) {
    return false;
  }
  for (size_t i = 0; i < input_layout.plane_count; ++i) {
    if (input_layout.plane_sizes[i].width <= 0 || input_layout.plane_sizes[i].height <= 0) {
      return false;
    }
    if (input_layout.plane_formats[i] == 0) {
      return false;
    }
  }
  return true;
}