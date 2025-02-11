void BnCrypto::writeVector(Parcel *reply, Vector<uint8_t> const &vector) const {
reply->writeInt32(vector.size());
size\_t arraySize = vector.size();
if (arraySize > 0) {
// Check if the stored size matches the actual array size
uint32\_t storedSize = reply->readInt32();
if (storedSize != arraySize) {
// Handle error scenario, throw exception or return
}
reply->write(vector.array(), arraySize);
}
}