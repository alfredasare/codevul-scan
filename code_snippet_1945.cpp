void BnCrypto::writeVector(Parcel *reply, Vector<uint8_t> const &vector) const {
    uint32_t vectorSize = vector.size();
    if (vectorSize > reply->getMaxBufferSize()) {
        throw std::runtime_error("Vector size exceeds Parcel buffer capacity");
    }
    reply->writeInt32(vectorSize);
    reply->write(vector.array(), vectorSize);
}