#include <atomic>

std::atomic<int> pre_count_(0);

int GetPreCountAndReset() {
    return pre_count_.exchange(0);
}