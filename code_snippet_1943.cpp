StateStore& ExtensionSystemImpl::Shared::state\_store() {
std::unique\_lock<std::mutex> lock(state\_store\_mutex_);
return *state\_store\_;
}