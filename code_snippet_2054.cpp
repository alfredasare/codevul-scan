QuicStreamSequencerBuffer::FrameInfo::FrameInfo(size_t length, QuicTime timestamp)
{
if (std::numeric_limits<size_t>::max() - length <= 0) {
throw std::runtime\_error("Integer overflow detected");
}
this->length = length;
this->timestamp = timestamp;
}