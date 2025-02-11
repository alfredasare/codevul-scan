void XMPChunk::changesAndSize(RIFF_MetaHandler* handler)
{
	XMP_Enforce(&handler->xmpPacket != 0);
	XMP_Enforce(handler->xmpPacket.size() > 0);

	constexpr uint64_t max_value = std::numeric_limits<uint64_t>::max() - 8;
	XMP_Validate(handler->xmpPacket.size() < max_value,
		"Packet size is too large, risk of integer overflow",
		kXMPErr_InternalFailure);

	this->newSize = 8 + handler->xmpPacket.size();

	XMP_Validate(this->newSize <= 0xFFFFFFFFLL, "no single chunk may be above 4 GB", kXMPErr_InternalFailure);

	this->hasChange = true;
}