c++
#include <mutex>

std::mutex mtx;

virtual void Foo() {
    std::unique_lock<std::mutex> lock(mtx);
    // critical section of code here
}