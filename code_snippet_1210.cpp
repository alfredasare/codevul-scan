#include <mutex>

std::mutex mtx;

void HTMLIFrameElement::SetCollapsed(bool collapse) {
    std::unique_lock<std::mutex> lock(mtx);

    if (collapsed_by_client_ == collapse) {
        return;
    }

    collapsed_by_client_ = collapse;

    // Add any necessary error handling or notifications here.
}