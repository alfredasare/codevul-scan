void BnDrm::readVector(const Parcel &data, Vector<uint8_t> &vector) const {
    const int MAX_VECTOR_SIZE = 1024;
    uint32_t size = data.readInt32();
    if (size < 0 || size > MAX_VECTOR_SIZE) {
        throw std::runtime_error("Invalid vector size");
    }
    vector.insertAt(0, size);
    uint8_t* buffer = new uint8_t[size];
    data.read(buffer, size);
    vector.editArray()->assign(buffer, buffer + size);
    delete[] buffer;
}