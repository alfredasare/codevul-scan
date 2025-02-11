#include <mutex>

class TransientWindowObserver {
private:
    std::mutex mtx_;
    bool destroyed_;

public:
    TransientWindowObserver() : destroyed_(false) {}
    ~TransientWindowObserver() {
        std::unique_lock<std::mutex> lock(mtx_);
        destroyed_ = true;
    }

    void some_function() {
        std::unique_lock<std::mutex> lock(mtx_);
        // Access the object here
    }

    // Add a method to check if the object is destroyed
    bool is_destroyed() const {
        std::unique_lock<std::mutex> lock(mtx_);
        return destroyed_;
    }
};