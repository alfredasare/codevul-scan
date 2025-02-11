virtual int WritePacketToWire(QuicPacketSequenceNumber number,
                              const QuicEncryptedPacket& packet,
                              bool resend,
                              int* error) {
  QuicFramer framer(QuicDecrypter::Create(kNULL), QuicEncrypter::Create(kNULL));
  FramerVisitorCapturingAcks visitor;
  framer.set_visitor(&visitor);

  // Validate input parameters
  if (number < 0 || packet.length() > MAX_PACKET_LENGTH) {
    LOG_ERROR("Invalid input parameters");
    return -1;
  }

  // Validate IPEndPoint objects
  IPEndPoint src, dst;
  if (!src.IsValid() ||!dst.IsValid()) {
    LOG_ERROR("Invalid IPEndPoint objects");
    return -1;
  }

  EXPECT_TRUE(framer.ProcessPacket(src, dst, packet));
  header_ = *visitor.header();
  return packet.length();
}