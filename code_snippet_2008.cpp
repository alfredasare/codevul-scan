#include <mutex>
#include <unordered_set>

std::unordered_set<TracingUI*, MyHash, MyEqual> tracing_uis_;
std::mutex mtx;

void TracingControllerImpl::UnregisterTracingUI(TracingUI* tracing_ui) {
    std::lock_guard<std::mutex> lock(mtx);
    auto it = tracing_uis_.find(tracing_ui);
    if (it != tracing_uis_.end()) {
        tracing_uis_.erase(it);
    }
}