#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
size_t desired_records_size = 0;

void WaitForEvents(size_t numbers_of_events) {
    std::unique_lock<std::mutex> lck(mtx);
    desired_records_size = numbers_of_events;
    cv.wait(lck, [&]{ return records_.size() >= desired_records_size; });
}

void ProduceRecords() {
    while (true) {
        std::unique_lock<std::mutex> lck(mtx);
        records_.push_back(/* new record */);
        lck.unlock();
        cv.notify_one();
    }
}