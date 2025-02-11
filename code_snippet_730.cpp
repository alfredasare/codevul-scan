#include <memory>

class Stub {
public:
    //...
    std::shared_ptr<Loader> stub_;
    //...
};

bool is_loading(const std::shared_ptr<Stub>& stub) {
    if (stub && stub->stub_) {
        return stub->stub_->is_loading();
    }
    return false;
}