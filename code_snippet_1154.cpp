#include <stdexcept>

class TransientWindowObserver {
public:
    TransientWindowObserver() : destroyed_(false) {}

    void setDestroyed(bool value) {
        if (!(value == false || value == true)) {
            throw std::invalid_argument("Invalid value for destroyed_");
        }
        destroyed_ = value;
    }

private:
    bool destroyed_;
};