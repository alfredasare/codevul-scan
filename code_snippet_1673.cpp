#include <mutex>

class CustomButton {
public:
  // ...

  void StartThrobbing(int cycles_til_stop) {
    std::unique_lock<std::mutex> lock(button_mutex_);
    is_throbbing_ = true;
    hover_animation_->StartThrobbing(cycles_til_stop);
  }

private:
  std::mutex button_mutex_;
  // ...
};