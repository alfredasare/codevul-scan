c++
#include <mutex>

class NavigationControllerImpl {
public:
    // ...

private:
    mutable std::mutex mtx_;
    int transient_entry_index_ = -1;
    std::unique_ptr<NavigationEntryImpl> pending_entry_;
    std::vector<std::unique_ptr<NavigationEntryImpl>> entries_;

    NavigationEntryImpl* GetActiveEntry() const {
        std::lock_guard<std::mutex> lock(mtx_);
        if (transient_entry_index_ != -1)
            return entries_[transient_entry_index_].get();
        if (pending_entry_)
            return pending_entry_.get();
        return GetLastCommittedEntry();
    }

    // ...
};