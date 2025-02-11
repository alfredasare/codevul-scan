void BnDrm::readVector(const Parcel &data, Vector<uint8_t> &vector) const {
 uint32_t size = data.readInt32();
 if (size > 0 && size < vector.max_size()) {
 vector.insertAt((size_t)0, size);
 data.read(vector.editArray(), size);
 } else {
 // Handle error condition
 }
}