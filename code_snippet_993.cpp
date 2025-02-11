#include <random>

class VideoFrameBuffer {
public:
    VideoFrameBuffer() : bytes_per_row_(0), needs_update_(true) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 1023);
        bytes_per_row_ = dis(gen);
    }

    int bytes_per_row_;
    bool needs_update_;
};