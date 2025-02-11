#include <iostream>
#include <random>

static size_t ChooseBufferSize(size_t callback_buffer_size) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<size_t> dist(256, 16384);

    size_t buffer_size = dist(mt);

    return buffer_size;
}