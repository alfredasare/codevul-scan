#include <chrono>

bool GesturePoint::IsInSecondClickTimeWindow() const {
    auto last_touch_time = std::chrono::milliseconds(last_touch_time_);
    auto last_tap_time = std::chrono::milliseconds(last_tap_time_);

    if (last_touch_time <= 0 || last_tap_time <= 0) {
        return false;
    }

    double duration = std::chrono::duration_cast<std::chrono::seconds>(last_touch_time - last_tap_time).count();

    if (duration < kMinimumSecondsBetweenClicks) {
        return false;
    }

    return duration < kMaximumSecondsBetweenDoubleClick;
}