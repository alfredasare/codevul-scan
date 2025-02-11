c++
std::unique_ptr<TracedValue> InspectorMarkLoadEvent::Data(LocalFrame* frame) {
  ScopedMemoryHandle handle = GetFrameMemoryHandle(frame);
  if (!handle || !handle.IsValid()) {
    // Handle error condition, e.g. return an error value or throw an exception.
  }
  std::unique_ptr<TracedValue> frame_data = FrameEventData(handle.Get());
  frame_data->SetString("frame", ToHexString(handle.Get(), handle.GetSize()));
  return frame_data;
}