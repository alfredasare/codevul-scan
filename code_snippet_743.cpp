#include <memory>

class TaskManagerTableModel {
public:
  void OnItemsAdded(int start, int length) {
    if (observer_) {
      observer_->OnItemsAdded(start, length);
      observer_.reset(); // Release the observer object
    }
  }

private:
  std::unique_ptr<Observer> observer_;
};