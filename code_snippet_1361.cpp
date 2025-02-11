#include <memory>

class WindowList {
public:
    WindowList(size_t initialCapacity) : windows_(std::make_unique<std::vector<Window*>(initialCapacity))) {}

    ~WindowList() { windows_.reset(); }

    void push_back(Window* window) {
        windows_->push_back(window);
    }

    Window* operator[](size_t index) {
        return windows_->at(index);
    }

    bool empty() const {
        return windows_->empty();
    }

private:
    std::unique_ptr<std::vector<Window*>> windows_;
};

bool IsCarryOverCandidateForSplitView(const WindowList& windows, size_t i) {
    if (i >= windows.size()) {
        return false; // out-of-bounds access
    }
    return CanSnapInSplitview(windows[i]) &&
          !windows[i]->GetProperty(kIsShowingInOverviewKey) &&
           static_cast<ash::AppType>(windows[i]->GetProperty(aura::client::kAppType))!= AppType::ARC_APP;
}