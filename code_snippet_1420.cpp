class ImeObserver {
public:
    bool HasListener(const std::string& event_name) const {
        if (!profile_) {
            return false; // profile_ has not been initialized
        }
        return extensions::EventRouter::Get(*profile_)->HasEventListener(event_name);
    }

private:
    std::unique_ptr<extensions::Profile> profile_;
};