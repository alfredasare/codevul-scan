QuicPacket* ConstructHandshakePacket(QuicGuid guid, CryptoTag tag) {
CryptoHandshakeMessage message;
message.tag = tag;
CryptoFramer crypto\_framer;
scoped\_ptr<QuicData> data(crypto\_framer.ConstructHandshakeMessage(message));
QuicFramer quic\_framer(QuicDecrypter::Create(kNULL),
QuicEncrypter::Create(kNULL));

QuicPacketHeader header;
header.guid = guid;
header.retransmission\_count = 0;
header.packet\_sequence\_number = 1;
header.transmission\_time = 0;
header.flags = PACKET\_FLAGS\_NONE;
header.fec\_group = 0;

std::string data\_str = data->data();
size\_t max\_length = QuicPacket::kMaxHandshakeSize;
if (data\_str.length() > max\_length) {
data\_str.resize(max\_length);
}

QuicStreamFrame stream\_frame(kCryptoStreamId, false, 0,
data\_str);

QuicFrame frame(&stream\_frame);
QuicFrames frames;
frames.push\_back(frame);
QuicPacket* packet;
quic\_framer.ConstructFragementDataPacket(header, frames, &packet);
return packet;
}