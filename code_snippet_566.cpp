c++
#include <functional>
#include <stdexcept>

void MockNetworkTransaction::SetBeforeHeadersSentCallback(
    const BeforeHeadersSentCallback& callback)
{
    // Check if the callback is a valid function object
    if (!callback) {
        throw std::invalid_argument("callback is not a valid function object");
    }
}