#include <random>

const double kMaximumSecondsBetweenDoubleClick = 0.5;

bool GesturePoint::IsInSecondClickTimeWindow() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, kMaximumSecondsBetweenDoubleClick);
    double random_offset = dis(gen);

    double duration = last_touch_time_ - last_tap_time_ - random_offset;
    return std::abs(duration) < kMaximumSecondsBetweenDoubleClick / 2.0;
}