c++
static u64 OS_GetSysClockHIGHRES_FULL() {
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    now.QuadPart -= init_counter.QuadPart;

    if (frequency.QuadPart == 0) {
        throw std::runtime_error("Frequency is zero");
    }

    uint64_t max_value = std::numeric_limits<decltype(now.QuadPart)>::max() / 1000000;
    if (now.QuadPart > max_value * frequency.QuadPart) {
        throw std::runtime_error("Integer overflow in multiplication");
    }

    uint64_t result = now.QuadPart * 1000000 / frequency.QuadPart;
    return result;
}