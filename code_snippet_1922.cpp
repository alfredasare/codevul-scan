QuicStreamSequencerBuffer::FrameInfo::FrameInfo(size_t length,
                                            QuicTime timestamp)
: length(static_cast<uint64_t>(length)), timestamp(timestamp) {}