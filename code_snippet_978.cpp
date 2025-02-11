#include <mutex>

class OffscreenCanvas {
public:
  OffscreenCanvas() : origin_clean_(true), disable_reading_from_canvas_(false) {}

  bool OriginClean() const {
    std::lock_guard<std::mutex> lock(origin_mutex_);
    return origin_clean_ &&!disable_reading_from_canvas_;
  }

private:
  mutable std::mutex origin_mutex_;
  bool origin_clean_;
  bool disable_reading_from_canvas_;
};