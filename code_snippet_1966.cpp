V4L2JpegEncodeAccelerator::EncodedInstanceDmaBuf::EncodedInstanceDmaBuf(
    V4L2JpegEncodeAccelerator* parent)
    : parent_(parent),
      input_streamon_(false),
      output_streamon_(false),
      input_buffer_pixelformat_(0),
      input_buffer_num_planes_(0),
      output_buffer_pixelformat_(0) {
  if (!parent) {
    throw std::invalid_argument("parent pointer is null");
  }

  if (input_buffer_pixelformat_ < 0 || input_buffer_pixelformat_ > V4L2_PIX_FMT_MAX) {
    throw std::invalid_argument("Invalid input buffer pixelformat");
  }

  if (input_buffer_num_planes_ < 0 || input_buffer_num_planes_ > V4L2_MAX_PLANES) {
    throw std::invalid_argument("Invalid input buffer number of planes");
  }

  if (output_buffer_pixelformat_ < 0 || output_buffer_pixelformat_ > V4L2_PIX_FMT_MAX) {
    throw std::invalid_argument("Invalid output buffer pixelformat");
  }
}