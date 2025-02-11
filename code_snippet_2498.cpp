std::unique_ptr<ImageProcessorClient> ImageProcessorClient::Create(
    const ImageProcessor::PortConfig& input_config,
    const ImageProcessor::PortConfig& output_config,
    size_t num_buffers,
    std::vector<std::unique_ptr<VideoFrameProcessor>> frame_processors) {
  if (num_buffers > kMaxNumBuffers || num_buffers == 0) {
    LOG(ERROR) << "Invalid number of buffers: " << num_buffers;
    return nullptr;
  }

  if (!input_config.IsValid() || !output_config.IsValid()) {
    LOG(ERROR) << "Invalid input or output config";
    return nullptr;
  }

  if (frame_processors.empty()) {
    LOG(ERROR) << "No frame processors provided";
    return nullptr;
  }

  auto ip_client =
      base::WrapUnique(new ImageProcessorClient(std::move(frame_processors)));
  if (!ip_client->CreateImageProcessor(input_config, output_config, num_buffers)) {
    LOG(ERROR) << "Failed to create ImageProcessor";
    return nullptr;
  }
  return ip_client;
}