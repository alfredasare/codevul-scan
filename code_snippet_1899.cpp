ScopedMMap(void* mem, uint32_t len) : mem_(mem), len_(len) {
    if (mem == nullptr || len == 0 || len > std::numeric_limits<uint32_t>::max()) {
        throw std::runtime_error("Invalid input");
    }
    //... rest of the code...
}